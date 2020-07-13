/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 10:48:18 by aroque            #+#    #+#             */
/*   Updated: 2020/07/13 09:30:51 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "ray.h"
#include "server.h"
#include "color.h"
#include <math.h>
#include <stdio.h>

/*t_color	ray_color(t_ray ray)
//{
//	t_vector direction;
//	float t;
//
//	direction = norm(ray.direction);
//	t = 0.5 * (1 + direction.y);
//	return ((1 - t) * (0x92BEFE) + t * (0xFFFFFF));
//	
//}
*/

int		main(int argc, char *argv[])
{
	t_server	*x;

	(void) argc;
	(void) argv;
	x = new_server(800, 600);
	render(x);
	//draw_sphere();
	mlx_listen(x);
}
