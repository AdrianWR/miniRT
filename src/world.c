/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 11:18:50 by aroque            #+#    #+#             */
/*   Updated: 2020/08/25 08:54:17 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "figures.h"
#include "camera.h"
#include "light.h"

t_world		*new_world(unsigned int width, unsigned int height)
{
	t_world	*world;
	
	if (!(world = malloc(sizeof(*world))))
		return (NULL);
	world->lights = new_light_set();
	world->figures = new_figure_set();
	world->cameras = new_camera_set(width, height);
	world->ambience = new_light(point(0,0,0), 0.1, 0x00FFFFFF);
	return (world);
}

t_list	*new_light_set(void)
{
	t_list *light_set;

	light_set = NULL;
	//ft_lstadd_back(&light_set, ft_lstnew(
	//			new_light(point(-5, 5, -1), 0.4, 0x00FFFFFF)));
	//ft_lstadd_back(&light_set, ft_lstnew(
	//			new_light(point(2, 4, 0), 0.2, 0x00FFFFFF)));
	//ft_lstadd_back(&light_set, ft_lstnew(
	//			new_light(point(-5, 5, -1), 0.2, 0x0000FF00)));
	ft_lstadd_back(&light_set, ft_lstnew(
				new_light(point(0, 4, -2), 0.2, 0x00FFFFFF)));
	return (light_set);
}

t_list	*new_figure_set(void)
{
	t_list *figure_set;

	figure_set = NULL;
	ft_lstadd_back(&figure_set, ft_lstnew(
				new_sphere(point(-2, 0, -2), 0.5, 0x000000FF)));
	ft_lstadd_back(&figure_set, ft_lstnew(
				new_sphere(point(0, 0, -2), 0.5, 0x0000FF00)));
	ft_lstadd_back(&figure_set, ft_lstnew(
				new_sphere(point(2, 0, -2), 0.5, 0x00FF0000)));
	ft_lstadd_back(&figure_set, ft_lstnew(
				new_sphere(point(0, -100.5, -2), 100, 0x00FFFF00)));
	return (figure_set);
}

t_list	*new_camera_set(unsigned int width, unsigned int height)
{
	t_list *camera_set;

	camera_set = NULL;
	ft_lstadd_back(&camera_set, ft_lstnew(
		new_camera(point(0, 0, +3), vector(0, 0, -1), 60, width, height)));
	ft_lstadd_back(&camera_set, ft_lstnew(
		new_camera(point(0, 0, 0), vector(0.5, 0, -1), 60, width, height)));
	ft_lstadd_back(&camera_set, ft_lstnew(
		new_camera(point(0, 0, 0), vector(0, 0, -1), 60, width, height)));
	ft_lstadd_back(&camera_set, ft_lstnew(
		new_camera(point(0, 0, 0), vector(-0.5, 0, -1), 60, width, height)));
	ft_lstadd_back(&camera_set, ft_lstnew(
		new_camera(point(0, 10, 10), vector(0, -0.5, -1), 60, width, height)));
	ft_lstadd_back(&camera_set, ft_lstnew(
		new_camera(point(0, 10, 10), vector(-0.25, -0.5, -1), 60, width, height)));
	return (camera_set);
}
