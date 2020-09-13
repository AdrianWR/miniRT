/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 11:43:27 by aroque            #+#    #+#             */
/*   Updated: 2020/09/13 20:07:05 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# define EXTENSION 	".rt"

# include "libft.h"
# include "server.h"
# include "vector.h"
# include "errcode.h"

t_server	*scene_initializer(const char *file);
float		ft_atof(char *s);
t_vector	ft_atov(char *s, int *errcode);
t_color		ft_atoc(char *s, int *errcode);
unsigned	strarray_len(char **params);

#endif
