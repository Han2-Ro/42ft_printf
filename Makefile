# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hrother <hrother@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/04 12:56:10 by hrother           #+#    #+#              #
#    Updated: 2023/09/17 14:03:45 by hrother          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
OBJ_DIR = objs
SRCS = ft_printf.c ft_print_c.c ft_print_s.c ft_print_i.c ft_print_x.c ft_print_u.c ft_print_p.c
OBJS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRCS))
NAME = libftprintf.a

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

$(NAME): $(LIBFT) $(OBJS)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJS)

all: $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make all -C $(LIBFT_PATH)

clean:
	rm -f $(OBJS)
	if [ -d $(OBJ_DIR) ]; then rmdir $(OBJ_DIR); fi
	
fclean: clean #maybe call clean from libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
