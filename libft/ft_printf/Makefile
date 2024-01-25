NAME = libftprintf.a

SRC = ft_putcharrt.c ft_putstrrt.c ft_putvoidpt.c ft_itoa.c ft_strlen.c ft_printf.c ft_uitoa.c ft_printhexbase.c ft_countvoid.c

SRCS_DIR = ./sources/

SRCS =		$(addprefix $(SRCS_DIR), $(SRC))

HEADER_DIR = ./includes/

CC = cc

FLAGS = -Wall -Wextra -Werror

OBJS = ${SRCS:.c=.o}

.c.o:
		${CC} ${FLAGS} -I $(HEADER_DIR) -c $< -o ${<:.c=.o}

all:	${NAME}

${NAME}:	${OBJS}
			ar rc ${NAME} ${OBJS}
			ranlib ${NAME}

clean:
			rm -f ${OBJS}
			@echo "ft_printf object files cleaned!"

fclean:		clean
			rm -f ${NAME}
			@echo "ft_printf executable files cleaned!"

re:			fclean all
			@echo "Cleaned and rebuilt everything for ft_printf!"

.PHONY:		all clean fclean re
# OBJS		= ${SRCS:.c=.o}

# CC			= cc
# RM			= rm -f
# AR			= ar rc
# RN			= ranlib
# HEADER_DIR	= ./includes/

# CFLAGS 		= -Wall -Wextra -Werror


# .c.o:
# 			${CC} ${CFLAGS} -I ${HEADER_DIR} -c $< -o ${<:.c=.o}

# $(NAME): ${OBJS}
# 			${AR} ${NAME} ${OBJS}
# # ${RN} ${NAME}

# all:$(NAME)

# clean:
# 			${RM} ${OBJS}

# fclean: clean
# 			${RM} $(NAME)

# re: fclean all

# .PHONY: all clean fclean re


# $(OBJS): $(SRCS:.c=.o)

# AR = 	ar rc


# CFLAGS = -Wall -Wextra -Werror

# CC = gcc

# .c.o:
# 		$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

# $(NAME):	$(OBJS)
# 		$(AR) $(NAME) $(OBJS)

# all:	${NAME}

# clean:
# 		rm -f ${OBJS}

# fclean:	clean;
# 		rm -f ${NAME}

# re:	fclean all

# .PHONY: all clean fclean re bonus

