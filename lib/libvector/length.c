/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 16:02:34 by aroque            #+#    #+#             */
/*   Updated: 2020/09/01 22:28:16 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <math.h>

static double	sqr(double n)
{
	return (n * n);
}

double			length_squared(t_vector v)
{
	return (sqr(v.x) + sqr(v.y) + sqr(v.z));
}

double			length(t_vector v)
{
	return (sqrt(length_squared(v)));
}
