/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 18:16:42 by aroque            #+#    #+#             */
/*   Updated: 2020/09/15 11:53:59 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <X11/X.h>
#include "server.h"
#include "camera.h"
#include "libft.h"

static int		exit_hook(t_server *x)
{
	free_server(x, 0);
	exit(EXIT_SUCCESS);
}

static int		key_press_hook(int keycode, t_server *x)
{
	if (keycode == 0xFF1B)
		exit_hook(x);
	else if (keycode == 0xFF53)
		change_camera(x, 1);
	else if (keycode == 0xFF51)
		change_camera(x, -1);
	return (0);
}

unsigned int	mlx_listen(t_server *x)
{
	void *w;

	w = x->window;
	mlx_hook(w, KeyPress, KeyPressMask, key_press_hook, x);
	mlx_hook(w, DestroyNotify, StructureNotifyMask, exit_hook, x);
	mlx_loop(x->mlx);
	return (0);
}
