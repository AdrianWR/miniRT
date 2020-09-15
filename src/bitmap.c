/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 16:00:07 by aroque            #+#    #+#             */
/*   Updated: 2020/09/14 23:35:24 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bitmap.h"
#include "errcode.h"
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

# define BM 0x4D42
# define BITMAP_FILE "bitmap.bmp"
# define FILE_HEADER_SIZE 14
# define BITMAP_HEADER_SIZE 12
# define HEADER_SIZE 26
# define BI_RGB 0

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
	return (write(fd, (void *)&dh, BITMAP_HEADER_SIZE));
}

int		export_bitmap(t_server x)
{
	int	fd;
	int	y;

	y = x.height;
	if ((fd = open(BITMAP_FILE, O_CREAT | O_TRUNC | O_WRONLY,
					S_IRUSR | S_IWUSR)) < 0)
		message_and_exit(ERRSYS, 0x0);
	if ((write_file_header(fd, x.width, x.height)) < 0)
		message_and_exit(ERRSYS, 0x0);
	if ((write_dib_header(fd, x.width, x.height)) < 0)
		message_and_exit(ERRSYS, 0x0);
	while (--y >= 0)
		write(fd, &x.image->data[y * x.image->size_line], x.image->size_line);
	if ((close(fd) < 0))
		message_and_exit(ERRSYS, 0x0);
	return (0);
}
