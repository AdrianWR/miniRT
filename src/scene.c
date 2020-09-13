/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/29 16:44:29 by aroque            #+#    #+#             */
/*   Updated: 2020/09/12 22:52:09 by aroque           ###   ########.fr       */
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
#include "server.h"
#include <errno.h>
#include <stdio.h>
#include <string.h>

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

t_server		*scene_initializer(const char *file)
{
	int			fd;
	t_world		*world;
	int			res[2];
	t_server 	*x;

	x = NULL;
	if ((fd = open_scene_file(file)) < 0)
		message_and_exit(EBADFRT);
	world = new_world();
	if (parser_file(fd, world, res))
		message_and_exit(EPARSE);
	x = new_server(res[0], res[1], world);
	init_cameras(world->cameras, *x->window);
	close(fd);
	return (x);
}
