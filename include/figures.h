/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figures.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 22:38:41 by aroque            #+#    #+#             */
/*   Updated: 2020/08/16 18:08:29 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HITTABLES_H
# define HITTABLES_H

# include "vector.h"
# include "ray.h"
# include "libft.h"
# include "color.h"
# include <stdbool.h>

typedef enum	e_type {
	SPHERE,
	PLANE
}				t_type;


typedef struct	s_sphere {
	t_type		type;
	t_point		center;
	float		radius;
	t_color		color;
}				t_sphere;

t_sphere		*new_sphere(t_point center, float radius, t_color color);
bool			hit_sphere(t_ray ray, t_sphere *sphere, t_hit *rec);

#endif
