/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 10:48:18 by aroque            #+#    #+#             */
/*   Updated: 2020/09/15 11:19:32 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include "camera.h"
#include "scene.h"
#include "errcode.h"
#include "bitmap.h"

int		main(int argc, char *argv[])
{
	int			err;
	t_world		*world;
	t_server	*x;

	if (argc < 2 || argc > 3)
		message_and_exit(EUSAGE, 0x0);
	else if (argc == 3 && ft_strncmp(argv[2], "--save", 7))
		message_and_exit(EUSAGE, 0x0);
	world = scene_initializer(argv[1]);
	if (argc == 3)
	{
		x = new_server(world, true);
		render(x);
		if ((err = export_bitmap(*x)) > 0)
		{
			free_server(x);
			message_and_exit(err, 0x0);
		}
	}
	else
	{
		x = new_server(world, false);
		render(x);
		mlx_listen(x);
	}
	return (EXIT_SUCCESS);
}
