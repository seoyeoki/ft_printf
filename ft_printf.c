/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
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
#include "print.h"
#include "handle_set.h"

int	ft_printf(const char *format, ...)
{
	t_parse_set	*head;
	t_parse_set	*tail;
	va_list		args;
	t_parse_set	***varg_list;
	size_t		vlist_size;
	int			result;

	head = NULL;
	tail = NULL;
	parse_format(format, &head, &tail);
	varg_list = set_varg_list(head, &vlist_size);
	if (vlist_size > 0)
	{
		va_start(args, format);
		result = manage_args(args, varg_list, &vlist_size);
		va_end(args);
	}
	else
	{
		result = 0;
	}
	if (result == 0)
		result = print_output(head);
	parse_set_free(&head, &tail);
	return (result);
}
