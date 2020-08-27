/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 18:42:24 by aroque            #+#    #+#             */
/*   Updated: 2020/08/26 00:30:39 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "vector.h"
#include "figures.h"
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

#define SPHERE_ROOTS 2

t_sphere			*new_sphere(t_point center, float radius, t_color color)
{
	t_sphere		*sphere;

	if (!(sphere = malloc(sizeof(*sphere))))
		return (NULL);
	sphere->type = SPHERE;
	sphere->center = center;
	sphere->radius = radius;
	sphere->color = color;
	return (sphere);
}

static void			roots(t_ray ray, t_sphere sphere, float *root)
{
	t_vector		oc;
	float			a;
	float			half_b;
	float			c;
	float			sqrt_disc;

	oc = sub(ray.origin, sphere.center);
	a = length_squared(ray.direction);
	half_b = dot(oc, ray.direction);
	c = length_squared(oc) - pow(sphere.radius, 2);
	sqrt_disc = sqrt(pow(half_b, 2) - a * c);
	root[0] = (-half_b - sqrt_disc) / a;
	root[1] = (-half_b + sqrt_disc) / a;
}

bool				hit_sphere(t_ray *ray, t_sphere *sphere)
{
	unsigned int	i;
	float			root[SPHERE_ROOTS];

	i = 0;
	roots(*ray, *sphere, root);
	while (i < SPHERE_ROOTS)
	{
		if (ray->record.t > root[i] && root[i] > 0)
		{
			ray->record.t = root[i];
			ray->record.p = at(*ray);
			ray->record.normal = norm(sub(ray->record.p, sphere->center));
			ray->record.color = sphere->color;
			ray->record.type = SPHERE;
			return (true);
		}
		i++;
	}
	return (false);
}
