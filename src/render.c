/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 18:44:08 by aroque            #+#    #+#             */
/*   Updated: 2020/09/22 22:31:19 by aroque           ###   ########.fr       */
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

/*
**	intersect: Calculate the intersection between a ray
**  emitted by the camera and the world elements. During
**  the execution, the ray->hit struct is assigned with
**  intersection information.
**
**	@*ray: Ray emitted by a camera, with a particular orientation.
**	@*world: World data structure with the scene elements.
**
**  Return: True, if the ray intersects a scene element.
**  False otherwise.
*/

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

/*
**	raytrace: Calculate a pixel color on the screen based
**  on a ray emitted by the camera. The raytrace function
**  is capable of calculate lighting normals, shadows and
**  background pixels.
**
**	@*ray: Ray emitted by a camera, with a particular orientation.
**	@*world: World data structure with the scene elements.
**
**  Return: Color of pixel hit by the camera ray.
*/

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

/*
**	render: Renders a new scene, based on world, window and image
**  information found on the pointer to struct s_server *x;
**  Depending on the value of x->windowless, the scene can be
**  seen on a window or exported to a BMP file.
**
**	@*x: t_server data structure.
*/

void			render(t_server *x)
{
	unsigned	i;
	unsigned	j;
	t_ray		ray;
	t_color		pixel_color;

	if (!x->world->cameras)
		return ;
	j = x->height;
	while (j-- > 0)
	{
		i = x->width;
		while (i-- > 0)
		{
			ray = generate_ray(x->world->cameras->content,
					(float)i / x->width, (float)j / x->height);
			pixel_color = raytrace(&ray, x->world);
			put_pixel(x, i, x->height - 1 - j, pixel_color);
		}
	}
	if (!x->windowless)
		mlx_put_image_to_window(x->mlx, x->window,
								x->image->image, 0, 0);
}
