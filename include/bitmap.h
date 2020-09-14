/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 14:34:12 by aroque            #+#    #+#             */
/*   Updated: 2020/09/14 15:02:47 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

typedef struct		s_fileheader
{
	short 			type;
	int 			size;
	int				reserved;
	unsigned int	offset;
}					t_fileheader;


typedef struct	s_dibheader
{
	int 		size;
	int 		width;
	int 		height;
	short		planes;
	short		bitcount;
	int			compression;
	int			imagesize;
	int			x_ppm;
	int			y_ppm;
	int			color_used;
	int			color_important;
}				t_dibheader;


int	export_bitmap(t_image image);
