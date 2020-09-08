/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/29 16:44:29 by aroque            #+#    #+#             */
/*   Updated: 2020/09/08 09:29:55 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "get_next_line.h"
#include "scene.h"
#include "camera.h"

#include <stdio.h>

/*
**	open_scene_file(): Open the scene file as a file
**	descriptor integer. If the file doesn't have the
**	correct extension or fails to open, the function
**	returns -1. Otherwise, it returns the scene fd.
**
**	@file: scene filesystem path.
**
**	Return: fd number in case of success, -1 otherwise.
*/

static int		open_scene_file(const char *file)
{
	int		fd;
	char	*extension;

	extension = ft_strrchr(file, '.');
	if (ft_strncmp(extension, SCENE_EXTENSION, ft_strlen(SCENE_EXTENSION)))
		fd = -1;
	else
		fd = open(file, O_RDONLY);
	return (fd);
}

static bool		identifier(char *s, char *id)
{
	if (!ft_strncmp(s, id, ft_strlen(s)))
		return (true);
	return (false);
}

static void	resolution(unsigned res[2], unsigned x, unsigned y)
{
	res[0] = x;
	res[1] = y;
}

static void	lladd(t_list **list, void *content)
{
	ft_lstadd_back(list, ft_lstnew(content));
}

static void		scene_parser(char **r, t_world *w, unsigned res[2])
{
	t_list **c;
	t_list **l;
	t_list **f;

	c = &(w->cameras);
	l = &(w->lights);
	f = &(w->figures);
	if (!r[0])
		return ;
	else if (identifier(r[0], "R"))
		resolution(res, ft_atoi(r[1]), ft_atoi(r[2]));
	else if (identifier(r[0], "A"))
		w->ambient = new_light(point(0,0,0), ft_atof(r[1]), atoc(r[2]));
	else if (identifier(r[0], "c"))
		lladd(c, new_cam(atov(r[1]), atov(r[2]), ft_atof(r[3])));
	else if (identifier(r[0], "l"))
		lladd(l, new_light(atov(r[1]), ft_atof(r[2]), atoc(r[3])));
	else if (identifier(r[0], "pl"))
		lladd(f, new_plane(atov(r[1]), atov(r[2]), atoc(r[3])));
	else if (identifier(r[0], "sp"))
		lladd(f, new_sphere(atov(r[1]), ft_atof(r[2]), atoc(r[3])));
	else if (identifier(r[0], "sq"))
		lladd(f, new_square(atov(r[1]), atov(r[2]), ft_atof(r[3]), atoc(r[4])));
	else if (identifier(r[0], "cy"))
		lladd(f, new_cylinder(r));
	else if (identifier(r[0], "tr"))
		lladd(f, new_triangle(r));
		//lladd(f, new_triangle(atov(r[1]), atov(r[2]), atov(r[3]), atoc(r[4])));
}

void	scene_initializer(const char *file, t_server **x)
{
	int			fd;
	char		*line;
	char 		**split;
	t_world		*world;
	unsigned	res[2];

	line = NULL;
	split = NULL;
	if ((fd = open_scene_file(file)) < 0)
		return ;
	world = new_world();
	while (get_next_line(fd, &line))
	{
		if (*line || *line != '#')
		{
			split = ft_split(line, ' ');
			scene_parser(split, world, res);
			free_array((void **)split);
		}
	}
	*x = new_server(res[0], res[1], world);
	init_cameras(world->cameras, *(*x)->window);
	close(fd);
}
