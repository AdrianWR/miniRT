/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errcode.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 14:56:26 by aroque            #+#    #+#             */
/*   Updated: 2020/09/19 01:14:29 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRCODE_H
# define ERRCODE_H

# include <errno.h>

typedef enum	e_errcode {
	__ERRNONE,
	ERRSYS,
	EUSAGE,
	EBADEXT,
	EBADFMT,
	EREPEAT,
	ENOTRES,
	ENOTAMB,
	EBADVEC,
	EBADCLR,
	EOURCLR,
	EOURINT,
	EOURFOV,
	EOURVEC,
	EINVID,
	__ERRMAX
}				t_errcode;

static char		*g_errstr[__ERRMAX] = {
	"__ERRNONE",
	"System error",
	"Usage: ./miniRT <scene_file> [--save]",
	"Bad extension on scene file",
	"Bad element declaration",
	"Repeated element",
	"Mandatory element resolution not found",
	"Mandatory element ambient light not found",
	"Bad formatted vector",
	"Bad formatted color",
	"Color out of range",
	"Light intensity out of range",
	"Field of view out of range",
	"Orientation vector out of range",
	"Invalid element identifier",
};

void			message_and_exit(t_errcode code, char *note);

#endif
