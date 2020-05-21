/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 16:02:34 by aroque            #+#    #+#             */
/*   Updated: 2020/05/14 16:05:52 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <math.h>

static float	sqr(float n)
{
	return (n * n);
}

float			length2(t_vector v)
{
	return (sqr(v.x) + sqr(v.y) + sqr(v.z));
}

float			length(t_vector v)
{
	return (sqrt(length2(v)));
}
