/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 14:02:59 by aroque            #+#    #+#             */
/*   Updated: 2020/09/13 00:33:23 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "camera.h"
#include "libft.h"
#include "server.h"
#include "ray.h"
#include "scene.h"
#include <stdlib.h>
#include <math.h>

static float	deg2rad(float deg)
{
	return ((M_PI / 180) * deg);
}

void		init_cameras(t_list *camset, t_window win)
{
	float		vp[2];
	t_vector	u;
	t_vector	v;
	t_vector	w;
	t_camera	*camera;

	while (camset)
	{
		camera = (t_camera *)camset->content;
		vp[0] = 2 * tan(camera->fov / 2);
		vp[1] = vp[0] * (float)win.height / win.width;
		camera->direction = scale(camera->direction, -1);
		w = norm(camera->direction);
		u = cross(vector(0, 1, 0), w);
		v = cross(w, u);
		camera->horizontal = scale(u, vp[0]);
		camera->vertical = scale(v, vp[1]);
		camera->llc = sub(camera->origin, scale(camera->horizontal, 0.5));
		camera->llc = sub(camera->llc, scale(camera->vertical, 0.5));
		camera->llc = sub(camera->llc, w);
		camset = camset->next;
	}
}

t_camera		*new_cam(char **params)
{
	t_camera	*camera;
	unsigned	i;

	i = 1;
	while (params[i])
		i++;
	if (i-- != 4)
		return (NULL);
	if (!(camera = malloc(sizeof(*camera))))
		return (NULL);
	camera->fov = deg2rad(ft_atof(params[i--]));
	camera->direction = atov(params[i--]);
	camera->origin = atov(params[i--]);
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
	ray.direction = norm(sub(ray.direction, ray.origin));
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
