/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 11:06:11 by aroque            #+#    #+#             */
/*   Updated: 2020/09/13 20:16:30 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "vector.h"

t_point	at(t_ray ray)
{
	return (add(ray.origin, scale(ray.direction, ray.record.t)));
}
