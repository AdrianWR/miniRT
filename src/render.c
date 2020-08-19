/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 18:44:08 by aroque            #+#    #+#             */
/*   Updated: 2020/08/19 17:21:25 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include "ray.h"
#include "color.h"
#include "camera.h"
#include "figures.h"
#include "light.h"
#include <stdio.h>
#include <unistd.h>
#include <math.h>

//static 		t_color gradient(t_color start, t_color end, t_ray ray)
//{
//	float		t;
//	t_vector unit;
//
//	unit = norm(ray.direction);
//
//	t = 0.5 * (unit.y + 1);
//	return add(scale(start, 1 - t), scale(end, t));
//}
//
int		cproduct(int color, double coef)
{
	int mask;
	int r;
	int	g;
	int	b;

	mask = 255;
	r = coef * ((color & (mask << 16)) >> 16);
	g = coef * ((color & (mask << 8)) >> 8);
	b = coef * (color & mask);
	r = r > 255 ? 255 : r;
	g = g > 255 ? 255 : g;
	b = b > 255 ? 255 : b;
	return ((r << 16) | (g << 8) | b);
}

float light_intensity(t_hit record)
{

	t_light		light;


	//float		light_intensity;
	t_vector	light_direction;
	//t_vector	light_color;
	float		r2;

	light.position = point(2, 5, -1);
	light.brightness = 0.6;

	light_direction = sub(light.position, record.p);
	r2 = length_squared(light_direction);
	light_direction = norm(light_direction);

	float dotnormal = dot(light_direction, record.normal);
	if (dotnormal < 0)
		return (0);
	return ((light.brightness * dotnormal * 1000) / (4.0 * M_PI * r2));
}

t_color 			raytrace(t_ray *ray, t_color background, t_list *world, int depth)
{
	t_color		pixel_color;
	t_hit		record;

	//t_color		light_color = hex2color(0x00FFFFFF);

	if (depth <= 0)
		return hex2color(0x0);
	if (!intersect(ray, world, &record))
		return background;
	pixel_color = ((t_sphere *)record.object)->color;
	pixel_color.hex = cproduct(pixel_color.hex, light_intensity(record));
	world = world->next;
	return (pixel_color);
}


void				render(t_server *x)
{
	unsigned int	i;
	unsigned int	j;
	float			u;
	float			v;
	t_ray			ray;
	t_color			pixel_color;
	t_color			background;

	background.hex = 0x00C3EFFC;
	j = x->window->height;
	while (--j)
	{
		i = x->window->width;
		while (--i)
		{
			u = (float) i / x->window->width;
			v = (float) j / x->window->height;
			ray = generate_ray(x->camera_set->content, u, v);
			pixel_color = raytrace(&ray, background, x->world, MAX_RAY_DEPTH);
			put_pixel(x, i, x->window->height - 1 - j, pixel_color);
		}
	}
	mlx_put_image_to_window(x->mlx, x->window->window, x->image->image, 0, 0);
}
