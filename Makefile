NAME		=	fdf

LIBFT		=	./libft/
GNL			=	./Get_Next_Line/
MLX			=	./minilibx_macos/
LIBFT_A		=	./libft/libft.a
GNL_A		=	./Get_Next_Line/libgnl.a
MLX_A		=	./minilibx_macos/libmlx.a

CC			=	gcc
INCLUDE 	=	./includes
CFLAGS		=	-g -I$(INCLUDE)# -Wall -Wextra -Werror 
SRCS		=	$(wildcard srcs/*.c)

OBJS		=	$(SRCS:%.c=%.o)

all:			$(NAME)

$(NAME):		$(OBJS) $(LIBFT_A) $(GNL_A) $(MLX_A)
				$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT) -lft -L$(GNL) -lgnl -L$(MLX) -lmlx -o $(NAME) -framework OpenGL -framework AppKit

$(LIBFT_A):
				$(MAKE) -C $(LIBFT)

$(GNL_A):
				$(MAKE) -C $(GNL)

$(MLX_A):
				$(MAKE) -C $(MLX)

.c.o:
				$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

localclean:
				$(RM) $(OBJS)

clean:			localclean
				$(MAKE) clean -C $(LIBFT)
				$(MAKE) clean -C $(GNL)
				$(MAKE) clean -C $(MLX)

fclean:			localclean
				$(MAKE) fclean -C $(LIBFT)
				$(MAKE) fclean -C $(GNL)
				$(MAKE) clean -C $(MLX)
				$(RM) $(NAME)

re:				fclean all

test: $(NAME)
	@echo "Running tests on .fdf files..."
	@for f in test_maps/*.fdf; do \
		echo "run: $$f"; \
		./$(NAME) $$f; \
	done
	@echo "All tests completed."

.PHONY: all clean fclean re localclean test

.PHONY:			all clean fclean re localclean test