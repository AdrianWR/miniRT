# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aroque <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/21 11:20:51 by aroque            #+#    #+#              #
#    Updated: 2020/08/20 16:54:20 by aroque           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libvector.a

INCLUDE_DIR	 =	.

SRC_DIR	= 	.
SRC		=	${SRC_DIR}/add.c		\
			${SRC_DIR}/product.c	\
			${SRC_DIR}/length.c		\
			${SRC_DIR}/norm.c		\
			${SRC_DIR}/vector.c

OBJ_DIR =	.
OBJ		=	$(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

CC			=	gcc
CC_FLAGS	=	-Wall	\
				-Wextra	\
				-Werror	\
				-I${INCLUDE_DIR}

LD_FLAGS = 

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CC_FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
