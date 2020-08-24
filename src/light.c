/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 18:49:11 by aroque            #+#    #+#             */
/*   Updated: 2020/08/24 02:21:39 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"
#include "vector.h"
#include "color.h"
#include "libft.h"
#include "ray.h"
#include "figures.h"
#include <math.h>

t_light		*new_light(t_point position, float brightness, t_color color)
{
	t_light	*light;

	if (!(light = malloc(sizeof(*light))))
		return (NULL);
	light->position = position;
	light->brightness = brightness;
	light->color = color;
	return (light);
}

static float light_intensity(t_light light, t_hit record)
{
	t_vector	light_direction;
	float		dotnormal;
	float		r2;

	light_direction = sub(light.position, record.p);
	r2 = length_squared(light_direction);
	dotnormal = dot(norm(light_direction), record.normal);
	if (dotnormal <= 0)
		return (0);
	return ((light.brightness * dotnormal * 1000) / (4.0 * M_PI * r2));
}

#include <stdio.h>

static t_color	color_component(t_light light, t_hit record)
{
	t_color		obj_color;
	t_color		color;

	color = 0x0;
	obj_color = ((t_sphere *)record.object)->color;
	color = cadd(color, cscale(obj_color, light_intensity(light, record)));
	color = cproduct(color, light.color);
	return (color);
}

t_color generate_light(t_light ambience, t_list *light, t_hit record)
{
	t_color color;
	t_color obj_color;
	t_light current_light;


	obj_color = ((t_sphere *)record.object)->color;
	color = cproduct(obj_color, cscale(ambience.color, ambience.brightness));
	while (light)
	{
		current_light = *((t_light *)light->content);
		color = cadd(color, color_component(current_light, record));
		light = light->next;
	}	
	return (color);
}
