/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 14:34:12 by aroque            #+#    #+#             */
/*   Updated: 2020/09/15 11:57:03 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITMAP_H
# define BITMAP_H

# include "server.h"

# define BM					0x4D42
# define BI_RGB				0
# define FILE_HEADER_SIZE	14
# define BITMAP_HEADER_SIZE	40
# define HEADER_SIZE		54
# define BITMAP_FILE		"bitmap.bmp"

# pragma pack(push, 1)

typedef struct		s_fileheader
{
	short			type;
	int				size;
	int				reserved;
	unsigned int	offset;
}					t_fileheader;

typedef struct		s_dibheader
{
	unsigned int	size;
	int				width;
	int				height;
	short			planes;
	short			bpp;
	unsigned int	compression;
	unsigned int	image_size;
	int				ppm_x;
	int				ppm_y;
	unsigned int	clr_used;
	unsigned int	clr_important;
}					t_dibheader;

# pragma pack(pop)

int					export_bitmap(t_server x);

#endif
