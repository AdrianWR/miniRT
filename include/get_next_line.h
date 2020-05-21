/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 11:12:57 by aroque            #+#    #+#             */
/*   Updated: 2020/05/11 10:00:03 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# define GNL_SUCCESS	1
# define GNL_FAILURE	-1
# define GNL_EOF		0

# define LBREAK	'\n'
# define STR_EMPTY ""

# define OPEN_MAX		16
# define BUFFER_SIZE	1024

int		get_next_line(int fd, char **line);

/*
 * **	░░░░░░░█▐▓▓░████▄▄▄█▀▄▓▓▓▌█
 * **	░░░░░▄█▌▀▄▓▓▄▄▄▄▀▀▀▄▓▓▓▓▓▌█
 * **	░░░▄█▀▀▄▓█▓▓▓▓▓▓▓▓▓▓▓▓▀░▓▌█
 * **	░░█▀▄▓▓▓███▓▓▓███▓▓▓▄░░▄▓▐█▌
 * **	░█▌▓▓▓▀▀▓▓▓▓███▓▓▓▓▓▓▓▄▀▓▓▐█
 * **	▐█▐██▐░▄▓▓▓▓▓▀▄░▀▓▓▓▓▓▓▓▓▓▌█▌
 * **	█▌███▓▓▓▓▓▓▓▓▐░░▄▓▓███▓▓▓▄▀▐█
 * **	█▐█▓▀░░▀▓▓▓▓▓▓▓▓▓██████▓▓▓▓▐█
 * **	▌▓▄▌▀░▀░▐▀█▄▓▓██████████▓▓▓▌█▌
 * **	▌▓▓▓▄▄▀▀▓▓▓▀▓▓▓▓▓▓▓▓█▓█▓█▓▓▌█▌
 * **	█▐▓▓▓▓▓▓▄▄▄▓▓▓▓▓▓█▓█▓█▓█▓▓▓▐█
 * */

#endif
