# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/20 08:52:16 by fcoullou          #+#    #+#              #
#    Updated: 2023/12/08 13:49:00 by fcoullou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= libftprintf.a
LIBFTNAME	:= libft.a

#------------------------------------------------#

SRC_DIR		:= srcs
OBJ_DIR		:= obj
LIBFT_DIR	:= ./libft
SRCS		= $(wildcard $(SRC_DIR)/*.c)
OBJS		= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

AR			:= ar
CC			:= clang
CFLAGS		:= -Wall -Wextra -Werror
CPPFLAGS	:= -I includes -I libft

RM			:= rm -f
CD			:= cd
DIR_DUP		= mkdir -p $(@D)

#------------------------------------------------#

all: $(NAME)

$(NAME): makelibft $(OBJS)
	$(AR) rcs $(NAME) $(OBJS)
	@echo "CREATED $@"

makelibft:
	@make -C $(LIBFT_DIR)
	@cp $(LIBFT_DIR)/$(LIBFTNAME) .
	@mv $(LIBFTNAME) $(NAME)
	@echo "CREATED $@"

bonus: all

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<
	@echo "CREATED $@"
		
clean:
	$(RM) $(OBJS)
	$(CD) $(LIBFT_DIR) && make clean
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)
	$(CD) $(LIBFT_DIR) && make fclean
	$(RM) -r $(OBJ_DIR)
	
re: fclean all