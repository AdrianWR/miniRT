/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 10:23:55 by aroque            #+#    #+#             */
/*   Updated: 2020/07/09 10:45:25 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include "server.h"
# include "vector.h"

//typedef union	u_color {
//	int 		i;
//	struct		s_color {
//		unsigned char	b;
//		unsigned char	g;
//		unsigned char	r;
//		unsigned char	a;
//	}			rgb;
//}				t_color;

typedef unsigned int t_color;

void gradient(int start, int end, t_server *x);

#endif
