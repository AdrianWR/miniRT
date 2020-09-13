/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errcode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 15:11:26 by aroque            #+#    #+#             */
/*   Updated: 2020/09/13 15:10:41 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errcode.h"
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void			message_and_exit(t_errcode code, char *note)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	if (errno)
		perror("");
	else if (code > 0)
	{
		ft_putstr_fd(g_errstr[code], STDERR_FILENO);
		if (note)
		{
			ft_putstr_fd(": ", STDERR_FILENO);
			ft_putstr_fd(note, STDERR_FILENO);
			free(note);
		}
		ft_putchar_fd('\n', STDERR_FILENO);
	}
	else
		ft_putstr_fd("Fatal Error\n", STDERR_FILENO);
	exit(EXIT_FAILURE);
}
