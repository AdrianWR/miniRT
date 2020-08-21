/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 18:49:11 by aroque            #+#    #+#             */
/*   Updated: 2020/08/20 23:19:07 by aroque           ###   ########.fr       */
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

float light_intensity(t_light *light, t_hit record)
{
	t_vector	light_direction;
	float		r2;

	light_direction = sub(light->position, record.p);
	r2 = length_squared(light_direction);
	light_direction = norm(light_direction);

	float dotnormal = dot(light_direction, record.normal);
	if (dotnormal < 0)
		return (0);
	return ((light->brightness * dotnormal * 1000) / (4.0 * M_PI * r2));
}

t_color light_object(t_list *light, t_hit record)
{
	t_color color;
	t_color object_color;

	color = 0x0;
	object_color = ((t_sphere *)record.object)->color;
	while (light)
	{
		color = cadd(color, cscale(object_color, light_intensity((t_light *)light->content, record)));
		light = light->next;
	}	
	return (color);
}
