/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 11:18:50 by aroque            #+#    #+#             */
/*   Updated: 2020/08/14 22:15:04 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "hittables.h"

void		new_world(t_list **world)
{
	ft_lstadd_back(world, ft_lstnew(new_sphere(point(0, 0, -1), 0.5)));
	ft_lstadd_back(world, ft_lstnew(new_sphere(point(0, -100.5, -1), 100)));
}
