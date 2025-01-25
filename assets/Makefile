SRCS = game.c


	
	
	

OBJS = ${SRCS:.c=.o}
NAME = game
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

all: ${NAME}

%.o:%.c 
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