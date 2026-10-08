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

int	ft_print(const char *str, ...)
{   
	va_list	ptr;
    int		c;
	char	*ch;

	ch = "+ #";
	va_start(ptr, str);
    c = 0;
	while (*str != '\0')
	{
		if(*str == '%' && *(str + 1) != '%')
		{
			str++;
			if(*str == '+')
			{
				str++;
				str = print((char *)str, ptr , &c, ch[0]);
			}
			else if (*str == ' ')
			{
				str++;
				str = print((char *)str, ptr , &c,ch[1]);
			}
			else if(*str == '#')
			{
				str++;
				str = print((char *)str, ptr , &c,ch[2]);
            }
            else  
				str = print((char *)str, ptr , &c,0);
		}
		else
		{   
			write(1,str,1);
			str++;
			c++;
		}
	}
    return (c);
}

int main(void)
{   
    int x, y;
    x = printf("hi raghad alsharawneh\n");
    y = ft_print("hi raghad alsharawneh\n");
    x = 8;
    printf("%+i%i\n",x,y);
    ft_print("%+i%i\n",x,y);
}
