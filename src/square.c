/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 17:24:59 by aroque            #+#    #+#             */
/*   Updated: 2020/09/01 17:58:56 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ray.h"
#include "vector.h"
#include "figures.h"
#include <stdbool.h>
#include <math.h>

t_square			*new_square(t_point c, float side, t_vector n, t_color cl)
{
	t_square	*square;

	if (!(square = malloc(sizeof(*square))))
		return (NULL);
	square->type = SQUARE;
	square->center = c;
	square->side = side;
	square->normal = n;
	square->color = cl;
	return (square);
}



bool			hit_square(t_ray *ray, t_square *square)
{
	t_plane		plane;
	t_ray		r;

	plane.normal = square->normal;
	plane.point = square->center;
	plane.color = square->color;
	plane.type = TRIANGLE;

	r.origin = ray->origin;
	r.direction = ray->direction;
	r.record.t = INFINITY;
	if (hit_plane(&r, &plane))
	{
		*ray = r;
		ray->record.object = square;
		return (true);
	}
	return (false);
}
