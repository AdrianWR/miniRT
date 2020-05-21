/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/29 16:44:29 by aroque            #+#    #+#             */
/*   Updated: 2020/05/12 23:27:38 by aroque           ###   ########.fr       */
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
#include "hash.h"

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

void			free_array(char **array)
{
	unsigned int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

static t_scene	*scene_parser(int fd)
{
	char		*line;
	char 		**split;
	t_scene		*scene;
	t_hashtable	*ht;

	line = NULL;
	split = NULL;
	if (!(scene = malloc(sizeof(*scene))))
		return (NULL);
	if (!(ht = ht_create(HT_SIZE)))
		return (NULL);
	while (get_next_line(fd, &line))
	{
		split = ft_split(line, ' ');
		ht_set(ht, split[0], ft_strdup(split[1]));
		free_array(split);
		free(line);
	}
	scene->elems = ht;
	free(line);
	return (scene);
}

t_scene			*scene_initializer(const char *file)
{
	t_scene	*map;
	int		fd;

	if ((fd = open_scene_file(file)) < 0)
		return (NULL);
	map = scene_parser(fd);
	close(fd);
	return (map);
}
