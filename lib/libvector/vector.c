/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 16:01:16 by aroque            #+#    #+#             */
/*   Updated: 2020/09/01 22:30:43 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector	vector(double x, double y, double z)
{
	t_vector v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

t_point		point(double x, double y, double z)
{
	return (vector(x, y, z));
}
