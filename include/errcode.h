/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errcode.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 14:56:26 by aroque            #+#    #+#             */
/*   Updated: 2020/09/13 20:23:17 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRCODE_H
# define ERRCODE_H

# include <errno.h>

typedef enum	e_errcode {
	__ERRNONE,
	EUSAGE,
	EBADFRT,
	EBADFMT,
	EREPEAT,
	EBADVEC,
	EBADCLR,
	EOURCLR,
	EINVID,
	__ERRMAX
}				t_errcode;

static char *g_errstr[__ERRMAX] = {
	"__ERRNONE",
	"Usage: ./miniRT <scene_file> [--save]",
	"Bad file descriptor on <.rt> file",
	"Bad element declaration",
	"Repeated element",
	"Bad formatted vector",
	"Bad formatted color",
	"Color out of range",
	"Invalid element identifier",
};

void			message_and_exit(t_errcode code, char *note);

#endif
