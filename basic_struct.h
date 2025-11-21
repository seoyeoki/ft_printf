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

# define HASH	(1 << 0)
# define ZERO	(1 << 1)
# define MINUS	(1 << 2)
# define SPACE	(1 << 3)
# define PLUS	(1 << 4)

typedef union u_data
{
	char		*c;
	int			i;
	unsigned int	ui;
	long		l;
	unsigned long	ul;
	long long		ll;
	unsigned long long	ull;
	intmax_t	im;
	uintmax_t	uim;
	size_t		st;
	ssize_t		sst;
	ptrdiff_t	pd;
	void		*p;
	char		*s;
}	t_data;

typedef struct s_parse_set
{
	uint8_t				flag;
	size_t				pos_width;
	size_t				pos_precision;
	size_t				pos_conv;
	int					width;
	int					precision;
	char 				*length_modifier;
	char 				*conv_type;
	t_data				data;
	struct s_parse_set	*next;
}	t_parse_set;

#endif
