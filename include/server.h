/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 18:20:31 by aroque            #+#    #+#             */
/*   Updated: 2020/09/12 22:53:22 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include "mlx.h"
# include "color.h"
# include "light.h"
# include "libft.h"

# define TITLE	"miniRT"

typedef struct		s_world {
	t_list			*figures;
	t_list			*lights;
	t_list			*cameras;
	t_light			*ambient;
}					t_world;

typedef struct		s_image
{
	void			*image;
	char			*data;
	int				bpp;
	int				endian;
	int				size_line;
	unsigned int	width;
	unsigned int	height;
}					t_image;

typedef struct		s_window
{
	void			*window;
	int				width;
	int				height;
}					t_window;

typedef struct		s_server
{
	void			*mlx;
	t_window		*window;
	t_image			*image;
	t_world			*world;
}					t_server;

typedef enum	e_errcode {
	__ERRNONE,
	EUSAGE,
	EBADFRT,
	EPARSE,
	__ERRMAX
}				t_errcode;

t_server			*new_server	(int w, int h, t_world *world);
unsigned int		mlx_listen	(t_server *x);
void				color_map	(t_server *x, int color);
void				put_pixel	(t_server *s, unsigned x, unsigned y, t_color c);
void				free_server	(t_server *x);
void				free_world	(t_world *world);
void				free_array	(void **array);
void			message_and_exit(t_errcode code);
int				parser_file(int fd, t_world *world, int res[2]);

#endif
