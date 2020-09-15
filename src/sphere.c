/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 18:42:24 by aroque            #+#    #+#             */
/*   Updated: 2020/09/15 11:02:17 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "vector.h"
#include "figures.h"
#include "scene.h"
#include "errcode.h"
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

t_sphere			*new_sphere(char **params, int *errcode)
{
	t_sphere		*sphere;

	if (strarray_len(params) != 4 && (*errcode = EBADFMT))
		return (NULL);
	if (!(sphere = malloc(sizeof(*sphere))))
		return (NULL);
	sphere->type = SPHERE;
	sphere->color = ft_atoc(params[3], errcode);
	sphere->radius = ft_atof(params[2], errcode) / 2;
	sphere->center = ft_atov(params[1], errcode);
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
	float			root[2];

	i = 0;
	roots(*ray, *sphere, root);
	while (i < 2)
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
