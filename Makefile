# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/23 10:13:02 by aroque            #+#    #+#              #
#    Updated: 2020/09/15 11:24:52 by aroque           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	miniRT

LIB_DIR		=	./lib

MLX_DIR		=	${LIB_DIR}/minilibx
MLX			=	${MLX_DIR}/libmlx_Linux.a

LIBFT_DIR	=	${LIB_DIR}/libft
LIBFT		=	${LIBFT_DIR}/libft.a

LIBVECTOR_DIR	=	${LIB_DIR}/libvector
LIBVECTOR		=	${LIBVECTOR_DIR}/libvector.a

MODULES		=	${MLX_DIR} ${LIBFT_DIR} ${LIBVECTOR_DIR}

INCLUDE_DIR	=	./include
INCLUDE		=	${INCLUDE_DIR}/camera.h 	\
				${INCLUDE_DIR}/color.h		\
				${INCLUDE_DIR}/ray.h		\
				${INCLUDE_DIR}/server.h		\
				${INCLUDE_DIR}/scene.h		\
				${INCLUDE_DIR}/errcode.h	\
				${INCLUDE_DIR}/bitmap.h		\
				${INCLUDE_DIR}/figures.h

CC			=	clang
CC_FLAGS	=	-c					\
				-Wall				\
				-Wextra				\
				-Werror				\
				-I${MLX_DIR}		\
				-I${LIBFT_DIR}		\
				-I${LIBVECTOR_DIR}	\
				-I${INCLUDE_DIR}	\
				-g

LD_FLAGS	=	-L${LIBFT_DIR}		\
				-L${LIBVECTOR_DIR}	\
				-L${MLX_DIR}		\
				-lm					\
				-lft				\
				-lvector			\
				-lmlx_Linux			\
				-lXext				\
				-lX11

SRC_DIR	=	./src
SRC		= 	${SRC_DIR}/server.c			\
			${SRC_DIR}/ray.c			\
			${SRC_DIR}/bitmap.c			\
			${SRC_DIR}/camera.c			\
			${SRC_DIR}/color.c			\
			${SRC_DIR}/minirt.c			\
			${SRC_DIR}/render.c			\
			${SRC_DIR}/light.c			\
			${SRC_DIR}/sphere.c			\
			${SRC_DIR}/triangle.c		\
			${SRC_DIR}/square.c			\
			${SRC_DIR}/cylinder.c		\
			${SRC_DIR}/plane.c			\
			${SRC_DIR}/scene.c			\
			${SRC_DIR}/listen.c			\
			${SRC_DIR}/ascii.c			\
			${SRC_DIR}/errcode.c		\
			${SRC_DIR}/parser.c			\
			${SRC_DIR}/elements.c		\
			${SRC_DIR}/utils.c		\
			${SRC_DIR}/free.c


OBJ_DIR	=	./build
OBJ		=	$(patsubst ${SRC_DIR}/%.c, ${OBJ_DIR}/%.o, ${SRC})

all: $(NAME)

$(NAME): ${OBJ}
	$(CC) $^ $(LD_FLAGS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c ${LIBFT} ${LIBVECTOR} ${MLX}
	mkdir -p $(OBJ_DIR)
	$(CC) $(CC_FLAGS) $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	$(MAKE) -C $(MLX_DIR)

$(LIBVECTOR):
	$(MAKE) -C $(LIBVECTOR_DIR)

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
	./$(NAME) ./examples/board.rt

bonus: re
