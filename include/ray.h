/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 17:16:37 by aroque            #+#    #+#             */
/*   Updated: 2020/08/24 21:50:23 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "libft.h"
# include "vector.h"
# include <stdbool.h>

# define RAY_T_MIN		0.0001f
# define RAY_T_MAX		1000.0f
# define MAX_RAY_DEPTH	5

typedef struct	s_ray
{
	t_point		origin;
	t_vector	direction;
	float		t;
}				t_ray;

typedef struct	s_hit {
	t_vector	normal;
	t_point		p;
	float		t;
	void		*object;
}				t_hit;

t_point			at(t_ray ray, float t);
bool			intersect(t_ray *ray, t_list *world, t_hit *record);

#endif
