/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 18:20:31 by aroque            #+#    #+#             */
/*   Updated: 2020/08/25 11:52:27 by aroque           ###   ########.fr       */
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
	unsigned int	width;
	unsigned int	height;
}					t_window;

typedef struct		s_server
{
	void			*mlx;
	t_window		*window;
	t_image			*image;
	t_world			*world;
}					t_server;


t_world				*new_world		(t_window window);
t_list				*new_light_set	(void);
t_list				*new_figure_set	(void);
t_list				*new_camera_set	(t_window window);
t_server			*new_server		(unsigned int width, unsigned int height);
unsigned int		mlx_listen		(t_server *x);
void				color_map		(t_server *x, int color);
void				put_pixel		(t_server *server, unsigned int x, unsigned int y, t_color color);
void				free_server		(t_server *x);

#endif
