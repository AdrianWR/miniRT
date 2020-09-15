/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 17:24:59 by aroque            #+#    #+#             */
/*   Updated: 2020/09/15 11:29:58 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "vector.h"
#include "figures.h"
#include "server.h"
#include <stdbool.h>
#include <math.h>

static void			square_vertex(t_square *s)
{
	t_point		basis_i;
	t_point		basis_j;

	basis_i = cross(s->normal, vector(s->normal.z, s->normal.x, s->normal.y));
	basis_j = cross(s->normal, basis_i);
	basis_i = scale(basis_i, s->side / 2);
	basis_j = scale(basis_j, s->side / 2);
	s->vertex[0] = add(add(s->center, basis_i), basis_j);
	s->vertex[1] = sub(add(s->center, basis_i), basis_j);
	s->vertex[2] = sub(sub(s->center, basis_i), basis_j);
	s->vertex[3] = add(sub(s->center, basis_i), basis_j);
}

t_square			*new_square(char **params, int *errcode)
{
	t_square	*square;

	if (strarray_len(params) != 5 && (*errcode = EBADFMT))
		return (NULL);
	if (!(square = malloc(sizeof(*square))))
		return (NULL);
	square->type = SQUARE;
	square->color = ft_atoc(params[4], errcode);
	square->normal = ft_atov(params[3], errcode);
	square->side = ft_atof(params[2], errcode);
	square->center = ft_atov(params[1], errcode);
	square_vertex(square);
	if (out_of_range_vector(square->normal))
		*errcode = EOURVEC;
	return (square);
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

bool				hit_square(t_ray *ray, t_square *square)
{
	bool			hit;
	t_ray			r;
	t_plane			pl;

	hit = false;
	pl.point = square->center;
	pl.normal = square->normal;
	pl.color = square->color;
	r.origin = ray->origin;
	r.direction = ray->direction;
	r.record.t = ray->record.t;
	if (hit_plane(&r, &pl) && is_inside(r.record, square->vertex, 4))
	{
		*ray = r;
		ray->record.object = square;
		hit = true;
	}
	return (hit);
}
