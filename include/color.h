/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 10:23:55 by aroque            #+#    #+#             */
/*   Updated: 2020/08/21 10:36:31 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include "vector.h"

//typedef union	u_color {
//	int 		hex;
//	struct {
//		unsigned char	a;
//		unsigned char	r;
//		unsigned char	g;
//		unsigned char	b;
//	}			rgb;
//}				t_color;
//
//
typedef int		t_color;

t_color			cadd(int color_a, int color_b);
t_color			cscale(int color, float c);
t_color 		cproduct(t_color a, t_color b);

#endif
