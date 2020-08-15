/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 17:16:37 by aroque            #+#    #+#             */
/*   Updated: 2020/08/14 21:25:09 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "vector.h"

# define RAY_T_MIN	0.0001f
# define RAY_T_MAX	1000.0f

typedef struct	s_ray
{
	t_point		origin;
	t_vector	direction;
	float		t;
}				t_ray;

t_point			intersection(t_ray ray, float t);

#endif
