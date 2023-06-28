#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main ()
{
int min = -2147483648;
void *ptr;
ptr = &min;
ft_printf(" %p ",LONG_MIN);
printf(" \n");
printf(" %p ", LONG_MIN);
return 0;
}
