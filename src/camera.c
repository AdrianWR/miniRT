/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 14:02:59 by aroque            #+#    #+#             */
/*   Updated: 2020/09/01 16:16:01 by aroque           ###   ########.fr       */
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

static void		set_camera(t_camera *camera, float vpx, float vpy)
{
	t_vector u;
	t_vector v;
	t_vector w;

	camera->direction = scale(camera->direction, -1);
	w = norm(camera->direction);
	u = cross(vector(0, 1, 0), w);
	v = cross(w, u);
	camera->horizontal = scale(u, vpx);
	camera->vertical = scale(v, vpy);
	camera->llc = sub(camera->origin, scale(camera->horizontal, 0.5));
	camera->llc = sub(camera->llc, scale(camera->vertical, 0.5));
	camera->llc = sub(camera->llc, w);
}

t_camera		*new_cam(t_point origin, t_vector dir, float fov, t_window win)
{
	t_camera	*camera;
	float		vpy;
	float		vpx;

	if (!(camera = malloc(sizeof(*camera))))
		return (NULL);
	camera->origin = origin;
	camera->direction = dir;
	camera->fov = deg2rad(fov);
	vpx = 2 * tan(camera->fov / 2);
	vpy = vpx * (float)win.height / win.width;
	set_camera(camera, vpx, vpy);
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
	ray.record.object = NULL;
	ray.record.color = 0x0;
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
