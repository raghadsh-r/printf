/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralshraw <ralshraw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 10:46:03 by ralshraw          #+#    #+#             */
/*   Updated: 2026/10/08 11:20:22 by ralshraw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


void	ft_printf_char(va_list ptr)
{
	char	ch;

	ch = va_arg(ptr, int);
	write(1, &ch, 1);
}

int	printff(const char *str, va_list ptr)
{
	int		c;
	char	*ch;

	ch = "+ #";
	c = 0;
	while (*str != '\0')
	{
		if (*str == '%')
		{
			str++;
			if (*str == '+')
				str = print((char *)++str, ptr, &c, ch[0]);
			else if (*str == ' ')
				str = print((char *)++str, ptr, &c, ch[1]);
			else if (*str == '#')
				str = print((char *)++str, ptr, &c, ch[2]);
			else if (*str == '%')
				c += write(1, str++, 1);
			else
				str = print((char *)str, ptr, &c, 0);
		}
		else
			c += write(1, str++, 1);
	}
	return (c);
}

int	ft_printf(const char *str, ...)
{
	va_list	ptr;
	int		count;

	if (!str)
		return (-1);
	va_start(ptr, str);
	count = printff(str, ptr);
	return (count);
}

// int main(void)
// {   
// ft_printf("Value: %+d%\n", 42);
// ft_printf("\nValue: % d%\n", 42);
// ft_printf("\nValue: %+d%\n", -42);
// printf("\nValue: %+d%\n", 42);
// printf("\nValue: % d%\n", 42);
// printf("\nValue: %+d%\n", -42);
// }