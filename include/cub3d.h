/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 17:24:27 by aroque            #+#    #+#             */
/*   Updated: 2020/03/30 11:07:25 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include "stdlib.h"

# define SCREENWIDTH	640
# define SCREENHEIGHT	480
# define SCREENTITLE	"cub3d"

# define ERR_MSG		"Error\n"
# define ERR_MSG_NARGS	"Invalid number of arguments\n"

/*
** Vector space dimension for a plane,
*/

# define DIM	2
# define X		0
# define Y		1

# define	WALL	'#'
# define	SPACE	' '

# define ERR_INIT	"Game Initialization Error"
# define ERR_MALLOC	"Memory allocation error"

/*
**
**
*/

typedef struct		s_player
{
	double	*position[DIM];
	double	angle;
}					t_player;

typedef struct	s_cell
{
	unsigned int	coordinates[DIM];
	unsigned int	size[DIM];
}				t_cell;

//typedef struct	s_board
//{
//	char			**grid;
//	unsigned int	size[DIM];
//	unsigned int	grid_size[DIM];
//}				t_board;

typedef struct		s_game
{
	void			*mlx;
	void			*window;
	unsigned int	*resolution[DIM];
	char			**grid;
	unsigned int	grid_size[DIM];
	t_player		*player;
}					t_game;

t_game			*game_initializer(void);
t_game			*map_initializer(const char *file);

#endif
