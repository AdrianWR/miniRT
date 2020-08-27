/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 18:44:08 by aroque            #+#    #+#             */
/*   Updated: 2020/08/26 17:03:45 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include "ray.h"
#include "color.h"
#include "camera.h"
#include "figures.h"
#include "light.h"
#include <math.h>
#include <stdbool.h>

#include <stdio.h>

static bool	in_shadow(t_light light, t_list *figures, t_hit record)
{
	t_ray shadow;

	//if (record.type == PLANE)
	//	shadow.origin = add(record.p, scale(record.normal, 1));
	//else
	shadow.origin = add(record.p, scale(record.normal, 0.0001));
	shadow.direction = norm(sub(light.position, record.p));
	//printf("plano y -> %f\n", record.p.y);
	return (intersect(&shadow, figures));
}

bool 			raytrace(t_color *color, t_ray *ray, t_world *world)
{
	bool		vis;
	t_color		obj_color;
	t_list		*light;
	t_light		amb;
	t_light 	current_light;

	*color = 0x0;
	if (!intersect(ray, world->figures))
		return (false);
	light = world->lights;
	amb = *world->ambient;
	obj_color = ray->record.color;
	*color = cproduct(obj_color, cscale(amb.color, amb.brightness));
	while (light)
	{
		current_light = *((t_light *)light->content);
		vis = !in_shadow(current_light, world->figures, ray->record);
		//*color = cadd(*color, 1 * color_component(current_light, ray->record));
		*color = cadd(*color, vis * color_component(current_light, ray->record));
		light = light->next;
	}	
	return (true);
}

void				render(t_server *x)
{
	unsigned int	i;
	unsigned int	j;
	float			u;
	float			v;
	t_ray			ray;
	t_color			pixel_color;

	pixel_color = 0x0;
	j = x->window->height;
	while (--j)
	{
		i = x->window->width;
		while (--i)
		{
			u = (float) i / x->window->width;
			v = (float) j / x->window->height;
			ray = generate_ray(x->world->cameras->content, u, v);
			raytrace(&pixel_color, &ray, x->world);
			put_pixel(x, i, x->window->height - 1 - j, pixel_color);
		}
	}
	mlx_put_image_to_window(x->mlx, x->window->window, x->image->image, 0, 0);
}
