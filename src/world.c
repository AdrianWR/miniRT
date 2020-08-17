/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 11:18:50 by aroque            #+#    #+#             */
/*   Updated: 2020/08/16 21:47:40 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "figures.h"

void		new_world(t_list **world)
{
	ft_lstadd_back(world, ft_lstnew(
				new_sphere(point(0, 0, -2), 0.5, hex2color(0x0000FF00))));
	ft_lstadd_back(world, ft_lstnew(
				new_sphere(point(1, 0, -2), 0.5, hex2color(0x00FF0000))));
	ft_lstadd_back(world, ft_lstnew(
				new_sphere(point(0, -100.5, -2), 100, hex2color(0x00FFFF00))));
}
