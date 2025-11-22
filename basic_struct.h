/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_struct.h                                      :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: seoykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 05:30:00 by seoykim           #+#    #+#             */
/*   Updated: 2025/07/19 05:30:00 by seoykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASIC_STRUCT_H
# define BASIC_STRUCT_H

# include <stdint.h>

# include "libft.h"
# include "handle_error.h"
# include <stddef.h>

# define HASH	1
# define ZERO	2
# define MINUS	4
# define SPACE	8
# define PLUS	16

typedef union u_data
{
	char				*c;
	int					i;
	unsigned int		ui;
	long				l;
	unsigned long		ul;
	long long			ll;
	unsigned long long	ull;
	intmax_t			im;
	uintmax_t			uim;
	size_t				st;
	ssize_t				sst;
	ptrdiff_t			pd;
	void				*p;
	char				*s;
}	t_data;

typedef struct s_parse_set
{
	uint8_t				flag;
	size_t				pos_width;
	size_t				pos_precision;
	size_t				pos_conv;
	int					width;
	int					precision;
	char				*length_modifier;
	char				*conv_type;
	t_data				data;
	size_t				out_len;
	struct s_parse_set	*next;
}	t_parse_set;

#endif
