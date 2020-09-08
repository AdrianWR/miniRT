/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 23:56:26 by aroque            #+#    #+#             */
/*   Updated: 2020/09/08 09:33:23 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "vector.h"
#include "figures.h"
#include "scene.h"
#include <stdbool.h>
#include <math.h>

t_triangle			*new_triangle(char **params)
{
	t_triangle		*triangle;
	t_vector		*v;

	if (!(triangle = malloc(sizeof(*triangle))))
		return (NULL);
	v = triangle->vertex;
	triangle->type = TRIANGLE;
	triangle->vertex[0] = atov(params[1]);
	triangle->vertex[1] = atov(params[2]);
	triangle->vertex[2] = atov(params[3]);
	triangle->color = atoc(params[4]);
	triangle->normal = norm(cross(
				sub(v[1], v[0]), sub(v[2], v[0])));
	return (triangle);
}

static bool			is_inside(t_hit r, t_point *v, unsigned int vertex)
{
	unsigned int	i;
	bool			in;
	float			det[vertex];
	t_vector		det_cross;

	in = true;
	i = 0;
	while (i < vertex)
	{
		if (i == vertex - 1)
			det_cross = cross(sub(v[i], v[0]), sub(r.p, v[0]));
		else
			det_cross = cross(sub(v[i], v[i + 1]), sub(r.p, v[i + 1]));
		det[i] = dot(det_cross, r.normal);
		if (i > 0)
			in &= (det[i - 1] >= 0) ^ (det[i] < 0);
		i++;
	}
	return (in);
}

bool				hit_triangle(t_ray *ray, t_triangle *triangle)
{
	bool			hit;
	t_ray			r;
	t_plane			pl;

	hit = false;
	pl.point = triangle->vertex[0];
	pl.normal = triangle->normal;
	pl.color = triangle->color;
	r.origin = ray->origin;
	r.direction = ray->direction;
	r.record.t = ray->record.t;
	if (hit_plane(&r, &pl) && is_inside(r.record, triangle->vertex, 3))
	{
		*ray = r;
		ray->record.object = triangle;
		hit = true;
	}
	return (hit);
}
