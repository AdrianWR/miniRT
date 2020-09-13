/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figures.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 22:38:41 by aroque            #+#    #+#             */
/*   Updated: 2020/09/13 20:22:34 by aroque           ###   ########.fr       */
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
	t_point		vertex[4];
	t_color		color;
}				t_square;

typedef struct	s_cylinder {
	t_type		type;
	t_point		center;
	t_vector	axis;
	float		radius;
	float		height;
	t_point		edge[2];
	t_color		color;
}				t_cylinder;

typedef struct	s_triangle {
	t_type		type;
	t_point		vertex[3];
	t_vector	normal;
	t_color		color;
}				t_triangle;

t_sphere		*new_sphere(char **params, int *errcode);
t_plane			*new_plane(char **params, int *errcode);
t_square		*new_square(char **params, int *errcode);
t_triangle		*new_triangle(char **params, int *errcode);
t_cylinder		*new_cylinder(char **params, int *errcode);

#endif
