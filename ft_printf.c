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

#include "handle_set.h"
#include "manage_varg.h"

int	ft_printf(const char *format, ...)
{
	va_list		args;
	t_parse_set	***varg_list;
	size_t		vlist_size;

	head = NULL;
	tail = NULL;
	parse_format(format);
	varg_list = set_varg_list(&vlist_size);
	va_start(args, format);
	manage_args(args, varg_list, &vlist_size); /// 여기 작업중(개판)
	va_end(args);
	construct_buffer();
	print();
}
