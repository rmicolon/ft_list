# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmicolon <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/22 14:46:36 by rmicolon          #+#    #+#              #
#    Updated: 2018/11/23 14:46:09 by rmicolon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

FLAGS = -Wall \
		-Wextra \
		-Werror \
		-Os

NAME = liblst.a

SDIR = sources

ODIR = objects

SRCS = $(SDIR)/ft_list_add.c \
	   $(SDIR)/ft_list_cut.c \
	   $(SDIR)/ft_list_del.c \
	   $(SDIR)/ft_list_apply.c \
	   $(SDIR)/ft_list_init.c \
	   $(SDIR)/ft_list_move.c \
	   $(SDIR)/ft_list_replace.c \
	   $(SDIR)/ft_list_splice.c \
	   $(SDIR)/ft_list_tests.c

OBJ = $(SRCS:$(SDIR)/%.c=$(ODIR)/%.o)

HDRS =  -I./includes/

all: $(NAME)

$(NAME): $(ODIR) $(OBJ)
	@ar rc $@ $(OBJ)
	@echo "Lib created."

$(ODIR):
	@mkdir $@

$(ODIR)/%.o: $(SDIR)/%.c
	@$(CC) $(FLAGS) -c $< $(HDRS) -o $@

clean:
	@rm -rf $(ODIR)
	@echo "Lib-objects deleted."

fclean: clean
	@rm -rf $(NAME)
	@echo "Lib deleted."

re: fclean all

.PHONY: all clean fclean re
