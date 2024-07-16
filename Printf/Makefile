NAME= libftprintf.a

CC= gcc

CFLAGS= -Wall -Wextra -Werror

RM= rm -f

SRCS =	ft_printf.c ft_putunbr.c ft_putchar.c ft_puthex_mayus.c \
        ft_puthex_minus.c ft_putnbr.c ft_putptr.c ft_putstr.c \
				
								
OBJS = $(SRCS:.c=.o) 

$(NAME) : $(OBJS)
	@ar crs $(NAME) $(OBJS) 

all: $(NAME)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean
