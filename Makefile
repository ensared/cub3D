NAME = Cub3D
LIBDIR = ./Libft
LIB = ./Libft/libft.a
GNLDIR = ./Libft/get_next_line

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

SRCS = 	src/*.c
INCS = 	library/*.h

# OBJS = $(SRCS:%.c=%.o)

all : $(NAME)

$(NAME) : $(OBJS)
	make -C $(LIBDIR)
	$(CC)  $(SRCS) -o $(NAME) $(LIB) $(GNLDIR)

# %.o: src/%.c $(INCS)
# 	$(CC) $(CFLAGS) -c $< -o $@

clean :
	make fclean -C $(LIBDIR)
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
