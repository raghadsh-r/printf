/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_fun.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralshraw <ralshraw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 09:50:21 by ralshraw          #+#    #+#             */
/*   Updated: 2026/10/08 11:26:01 by ralshraw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(va_list ptr)
{
	char	*stri;
	int		i;

	stri = va_arg(ptr, char *);
	if (!stri)
	{
		write(1, "(null)", 6);
		return (6);
	}
	i = 0;
	while (stri[i] != '\0')
		i++;
	write(1, stri, i);
	return (i);
}

void	ft_putnbr(long nb, int *c, char postive)
{
	char	b;

	if (nb < 0)
	{
		nb *= -1;
		(*c)++;
		write(1, "-", 1);
		postive = 0;
	}
	if (postive)
	{
		write(1, &postive, 1);
		(*c)++;
		postive = 0;
	}
	b = (nb % 10) + '0';
	if (nb >= 10)
	{
		ft_putnbr(nb / 10, c, postive);
	}
	(*c)++;
	write(1, &b, 1);
}

void	ft_printf_hexa(unsigned long nb, char *str, int *c, char postive)
{
	int	b;

	b = (nb % 16);
	if (postive)
	{
		if (str[15] == 'f')
			write(1, "0x", 2);
		else
			write(1, "0X", 2);
		(*c) += 2;
		postive = 0;
	}
	if (nb >= 16)
	{
		ft_printf_hexa(nb / 16, str, c, postive);
	}
	(*c)++;
	write(1, &str[b], 1);
}

void	ft_printf_pointer(va_list ptr, int *c)
{
	void	*ptr_val;

	ptr_val = va_arg(ptr, void *);
	if (!ptr_val)
	{
		write(1, "(nil)", 5);
    	(*c) += 5;
	}
	else
	{
		write(1, "0x", 2);
		(*c) += 2;
		ft_printf_hexa((unsigned long)ptr_val, "0123456789abcdef", c, 0);
    }
}

char	*print(char *str, va_list ptr, int *c, int postive)
{
	if (*str == 's')
		(*c) += ft_strlen(ptr);
	else if (*str == 'i' || *str == 'd')
	{
		ft_putnbr(va_arg(ptr, int), c, postive);
	}
	else if (*str == 'c')
	{
		ft_printf_char(ptr);
		(*c)++;
	}
	else if (*str == 'x')
		ft_printf_hexa(va_arg(ptr, unsigned int), "0123456789abcdef", c, postive);
	else if (*str == 'X')
		ft_printf_hexa(va_arg(ptr, unsigned int), "0123456789ABCDEF", c, postive);
	else if (*str == 'p')
		ft_printf_pointer(ptr, c);
	else if (*str == 'u')
		ft_putnbr(va_arg(ptr, unsigned int), c, 0);
	str++;
	return (str);
}
