/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 18:20:31 by aroque            #+#    #+#             */
/*   Updated: 2020/07/09 11:17:35 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# define WIDTH	800
# define HEIGHT	600
# define TITLE	"miniRT"

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
}					t_server;

t_server			*new_server(unsigned int width, unsigned int height);
unsigned int		mlx_listen(t_server *x);
void				color_map(t_server *x, int color);

#endif
