/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 11:18:50 by aroque            #+#    #+#             */
/*   Updated: 2020/08/14 09:43:03 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "hittables.h"

void		new_world(t_list **world)
{
	t_sphere *sphere;

	sphere = new_sphere(point(0, 0, -1.5), 0.5);
	ft_lstadd_back(world, ft_lstnew(sphere));
}
