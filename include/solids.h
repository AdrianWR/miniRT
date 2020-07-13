/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solids.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 22:38:41 by aroque            #+#    #+#             */
/*   Updated: 2020/07/13 11:18:20 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLIDS_H
# define SOLIDS_H

# include "vector.h"
# include "ray.h"



typedef struct	s_solid {
	void		*solid;
	float		(*hit)();
}				t_solid;

typedef struct	s_sphere {
	t_point		center;
	float		radius;
}				t_sphere;

t_sphere		sphere(t_point center, float radius);
//float			hit();
float			hit_sphere(t_ray ray, t_sphere sphere);

#endif
