# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ipresno- <ipresno-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/22 14:23:01 by ipresno-          #+#    #+#              #
#    Updated: 2022/12/22 14:23:02 by ipresno-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= pipex
PROG	= pipex

SRCS 	= pipex.c utils.c
SRCS_F 	= sources/
OBJS 	= ${SRCS:.c=.o}
OBJS_F	= obj/
MAIN	= sources/pipex.c

LIBFT_A = libft.a
LIBF_DIR = Libft/
LIBFT  = $(addprefix $(LIBF_DIR), $(LIBFT_A))

HEADER	= -I./includes/

CC 		 = gcc
CFLAGS 	 = -Wall -Wextra -Werror -g

NONE='\033[0m'
GREEN='\033[32m'
GRAY='\033[2;37m'
CURSIVE='\033[3m'
RED='\x1b[31m'

all:		$(NAME)

$(NAME):

					@echo $(CURSIVE)$(GRAY) "     - Creating object directory..." $(NONE)
					@mkdir -p $(OBJS_F)
					@echo $(CURSIVE)$(GRAY) "     - Making object files..." $(NONE)
					@$(CC) $(CFLAGS) -c $(addprefix $(SRCS_F), $(SRCS))
					@echo $(CURSIVE)$(GRAY) "     - Moving object files to $(OBJS_F)..." $(NONE)	
					@mv $(OBJS) $(OBJS_F)
					@echo $(CURSIVE)$(GRAY) "     - Compiling Libft..." $(NONE)
					@make -C $(LIBF_DIR)
					@echo $(CURSIVE)$(GRAY) "     - Compiling $(NAME)..." $(NONE)
					@$(CC) $(FLAGS) $(LIBFT) $(addprefix $(OBJS_F), $(OBJS)) -o $(NAME)
					@echo $(GREEN)"- Pipex Compiled -"$(NONE)

clean:
					@make clean -C ./libft
					@rm -rf $(OBJS_F)
					@rm -f ${OBJS} ${OBJS_B}

fclean: 	clean
					@make -C $(LIBF_DIR) fclean
					@rm -f $(NAME)
					@rm -f ${PROG}
					@echo $(RED) "Deleting EVERYTHING!\n"

re:			fclean all

.PHONY: all clean fclean re 