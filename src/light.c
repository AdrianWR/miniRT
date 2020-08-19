/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 18:49:11 by aroque            #+#    #+#             */
/*   Updated: 2020/08/19 17:17:01 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"
#include "libft.h"

t_light		*new_light(t_point position, float brightness, t_color color)
{
	t_light	*light;

	if (!(light = malloc(sizeof(*light))))
		return (NULL);
	light->position = position;
	light->brightness = brightness;
	light->color = color;
	return (light);
}

t_list	*new_light_set(void)
{
	t_list *light_set;

	light_set = NULL;
	ft_lstadd_back(&light_set, ft_lstnew(
				new_light(point(2, 5, -1), 0.5, hex2color(0x0000FF00))));
	return (light_set);
}
