/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 14:02:59 by aroque            #+#    #+#             */
/*   Updated: 2020/08/15 19:20:40 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "camera.h"
#include "libft.h"
#include "server.h"
#include <stdlib.h>
#include <math.h>

static float	deg2rad(float deg)
{
	return ((M_PI / 180) * deg);
}

t_camera		*new_camera(t_point origin, t_vector direction, float fov, t_server *x)
{
	t_camera	*camera;

	if (!(camera = malloc(sizeof(*camera))))
		return NULL;
	camera->origin = origin;
	camera->direction = direction;
	camera->fov = deg2rad(fov);


	float	vpy;
	float	vpx;
	float	focal_length;

	vpx = 2 * tan(camera->fov / 2);
	vpy = (vpx * (float)x->window->height) / (float)x->window->width;
	focal_length = 1.0;

	camera->horizontal = vector(vpx, 0, 0);
	camera->vertical = vector(0, vpy, 0);
	camera->llc = sub(camera->origin, scale(camera->horizontal, 0.5));
	camera->llc = sub(camera->llc, scale(camera->vertical, 0.5));
	camera->llc = sub(camera->llc, vector(0, 0, focal_length));

	return (camera);
}

//t_ray			*generate_ray(t_camera *camera, t_server *x)
//{
//	t_ray		*ray;
//}

//t_list		*new_camera_set()

