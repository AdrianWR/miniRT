/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 10:23:55 by aroque            #+#    #+#             */
/*   Updated: 2020/07/13 14:47:01 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include "server.h"
# include "vector.h"

typedef t_vector	t_color;

int					hex(t_color color);
t_color				color(float r, float g, float b);
void				put_pixel(t_server *server, unsigned int x, unsigned int y, t_color color);

#endif
