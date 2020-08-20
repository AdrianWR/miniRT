/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 14:02:59 by aroque            #+#    #+#             */
/*   Updated: 2020/08/19 18:30:20 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "camera.h"
#include "libft.h"
#include "server.h"
#include "ray.h"
#include <stdlib.h>
#include <math.h>

static float	deg2rad(float deg)
{
	return ((M_PI / 180) * deg);
}

t_camera		*new_camera(t_point origin, t_vector direction, float fov,
							unsigned int width, unsigned int height)
{
	t_camera	*camera;

	if (!(camera = malloc(sizeof(*camera))))
		return NULL;
	camera->origin = origin;
	camera->direction = direction;
	camera->fov = deg2rad(fov);

	float	vpy;
	float	vpx;

	vpx = 2 * tan(camera->fov / 2);
	vpy = (vpx * (float)height) / (float)width;

	camera->direction = scale(camera->direction, -1);
	t_vector w = norm(camera->direction);
	t_vector u = cross(vector(0, 1, 0), w);
	t_vector v = cross(w, u);

	camera->horizontal = scale(u, vpx);
	camera->vertical = scale(v, vpy);
	camera->llc = sub(camera->origin, scale(camera->horizontal, 0.5));
	camera->llc = sub(camera->llc, scale(camera->vertical, 0.5));
	camera->llc = sub(camera->llc, w);

	return (camera);
}

t_ray			generate_ray(t_camera *cam, float u, float v)
{
	t_ray		ray;
	t_vector	horizontal;
	t_vector	vertical;
	t_vector	llc;

	horizontal = cam->horizontal;
	vertical = cam->vertical;
	llc = cam->llc;
	ray.origin = cam->origin;
	ray.direction = add(scale(horizontal, u), scale(vertical, v));
	ray.direction = add(ray.direction, llc);
	ray.direction = sub(ray.direction, ray.origin);
	return (ray);
}

void			change_camera(t_server *x, int step)
{
	t_list **cam;

	cam = &(x->world->cameras);
	if (step > 0)
		while (step-- && (*cam)->next)
			*cam = ((*cam)->next);
	else if (step < 0)
		while (step++ && (*cam)->previous)
			*cam = ((*cam)->previous);
	render(x);
}

//t_list		*new_camera_set()

