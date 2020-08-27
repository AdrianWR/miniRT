/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 10:48:18 by aroque            #+#    #+#             */
/*   Updated: 2020/08/26 23:43:42 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include "camera.h"

int		main(int argc, char *argv[])
{
	t_server	*x;

	(void) argc;
	(void) argv;

	//x = new_server(100, 100);
	x = new_server(1024, 768);
	x->world = new_world(*x->window);
	render(x);
	mlx_listen(x);
}
