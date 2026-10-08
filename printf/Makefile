NAME = libftprintf.a  
CC = cc
CFLAG = -Wall -Werror -Wextra 
AR = ar arc 
SRCS = ft_printf.c  ft_printf.h  helper_fun.c
OBJS = $(SRCS:.c=.o)
HEADER = ft_printf.h
PATH = ../libft


all = $(NAME)


%.o = %.c $(HEADER)
	$(CC) $(CFLAG) -c $<


$(NAME) : $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean :
	rm -f $(OBJC)

fclean : clean
	rm -f $(NAME) 

rm : all fclen


.PHONY : clean re fclean 
