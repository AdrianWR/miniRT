/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 16:07:10 by aroque            #+#    #+#             */
/*   Updated: 2020/05/14 16:28:38 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector	add(t_vector u, t_vector v)
{
	return (vector((u.x + v.x), (u.y + v.y), (u.z + v.z)));
}

t_vector	sub(t_vector u, t_vector v)
{
	return (vector((u.x - v.x), (u.y - v.y), (u.z - v.z)));
}
