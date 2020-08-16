/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 17:32:15 by aroque            #+#    #+#             */
/*   Updated: 2020/08/15 15:40:44 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "vector.h"
# include "server.h"

typedef struct	s_camera
{
	t_point		origin;
	t_vector	direction;
	float		fov;
	t_vector	horizontal;
	t_vector	vertical;
	t_point		llc;
}				t_camera;

t_camera		*new_camera	(t_point origin, t_vector direction, float fov, t_server *x);
void			render		(t_server *x, t_camera *cam);

#endif
