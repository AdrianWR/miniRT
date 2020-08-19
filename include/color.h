/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 10:23:55 by aroque            #+#    #+#             */
/*   Updated: 2020/08/19 13:44:17 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include "server.h"
# include "vector.h"

typedef union	u_color {
	int 		hex;
	struct {
		unsigned char	a;
		unsigned char	r;
		unsigned char	g;
		unsigned char	b;
	}			rgb;
}				t_color;

t_color			hex2color		(int hex);
void			put_pixel		(t_server *server, unsigned int x, unsigned int y, t_color color);
t_color			color_product	(t_color color1, t_color color2);
t_color			color_scale		(t_color color, float c);
t_vector		color2vector(t_color color);

#endif
