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

static size_t	check_conv_type_size(t_parse_set *current, size_t max_type_size)
{
	if (ft_strcmp(current->conv_type, "c") == 0 && max_type_size < sizeof(int))
		return (sizeof(int));
	else if (ft_strcmp(current->conv_type, "s") == 0 && max_type_size < sizeof(char*))
		return (sizeof(char*));
	else if (ft_strcmp(current->conv_type, "p") == 0 && max_type_size < sizeof(void*))
		return (sizeof(void*));
	else if (ft_strcmp(current->conv_type, "d") == 0 || ft_strcmp(current->conv_type, "i") == 0)
	{
		if (current->length_modifier)
		{
			if (ft_strcmp(current->length_modifier, "l") == 0 && max_type_size < sizeof(long))
				return (sizeof(long));
			else if (ft_strcmp(current->length_modifier, "ll") == 0 && max_type_size < sizeof(long long))
				return (sizeof(long long));
			else if (max_type_size < sizeof(int))
				return (sizeof(int));
		}
		else if (max_type_size < sizeof(int))
			return (sizeof(int));
	}
	else if (ft_strcmp(current->conv_type, "u") == 0)
	{
		if (current->length_modifier)
		{
			if (ft_strcmp(current->length_modifier, "l") == 0 && max_type_size < sizeof(unsigned long))
				return (sizeof(unsigned long));
			else if (ft_strcmp(current->length_modifier, "ll") == 0 && max_type_size < sizeof(unsigned long long))
				return (sizeof(unsigned long long));
			else if (max_type_size < sizeof(unsigned int))
				return (sizeof(unsigned int));
		}
		else if (max_type_size < sizeof(unsigned int))
			return (sizeof(unsigned int));
	}
	else if (ft_strcmp(current->conv_type, "x") == 0 || ft_strcmp(current->conv_type, "X") == 0)
	{
		if (current->length_modifier)
		{
			if (ft_strcmp(current->length_modifier, "l") == 0 && max_type_size < sizeof(unsigned long))
				return (sizeof(unsigned long));
			else if (ft_strcmp(current->length_modifier, "ll") == 0 && max_type_size < sizeof(unsigned long long))
				return (sizeof(unsigned long long));
			else if (max_type_size < sizeof(unsigned int))
				return (sizeof(unsigned int));
		}
		else if (max_type_size < sizeof(unsigned int))
			return (sizeof(unsigned int));
	}
	return (max_type_size);
}

size_t	find_max_type_size(t_parse_set *current)
{
	size_t	max_type_size;

	max_type_size = 0;
	while (current)
	{
		if (current->conv_type)
			max_type_size = check_conv_type_size(current, max_type_size);
		current = current->next;
	}
	return (max_type_size);
}

t_data	extract_arg(va_list args, size_t max_type_size)
{
	t_data	arg = {0};

	if (max_type_size == sizeof(void*))
		arg.p = va_arg(args, void*);
	else if (max_type_size == sizeof(char*))
		arg.s = va_arg(args, char*);
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

static void	assign_signed_data(t_parse_set *current, t_data arg)
{
	if (current->length_modifier)
	{
		if (ft_strcmp(current->length_modifier, "hh") == 0)
			current->data.i = (char)arg.i;
		else if (ft_strcmp(current->length_modifier, "h") == 0)
			current->data.i = (short)arg.i;
		else if (ft_strcmp(current->length_modifier, "l") == 0)
			current->data.l = arg.l;
		else if (ft_strcmp(current->length_modifier, "ll") == 0)
			current->data.ll = arg.ll;
		else
			current->data.i = arg.i;
	}
	else
		current->data.i = arg.i;
}

static void	assign_unsigned_data(t_parse_set *current, t_data arg)
{
	if (current->length_modifier)
	{
		if (ft_strcmp(current->length_modifier, "hh") == 0)
			current->data.ui = (unsigned char)arg.ui;
		else if (ft_strcmp(current->length_modifier, "h") == 0)
			current->data.ui = (unsigned short)arg.ui;
		else if (ft_strcmp(current->length_modifier, "l") == 0)
			current->data.ul = arg.ul;
		else if (ft_strcmp(current->length_modifier, "ll") == 0)
			current->data.ull = arg.ull;
		else
			current->data.ui = arg.ui;
	}
	else
		current->data.ui = arg.ui;
}

void	assign_data_to_nodes(t_parse_set *current, t_data arg)
{
	while (current)
	{
		if (current->conv_type)
		{
			if (ft_strcmp(current->conv_type, "c") == 0)
				current->data.i = arg.i;
			else if (ft_strcmp(current->conv_type, "s") == 0)
				current->data.s = arg.s;
			else if (ft_strcmp(current->conv_type, "p") == 0)
				current->data.p = arg.p;
			else if (ft_strcmp(current->conv_type, "d") == 0 || ft_strcmp(current->conv_type, "i") == 0)
				assign_signed_data(current, arg);
			else if (ft_strcmp(current->conv_type, "u") == 0)
				assign_unsigned_data(current, arg);
			else if (ft_strcmp(current->conv_type, "x") == 0 || ft_strcmp(current->conv_type, "X") == 0)
				assign_unsigned_data(current, arg);
		}
		current = current->next;
	}
}
