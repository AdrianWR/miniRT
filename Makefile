# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/23 10:13:02 by aroque            #+#    #+#              #
#    Updated: 2020/05/18 00:40:46 by aroque           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	miniRT

LIB_DIR		=	./lib

MLX_DIR		=	${LIB_DIR}/minilibx
MLX			=	${MLX_DIR}/libmlx_Linux.a

LIBFT_DIR	=	${LIB_DIR}/libft
LIBFT		=	${LIBFT_DIR}/libft.a

HASH_DIR	=	${LIB_DIR}/hash
HASH		=	${HASH_DIR}/libhash.a

MODULES		=	${MLX_DIR} ${LIBFT_DIR} ${HASH_DIR}

INCLUDE_DIR	=	./include

CC			=	gcc
CC_FLAGS	=	-c					\
				-Wall				\
				-Wextra				\
				-g					\
				-Werror				\
				-I${MLX_DIR}		\
				-I${LIBFT_DIR}		\
				-I${HASH_DIR}		\
				-I${INCLUDE_DIR}	

LD_FLAGS	=	-L${LIBFT_DIR}	\
				-L${HASH_DIR}	\
				-L${MLX_DIR}	\
				-lm				\
				-lft			\
				-lhash			\
				-lmlx_Linux		\
				-lXext			\
				-lX11

SRC_DIR	=	./src
SRC		=	${SRC_DIR}/minirt.c			\
			${SRC_DIR}/scene.c			\
			${SRC_DIR}/vector.c			\
			${SRC_DIR}/add.c			\
			${SRC_DIR}/product.c		\
			${SRC_DIR}/length.c			\
			${SRC_DIR}/norm.c			\
			${SRC_DIR}/get_next_line.c	\
			${SRC_DIR}/server.c			\
			${SRC_DIR}/color_map.c		\
			${SRC_DIR}/hooks.c

OBJ_DIR	=	./build
OBJ		=	$(patsubst ${SRC_DIR}/%.c, ${OBJ_DIR}/%.o, ${SRC})

all: $(NAME)

$(NAME): ${OBJ}
	$(CC) $^ $(LD_FLAGS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c ${LIBFT} ${MLX} ${HASH}
	mkdir -p $(OBJ_DIR)
	$(CC) $(CC_FLAGS) $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	$(MAKE) -C $(MLX_DIR)

$(HASH):
	$(MAKE) -C $(HASH_DIR)

clean:
	for dir in $(MODULES); do	\
		$(MAKE) -C $$dir clean;	\
	done
	$(RM) $(OBJ)

fclean: clean
	for dir in $(MODULES);	do	\
		$(MAKE) -C $$dir fclean;\
	done
	$(RM) $(NAME)

re: fclean all

test: all
	./$(NAME)

bonus: re
