/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 15:58:26 by aroque            #+#    #+#             */
/*   Updated: 2020/09/15 11:31:05 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	float		fov;

	if (strarray_len(params) != 4 && (*errcode = EBADFMT))
		return (NULL);
	if (!(camera = malloc(sizeof(*camera))))
		return (NULL);
	if ((fov = ft_atof(params[3], errcode)) < 0 || fov > 180)
		*errcode = EOURFOV;
	camera->fov = deg2rad(fov);
	camera->direction = ft_atov(params[2], errcode);
	camera->origin = ft_atov(params[1], errcode);
	if (out_of_range_vector(camera->direction))
		*errcode = EOURVEC;
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
	light->brightness = ft_atof(params[1], errcode);
	if (light->brightness < 0 || light->brightness > 1)
		*errcode = EOURINT;
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
	light->brightness = ft_atof(params[2], errcode);
	if (light->brightness < 0 || light->brightness > 1)
		*errcode = EOURINT;
	light->position = ft_atov(params[1], errcode);
	return (light);
}
