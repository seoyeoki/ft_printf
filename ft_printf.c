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

int	process_va_args_if_needed(va_list args, \
			t_parse_set ***varg_list, size_t *vlist_size);
void	cleanup_resources(t_parse_set ***varg_list, size_t vlist_size, \
			t_parse_set **head, t_parse_set **tail);

static t_parse_set	***parse_and_create_vlist(const char *format, \
					t_parse_set **head, t_parse_set **tail, \
					size_t *vlist_size)
{
	*head = NULL;
	*tail = NULL;
	parse_format(format, head, tail);
	return (set_varg_list(*head, vlist_size));
}

static int	cleanup_and_print(t_parse_set ***varg_list, size_t vlist_size, \
				t_parse_set **head, t_parse_set **tail)
{
	int	result;

	result = print_output(*head);
	cleanup_resources(varg_list, vlist_size, head, tail);
	return (result);
}

int	ft_printf(const char *format, ...)
{
	t_parse_set	*head;
	t_parse_set	*tail;
	t_parse_set	***varg_list;
	size_t		vlist_size;
	va_list		args;

	varg_list = parse_and_create_vlist(format, &head, &tail, &vlist_size);
	if (!varg_list)
	{
		parse_set_free(&head, &tail);
		return (-1);
	}
	va_start(args, format);
	if (process_va_args_if_needed(args, varg_list, &vlist_size) != 0)
	{
		va_end(args);
		parse_set_free(&head, &tail);
		return (-1);
	}
	va_end(args);
	return (cleanup_and_print(varg_list, vlist_size, &head, &tail));
}
