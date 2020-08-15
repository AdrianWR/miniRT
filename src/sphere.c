/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 18:42:24 by aroque            #+#    #+#             */
/*   Updated: 2020/08/14 21:34:34 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "hittables.h"
#include "ray.h"
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

t_sphere		*new_sphere(t_point center, float radius)
{
	t_sphere	*sphere;

	if (!(sphere = malloc(sizeof(*sphere))))
		return NULL;
	sphere->center = center;
	sphere->radius = radius;
	return (sphere);
}


bool			hit_sphere(t_ray ray, t_sphere *sphere, t_hit *rec)
{
	t_vector	oc;
	float		a;
	float		half_b;
	float		c;
	float		sqrt_disc;

	oc = sub(ray.origin, sphere->center);
	a = length_squared(ray.direction);
	half_b = dot(oc, ray.direction);
	c = length_squared(oc) - sphere->radius * sphere->radius;
	sqrt_disc = sqrt(half_b * half_b - a * c);

    rec->t = (-half_b - sqrt_disc) / a;
    if (rec->t < ray.t && rec->t > 0)
	{
		rec->p = intersection(ray, rec->t);
        rec->normal = norm(sub(rec->p, sphere->center));
    }
	else
	{
    	rec->t = (-half_b + sqrt_disc) / a;
    	if (rec->t < ray.t && rec->t > 0)
		{
			rec->p = intersection(ray, rec->t);
        	rec->normal = norm(sub(rec->p, sphere->center));
    	}
		else
			return (false);
	}
    return (true);
}
