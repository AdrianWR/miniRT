/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 11:48:45 by aroque            #+#    #+#             */
/*   Updated: 2020/07/10 17:02:09 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "mlx.h"
#include "libft.h"
#include "color.h"
#include "server.h"

t_color color(float r, float g, float b)
{
	return vector(r, g, b);
}

int	hex(t_color color)
{
	int hex;

	hex = (int)(color.x * 255) << 16;
	hex |= ((int)(color.y * 255) & 0xFF) << 8;
	hex |= (int)(color.z * 255) & 0xFF;
	return (hex);
}

void	put_pixel(t_server *s, unsigned int x, unsigned int y, t_color color)
{
	char			*color_addr;
	unsigned int 	hex_color;
	unsigned int 	opp;
	
	opp = s->image->bpp / 8;
	color_addr = (s->image->data + y * s->image->size_line + x * opp);
	hex_color = mlx_get_color_value(s->mlx, hex(color));
	ft_memcpy(color_addr, &hex_color, opp);
}
