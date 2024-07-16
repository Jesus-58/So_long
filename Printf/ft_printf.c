/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesumore <jesumore@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 21:30:21 by jesumore          #+#    #+#             */
/*   Updated: 2024/03/04 17:22:31 by jesumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	select_format(char type, va_list args)
{
	int	count_chr;

	count_chr = 0;
	if (type == 'c')
		count_chr += ft_putchar(va_arg(args, int));
	else if (type == '%')
		return (write(1, "%", 1));
	else if (type == 's')
		count_chr += ft_putstr(va_arg(args, char *));
	else if (type == 'd' || type == 'i')
		count_chr += ft_putnbr(va_arg(args, int));
	else if (type == 'u')
		count_chr += ft_putunbr(va_arg(args, unsigned int));
	else if (type == 'x')
		count_chr += ft_puthex_minus(va_arg(args, unsigned int));
	else if (type == 'X')
		count_chr += ft_puthex_mayus(va_arg(args, unsigned int));
	else if (type == 'p')
	{
		count_chr += ft_putstr("0x");
		count_chr += ft_putptr(va_arg(args, void *));
	}
	return (count_chr);
}

int	ft_printf(char const *format, ...)
{
	int		total_chr;
	va_list	args;

	if (write(1, "", 0) == -1)
		return (-1);
	total_chr = 0;
	va_start(args, format);
	if (!format)
		return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			total_chr += select_format(*format, args);
			format++;
		}
		else
		{
			total_chr += write(1, format, 1);
			format++;
		}
	}
	va_end(args);
	return (total_chr);
}
/*
int	main()
{
	int i = 12;
	int u = -12;
	char a = 'z';
	char *s = "jesus";
	printf("la letra es %c\nEl string es %s\n, a, s);
	printf("El numero es %i\nEl unsignednum es %u\n", i, u);
	ft_printf("la letra es %c\nEl string es %s\n, a, s);
	ft_printf("El numero es %i\nEl unsignednum es %u\n", i, u);
	printf("\001\002\007\v\010\f\r\n");
	ft_printf("\001\002\007\v\010\f\r\n");
	return(0);
}*/