HEADER			=	includes/minishell.h

NAME			=	minishell

MAIN			=	main.c

RDL_DIR			=	/Users/yongmiki/.brew/opt/readline/

SRCS			=	srcs/ft_lstfuncs.c\
					srcs/ft_cmd_lstfuncs.c\
					srcs/ft_wc_strcmp.c\
					srcs/ft_remove_quotes.c\
					srcs/ft_getenv.c\
					srcs/ft_init_vars.c\
					srcs/ft_handle_signals.c\
					srcs/ft_tokenization.c\
					srcs/ft_verify_syntax.c\
					srcs/ft_parse_cmds.c\
					srcs/ft_split_args.c\
					srcs/ft_expand_env_vars.c\
					srcs/ft_expand_wildcards.c\
					srcs/exec.c\
					srcs/exec_cmds.c\
					srcs/exec_pipes.c\
					srcs/exec_redirections.c\
					srcs/exec_heredoc.c\
					srcs/exec_tools.c\
					srcs/exec_builtin.c\
					srcs/exec_echo.c\
					srcs/exec_pwd.c\
					srcs/exec_cd.c\
					srcs/exec_env.c\
					srcs/exec_export.c\
					srcs/exec_export_print.c\
					srcs/exec_unset.c\
					srcs/exec_exit.c\
					srcs/ft_free_program.c

OBJS			=	$(SRCS:.c=.o)\
					$(MAIN:.c=.o)

LIBFT			=	./Libft

LIB				=	./Libft/libft.a

CC				=	gcc

CFLAGS			=	-Wall -Wextra -Werror

RM				=	rm -f

INCS			=	-Iincludes/ -I$(LIBFT) -I$(RDL_DIR)include/

%.o:%.c			$(HEADER) 
				$(CC) $(CFLAGS) $(CPPFLAGS)  -c $< -o $@ $(INCS) 

$(NAME):		$(HEADER) $(LIB) $(OBJS)
				$(CC) $(INCS) $(CFLAGS) $(OBJS) $(LIB) -o $(NAME) -L$(RDL_DIR)lib/ -lreadline $(LDFLAGS)

all:			$(NAME)

$(LIB):
				make -C $(LIBFT)

clean:
				$(RM) $(OBJS)
				make clean -C Libft

fclean:			clean
				$(RM) $(NAME)
				make fclean -C Libft

re:				fclean all

.PHONY:			all clean fclean re
