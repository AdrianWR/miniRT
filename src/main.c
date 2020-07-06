/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 11:44:28 by aroque            #+#    #+#             */
/*   Updated: 2020/05/27 23:02:36 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include "scene.h"

// comment
//
int	main(int argc, char *argv[])
{
	t_scene	*scene;

	(void) argc;
	scene = scene_initializer(argv[1]);
	if (!scene)
	{
		perror("Scene Initialization Error");
		exit(EXIT_FAILURE);
	}
	printf("Tudo certo.\n");
	printf("%s\n", (char *)ht_get(scene->elems, "R"));
	printf("%s\n", (char *)ht_get(scene->elems, "cy"));
	ht_free(scene->elems, free);
	free(scene);
	exit(EXIT_SUCCESS);
}
