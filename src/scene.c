/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/29 16:44:29 by aroque            #+#    #+#             */
/*   Updated: 2020/09/14 15:33:38 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "scene.h"
#include "camera.h"
#include "server.h"
#include "errcode.h"

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
	if (!ext)
		fd = -1;
	else if (ft_strncmp(ext, EXTENSION, 0x100))
		fd = -1;
	else
		fd = open(file, O_RDONLY);
	return (fd);
}

static t_world	*new_world(void)
{
	t_world	*world;

	if (!(world = malloc(sizeof(*world))))
		return (NULL);
	world->cameras = NULL;
	world->lights = NULL;
	world->figures = NULL;
	return (world);
}

t_world		*scene_initializer(const char *file)
{
	int			fd;
	int			err;
	char		*note;
	t_world		*world;

	if ((fd = open_scene_file(file)) < 0)
		message_and_exit(EBADFRT, 0x0);
	world = new_world();
	if ((err = parser_file(fd, world, &note)))
	{
		free_world(world);
		message_and_exit(err, note);
	}
	close(fd);
	return (world);
}
