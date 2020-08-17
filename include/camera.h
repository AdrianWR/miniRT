/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 17:32:15 by aroque            #+#    #+#             */
/*   Updated: 2020/08/16 18:07:11 by aroque           ###   ########.fr       */
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

t_camera		*new_camera	(t_point origin, t_vector direction, float fov, t_server *x);
t_ray			generate_ray(t_camera *cam, float u, float v);
void			new_camera_set(t_list **cam_set, t_server *x);
void			change_camera(t_server *x, int step);
void			render		(t_server *x);

#endif
