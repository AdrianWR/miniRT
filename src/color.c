/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 11:48:45 by aroque            #+#    #+#             */
/*   Updated: 2020/07/10 11:49:57 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libft.h"
#include "color.h"
#include "server.h"

void	put_pixel(t_server *server, unsigned int x, unsigned int y, t_color color)
{
	char			*color_addr;
	unsigned int 	x_color;
	unsigned int 	opp;
	
	opp = server->image->bpp / 8;
	color_addr = (server->image->data + y * server->image->size_line + x * opp);
	x_color = mlx_get_color_value(server->mlx, color);
	ft_memcpy(color_addr, &x_color, opp);
}
