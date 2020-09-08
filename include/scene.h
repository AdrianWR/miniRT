/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 11:43:27 by aroque            #+#    #+#             */
/*   Updated: 2020/09/08 09:03:48 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# define HT_SIZE			120

# define SCENE_EXTENSION 	".rt"

# include "libft.h"
# include "server.h"
# include "vector.h"


void scene_initializer(const char *file, t_server **x);
t_vector atov(char *s);
t_color atoc(char *s);
float ft_atof(char *s);

#endif
