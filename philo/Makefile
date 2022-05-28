NAME = philo

HEADER = philo.h

SRC = philo.c Utils/ft_atoi.c Utils/get_argument.c Utils/utils1.c Utils/utils2.c Utils/utils3.c Utils/utils4.c\
	
OBJ = ${SRC:.c=.o}

CFLAGS = -Wall -Wextra -Werror


CC = gcc

all : $(NAME)

$(NAME) : $(OBJ) $(HEADER)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -lpthread

clean : 
	@rm -f $(OBJ)

fclean : clean 
	@rm -rf $(NAME)

re : fclean all