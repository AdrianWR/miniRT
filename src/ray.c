/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 11:06:11 by aroque            #+#    #+#             */
/*   Updated: 2020/08/30 01:36:25 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "vector.h"
#include "figures.h"
#include <math.h>
#include <stdbool.h>
#include <stdio.h>

t_point	at(t_ray ray)
{
	return (add(ray.origin, scale(ray.direction, ray.record.t)));
}

bool		intersect(t_ray *ray, t_list *world)
{
	bool		hit;
	void		*figure;
	t_type		type;

	figure = NULL;
	hit = false;
	ray->record.t = INFINITY;
	while (world)
	{
		type = *((t_type *)world->content);
		if (ray->record.object != world->content)
		{
			if (type == SPHERE)
				hit |= hit_sphere(ray, (t_sphere *)world->content);
			if (type == PLANE)
				hit |= hit_plane(ray, (t_plane *)world->content);
			if (type == TRIANGLE)
				hit |= hit_triangle(ray, (t_triangle *)world->content);
			//if (ray->record)

		}
		world = world->next;
	}
	return (hit);
}
