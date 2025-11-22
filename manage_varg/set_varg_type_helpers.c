/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_varg_type_helpers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 05:30:00 by seoykim           #+#    #+#             */
/*   Updated: 2025/07/19 05:30:00 by seoykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "manage_varg.h"

bool	check_signed_type_size(t_parse_set *cur, size_t *max_sz)
{
	if (ft_strcmp(cur->conv_type, "d") == 0
		|| ft_strcmp(cur->conv_type, "i") == 0)
	{
		if (cur->length_modifier)
		{
			if (ft_strcmp(cur->length_modifier, "l") == 0
				&& *max_sz < sizeof(long))
				*max_sz = sizeof(long);
			else if (ft_strcmp(cur->length_modifier, "ll") == 0
				&& *max_sz < sizeof(long long))
				*max_sz = sizeof(long long);
			else if (*max_sz < sizeof(int))
				*max_sz = sizeof(int);
		}
		else if (*max_sz < sizeof(int))
			*max_sz = sizeof(int);
		return (true);
	}
	return (false);
}

bool	check_uint_type_size(t_parse_set *cur, size_t *max_sz)
{
	if (ft_strcmp(cur->conv_type, "u") == 0
		|| ft_strcmp(cur->conv_type, "x") == 0
		|| ft_strcmp(cur->conv_type, "X") == 0)
	{
		if (cur->length_modifier)
		{
			if (ft_strcmp(cur->length_modifier, "l") == 0
				&& *max_sz < sizeof(unsigned long))
				*max_sz = sizeof(unsigned long);
			else if (ft_strcmp(cur->length_modifier, "ll") == 0
				&& *max_sz < sizeof(unsigned long long))
				*max_sz = sizeof(unsigned long long);
			else if (*max_sz < sizeof(unsigned int))
				*max_sz = sizeof(unsigned int);
		}
		else if (*max_sz < sizeof(unsigned int))
			*max_sz = sizeof(unsigned int);
		return (true);
	}
	return (false);
}

void	assign_signed_data(t_parse_set *cur, t_data arg)
{
	if (cur->length_modifier)
	{
		if (ft_strcmp(cur->length_modifier, "hh") == 0)
			cur->data.i = (char)arg.i;
		else if (ft_strcmp(cur->length_modifier, "h") == 0)
			cur->data.i = (short)arg.i;
		else if (ft_strcmp(cur->length_modifier, "l") == 0)
			cur->data.l = arg.l;
		else if (ft_strcmp(cur->length_modifier, "ll") == 0)
			cur->data.ll = arg.ll;
		else
			cur->data.i = arg.i;
	}
	else
		cur->data.i = arg.i;
}

void	assign_uint_data(t_parse_set *cur, t_data arg)
{
	if (cur->length_modifier)
	{
		if (ft_strcmp(cur->length_modifier, "hh") == 0)
			cur->data.ui = (unsigned char)arg.ui;
		else if (ft_strcmp(cur->length_modifier, "h") == 0)
			cur->data.ui = (unsigned short)arg.ui;
		else if (ft_strcmp(cur->length_modifier, "l") == 0)
			cur->data.ul = arg.ul;
		else if (ft_strcmp(cur->length_modifier, "ll") == 0)
			cur->data.ull = arg.ull;
		else
			cur->data.ui = arg.ui;
	}
	else
		cur->data.ui = arg.ui;
}
