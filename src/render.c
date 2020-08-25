/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 18:44:08 by aroque            #+#    #+#             */
/*   Updated: 2020/08/24 23:08:44 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include "ray.h"
#include "color.h"
#include "camera.h"
#include "figures.h"
#include "light.h"
#include <stdbool.h>
#include <math.h>

static bool	in_shadow(t_light light, t_list *figures, t_hit record)
{
	t_ray shadow;
	t_hit rec;

	shadow.origin = add(record.p, scale(record.normal, 0.0001));
	shadow.direction = norm(sub(light.position, record.p));
	return (intersect(&shadow, figures, &rec));
}

bool 			raytrace(t_color *color, t_ray *ray, t_world *world)
{
	t_hit		record;
	t_list		*light;
	t_light		ambient;
	bool		vis;

	*color = 0x0;
	if (!intersect(ray, world->figures, &record))
		return (false);
	//*color = generate_light(*world->ambience, world->lights, record);
	t_color obj_color;
	t_light current_light;
	
	light = world->lights;
	ambient = *world->ambience;
	obj_color = ((t_sphere *)record.object)->color;
	*color = cproduct(obj_color, cscale(ambient.color, ambient.brightness));
	while (light)
	{
		current_light = *((t_light *)light->content);
		vis = !in_shadow(current_light, world->figures, record);
		*color = cadd(*color, vis * color_component(current_light, record));
		//*color = cproduct(*color, cscale(ambient.color, ambient.brightness));
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
