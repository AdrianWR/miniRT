/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 18:49:11 by aroque            #+#    #+#             */
/*   Updated: 2020/09/13 20:11:56 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"
#include "color.h"
#include "libft.h"
#include "ray.h"
#include <math.h>

static float	light_intensity(t_light light, t_hit record)
{
	t_vector	light_direction;
	float		gain;
	float		r2;

	light_direction = sub(light.position, record.p);
	r2 = length_squared(light_direction);
	gain = dot(norm(light_direction), record.normal);
	if (gain <= 0)
		return (0);
	return ((light.brightness * gain * ALBEDO) / (4.0 * M_PI * r2));
}

t_color			color_component(t_light light, t_hit record)
{
	t_color		obj_color;
	t_color		color;

	color = 0x0;
	obj_color = record.color;
	color = cadd(color, cscale(obj_color, light_intensity(light, record)));
	color = cproduct(color, light.color);
	return (color);
}

bool			in_shadow(t_light light, t_list *figures, t_hit record)
{
	t_ray	shadow;

	shadow.origin = add(record.p, scale(record.normal, EPSILON));
	shadow.direction = norm(sub(light.position, shadow.origin));
	shadow.record.object = record.object;
	return (intersect(&shadow, figures));
}
