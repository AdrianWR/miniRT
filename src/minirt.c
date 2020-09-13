/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 10:48:18 by aroque            #+#    #+#             */
/*   Updated: 2020/09/12 17:56:32 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include "camera.h"
#include "scene.h"
#include <stdio.h>
#include <unistd.h>

int		main(int argc, char *argv[])
{
	t_server	*x;

	if (argc < 2 || argc > 3)
		message_and_exit(EUSAGE);
	else if (argc == 3 && ft_strncmp(argv[2], "--save", 7))
		message_and_exit(EUSAGE);
	if ((x = scene_initializer(argv[1])))
	{
		render(x);
		mlx_listen(x);
	}
	else
		message_and_exit(__ERRNONE);
	return (EXIT_SUCCESS);
}
