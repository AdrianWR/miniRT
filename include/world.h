/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 00:33:58 by aroque            #+#    #+#             */
/*   Updated: 2020/08/21 11:09:31 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORLD_H
# define WORLD_H

# include "color.h"
# include "light.h"
# include "libft.h"

typedef struct	s_world {
	t_list		*figures;
	t_list		*lights;
	t_list		*cameras;
	t_light		*ambience;
}				t_world;

t_world		*new_world(unsigned int width, unsigned int height);
t_list	*new_light_set(void);
t_list	*new_figure_set(void);
t_list	*new_camera_set(unsigned int width, unsigned int height);

#endif
