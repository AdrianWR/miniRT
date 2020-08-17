/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 11:06:11 by aroque            #+#    #+#             */
/*   Updated: 2020/08/16 18:30:29 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "vector.h"
#include "figures.h"
#include <math.h>
#include <stdbool.h>
#include <stdio.h>

t_point	at(t_ray ray, float t)
{
	t_point p;

	p = scale(ray.direction, t);
	p = add(ray.origin, p);
	return (p);
}

bool		intersect(t_ray *ray, t_list *world, t_hit *record)
{
	bool		hit_anything;
	t_sphere	*sphere;

	sphere = NULL;
	hit_anything = false;
	ray->t = INFINITY;
	while (world)
	{
		sphere = (t_sphere *)world->content;
		if (hit_sphere(*ray, sphere, record))
		{
			hit_anything = true;
			ray->t = record->t;
			record->object = sphere;
		}
		world = world->next;
	}
	return (hit_anything);
}
