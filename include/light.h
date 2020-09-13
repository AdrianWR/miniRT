/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 17:04:02 by aroque            #+#    #+#             */
/*   Updated: 2020/09/13 20:22:22 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

# include "color.h"
# include "vector.h"
# include "libft.h"
# include "ray.h"
# include "figures.h"

# define ALBEDO 1000

typedef struct	s_light
{
	t_point		position;
	float		brightness;
	t_color		color;
}				t_light;

t_light			*new_light(char **r, int *errcode);
t_light			*new_ambient_light(char **r, int *errcode);
bool			in_shadow(t_light light, t_list *figures, t_hit record);
t_color			color_component(t_light light, t_hit record);

#endif
