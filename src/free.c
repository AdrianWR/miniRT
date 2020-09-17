/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 11:50:06 by aroque            #+#    #+#             */
/*   Updated: 2020/09/15 15:15:28 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <stdlib.h>

void			free_array(void **array)
{
	unsigned	i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}

void			free_world(t_world *world)
{
	t_list		*cam;

	cam = ft_lstfirst(world->cameras);
	ft_lstclear(&world->figures, free);
	ft_lstclear(&world->lights, free);
	ft_lstclear(&cam, free);
	free(world->ambient);
	free(world->resolution);
	free(world);
}

void			free_server(t_server *x, int errcode)
{
	if (x->window)
	{
		mlx_clear_window(x->mlx, x->window);
		mlx_destroy_window(x->mlx, x->window);
	}
	mlx_destroy_image(x->mlx, x->image->image);
	free_world(x->world);
	free(x->image);
	free(x);
	if (errcode)
		message_and_exit(errcode, 0x0);
}
