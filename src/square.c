/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 17:24:59 by aroque            #+#    #+#             */
/*   Updated: 2020/09/06 17:57:25 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ray.h"
#include "vector.h"
#include "figures.h"
#include <stdbool.h>
#include <math.h>

static void			square_vertex(t_point center, t_vector normal, t_point *v)
{
	t_point		basis_i;
	t_point		basis_j;

	basis_i = norm(cross(normal, vector(normal.z, normal.x, normal.y)));
	basis_j = norm(cross(normal, basis_i));
	v[0] = add(add(center, basis_i), basis_j);
	v[1] = sub(add(center, basis_i), basis_j);
	v[2] = sub(sub(center, basis_i), basis_j);
	v[3] = add(sub(center, basis_i), basis_j);
}

t_square			*new_square(t_point c, t_vector n, float side, t_color cl)
{
	t_square	*square;

	if (!(square = malloc(sizeof(*square))))
		return (NULL);
	square->type = SQUARE;
	square->center = c;
	square->side = side;
	square->normal = n;
	square->color = cl;
	square_vertex(c, n, square->vertex);
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
	t_plane			*pl;

	hit = false;
	pl = new_plane(square->center, square->normal, square->color);
	r.origin = ray->origin;
	r.direction = ray->direction;
	r.record.t = ray->record.t;
	if (hit_plane(&r, pl) && is_inside(r.record, square->vertex, 4))
	{
		*ray = r;
		ray->record.object = square;
		hit = true;
	}
	free(pl);
	return (hit);
}
