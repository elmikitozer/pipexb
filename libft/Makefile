GREEN = \033[0;32m
YELLOW = \033[0;33m
CYAN = \033[1;36m
RED = \033[0;31m
END = \033[0m

LIBC =	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
		ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c \
		ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c \
		ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c \
		ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c ft_strcmp.c

ADDITIONAL =	ft_itoa.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
				ft_split.c ft_strjoin.c ft_strmapi.c ft_strtrim.c ft_substr.c ft_striteri.c

BONUS =	ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c \
		ft_lstdelone.c ft_lstiter.c ft_lstlast.c \
		ft_lstmap.c ft_lstnew.c ft_lstsize.c

SRCS = ${LIBC} ${ADDITIONAL}

SRCSALL = ${LIBC} ${ADDITIONAL} ${BONUS}

OBJS = ${SRCS:.c=.o}

OBJSALL = ${SRCSALL:.c=.o}

LIB = libft.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra -I ./

.c.o:
		@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${LIB}:	${OBJS}
		@ar -rsc ${LIB} ${OBJS}
		@echo "\n$(GREEN)Libft library compiled successfully$(END)"

bonus:	${OBJSALL}
		@ar -rsc ${LIB} ${OBJSALL}
		@echo "$(CYAN)Libft bonus parts compiled successfully$(END)"

all: 	${LIB}

clean:
		@rm -f ${OBJSALL}
		@echo "$(YELLOW)Object files cleaned$(END)"

fclean:	clean
		@rm -f ${LIB}
		@echo "$(YELLOW)Library file cleaned$(END)"

re:	fclean all

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRCSALL)
	gcc -nostartfiles -shared -o libft.so $(OBJSALL)

.PHONY: all clean fclean re bonus
