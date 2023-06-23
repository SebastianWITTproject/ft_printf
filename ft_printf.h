#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_print_hex(unsigned int num, const char caps);
int	calc_hex_len(unsigned	int num);
int	ft_formats(va_list args, const char format);
int	ft_printf(const char *str, ...);
char	*ft_itoa(int nbr);
void	ft_putnbr_base(int nbr, char *base);
int	ft_printnbr(int n);
int	percent(void);
char	*ft_un_itoa(unsigned int nbr);
int	ft_print_unsigned(unsigned int nbr);
int	ft_print_ptr(void *ptr);
int	calc_ptr_len(unsigned long num);
int	printstr(char *str);
int printchar(int c);

#endif
