NAME = cub3D

SRCS =	./main.c\
		srcs/parsing/ft_get_params.c \
		srcs/parsing/ft_colors.c \
		srcs/parsing/ft_resolution.c\
		srcs/parsing/ft_textures.c \
		srcs/parsing/ft_init_params.c \
		srcs/parsing/ft_map_checker.c \
		srcs/parsing/ft_param_checker.c \
		srcs/ray_casting/ft_start_game.c \
		srcs/ray_casting/ft_cast_scene.c\
		srcs/ray_casting/ft_sprite.c\
		srcs/ray_casting/ft_raycasting_utils.c\
		srcs/ray_casting/ft_pixel.c\
		srcs/ft_init.c \
		srcs/ft_exit.c\
		srcs/ft_screenshot.c\
		srcs/ft_no_leaks.c\
		srcs/event/ft_keys_init_utils.c\
		srcs/event/ft_keys_init.c\

OBJS=		${SRCS:.c=.o}
HEAD=		-I includes -I libft/includes -I minilibx
CC=			gcc
CFLAGS=		-Wall -Werror -Wextra
LIBFT_DIR=	libft
MLX_DIR=	mlx
LDFLAGS=	-L ${LIBFT_DIR} -L ${MLX_DIR}
LIBS=		-lm -lft -lmlx -lXext -lX11
DEFINE_DEFAULT= -D PROJECT_NAME="${NAME}"

%.o:%.c
		${CC} ${CFLAGS} ${HEAD} -c $< -o ${<:.c=.o}
$(NAME):	${OBJS}
		make -C ${LIBFT_DIR}
		make -C ${MLX_DIR}
		${CC} ${CFLAGS} ${LDFLAGS} ${DEFINE_DEFAULT} ${OBJS} -o ${NAME} ${LIBS}
all:	${NAME}

clean:
		rm -rf ${OBJS}
		make clean -C ${LIBFT_DIR}
		make clean -C ${MLX_DIR}
fclean:	clean
		rm -rf ${NAME}
		make fclean -C ${LIBFT_DIR}
		rm -rf screenshot.bmp
re:	fclean all
.PHONY:	all clean fclean re
