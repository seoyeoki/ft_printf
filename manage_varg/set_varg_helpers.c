/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_varg_helpers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 05:30:00 by seoykim           #+#    #+#             */
/*   Updated: 2025/07/19 05:30:00 by seoykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "manage_varg.h"

static void	update_max_size(size_t *max_sz, size_t new_size)
{
	if (*max_sz < new_size)
		*max_sz = new_size;
}

static void	process_conv_type(t_parse_set *cur, size_t *max_sz)
{
	if (ft_strcmp(cur->conv_type, "c") == 0)
		update_max_size(max_sz, sizeof(int));
	else if (ft_strcmp(cur->conv_type, "s") == 0)
		update_max_size(max_sz, sizeof(char *));
	else if (ft_strcmp(cur->conv_type, "p") == 0)
		update_max_size(max_sz, sizeof(void *));
	else
	{
		check_signed_type_size(cur, max_sz);
		check_uint_type_size(cur, max_sz);
	}
}

size_t	find_max_type_size(t_parse_set *cur)
{
	size_t	max_sz;

	max_sz = 0;
	if (cur && cur->conv_type)
		process_conv_type(cur, &max_sz);
	return (max_sz);
}

t_data	extract_arg(va_list args, size_t max_type_size)
{
	t_data	arg;

	arg = (t_data){0};
	if (max_type_size == sizeof(void *))
		arg.p = va_arg(args, void *);
	else if (max_type_size == sizeof(char *))
		arg.s = va_arg(args, char *);
	else if (max_type_size == sizeof(unsigned long long))
		arg.ull = va_arg(args, unsigned long long);
	else if (max_type_size == sizeof(long long))
		arg.ll = va_arg(args, long long);
	else if (max_type_size == sizeof(unsigned long))
		arg.ul = va_arg(args, unsigned long);
	else if (max_type_size == sizeof(long))
		arg.l = va_arg(args, long);
	else if (max_type_size == sizeof(unsigned int))
		arg.ui = va_arg(args, unsigned int);
	else if (max_type_size == sizeof(int))
		arg.i = va_arg(args, int);
	return (arg);
}

void	assign_data_to_nodes(t_parse_set *cur, t_data arg)
{
	if (!cur || !cur->conv_type)
		return ;
	if (ft_strcmp(cur->conv_type, "c") == 0)
		cur->data.i = arg.i;
	else if (ft_strcmp(cur->conv_type, "s") == 0)
		cur->data.s = arg.s;
	else if (ft_strcmp(cur->conv_type, "p") == 0)
		cur->data.p = arg.p;
	else if (ft_strcmp(cur->conv_type, "d") == 0
		|| ft_strcmp(cur->conv_type, "i") == 0)
		assign_signed_data(cur, arg);
	else if (ft_strcmp(cur->conv_type, "u") == 0
		|| ft_strcmp(cur->conv_type, "x") == 0
		|| ft_strcmp(cur->conv_type, "X") == 0)
		assign_uint_data(cur, arg);
}
