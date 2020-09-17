/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 16:13:00 by aroque            #+#    #+#             */
/*   Updated: 2020/09/15 12:47:33 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "libft.h"
#include "vector.h"
#include "figures.h"
#include "server.h"
#include <stdbool.h>

t_plane		*new_plane(char **params, int *errcode)
{
	t_plane	*plane;

	if (strarray_len(params) != 4 && (*errcode = EBADFMT))
		return (NULL);
	if (!(plane = malloc(sizeof(*plane))))
		return (NULL);
	plane->type = PLANE;
	plane->point = ft_atov(params[1], errcode);
	plane->normal = ft_atov(params[2], errcode);
	plane->color = ft_atoc(params[3], errcode);
	if (out_of_range_vector(plane->normal))
		*errcode = EOURVEC;
	return (plane);
}

bool		hit_plane(t_ray *ray, t_plane *plane)
{
	double	t;
	double	den;

	den = dot(norm(ray->direction), plane->normal);
	if (!den)
		return (false);
	t = dot(sub(plane->point, ray->origin), plane->normal) / den;
	if (ray->record.t > t && t > EPSILON)
	{
		if (dot(ray->direction, plane->normal) > 0)
			plane->normal = scale(plane->normal, -1);
		ray->record.t = t;
		ray->record.p = at(*ray);
		ray->record.normal = plane->normal;
		ray->record.color = plane->color;
		ray->record.type = plane->type;
		ray->record.object = plane;
		return (true);
	}
	return (false);
}
