/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_helpers.c                                 :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: seoykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 00:58:12 by seoykim           #+#    #+#             */
/*   Updated: 2025/07/17 05:14:51 by seoykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "basic_struct.h"
#include "parse_format.h"
#include "manage_varg.h"
#include "handle_set.h"

static int	process_args(va_list args, t_parse_set ***varg_list, \
				size_t *vlist_size)
{
	if (manage_args(args, varg_list, vlist_size) != 0)
		return (-1);
	return (0);
}

int	process_va_args_if_needed(va_list args, \
			t_parse_set ***varg_list, size_t *vlist_size)
{
	if (*vlist_size == 0)
		return (0);
	if (process_args(args, varg_list, vlist_size) != 0)
	{
		vlist_free(varg_list, *vlist_size);
		return (-1);
	}
	return (0);
}

void	cleanup_resources(t_parse_set ***varg_list, size_t vlist_size, \
			t_parse_set **head, t_parse_set **tail)
{
	vlist_free(varg_list, vlist_size);
	parse_set_free(head, tail);
}
