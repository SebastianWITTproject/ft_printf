FLAGS = -Wall -Werror -Wextra

CFILES = ft_printf.c \
			func_list.c \
			convert_hex.c \
			ft_putnbr_base.c \
			ft_itoa.c \
			unsigned.c \
			ft_print_ptr.c \

OFILES = $(CFILES:%.c=%.o)

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OFILES)
	ar -rcs $(NAME) $(OFILES)

$(OFILES): $(CFILES)
	cc $(FLAGS) -c $(CFILES) -I.
	
clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all 
