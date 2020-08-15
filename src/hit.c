/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 15:33:33 by aroque            #+#    #+#             */
/*   Updated: 2020/08/14 22:59:14 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "hittables.h"
#include <math.h>
#include <stdbool.h>
#include <stdio.h>

bool		hit_world(t_ray ray, t_list *world, t_hit *record)
{
	bool		hit_anything;
	//void		*closest_figure;
	float		shortest_distance;
	t_sphere	*sphere;

	sphere = NULL;
	hit_anything = false;
	shortest_distance = INFINITY;
	ray.t = RAY_T_MAX;
	while (world)
	{
		sphere = (t_sphere *) world->content;
		if (hit_sphere(ray, sphere, record))
		{
			hit_anything = true;
			ray.t = record->t;
			shortest_distance = record->t;
		}
		world = world->next;
	}
	return (hit_anything);
}
