/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 14:02:59 by aroque            #+#    #+#             */
/*   Updated: 2020/09/15 11:28:24 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "camera.h"
#include "libft.h"
#include "server.h"
#include "ray.h"
#include <stdlib.h>
#include <math.h>

void			init_cameras(t_list *camset, unsigned width, unsigned height)
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
		vp[1] = vp[0] * (float)height / width;
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
