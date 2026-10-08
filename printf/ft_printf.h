/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralshraw <ralshraw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 09:41:53 by ralshraw          #+#    #+#             */
/*   Updated: 2026/10/08 11:05:15 by ralshraw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdio.h>
# include <limits.h>

int     ft_strlen(va_list ptr);
void    ft_putnbr(long nb,int *c, char postive);
void	ft_printf_hexa(long nb,char *str, int *c,char postive);
char    *print(char *str,  va_list ptr , int *c, int postive);
int     ft_print(const char *str, ...);
#endif
