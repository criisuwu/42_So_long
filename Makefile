NAME = #nombre del archivo <archivo.a>
BONUS_NAME = .bonus

SRCS = #Aqui pongo todos los archivos que vaya a usar
#		y compilar con el makefile
BONUS = #Lo mismo va para el bonus, aqui van todos los
#		archivos para compilar con el makefile
OBJS = $(SRCS:.c=.o) #Esto transforma los .c en .o
BONUS_OBJS = $(BONUS:.c=.o) #Esto tambien transforma los .c en .o
CC = gcc #Para la compilacion
CFLAGS = -Wall -Werror -Wextra #Las flags con las que quiero compilar
RM = rm -f # para borrar los archivos que se creen con el makefile

all: %(NAME) #Esto hace que se aplique a todo
$(NAME) = $(OBJECT)