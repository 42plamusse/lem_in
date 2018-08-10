# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plamusse <plamusse@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/17 14:39:22 by plamusse          #+#    #+#              #
#    Updated: 2018/08/10 14:40:11 by plamusse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# programs
NAME		= lem-in

# directories
SRC_DIR		= ./src
INC_DIR		= ./includes
OBJ_DIR		= ./obj
LIB_DIR		= ./libft

# src / obj files

SRC			=	main.c \
				debug.c \
				handle_vertices.c \
				free_hex.c \
				handle_edges.c \
				print_ants.c \
				algo.c \
				vert_helpers.c
				

OBJ			= $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))


# compiler and flags
CC			= gcc
CFLAGS		= -g -Wall -Werror -Wextra

# libraries
L_FT		= $(LIB_DIR)
LIB_LNK		= -L $(L_FT) -lft
LIB_INC		= $(L_FT)/includes

all: $(NAME) Makefile libft/libft.a

$(OBJ_DIR):
	mkdir -p $@

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c $(INC_DIR)
	$(CC) $(CFLAGS)  -o $@ -c $< -I $(INC_DIR)

$(NAME): $(OBJ_DIR) $(OBJ)
	@$(MAKE) -C $(L_FT)
	$(CC) -o $@ $(OBJ) $(LIB_LNK)

clean:
	@$(MAKE) fclean -C $(L_FT)
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)
	rm -rf *.dSYM

re:
	@$(MAKE) fclean
	@$(MAKE) all
