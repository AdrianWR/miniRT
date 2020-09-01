/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 23:56:26 by aroque            #+#    #+#             */
/*   Updated: 2020/08/29 18:52:47 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "vector.h"
#include "figures.h"
#include <stdbool.h>

#include <stdio.h>

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

//static t_vector	triangle_normal(t_vector dir, t_triangle triangle)
//{
//	t_vector side_a;
//	t_vector side_b;
//	t_vector normal;
//
//	(void) dir;
//	side_b = sub(triangle.c, triangle.a);
//	side_a = sub(triangle.b, triangle.a);
//	normal = norm(cross(side_a, side_b));
//	//normal = norm(cross(side_b, side_a));
//	//pvec = cross(dir, side_a);
//	//det = dot(pvec, side_b);
//	//printf("det = %f\n", dot(dir, normal));
//	//return (dot(ray.direction, normal) > 0 ? scale(normal, -1) : normal);
//	//if (det > 0)
//	//if (dot(norm(dir), normal) > 0)
//	//	normal = scale(normal, -1);
//	return (normal);
//}

#include <math.h>

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

//static int		p_is_outside(t_point p1, t_point p2, t_point p3, t_point ip)
//{
//	t_point	v1;
//	t_point	v2;
//	t_point	vp;
//
//	v1 = sub(p2, p1);
//	v2 = sub(p3, p1);
//	vp = sub(ip, p1);
//	if (dot(cross(v1, v2), cross(v1, vp)) < 0)
//		return (1);
//	return (0);
//}

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
	(void) is_inside;
	if (hit_plane(&r, &plane))
	{
		if (!is_inside(r.record.p, triangle->a, triangle->b, plane.normal))
			return (false);
		if (!is_inside(r.record.p, triangle->b, triangle->c, plane.normal))
			return (false);
		if (!is_inside(r.record.p, triangle->c, triangle->a, plane.normal))
			return (false);
		*ray = r;
		//printf("%f | %f | %f\n", ray->record.normal.x, ray->record.normal.y, ray->record.normal.z);
		ray->record.object = triangle;
		return (true);
	}
	return (false);
}
