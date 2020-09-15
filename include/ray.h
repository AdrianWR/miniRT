/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 17:16:37 by aroque            #+#    #+#             */
/*   Updated: 2020/09/15 11:44:14 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "libft.h"
# include "color.h"
# include "vector.h"
# include "figures.h"
# include <stdbool.h>

# define EPSILON	0.0001

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
bool			hit_square(t_ray *ray, t_square *square);
bool			hit_cylinder(t_ray *ray, t_cylinder *cylinder);

#endif
