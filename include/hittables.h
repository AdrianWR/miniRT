/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hittables.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 22:38:41 by aroque            #+#    #+#             */
/*   Updated: 2020/08/14 21:34:44 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HITTABLES_H
# define HITTABLES_H

# include "vector.h"
# include "ray.h"
# include "libft.h"
# include <stdbool.h>

typedef struct	s_hit {
	t_vector	normal;
	t_point		p;
	float		t;
}				t_hit;

typedef struct	s_sphere {
	t_point		center;
	float		radius;
}				t_sphere;

t_sphere		*new_sphere(t_point center, float radius);
bool			hit_sphere(t_ray ray, t_sphere *sphere, t_hit *rec);
float			hit(t_ray, t_list *hittables);
bool			hit_world(t_ray ray, t_list *world, t_hit *record);

#endif
