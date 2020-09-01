/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 16:13:00 by aroque            #+#    #+#             */
/*   Updated: 2020/08/29 18:24:32 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "vector.h"
#include "figures.h"
#include <stdbool.h>

t_plane		*new_plane(t_point point, t_vector normal, t_color color)
{
	t_plane	*plane;

	if (!(plane = malloc(sizeof(*plane))))
		return (NULL);
	plane->type = PLANE;
	plane->point = point;
	plane->normal = norm(normal);
	plane->color = color;
	return (plane);
}

bool		hit_plane(t_ray *ray, t_plane *plane)
{
	float	t;
	float	den;

//	ray->record.normal = dot(ray->direction, plane->normal) > 0 ? scale(plane->normal, -1) : plane->normal;
	den = dot(norm(ray->direction), plane->normal);
	if (den)
	{
		t = dot(sub(plane->point, ray->origin), plane->normal) / den;
		if (ray->record.t > t && t > 0)
		{
			ray->record.t = t;
			ray->record.p = at(*ray);
			ray->record.normal = dot(ray->direction, plane->normal) > 0 ? scale(plane->normal, -1) : plane->normal;
			ray->record.color = plane->color;
			ray->record.type = plane->type;
			ray->record.object = plane;
			return (true);
		}
	}
	//t = dot(sub(plane->point, ray->origin), plane->normal) / den;
	//if (ray->record.t > t && t > 0 && den <= 0)
	//{
	//	ray->record.t = t;
	//	ray->record.p = at(*ray);
	//	ray->record.normal = plane->normal;
	//	ray->record.color = plane->color;
	//	ray->record.type = plane->type;
	//	return (true);
	//}
	return (false);
}
