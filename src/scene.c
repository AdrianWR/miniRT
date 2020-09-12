/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/29 16:44:29 by aroque            #+#    #+#             */
/*   Updated: 2020/09/10 21:59:22 by aroque           ###   ########.fr       */
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
#include <errno.h>
#include <stdio.h>

extern int g_rterrno;

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
	char	*ext;

	ext = ft_strrchr(file, '.');
	if (!ext || ft_strncmp(ext, EXTENSION, 0x100))
		fd = -1;
	else
		fd = open(file, O_RDONLY);
	return (fd);
}

static bool		identifier(char *s, char *id)
{
	return (!ft_strncmp(s, id, 0x10));
}

static void	resolution(unsigned res[2], char **r)
{
	res[0] = ft_atoi(r[1]);
	res[1] = ft_atoi(r[2]);
}

//static void	lladd(t_list **list, void *content)
//{
//	ft_lstadd_back(list, ft_lstnew(content));
//}

static void		figures_parser(char **r, t_world *w)
{
	if (identifier(r[0], "pl"))
		ft_lstadd_back(&(w->figures), ft_lstnew(new_plane(r)));
	else if (identifier(r[0], "sp"))
		ft_lstadd_back(&(w->figures), ft_lstnew(new_sphere(r)));
	else if (identifier(r[0], "sq"))
		ft_lstadd_back(&(w->figures), ft_lstnew(new_square(r)));
	else if (identifier(r[0], "cy"))
		ft_lstadd_back(&(w->figures), ft_lstnew(new_cylinder(r)));
	else if (identifier(r[0], "tr"))
		ft_lstadd_back(&(w->figures), ft_lstnew(new_triangle(r)));
}

static void		scene_parser(char **r, t_world *w, unsigned res[2])
{
	if (identifier(r[0], "R"))
		resolution(res, r);
	else if (identifier(r[0], "A"))
		w->ambient = new_light(r, 1);
	else if (identifier(r[0], "c"))
		ft_lstadd_back(&(w->cameras), ft_lstnew(new_cam(r)));
	else if (identifier(r[0], "l"))
		ft_lstadd_back(&(w->lights), ft_lstnew(new_light(r, 0)));
	figures_parser(r, w);
}

int	scene_initializer(const char *file, t_server **x)
{
	int			fd;
	char		*line;
	char 		**split;
	t_world		*world;
	unsigned	res[2];

	line = NULL;
	split = NULL;
	if ((fd = open_scene_file(file)) < 0)
		return (fd);
	world = new_world();
	while (get_next_line(fd, &line))
	{
		if (*line && *line != '#')
		{
			split = ft_split(line, ' ');
			scene_parser(split, world, res);
			free_array((void **)split);
		}
	}
	*x = new_server(res[0], res[1], world);
	init_cameras(world->cameras, *(*x)->window);
	close(fd);
	return (0);
}
