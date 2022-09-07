
NAME = philo
cc = gcc
RM = rm -rf
flags = -Wall -Wextra -Werror
sources = finish.c \
		  functions_utils.c \
		  parse.c \
		  main.c \
		  routine.c \
		  init_create.c \
		  check_death.c \

objects = $(sources:.c=.o)

all : $(NAME)

$(NAME) : $(objects)
	$(cc) $(flags) $(objects) -o $(NAME)

%.o : %.c philo.h
	$(cc) $(flags) -c $^ 

clean :
	$(RM) $(objects)

fclean : clean
	$(RM) $(NAME)

re : fclean all
