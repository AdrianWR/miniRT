/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 18:44:08 by aroque            #+#    #+#             */
/*   Updated: 2020/09/12 00:43:48 by aroque           ###   ########.fr       */
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

bool			intersect(t_ray *ray, t_list *world)
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
		if (type == SPHERE)
			hit |= hit_sphere(ray, (t_sphere *)world->content);
		else if (type == PLANE)
			hit |= hit_plane(ray, (t_plane *)world->content);
		else if (type == TRIANGLE)
			hit |= hit_triangle(ray, (t_triangle *)world->content);
		else if (type == SQUARE)
			hit |= hit_square(ray, (t_square *)world->content);
		else if (type == CYLINDER)
			hit |= hit_cylinder(ray, (t_cylinder *)world->content);
		world = world->next;
	}
	return (hit);
}

t_color			raytrace(t_ray *ray, t_world *world)
{
	bool		vis;
	t_color		color;
	t_color		ambient;
	t_list		*light;
	t_light		current_light;

	if (!intersect(ray, world->figures))
		return (0x0);
	light = world->lights;
	ambient = cscale((*world->ambient).color, (*world->ambient).brightness);
	color = cproduct(ray->record.color, ambient);
	while (light)
	{
		current_light = *((t_light *)light->content);
		vis = !in_shadow(current_light, world->figures, ray->record);
		color = cadd(color, vis * color_component(current_light, ray->record));
		light = light->next;
	}
	return (color);
}

void			render(t_server *x)
{
	unsigned	i;
	unsigned	j;
	t_ray		ray;
	t_color		pixel_color;

	j = x->window->height;
	while (--j)
	{
		i = x->window->width;
		while (--i)
		{
			ray = generate_ray(x->world->cameras->content,
					(float)i / x->window->width, (float)j / x->window->height);
			pixel_color = raytrace(&ray, x->world);
			put_pixel(x, i, x->window->height - 1 - j, pixel_color);
		}
	}
	mlx_put_image_to_window(x->mlx, x->window->window, x->image->image, 0, 0);
}
