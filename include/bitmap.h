/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 14:34:12 by aroque            #+#    #+#             */
/*   Updated: 2020/09/15 11:03:44 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

# define BM 0x4D42
# define BITMAP_FILE "bitmap.bmp"
# define FILE_HEADER_SIZE 14
# define BITMAP_HEADER_SIZE 40
# define HEADER_SIZE 54
# define BI_RGB 0

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
	int	 		width;
	int			height;
	short			planes;
	short			bpp;
	unsigned int    compression;        // 4 bytes
    unsigned int    image_size;         // 4 bytes
    int    ppm_x;              // 4 bytes
    int    ppm_y;              // 4 bytes
    unsigned int    clr_used;           // 4 bytes
    unsigned int    clr_important;      // 4 bytest			bpp;
}					t_dibheader;

# pragma pack(pop)

int					export_bitmap(t_server x);
