/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 18:20:31 by aroque            #+#    #+#             */
/*   Updated: 2020/09/14 15:39:55 by aroque           ###   ########.fr       */
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
	int				resolution[2];
}					t_world;

typedef struct		s_image
{
	void			*image;
	char			*data;
	int				bpp;
	int				endian;
	int				size_line;
}					t_image;

//typedef struct		s_window
//{
//	void			*window;
//	int				width;
//	int				height;
//}					t_window;

typedef struct		s_server
{
	void			*mlx;
	void			*window;
	t_image			*image;
	t_world			*world;
	unsigned int	width;
	unsigned int	height;
	bool			windowless;
}					t_server;

t_server			*new_server(t_world *world, bool windowless);
unsigned int		mlx_listen(t_server *x);
void				put_pixel(t_server *s, unsigned x, unsigned y, t_color c);
void				free_server(t_server *x);
void				free_world(t_world *world);
void				free_array(void **array);
int					parser_file(int fd, t_world *world, char **note);
void				render(t_server *x);

#endif
