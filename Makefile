FLAGS = -Wall -Werror -Wextra

CFILES = ft_printf.c \
			func_list.c \
			convert_hex.c \
			ft_putnbr_base.c \
			ft_itoa.c \

OFILES = $(CFILES:%.c=%.o)

NAME = printf.a

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
