# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aroque <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/21 11:20:51 by aroque            #+#    #+#              #
#    Updated: 2020/09/05 18:51:23 by aroque           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = run

CC =		gcc
CC_FLAGS =	-Wall	\
			-Wextra	\
			-Werror	\
			-DLIBBSD_OVERLAY	\
			-I/usr/include/bsd

LD_FLAGS = 

INCLUDES =	..

LIB_DIR =	..
LIB		=	${LIB_DIR}/libft.a

SRC_DIR	= 	.
SRC		=	${SRC_DIR}/test.c

all: ${NAME}
	./run

${NAME}: ${SRC} ${LIB}
	${CC} ${LD_FLAGS} -I${INCLUDES} $^ -o $@

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean all
