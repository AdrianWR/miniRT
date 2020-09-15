/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 14:34:12 by aroque            #+#    #+#             */
/*   Updated: 2020/09/14 23:34:30 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

# pragma pack(push, 1)

typedef struct		s_fileheader
{
	short 			type;
	int 			size;
	int				reserved;
	unsigned int	offset;
}					t_fileheader;

typedef struct		s_dibheader
{
	unsigned int	size;
	short	 		width;
	short			height;
	short			planes;
	short			bpp;
}					t_dibheader;

# pragma pack(pop)

int					export_bitmap(t_server x);
