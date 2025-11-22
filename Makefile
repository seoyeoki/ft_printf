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
	   ft_printf_helpers.c \
	   handle_set/condition_check.c \
	   handle_set/handle_set_parse.c \
	   handle_set/handle_set_parse_flags.c \
	   handle_set/handle_set_parse_helpers.c \
	   handle_set/handle_set_util.c \
	   manage_varg/manage_varg.c \
	   manage_varg/set_varg.c \
	   manage_varg/set_varg_insert.c \
	   manage_varg/set_varg_extend.c \
	   manage_varg/set_varg_util.c \
	   manage_varg/set_varg_helpers.c \
	   manage_varg/set_varg_type_helpers.c \
	   parse_in/parse_format.c \
	   form_out/format_main.c \
	   form_out/format_char.c \
	   form_out/format_conversions.c \
	   form_out/format_integer.c \
	   form_out/format_utils.c \
	   form_out/format_helpers.c \
	   form_out/format_flag_helpers.c \
	   form_out/format_padding_helpers.c \
	   form_out/format_itoa_helpers.c \
	   print/print.c

# Source files (bonus)
BONUS_SRCS = ft_printf.c \
			 ft_printf_helpers.c \
			 handle_set/condition_check.c \
			 handle_set/handle_set_parse.c \
			 handle_set/handle_set_parse_flags.c \
			 handle_set/handle_set_parse_helpers.c \
			 handle_set/handle_set_util.c \
			 manage_varg/manage_varg.c \
			 manage_varg/set_varg.c \
			 manage_varg/set_varg_insert.c \
			 manage_varg/set_varg_extend.c \
			 manage_varg/set_varg_util.c \
			 manage_varg/set_varg_helpers.c \
			 manage_varg/set_varg_type_helpers.c \
			 parse_in/parse_format.c \
			 form_out/format_main.c \
			 form_out/format_char.c \
			 form_out/format_conversions.c \
			 form_out/format_integer.c \
			 form_out/format_utils.c \
			 form_out/format_helpers.c \
			 form_out/format_flag_helpers.c \
			 form_out/format_padding_helpers.c \
			 form_out/format_itoa_helpers.c \
			 print/print.c

# Object files
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
LIBFT_OBJS = libft/libft_basic.o

# Default target
all: $(NAME)

# Build libft first (libft's Makefile handles its own dependencies)
libft/libft.a:
	$(MAKE) -C libft

# Build the library (mandatory)
$(NAME): libft/libft.a $(OBJS)
	ar rcs $(NAME) $(OBJS) $(LIBFT_OBJS)

# Build the library (bonus)
bonus: libft/libft.a $(BONUS_OBJS)
	ar rcs $(NAME) $(BONUS_OBJS) $(LIBFT_OBJS)

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
