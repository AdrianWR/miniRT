/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 18:16:42 by aroque            #+#    #+#             */
/*   Updated: 2020/06/22 15:38:21 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <X11/X.h>
#include "server.h"
#include "libft.h"
#include "mlx.h"
#include <stdio.h>

static int		exit_hook(t_server *x)
{
	mlx_destroy_image(x->mlx, x->image->image);
	mlx_clear_window(x->mlx, x->window->window);
	mlx_destroy_window(x->mlx, x->window->window);
	free(x->window);
	free(x->image);
	free(x);
	exit(0);
}

static int		key_press_hook(int keycode, t_server *x)
{
	static int color = 0;
	int	step = 0x00111111;

	if (keycode == 65361 && color > 0x00000000)
		color_map(x, color -= step);
	if (keycode == 65363 && color < 0x00FFFFFF)
		color_map(x, color += step);
	if (keycode == 65307)
		exit_hook(x);
	printf("%0#8x\n", color);
	return (0);
}

unsigned int	mlx_listen(t_server *x)
{
	mlx_hook(x->window->window, KeyPress, KeyPressMask, key_press_hook, x);
	mlx_hook(x->window->window, DestroyNotify, StructureNotifyMask, exit_hook, x);
	mlx_loop(x->mlx);
	return (0);
}
