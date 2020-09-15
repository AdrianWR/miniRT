/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 11:21:25 by aroque            #+#    #+#             */
/*   Updated: 2020/09/15 11:25:35 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "vector.h"
#include <stdbool.h>

unsigned		strarray_len(char **params)
{
	unsigned	i;

	i = 0;
	while (params[i])
		i++;
	return (i);
}

bool			out_of_range_vector(t_vector v)
{
	bool out;

	out = false;
	out |= v.x < -1 || v.x > 1;
	out |= v.y < -1 || v.y > 1;
	out |= v.z < -1 || v.z > 1;
	return (out);
}
