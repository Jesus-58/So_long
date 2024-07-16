NAME	= so_long
CC = clang
CCFLAGS = -g -Wall -Wextra -Werror -Iinclude
GLFW = -ldl -lglfw -pthread -lm

LIBFT_PATH	= ./Libft
LIBFT = $(LIBFT_PATH)/libft.a

MLX_PATH	= ./MLX42/build
MLX = $(MLX_PATH)/libmlx42.a

PRINTF_PATH = ./Printf
PRINTF = $(PRINTF_PATH)/libftprintf.a

SRCS	= checks_2.c checks_3.c checks.c game.c images.c \
			main.c map_utils.c moves.c \

OBJS	= ${SRCS:.c=.o}
RM = rm -f
HEADERS	= -I ./includes -I ${MLX_PATH}/include/MLX42 -I ${LIBFT_PATH} -I ${PRINTF_PATH}


%.o: %.c
	@$(CC) $(CCFLAGS) -c $< -o $@ $(HEADERS)

$(NAME): $(LIBFT) $(PRINTF) $(MLX) $(OBJS)
	@$(CC) $(CCFLAGS) $(GLFW) $(HEADERS) $(OBJS) $(LIBFT) $(PRINTF) $(MLX) -o $(NAME)

$(LIBFT):
	@make -s -C $(LIBFT_PATH) all

$(PRINTF):
	@make -s -C $(PRINTF_PATH) all

$(MLX):
	@make -s -C ${MLX_PATH} all

all: libft ${NAME}

clean:
	@-$(RM) $(OBJS)
	@make -s -C $(LIBFT_PATH) clean
	@make -s -C $(PRINTF_PATH) clean

fclean:
	@-$(RM) $(OBJS)
	@-$(RM) $(NAME)
	@make -s -C $(LIBFT_PATH) fclean
	@make -s -C $(PRINTF_PATH) fclean
	
re: fclean all

.PHONY: all clean fclean re libft printf
