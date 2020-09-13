/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 16:13:00 by aroque            #+#    #+#             */
/*   Updated: 2020/09/13 00:32:54 by aroque           ###   ########.fr       */
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
	unsigned i;

	i = 1;
	while (params[i])
		i++;
	if (i != 4)
		return (NULL);
	if (!(plane = malloc(sizeof(*plane))))
		return (NULL);
	plane->type = PLANE;
	plane->color = atoc(params[--i]);
	plane->normal = norm(atov(params[--i]));
	plane->point = atov(params[--i]);
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
