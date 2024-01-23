DARKBLUE = \033[34;5m
GREEN = \033[0;32m
YELLOW = \033[0;33m
CYAN = \033[1;36m
RED = \033[0;31m
END = \033[0m


NAME			=	pipex

LIBFT			=	libft.a

DIR_SRCS		=	srcs/

DIR_BONUS		=	srcs/bonus

DIR_OBJS		=	objs

SRCS_NAMES		=	main.c  ft_split.c utils.c get_next_line.c get_next_line_utils.c

SRCS_NAMES_B	=	main.c  misc.c	fork.c 	utils.c

OBJS_NAMES		=	${SRCS_NAMES:.c=.o}

OBJS_NAMES_B	=	${SRCS_NAMES_B:.c=.o}

SRCS			=	$(addprefix $(DIR_SRCS)/,$(SRCS_NAMES))

SRCS_B			=	$(addprefix $(DIR_BONUS)/,$(SRCS_NAMES_B))

OBJS			=	$(addprefix $(DIR_OBJS)/,$(OBJS_NAMES))

HEAD			=	-Ilibft/includes -Iincludes

CC				=	cc

CFLAGS			=	-g3 -Wall -Werror -Wextra

MAKEFLAGS		=	--no-print-directory

TOTAL_FILES := $(words $(SRCS_NAMES))

CURRENT_FILES = $(shell ls $(DIR_OBJS)/*.o 2> /dev/null | wc -l | xargs)

all				:	${NAME}

define progress_bar
	@$(eval PERCENT=$(shell echo $$((($(CURRENT_FILES) + 1) * 100 / $(TOTAL_FILES)))))
	@printf "["
	@printf "%-50s" "$$(for i in `seq 1 $$(($(PERCENT) / 4))`; do printf "🟩"; done)"
	@printf "] %d%%\r" $(PERCENT)
endef

$(NAME): $(OBJS)
	@make -C libft
	@echo "\n"
	@mv libft/libft.a .
	@$(CC) $(CFLAGS) $(OBJS) ${LIBFT} ${HEAD} -o $(NAME)
	@echo "${GREEN}Pipex was successfuly compiled 🎉${END}"

$(DIR_OBJS)/%.o: $(DIR_SRCS)/%.c | $(DIR_OBJS)
	@$(CC) $(CFLAGS) -c $< -o $@ $(HEAD)
	$(call progress_bar)

$(DIR_OBJS):
	@mkdir -p $(DIR_OBJS)

bonus:
	make -C libft
	mv libft/libft.a .
	$(CC) $(CFLAGS) $(SRCS_B) ${LIBFT} ${HEAD} -o $(NAME)
	@echo "\033[39;5mpipex bonus\033[0m"

clean:
	@make clean -C libft
	@rm -rf ${DIR_OBJS}
	@rm -rf ${OBJS}

fclean:	clean
	@make fclean -C libft
	@rm -rf ${LIBFT}
	@rm -rf ${NAME}

re:	fclean all

stop:
	rm -f ${NAME}

.PHONY:	all clean fclean re bonus
# .SILENT:
