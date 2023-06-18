#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printstr(char *str);
int printchar(int c);
int	ft_print_hex(unsigned int num, const char caps);
int	calc_hex_len(unsigned	int num);
int	ft_formats(va_list args, const char format);
int	ft_printf(const char *str, ...);
char	*ft_itoa(int n);
void	ft_putnbr_base(int nbr, char *base);
int	ft_printnbr(int n);

#endif
