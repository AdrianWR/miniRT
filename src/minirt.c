/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 10:48:18 by aroque            #+#    #+#             */
/*   Updated: 2020/05/27 23:03:24 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "server.h"
#include <stdlib.h>

//comment
int		main(int argc, char *argv[])
{
	t_server	*x;

	(void) argc;
	(void) argv;
	x = new_server(WIDTH, HEIGHT);
	mlx_listen(x);
}
