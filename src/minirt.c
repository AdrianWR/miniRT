/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 10:48:18 by aroque            #+#    #+#             */
/*   Updated: 2020/09/10 17:09:06 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include "camera.h"
#include "scene.h"
#include <stdio.h>

int		main(int argc, char *argv[])
{
	t_server	*x;

	int e;
	if (argc < 2)
		exit(1);
	else if (argc == 3 && ft_strncmp(argv[2], "--save", 6))
		exit(1);
	x = NULL;
	//void *ml = mlx_init();
	//int width;
	//int height;
	//mlx_get_screen_size(ml, &width, &height);
	e = scene_initializer(argv[1], &x);
	render(x);
	mlx_listen(x);
	return (e);
}
