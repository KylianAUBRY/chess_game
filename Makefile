NAME	=	chess

LIBDIR = ./minilibx-linux

SRCS	=	main.c	\
			adieux.c \
			error.c \
			edge.c \
			img.c \
			init.c \
			draw.c \
			case_int.c \
			check/check_black.c \
			check/check_white.c \
			check/look_check.c \
			promotion.c \
			piece/wpawn.c \
			piece/bpawn.c \
			piece/wbisho.c \
			piece/bbisho.c \
			piece/wrook.c \
			piece/brook.c \
			piece/wqueen.c \
			piece/bqueen.c \
			piece/wknight.c \
			piece/bknight.c \
			piece/wking.c \
			piece/bking.c \

OBJ =	${SRCS:.c=.o}

CC =	cc

CFLAGS	=	-Wall -Wextra -Werror -pthread -g

.c.o:
			$(CC) $(CFLAGS) -Iminilibx-linux  -Imlx_linux -c $< -o $(<:.c=.o)

$(NAME): ${OBJ}
		$(CC) ${CFLAGS} ${OBJ} -Iminilibx-linux minilibx-linux/libmlx_Linux.a -lXext -lX11 -lm -lz -o $(NAME) 
#-L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
all:	${NAME}

clean:
		rm -f ${OBJ}

fclean:	clean
		rm -f ${NAME}
		
re:	fclean all

.PHONY: all clean fclean re
