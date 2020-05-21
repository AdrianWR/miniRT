/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 15:56:30 by aroque            #+#    #+#             */
/*   Updated: 2020/05/15 11:15:09 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

typedef struct		s_vector
{
	float			x;
	float			y;
	float			z;
}					t_vector;

typedef	t_vector	t_point;

t_vector			vector(float x, float y, float z);
t_vector			add(t_vector u, t_vector v);
t_vector			sub(t_vector u, t_vector v);
t_vector			scale(t_vector u, float c);
t_vector			cross(t_vector u, t_vector v);
float				dot(t_vector u, t_vector v);
float				length(t_vector u);
t_vector			norm(t_vector u);

#endif
