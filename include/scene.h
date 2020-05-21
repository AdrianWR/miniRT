/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 11:43:27 by aroque            #+#    #+#             */
/*   Updated: 2020/05/15 11:31:02 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# define HT_SIZE			120

# define SCENE_EXTENSION 	".rt"
# define SCENE_KEYS			["R", "A", "c", "l", "pl", "sp", "sq", "cy", "tr"]

# include "hash.h"
# include "libft.h"

typedef struct	s_scene {
	t_hashtable	*elems;
	t_list		*shapeset;
} 				t_scene;


t_scene	*scene_initializer(const char *file);

#endif
