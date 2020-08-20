/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 17:04:02 by aroque            #+#    #+#             */
/*   Updated: 2020/08/19 22:43:07 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

#include "color.h"
#include "vector.h"
#include "libft.h"
#include "ray.h"

typedef struct	s_light
{
	t_point		position;
	float		brightness;
	t_color		color;
}				t_light;

t_light			*new_light(t_point position, float brightness, t_color color);
t_list			*new_light_set(void);
t_color			light_object(t_list *light, t_hit record);
float			light_intensity(t_light *light, t_hit record);

#endif
