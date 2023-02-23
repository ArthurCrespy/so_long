# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/09 14:54:39 by acrespy           #+#    #+#              #
#    Updated: 2023/01/16 15:01:53 by acrespy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        := so_long

SRC_DIR     := srcs
SRCS := \
			args_check.c \
			exit.c \
			free.c \
			ft_flood_fill.c \
			ft_get_next_line.c \
			ft_put.c \
			ft_split.c \
			ft_strjoin.c \
			ft_utils.c \
			game_collectibles.c \
			game_exit.c \
			game_moves.c \
			game_position.c \
			main.c \
			map_check.c \
			map_checker_content.c \
			map_checker_path.c \
			map_checker_struct.c \
			map_open.c \
			map_open_file.c \
			map_open_objects.c \
			mlx_initialize.c \
			mlx_run.c \

SRCS := ${SRCS:%=${SRC_DIR}/%}

OBJ_DIR     := .objs
OBJS := ${SRCS:${SRC_DIR}/%.c=${OBJ_DIR}/%.o}

CC          := clang
CFLAGS      := -Wall -Wextra -Werror -g

RM          := rm -f
MAKEFLAGS   += --no-print-directory
DIR_DUP     = mkdir -p ${@D}

all: miniLibX ${NAME}

miniLibX:
	${MAKE} -C mlx_linux

${NAME}: ${OBJS}
	${CC} ${OBJS} -Lmlx_linux -lmlx_Linux -L./mlx_linux -Imlx_linux -lXext -lX11 -lm -lz -o ${NAME}
	${info EXECUTABLE CREATED: ${NAME}}


${OBJ_DIR}/%.o: ${SRC_DIR}/%.c
	${DIR_DUP}
	${CC} ${CFLAGS} -c -o $@ $<
	${info OBJECT CREATED: $@}

clean:
	${RM} ${OBJS}
	${info REMOVED OBJECTS: ${OBJS}}

fclean: clean
	${RM} ${NAME}
	${info REMOVED EXECUTABLES: ${NAME}}

re:
	${MAKE} fclean
	${MAKE} all

.PHONY: clean fclean re
.SILENT: ${OBJS} ${OBJS_CLIENT} ${NAME} ${NAME_CLIENT} clean fclean re