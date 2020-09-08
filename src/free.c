/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 11:50:06 by aroque            #+#    #+#             */
/*   Updated: 2020/09/08 09:21:39 by aroque           ###   ########.fr       */
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
	free(world);
}

void			free_server(t_server *x)
{
	mlx_destroy_image(x->mlx, x->image->image);
	mlx_clear_window(x->mlx, x->window->window);
	mlx_destroy_window(x->mlx, x->window->window);
	free_world(x->world);
	free(x->window);
	free(x->image);
	free(x);
}
