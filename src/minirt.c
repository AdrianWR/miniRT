/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 10:48:18 by aroque            #+#    #+#             */
/*   Updated: 2020/09/15 11:54:46 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include "camera.h"
#include "errcode.h"
#include "bitmap.h"

int		main(int argc, char *argv[])
{
	bool		windowless;
	int			status;
	t_world		*world;
	t_server	*x;

	windowless = (argc == 3);
	if (argc < 2 || argc > 3)
		message_and_exit(EUSAGE, 0x0);
	else if (argc == 3 && ft_strncmp(argv[2], "--save", 7))
		message_and_exit(EUSAGE, 0x0);
	world = scene_initializer(argv[1]);
	x = new_server(world, windowless);
	render(x);
	if (windowless)
	{
		status = export_bitmap(*x);
		free_server(x, status);
	}
	else
		mlx_listen(x);
	return (EXIT_SUCCESS);
}
