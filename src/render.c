/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 18:44:08 by aroque            #+#    #+#             */
/*   Updated: 2020/08/16 22:13:57 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include "ray.h"
#include "color.h"
#include "camera.h"
#include "figures.h"
#include <stdio.h>
#include <unistd.h>

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


t_color 			raytrace(t_ray *ray, t_color background, t_list *world, int depth)
{
	t_color		pixel_color;
	t_hit		record;

	//t_point		light_position = point(0, 5, -1);
	//t_color		light_color = hex2color(0x00FFFFFF);

	if (depth <= 0)
		return hex2color(0x0);
	if (!intersect(ray, world, &record))
		return background;

	//t_vector light_direction = sub(light_position, record.p);
	//let r2 = (s.position - *hit_point).norm() as f32;
	//s.intensity / (4.0 * ::std::f32::consts::PI * r2)
	float		light_intensity = 0.1;
	t_vector	light_direction = vector(-0.5, -1, 0);

	float light_power = dot(light_direction, record.normal) * light_intensity;
//let color = intersection.element.color() * scene.light.color *
 //           light_power * light_reflected;
	//let light_power = (surface_normal.dot(&direction_to_light) as f32) *
    //scene.light.intensity;

	pixel_color = ((t_sphere *)record.object)->color;
	pixel_color = color_scale(pixel_color, light_power);
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
