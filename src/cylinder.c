/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 17:44:32 by aroque            #+#    #+#             */
/*   Updated: 2020/09/15 11:30:14 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "vector.h"
#include "figures.h"
#include "server.h"
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

t_cylinder		*new_cylinder(char **params, int *errcode)
{
	t_cylinder	*cylinder;

	if (strarray_len(params) != 6 && (*errcode = EBADFMT))
		return (NULL);
	if (!(cylinder = malloc(sizeof(*cylinder))))
		return (NULL);
	cylinder->type = CYLINDER;
	cylinder->color = ft_atoc(params[5], errcode);
	cylinder->height = ft_atof(params[4], errcode);
	cylinder->radius = ft_atof(params[3], errcode) / 2;
	cylinder->axis = ft_atov(params[2], errcode);
	cylinder->center = ft_atov(params[1], errcode);
	if (out_of_range_vector(cylinder->axis))
		*errcode = EOURVEC;
	else
		cylinder->axis = norm(cylinder->axis);
	return (cylinder);
}

static void		roots(t_ray r, t_cylinder cy, float root[2])
{
	float		a;
	float		half_b;
	float		c;
	t_vector	v;
	t_vector	u;

	v = scale(cy.axis, dot(r.direction, cy.axis));
	v = sub(r.direction, v);
	u = scale(cy.axis, (dot(sub(r.origin, cy.center), cy.axis)));
	u = sub(sub(r.origin, cy.center), u);
	a = length_squared(v);
	half_b = dot(v, u);
	c = length_squared(u) - pow(cy.radius, 2);
	root[0] = (-half_b - sqrt(pow(half_b, 2) - a * c)) / a;
	root[1] = (-half_b + sqrt(pow(half_b, 2) - a * c)) / a;
}

static float	solve(t_ray r, t_cylinder cy, float *y, bool hit[2])
{
	float		t;
	float		dist[2];
	float		root[2];
	t_vector	b_ray;

	roots(r, cy, root);
	b_ray = sub(cy.center, r.origin);
	dist[0] = dot(cy.axis, sub(scale(r.direction, root[0]), b_ray));
	dist[1] = dot(cy.axis, sub(scale(r.direction, root[1]), b_ray));
	hit[0] = (dist[0] >= 0 && dist[0] <= cy.height && root[0] > EPSILON);
	hit[1] = (dist[1] >= 0 && dist[1] <= cy.height && root[1] > EPSILON);
	if (hit[0] && hit[1])
	{
		*y = root[0] < root[1] ? dist[0] : dist[1];
		t = root[0] < root[1] ? root[0] : root[1];
	}
	else
	{
		*y = hit[0] ? dist[0] : dist[1];
		t = hit[0] ? root[0] : root[1];
	}
	return (t);
}

bool			hit_cylinder(t_ray *ray, t_cylinder *cylinder)
{
	float		y;
	float		t;
	bool		hit[2];

	t = solve(*ray, *cylinder, &y, hit);
	if ((hit[0] || hit[1]) && ray->record.t > t && t > EPSILON)
	{
		ray->record.t = t;
		ray->record.p = at(*ray);
		ray->record.normal = norm(sub(ray->record.p,
					add(scale(cylinder->axis, y), cylinder->center)));
		if (hit[1] & !hit[0])
			ray->record.normal = scale(ray->record.normal, -1);
		ray->record.color = cylinder->color;
	}
	return (hit[0] || hit[1]);
}
