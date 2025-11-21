# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seoykim <seoykim@student.42gyeongsan.      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/19 05:30:00 by seoykim           #+#    #+#              #
#    Updated: 2025/07/19 05:30:00 by seoykim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -I. -I./handle_set -I./manage_varg -I./form_out -I./print -I./parse_in -I./libft

# Source files (mandatory)
SRCS = ft_printf.c \
	   handle_set/condition_check.c \
	   handle_set/handle_set_parse.c \
	   handle_set/handle_set_util.c \
	   manage_varg/manage_varg.c \
	   manage_varg/set_varg.c \
	   manage_varg/set_varg_util.c \
	   manage_varg/set_varg_helpers.c \
	   parse_in/parse_format.c \
	   form_out/format_main.c \
	   form_out/format_conversions.c \
	   form_out/format_utils.c \
	   print/print.c

# Source files (bonus)
BONUS_SRCS = ft_printf.c \
			 handle_set/condition_check.c \
			 handle_set/handle_set_parse_bonus.c \
			 handle_set/handle_set_util.c \
			 manage_varg/manage_varg.c \
			 manage_varg/set_varg.c \
			 manage_varg/set_varg_util.c \
			 manage_varg/set_varg_helpers.c \
			 parse_in/parse_format.c \
			 form_out/format_main.c \
			 form_out/format_conversions.c \
			 form_out/format_utils.c \
			 print/print.c

# Object files
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

# Default target
all: $(NAME)

# Build libft first
libft/libft.a:
	$(MAKE) -C libft

# Build the library (mandatory)
$(NAME): libft/libft.a $(OBJS)
	ar rcs $(NAME) $(OBJS)
	ar rcs $(NAME) libft/*.o

# Build the library (bonus)
bonus: libft/libft.a $(BONUS_OBJS)
	ar rcs $(NAME) $(BONUS_OBJS)
	ar rcs $(NAME) libft/*.o

# Compile source files to object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files
clean:
	rm -f $(OBJS) $(BONUS_OBJS)
	$(MAKE) -C libft clean

# Clean everything
fclean: clean
	rm -f $(NAME)
	$(MAKE) -C libft fclean

# Rebuild everything
re: fclean all

# Phony targets
.PHONY: all bonus clean fclean re