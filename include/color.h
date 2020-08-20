/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 10:23:55 by aroque            #+#    #+#             */
/*   Updated: 2020/08/19 22:02:37 by aroque           ###   ########.fr       */
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
typedef int t_color;

t_color			hex2color		(int hex);
t_color			color_product	(t_color color1, t_color color2);
t_color			color_scale		(t_color color, float c);
t_vector		color2vector(t_color color);
int				cadd(int color_a, int color_b);
int				cproduct(int color, double coef);

#endif
