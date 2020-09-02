/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 15:56:30 by aroque            #+#    #+#             */
/*   Updated: 2020/09/01 22:36:27 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

typedef struct		s_vector
{
	double			x;
	double			y;
	double			z;
}					t_vector;

typedef	t_vector	t_point;

t_vector			vector(double x, double y, double z);
t_point				point(double x, double y, double z);
t_vector			add(t_vector u, t_vector v);
t_vector			sub(t_vector u, t_vector v);
t_vector			scale(t_vector u, double c);
t_vector			cross(t_vector u, t_vector v);
double				dot(t_vector u, t_vector v);
double				length_squared(t_vector u);
double				length(t_vector u);
t_vector			norm(t_vector u);

#endif
