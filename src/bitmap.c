/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 16:00:07 by aroque            #+#    #+#             */
/*   Updated: 2020/09/22 22:57:31 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bitmap.h"
#include "errcode.h"
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

static int		write_file_header(int fd, unsigned w, unsigned h)
{
	t_fileheader	fh;

	fh.type = BM;
	fh.size = HEADER_SIZE + 4 * w * h;
	fh.reserved = 0x0;
	fh.offset = HEADER_SIZE;
	return (write(fd, (void *)&fh, FILE_HEADER_SIZE));
}

static int		write_dib_header(int fd, unsigned w, unsigned h)
{
	t_dibheader	dh;

	dh.size = BITMAP_HEADER_SIZE;
	dh.width = w;
	dh.height = h;
	dh.planes = 1;
	dh.bpp = 32;
	dh.compression = BI_RGB;
	dh.image_size = 4 * w * h;
	dh.ppm_x = 2000;
	dh.ppm_y = 2000;
	dh.clr_used = 0;
	dh.clr_important = 0;
	return (write(fd, (void *)&dh, BITMAP_HEADER_SIZE));
}

/*
**	export_bitmap: Export the scene image as a bitmap file,
**  with 40-bits header.
**
**	@x: t_server instance processed bu the render function.
**
**  Return: 0, if succesful, error code otherwise.
*/

int				export_bitmap(t_server x)
{
	int		y;
	int		fd;
	t_image	img;

	y = x.height;
	img = *x.image;
	if ((fd = open(BITMAP_FILE, O_CREAT | O_TRUNC | O_WRONLY,
					S_IRUSR | S_IWUSR)) < 0)
		return (ERRSYS);
	if ((write_file_header(fd, x.width, x.height)) < 0)
		return (ERRSYS);
	if ((write_dib_header(fd, x.width, x.height)) < 0)
		return (ERRSYS);
	while (--y >= 0)
	{
		if ((write(fd, &img.data[y * img.size_line], img.size_line)) < 0)
			return (ERRSYS);
	}
	if ((close(fd) < 0))
		return (ERRSYS);
	return (0);
}
