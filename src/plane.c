/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 16:13:00 by aroque            #+#    #+#             */
/*   Updated: 2020/09/08 15:38:48 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "libft.h"
#include "vector.h"
#include "figures.h"
#include "scene.h"
#include <stdbool.h>

t_plane	*new_plane(char **params)
{
	t_plane	*plane;

	if (!(plane = malloc(sizeof(*plane))))
		return (NULL);
	plane->type = PLANE;
	plane->point = atov(params[1]);
	plane->normal = norm(atov(params[2]));
	plane->color = atoc(params[3]);
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
