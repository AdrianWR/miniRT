/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 15:58:26 by aroque            #+#    #+#             */
/*   Updated: 2020/09/13 20:05:20 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "light.h"
#include "camera.h"
#include "errcode.h"
#include <math.h>

static float	deg2rad(float deg)
{
	return ((M_PI / 180) * deg);
}

t_camera		*new_cam(char **params, int *errcode)
{
	t_camera	*camera;

	if (strarray_len(params) != 4 && (*errcode = EBADFMT))
		return (NULL);
	if (!(camera = malloc(sizeof(*camera))))
		return (NULL);
	camera->fov = deg2rad(ft_atof(params[3]));
	camera->direction = ft_atov(params[2], errcode);
	camera->origin = ft_atov(params[1], errcode);
	return (camera);
}

t_light			*new_ambient_light(char **params, int *errcode)
{
	static bool	set;
	t_light		*light;

	if (set && (*errcode = EREPEAT))
		return (NULL);
	if (strarray_len(params) != 3 && (*errcode = EBADFMT))
		return (NULL);
	if (!(light = malloc(sizeof(*light))))
		return (NULL);
	light->color = ft_atoc(params[2], errcode);
	light->brightness = ft_atof(params[1]);
	set = true;
	return (light);
}

t_light			*new_light(char **params, int *errcode)
{
	t_light		*light;

	if (strarray_len(params) != 4 && (*errcode = EBADFMT))
		return (NULL);
	if (!(light = malloc(sizeof(*light))))
		return (NULL);
	light->color = ft_atoc(params[3], errcode);
	light->brightness = ft_atof(params[2]);
	light->position = ft_atov(params[1], errcode);
	return (light);
}
