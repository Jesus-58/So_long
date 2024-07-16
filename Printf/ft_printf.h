/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesumore <jesumore@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:07:02 by jesumore          #+#    #+#             */
/*   Updated: 2024/02/26 21:19:12 by jesumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdint.h>

int		ft_putchar(int c);
int		ft_putstr(char *s);
int		ft_putnbr(int n);
int		ft_putunbr(unsigned int n);
int		ft_puthex_minus(unsigned int n);
int		ft_puthex_mayus(unsigned int n);
int		ft_putptr(void *ptr);
int		ft_printf(char const *format, ...);

#endif
