/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 00:33:58 by aroque            #+#    #+#             */
/*   Updated: 2020/08/16 18:59:06 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORLD_H
# define WORLD_H

typedef struct	s_world {
	t_list		*figures;
	t_list		*lights;
	t_color		ambient_light;
}				t_world;

void		new_world(t_list **world);

#endif