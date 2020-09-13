/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 22:48:22 by aroque            #+#    #+#             */
/*   Updated: 2020/09/12 23:15:10 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "server.h"
#include "get_next_line.h"

static bool		identifier(char *s, char *id)
{
	return (!ft_strncmp(s, id, 0x11));
}

static void		resolution(int res[2], char **r)
{
	res[0] = ft_atoi(r[1]);
	res[1] = ft_atoi(r[2]);
}

static int		world_add(t_list **list, void *content)
{
	if (!content)
		return (-1);
	ft_lstadd_back(list, ft_lstnew(content));
	return (0);
}

static void		figures_parser(char **r, t_world *w, int *result)
{
	if (identifier(r[0], "pl"))
		*result = world_add(&(w->figures), new_plane(r));
	else if (identifier(r[0], "sp"))
		*result = world_add(&(w->figures), new_sphere(r));
	else if (identifier(r[0], "sq"))
		*result = world_add(&(w->figures), new_square(r));
	else if (identifier(r[0], "cy"))
		*result = world_add(&(w->figures), new_cylinder(r));
	else if (identifier(r[0], "tr"))
		*result = world_add(&(w->figures), new_triangle(r));
}

static int		scene_parser(char **r, t_world *w, int res[2])
{
	int result;

	result = 0;
	if (identifier(r[0], "R"))
		resolution(res, r);
	else if (identifier(r[0], "A"))
	{
		w->ambient = new_light(r, 1);
		if (w->ambient == 0x0)
			result = -1;
	}
	else if (identifier(r[0], "c"))
		result = world_add(&(w->cameras), new_cam(r));
	else if (identifier(r[0], "l"))
		result = world_add(&(w->lights), new_light(r, 0));
	else
		figures_parser(r, w, &result);
	return (result);
}

int				parser_file(int fd, t_world *world, int res[2])
{
	int			result;
	char		*line;
	char 		**split;

	result = 0;
	line = NULL;
	split = NULL;
	while (get_next_line(fd, &line) && !result)
	{
		if (*line && *line != '#')
		{
			split = ft_split(line, ' ');
			result = scene_parser(split, world, res);
			free_array((void **)split);
		}
	}
	return (result);
}
