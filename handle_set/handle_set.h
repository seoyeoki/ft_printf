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

typedef struct parse_set
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
	parse_set	*next;
}	parse_set;

parse_set	*head;
parse_set	*tail;

// handle_set_util
parse_set	*parse_set_init();
parse_set	*set_lstadd_last(set);

// handle_set_parse

#endif
