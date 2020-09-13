/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errcode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 15:11:26 by aroque            #+#    #+#             */
/*   Updated: 2020/09/12 22:42:30 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static char *g_errstr[__ERRMAX] = {
	"__ERRNONE",
	"Usage: ./miniRT <scene_file> [--save]\n",
	"Bad file descriptor on <.rt> file\n",
	"Bad element declaration\n",
};

void			message_and_exit(t_errcode code)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	if (errno)
		perror("");
	else if (code > 0)
		ft_putstr_fd(g_errstr[code], STDERR_FILENO);
	else
		ft_putstr_fd("Fatal Error\n", STDERR_FILENO);
	exit(EXIT_FAILURE);
}
