/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_set.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 00:11:15 by seoykim           #+#    #+#             */
/*   Updated: 2025/07/16 01:30:02 by seoykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLE_SET
# define HANDLE_SET

#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include "libft.h"

#define FLAG_#	(1 << 0)
#define FLAG_0	(1 << 1)
#define FLAG_-	(1 << 2)
#define FLAG_space	(1 << 3)
#define FLAG_+	(1 << 4)

typedef struct s_parse_set
{
	uint8_t		flag;
	size_t		pos_width;
	size_t		pos_precision;
	size_t		pos_conv;
	int			width;
	int			precision;
	char 		*length_modifier;
	char 		*conv_type;
	char 		*form;
	t_parse_set	*next;
}	t_parse_set;

t_parse_set	*head;
t_parse_set	*tail;

// handle_set_util
t_parse_set	*parse_set_init();
t_parse_set	*set_lstadd_last(set);

// handle_set_parse
const char	*substr_moving_idx(format, size_t *cur, size_t end);
void	set_conv(const char *format, size_t *cur, t_parse_set *set);
void	set_str(const char *format, size_t cur, size_t next, t_parse_set *set);

// condition_check
bool	is_argnum(const char *format, size_t cur_idx, size_t *end_idx);
bool	is_width(const char *format, size_t cur_idx, size_t *end_idx);
bool	is_length_modifier(const char *format, size_t cur_idx, size_t *end_idx);
bool	is_conversion(const char *format, size_t cur_idx, size_t *end_idx);

#endif
