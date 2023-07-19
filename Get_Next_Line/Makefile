# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kokada <kokada@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/17 16:39:46 by kokada            #+#    #+#              #
#    Updated: 2023/07/19 14:36:26 by kokada           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libgnl.a
SRCS = get_next_line.c get_next_line_utils.c
OBJS	=	$(SRCS:.c=.o)

all: ${NAME}

.c.o:
	cc -Wall -Wextra -Werror -c $< -o $@

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