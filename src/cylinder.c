/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 17:44:32 by aroque            #+#    #+#             */
/*   Updated: 2020/09/08 09:06:12 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "vector.h"
#include "figures.h"
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include "scene.h"

t_cylinder		*new_cylinder(char **params)
{
	t_cylinder	*cylinder;

	if (!(cylinder = malloc(sizeof(*cylinder))))
		return (NULL);
	cylinder->type = CYLINDER;
	cylinder->center = atov(params[1]);
	cylinder->axis = norm(atov(params[2]));
	cylinder->radius = atof(params[3]) / 2;
	cylinder->height = atof(params[4]);
	cylinder->color = atoc(params[5]);
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

static bool		solve(t_ray r, t_cylinder cy, float *y, float *t)
{
	bool		hit[2];
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
		*t = root[0] < root[1] ? root[0] : root[1];
	}
	else
	{
		*y = hit[0] ? dist[0] : dist[1];
		*t = hit[0] ? root[0] : root[1];
	}
	return (hit[0] || hit[1]);
}

bool			hit_cylinder(t_ray *ray, t_cylinder *cylinder)
{
	bool		hit;
	float		y;
	float		t;

	hit = false;
	if (solve(*ray, *cylinder, &y, &t) && ray->record.t > t && t > EPSILON)
	{
		ray->record.t = t;
		ray->record.p = at(*ray);
		ray->record.normal = norm(sub(ray->record.p,
					add(scale(cylinder->axis, y), cylinder->center)));
		ray->record.color = cylinder->color;
		hit = true;
	}
	return (hit);
}
