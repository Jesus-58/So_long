/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_mayus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesumore <jesumore@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 21:14:39 by jesumore          #+#    #+#             */
/*   Updated: 2024/03/04 17:21:06 by jesumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_mayus(unsigned int n)
{
	int		count;
	char	*base;

	count = 0;
	base = "0123456789ABCDEF";
	if (n >= 16)
	{
		count += ft_puthex_mayus(n / 16);
		count += ft_puthex_mayus(n % 16);
	}
	else
		count += ft_putchar(base[n]);
	return (count);
}
