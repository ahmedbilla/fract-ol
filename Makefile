# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahbilla <ahbilla@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/25 21:53:47 by ahbilla           #+#    #+#              #
#    Updated: 2025/02/08 17:55:50 by ahbilla          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = src/fractol.c src/window/init.c src/utils/ft_putstr.c src/parsing/user_interface.c\
	src/utils/ft_strcmp.c src/window/close_window.c src/fractals/julia.c src/fractals/mandelbrot.c\
	src/window/controler.c src/utils/ft_atoi.c src/fractals/get_color.c src/fractals/get_x_y.c\
	src/fractals/put_pixel.c

	
	
	

OBJS = ${SRCS:.c=.o}
NAME = fractol
CC = cc
RM = rm -f
# CFLAGS = -Wall -Wextra -Werror 

all: ${NAME}

	@echo "\n"
	@echo "  █████▒██▀███   ▄▄▄       ▄████▄  ▄▄▄█████▓ ▒█████   ██▓    "
	@echo "▓██   ▒▓██ ▒ ██▒▒████▄    ▒██▀ ▀█  ▓  ██▒ ▓▒▒██▒  ██▒▓██▒    "
	@echo "▒████ ░▓██ ░▄█ ▒▒██  ▀█▄  ▒▓█    ▄ ▒ ▓██░ ▒░▒██░  ██▒▒██░    "
	@echo "░▓█▒  ░▒██▀▀█▄  ░██▄▄▄▄██ ▒▓▓▄ ▄██▒░ ▓██▓ ░ ▒██   ██░▒██░    "
	@echo "░▒█░   ░██▓ ▒██▒ ▓█   ▓██▒▒ ▓███▀ ░  ▒██▒ ░ ░ ████▓▒░░██████▒"
	@echo " ▒ ░   ░ ▒▓ ░▒▓░ ▒▒   ▓▒█░░ ░▒ ▒  ░  ▒ ░░   ░ ▒░▒░▒░ ░ ▒░▓  ░"
	@echo " ░       ░▒ ░ ▒░  ▒   ▒▒ ░  ░  ▒       ░      ░ ▒ ▒░ ░ ░ ▒  ░"
	@echo " ░ ░     ░░   ░   ░   ▒   ░          ░      ░ ░ ░ ▒    ░ ░   "
	@echo "          ░           ░  ░░ ░                   ░ ░      ░  ░"
	@echo "                          ░                                   "

%.o:%.c include/fractol.h
	${CC} ${CFLAGS} -Imlx -c $< -o $@

# ${NAME}: ${OBJS}
# 	${CC} ${CFLAGS} $(OBJS) -o game
$(NAME): $(OBJS)
	$(CC) $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	


clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY : clean