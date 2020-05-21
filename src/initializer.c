/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 17:52:04 by aroque            #+#    #+#             */
/*   Updated: 2020/03/29 18:16:54 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"
#include <stdio.h>

void	*ft_memalloc(size_t data_size)
{
	void	*data;

	if (!(data = ft_calloc(1, data_size)))
	{
		perror(ERR_MALLOC);
		return (NULL);
	}
	return (data);
}

static t_player	*player_initializer(void)
{
	t_player	*player;

	player = ft_memalloc(sizeof(*player));
	player->position = ft_memalloc(sizeof(*player->position));
	return (player);
}

static t_board	*board_initializer(void)
{
	t_board	*board;

	board = ft_memalloc(sizeof(*board));
	board->size = ft_memalloc(sizeof(*board->size));
	return (board);
}

//  t_game			*game_initializer(int fd)
//  {
//  	t_game		*game;
//  
//  	if (!(game = malloc(sizeof(*game))))
//  	{
//  		perror(ERR_INIT);
//  		return (NULL);
//  	}
//  	game->mlx = mlx_init();
//  	game->window = mlx_new_window(game->mlx, 
//  			SCREENWIDTH, SCREENHEIGHT, SCREENTITLE);
//  	game->board = board_initializer();
//  	game->player = player_initializer();
//  	return (game);
//  }
