/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 10:48:18 by aroque            #+#    #+#             */
/*   Updated: 2020/08/15 17:37:14 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "ray.h"
#include "server.h"
#include "color.h"
#include "camera.h"
#include "world.h"
#include "hittables.h"
#include <math.h>
#include <stdio.h>

#include <stdbool.h>

int		main(int argc, char *argv[])
{
	t_server	*x;
	t_list		*world;
	t_camera	*cam;

	(void) argc;
	(void) argv;

	world = NULL;
	new_world(&world);
	//printf("%f\n", ((t_sphere *) world->content)->radius);
	//printf("%f\n", ((t_sphere *) world->next->content)->radius);
	x = new_server(1000, 600);
	x->world = world;
	cam = new_camera(point(0, 0, 0), vector(0, 0, -1), 120, x);
	render(x, cam);
	mlx_listen(x);
}
