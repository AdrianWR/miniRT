/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figures.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 22:38:41 by aroque            #+#    #+#             */
/*   Updated: 2020/08/25 23:49:30 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIGURES_H
# define FIGURES_H

# include "vector.h"
//# include "ray.h"
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

typedef struct	s_plane {
	t_type		type;
	t_point		point;
	t_vector	normal;
	t_color		color;
}				t_plane;


t_sphere		*new_sphere(t_point center, float radius, t_color color);
t_plane			*new_plane(t_point point, t_vector normal, t_color color);

#endif
