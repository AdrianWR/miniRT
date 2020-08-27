/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 17:04:02 by aroque            #+#    #+#             */
/*   Updated: 2020/08/25 23:47:50 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

#include "color.h"
#include "vector.h"
#include "libft.h"
#include "ray.h"
#include "figures.h"

typedef struct	s_light
{
	t_point		position;
	float		brightness;
	t_color		color;
}				t_light;

t_light			*new_light(t_point position, float brightness, t_color color);
t_list			*new_light_set(void);
float			light_intensity(t_light light, t_hit record);
t_color			color_component(t_light light, t_hit record);
t_color 		render_light(t_light ambience, t_list *light, t_hit record);
#endif
