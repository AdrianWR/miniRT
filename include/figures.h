/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figures.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 22:38:41 by aroque            #+#    #+#             */
/*   Updated: 2020/09/01 17:52:46 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIGURES_H
# define FIGURES_H

# include "vector.h"
# include "libft.h"
# include "color.h"
# include <stdbool.h>

typedef enum	e_type {
	SPHERE,
	PLANE,
	SQUARE,
	TRIANGLE,
	CYLINDER
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

typedef struct	s_square {
	t_type		type;
	t_point		center;
	float		side;
	t_vector	normal;
	t_color		color;
}				t_square;

typedef struct	s_triangle {
	t_type		type;
	t_point		a;
	t_point		b;
	t_point		c;
	t_color		color;
}				t_triangle;


t_sphere		*new_sphere(t_point center, float radius, t_color color);
t_plane			*new_plane(t_point point, t_vector normal, t_color color);
t_square		*new_square(t_point c, float side, t_vector n, t_color cl);
t_triangle		*new_triangle(t_point a, t_point b, t_point c, t_color cl);

#endif
