/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 17:16:37 by aroque            #+#    #+#             */
/*   Updated: 2020/08/27 16:00:04 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "libft.h"
# include "vector.h"
# include "color.h"
# include "figures.h"
# include <stdbool.h>

# define RAY_T_MIN		0.0001f
# define RAY_T_MAX		1000.0f

typedef struct	s_hit {
	t_vector	normal;
	t_point		p;
	float		t;
	void		*object;
	t_color		color;
	t_type		type;
}				t_hit;

typedef struct	s_ray
{
	t_point		origin;
	t_vector	direction;
	t_hit		record;
}				t_ray;

t_point			at(t_ray ray);
bool			intersect(t_ray *ray, t_list *world);
bool			hit_sphere(t_ray *ray, t_sphere *sphere);
bool			hit_plane(t_ray *ray, t_plane *plane);
bool			hit_triangle(t_ray *ray, t_triangle *triangle);
#endif
