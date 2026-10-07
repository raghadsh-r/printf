#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdio.h>
#include <limits.h>
int	ft_strlen(va_list ptr)
{
	char *stri;
	int	i;
	stri = va_arg(ptr, char *);
	i = 0;
	while (stri[i] != '\0')
		i++;
	write(1,stri, i);
	return (i);
}

void    ft_putnbr(long nb,int *c, char postive)
{
	char    b;

    c = 0;
	if (nb < 0)
	{
		nb *= -1;
        c++;
		write(1, "-", 1);
        postive = 0;
	}
    if(postive)
    {
        write(1,&postive,1);
        c++;
        postive = 0;
    }
	b = (nb % 10) + '0';
	if (nb >= 10)
	{
	    ft_putnbr(nb / 10,c,postive);
	}
    *c++;
	write(1, &b, 1);
}

void	ft_printf_hexa(long nb,char *str, int *c,char postive)
{
	int	    b;

	b = (nb % 16);
    if(postive)
    {
        if(str[15]=='f')
        write(1,"0x",2);
        else
        write(1,"0X",2);
        c+=2;
        postive = 0;
    }
	if (nb >= 16)
	{
		ft_printf_hexa(nb / 16,str ,c,postive);
	}
    (*c)++;
	write(1, &str[b], 1);
}

void	ft_printf_char(va_list ptr)
{
	char ch;
	ch = va_arg(ptr, int);
	write(1,&ch ,1);

}
char *print(char *str,  va_list ptr , int *c, int postive) 
{
    if(*str == 's')
        (*c) += ft_strlen(ptr);
    else if(*str=='i'||*str=='d')
    { 
        ft_putnbr(va_arg(ptr ,int),c,postive);
    }
    else if(*str=='c')
	{
        ft_printf_char(ptr);
		(*c)++;
	}
    else if(*str=='x')
		 ft_printf_hexa(va_arg(ptr,long), "0123456789abcdef",c,postive);
	else if(*str=='X')
        ft_printf_hexa(va_arg(ptr,long), "0123456789ABCDEF",c,postive);
    else if(*str == 'p')
	{
		write(1,"0x",2);
		ft_printf_hexa(va_arg(ptr,long),"0123456789abcdef",c,0);
        (*c) +=2;
    }
    else if(*str=='u')
		ft_putnbr(va_arg(ptr , unsigned),c,0);
    str++;
    return (str);
}

int ft_print(const char *str, ...)
{
    va_list ptr;
    va_start(ptr,str);
    int c;
    char chp  = '+';
    char chs  = ' ';
    char chh  = '#';
    c = 0;
    while (*str != '\0')
	{
        if(*str == '%' && *(str + 1) != '%')
        {
            str++;
            if(*str == '+')
            {
                str++;
                str = print((char *)str, ptr , &c,chp);
            }
            else if(*str == ' ')
            {
                str++;
                str = print((char *)str, ptr , &c,chs);
            }
            else if(*str == '#')
            {
                str++;
                str = print((char *)str, ptr , &c,chh);
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
    printf("%#X%i\n",x,y);
    ft_print("%#X%i\n",x,y);
}
