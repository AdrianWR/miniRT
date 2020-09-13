/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 10:23:55 by aroque            #+#    #+#             */
/*   Updated: 2020/09/13 20:23:35 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

typedef int		t_color;

t_color			cadd(int color_a, int color_b);
t_color			cscale(int color, float c);
t_color			cproduct(t_color a, t_color b);

#endif
