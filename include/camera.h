/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 17:32:15 by aroque            #+#    #+#             */
/*   Updated: 2020/09/13 19:01:40 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "vector.h"
# include "server.h"
# include "ray.h"

typedef struct	s_camera
{
	t_point		origin;
	t_vector	direction;
	t_vector	horizontal;
	t_vector	vertical;
	t_point		llc;
	float		fov;
}				t_camera;

t_camera		*new_cam	(char **params, int *errcode);
void			init_cameras(t_list *camset, t_window win);
t_ray			generate_ray(t_camera *cam, float u, float v);
void			change_camera(t_server *x, int step);
void			render		(t_server *x);

#endif
