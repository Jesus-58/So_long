/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesumore <jesumore@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 21:21:25 by jesumore          #+#    #+#             */
/*   Updated: 2024/03/04 17:21:24 by jesumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *ptr)
{
	uintptr_t	n;
	int			count;
	char		*base;

	n = (uintptr_t)ptr;
	count = 0;
	base = "0123456789abcdef";
	if (n >= 16)
	{
		count += ft_putptr((void *)(n / 16));
		count += ft_putptr((void *)(n % 16));
	}
	else
		count += ft_putchar(base[n]);
	return (count);
}
