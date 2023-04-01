# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jonhan <jonhan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/30 15:24:33 by jonhan            #+#    #+#              #
#    Updated: 2023/03/30 21:28:47 by jonhan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = libftprintf.a
RM = rm -rf
AR = ar
ARFLAGS = crs
SRCS = ft_func.c ft_nbrbase.c ft_printf.c
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ 

clean : 
	$(RM) $(RMFLAG) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : 
	$(MAKE) fclean
	$(MAKE) all

.PHONY : all clean fclean re
                                              