/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 23:56:26 by aroque            #+#    #+#             */
/*   Updated: 2020/09/01 22:18:41 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "vector.h"
#include "figures.h"
#include <stdbool.h>
#include <math.h>

t_triangle			*new_triangle(t_point a, t_point b, t_point c, t_color cl)
{
	t_triangle	*triangle;

	if (!(triangle = malloc(sizeof(*triangle))))
		return (NULL);
	triangle->type = TRIANGLE;
	triangle->a = a;
	triangle->b = b;
	triangle->c = c;
	triangle->color = cl;
	return (triangle);
}



static bool		is_inside(t_point p, t_point v0, t_point v1, t_vector n)
{
	t_vector	edge;
	t_vector	c;

	edge = sub(v1, v0);
	c = sub(p, v0);
	if (dot(cross(edge, c), n) > 0)
		return (true);
	return (false);
}

bool			hit_triangle(t_ray *ray, t_triangle *triangle)
{
	t_plane		plane;
	t_vector	side_b;
	t_vector	side_c;
	t_ray		r;

	side_b = sub(triangle->b, triangle->a);
	side_c = sub(triangle->c, triangle->a);
	plane.normal = norm(cross(side_b, side_c));
	plane.point = triangle->a;
	plane.color = triangle->color;
	plane.type = TRIANGLE;

	r.origin = ray->origin;
	r.direction = ray->direction;
	r.record.t = INFINITY;
	if (hit_plane(&r, &plane))
	{
		if (!is_inside(r.record.p, triangle->a, triangle->b, plane.normal))
			return (false);
		if (!is_inside(r.record.p, triangle->b, triangle->c, plane.normal))
			return (false);
		if (!is_inside(r.record.p, triangle->c, triangle->a, plane.normal))
			return (false);
		*ray = r;
		ray->record.object = triangle;
		return (true);
	}
	return (false);
}
