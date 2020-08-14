/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hittables.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 22:38:41 by aroque            #+#    #+#             */
/*   Updated: 2020/08/14 00:15:57 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HITTABLES_H
# define HITTABLES_H

# include "vector.h"
# include "ray.h"
# include "libft.h"

typedef struct	s_hittable {
	void		*solid;
	float		(*hit)();
}				t_hittable;

typedef struct	s_sphere {
	t_point		center;
	float		radius;
}				t_sphere;

t_sphere		*new_sphere(t_point center, float radius);
float			hit_sphere(t_ray ray, t_sphere *sphere);
float			hit(t_ray, t_list *hittables);

#endif
