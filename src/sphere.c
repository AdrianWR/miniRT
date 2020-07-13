/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 18:42:24 by aroque            #+#    #+#             */
/*   Updated: 2020/07/13 10:53:23 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "solids.h"
#include "ray.h"
#include <math.h>

t_sphere		sphere(t_point center, float radius)
{
	t_sphere	sphere;

	sphere.center = center;
	sphere.radius = radius;
	return (sphere);
}

float			hit_sphere(t_ray ray, t_sphere sphere)
{
	t_vector	oc;
	float		a;
	float		half_b;
	float		c;
	float		discriminant;

	oc = sub(ray.origin, sphere.center);
	a = length_squared(ray.direction);
	half_b = dot(oc, ray.direction);
	c = length_squared(oc) - sphere.radius * sphere.radius;
	discriminant = half_b * half_b - a * c;
	if (discriminant < 0)
		return (-1);
	return ((-half_b - sqrt(discriminant)) / a);
}
