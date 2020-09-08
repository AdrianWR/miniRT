/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 10:48:18 by aroque            #+#    #+#             */
/*   Updated: 2020/09/06 23:02:30 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include "camera.h"
#include "scene.h"
#include <stdio.h>

int		main(int argc, char *argv[])
{
	t_server	*x;

	(void) argc;
	(void) argv;

	if (argc != 2)
		exit(1);
	x = NULL;
	scene_initializer(argv[1], &x);
	render(x);
	mlx_listen(x);
}
