# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kokada <kokada@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/17 16:39:46 by kokada            #+#    #+#              #
#    Updated: 2023/05/25 21:19:31 by kokada           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a
SRCS =	ft_strlen.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strnstr.c \
		ft_strncmp.c \
		ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memchr.c \
		ft_memmove.c \
		ft_memcmp.c \
		ft_atoi.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c\
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c
B_SRCS=	ft_lstnew.c \
	 ft_lstadd_front.c \
	 ft_lstsize.c \
	 ft_lstlast.c \
	 ft_lstadd_back.c \
	 ft_lstdelone.c \
	 ft_lstclear.c \
	 ft_lstiter.c \
	 ft_lstmap.c
INCLUDE = libft.h
OBJS	=	$(SRCS:.c=.o)
B_OBJS	=	$(B_SRCS:.c=.o)

all: ${NAME}

.c.o:
	cc -Wall -Wextra -Werror -c -I $(INCLUDE) $< -o $@

clean:
		rm -f $(OBJS) $(B_OBJS)

fclean:	clean
		$(RM)	$(NAME)

re:		fclean	all

$(NAME): $(OBJS)
		ar rcs $(NAME) $(OBJS)

bonus: $(B_OBJS)
		ar rcs $(NAME) $(B_OBJS)

.PHONY:	all clean fclean re bonus