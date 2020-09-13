/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 22:48:22 by aroque            #+#    #+#             */
/*   Updated: 2020/09/13 20:14:03 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errcode.h"
#include "camera.h"
#include "server.h"
#include "get_next_line.h"

static int		resolution(int res[2], char **r)
{
	static bool	set;

	if (set)
		return (EREPEAT);
	res[0] = ft_atoi(r[1]);
	res[1] = ft_atoi(r[2]);
	if (res[0] <= 0 || res[1] <= 0)
		return (EBADFMT);
	set = true;
	return (0);
}

static void		figures_parser(char **line, t_world *w, int *err)
{
	if (!ft_strncmp(line[0], "pl", 0x11))
		ft_lstadd_back(&(w->figures), ft_lstnew(new_plane(line, err)));
	else if (!ft_strncmp(line[0], "sp", 0x11))
		ft_lstadd_back(&(w->figures), ft_lstnew(new_sphere(line, err)));
	else if (!ft_strncmp(line[0], "sq", 0x11))
		ft_lstadd_back(&(w->figures), ft_lstnew(new_square(line, err)));
	else if (!ft_strncmp(line[0], "cy", 0x11))
		ft_lstadd_back(&(w->figures), ft_lstnew(new_cylinder(line, err)));
	else if (!ft_strncmp(line[0], "tr", 0x11))
		ft_lstadd_back(&(w->figures), ft_lstnew(new_triangle(line, err)));
	else
		*err = EINVID;
}

static void		scene_parser(char **line, t_world *w, int *err)
{
	if (!ft_strncmp(line[0], "R", 0x10))
		*err = resolution(w->resolution, line);
	else if (!ft_strncmp(line[0], "A", 0x10))
		w->ambient = new_ambient_light(line, err);
	else if (!ft_strncmp(line[0], "c", 0x10))
		ft_lstadd_back(&(w->cameras), ft_lstnew(new_cam(line, err)));
	else if (!ft_strncmp(line[0], "l", 0x10))
		ft_lstadd_back(&(w->lights), ft_lstnew(new_light(line, err)));
	else
		figures_parser(line, w, err);
}

int				parser_file(int fd, t_world *world, char **note)
{
	int			errcode;
	char		*line;
	char		**split;

	errcode = 0;
	line = NULL;
	split = NULL;
	while (get_next_line(fd, &line) && !errcode)
	{
		if (*line && *line != '#')
		{
			split = ft_split(line, ' ');
			scene_parser(split, world, &errcode);
			if (errcode)
				*note = ft_strdup(line);
			free_array((void **)split);
		}
		free(line);
	}
	return (errcode);
}
