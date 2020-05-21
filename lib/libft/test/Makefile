# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aroque <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/21 11:20:51 by aroque            #+#    #+#              #
#    Updated: 2020/02/15 15:01:28 by aroque           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = run

CC =		gcc
CC_FLAGS =	-Wall	\
			-Wextra	\
			-Werror

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
