/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 18:49:11 by aroque            #+#    #+#             */
/*   Updated: 2020/09/12 23:23:25 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"
#include "color.h"
#include "libft.h"
#include "ray.h"
#include "scene.h"
#include <math.h>

t_light			*new_light(char **r, bool ambient)
{
	t_light		*light;
	unsigned	i;

	i = 1;
	if (!(light = malloc(sizeof(*light))))
		return (NULL);
	while (r[i])
		i++;
	if ((ambient && i != 3) || (!ambient && i != 4))
		return (NULL);
	light->color = atoc(r[--i]);
	light->brightness = ft_atof(r[--i]);
	if (!ambient)
		light->position = atov(r[--i]);
	return (light);
}

static float	light_intensity(t_light light, t_hit record)
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
