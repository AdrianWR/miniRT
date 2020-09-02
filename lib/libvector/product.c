/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   product.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 16:10:47 by aroque            #+#    #+#             */
/*   Updated: 2020/09/01 22:29:23 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector	scale(t_vector u, double c)
{
	return (vector((c * u.x), (c * u.y), (c * u.z)));
}

double		dot(t_vector u, t_vector v)
{
	return ((u.x * v.x) + (u.y * v.y) + (u.z * v.z));
}

t_vector	cross(t_vector u, t_vector v)
{
	t_vector	w;

	w.x = (u.y * v.z) - (u.z * v.y);
	w.y = (u.z * v.x) - (u.x * v.z);
	w.z = (u.x * v.y) - (u.y * v.x);
	return (w);
}
