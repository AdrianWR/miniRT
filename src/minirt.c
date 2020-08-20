/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 10:48:18 by aroque            #+#    #+#             */
/*   Updated: 2020/08/19 18:47:13 by aroque           ###   ########.fr       */
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

	(void) argc;
	(void) argv;

	x = new_server(1024, 768);
	//x = new_server(800, 800);
	x->world = new_world(x->window->height, x->window->height);
	render(x);
	mlx_listen(x);
}
