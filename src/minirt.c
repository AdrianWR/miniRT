/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 10:48:18 by aroque            #+#    #+#             */
/*   Updated: 2020/08/16 17:51:39 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "server.h"
#include "color.h"
#include "camera.h"
#include "world.h"
#include "figures.h"
#include <math.h>
#include <stdio.h>
#include <stdbool.h>

int		main(int argc, char *argv[])
{
	t_server	*x;
	t_list		*world;
	t_list		*cam_set;

	(void) argc;
	(void) argv;

	x = new_server(1200, 800);
	world = NULL;
	cam_set = NULL;
	new_world(&world);
	new_camera_set(&cam_set, x);
	x->world = world;
	x->camera_set = cam_set;
	render(x);
	mlx_listen(x);
}
