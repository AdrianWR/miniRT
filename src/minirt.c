/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 10:48:18 by aroque            #+#    #+#             */
/*   Updated: 2020/08/14 23:00:10 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "ray.h"
#include "server.h"
#include "color.h"
#include "world.h"
#include "hittables.h"
#include <math.h>
#include <stdio.h>

#include <stdbool.h>

int		main(int argc, char *argv[])
{
	t_server	*x;
	t_list		*world;

	(void) argc;
	(void) argv;

	world = NULL;
	new_world(&world);
	//printf("%f\n", ((t_sphere *) world->content)->radius);
	//printf("%f\n", ((t_sphere *) world->next->content)->radius);
	x = new_server(1200, 600);
	x->world = world;
	render(x);
	mlx_listen(x);
}
