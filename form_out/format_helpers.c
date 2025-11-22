/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_helpers.c                                    :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: seoykim <seoykim@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 05:30:00 by seoykim           #+#    #+#             */
/*   Updated: 2025/07/19 05:30:00 by seoykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "form_out.h"

long long	get_int_value(t_parse_set *set)
{
	long long	val;

	val = 0;
	if (!set->length_modifier)
		val = (long long)set->data.i;
	else if (ft_strcmp(set->length_modifier, "l") == 0)
		val = (long long)set->data.l;
	else if (ft_strcmp(set->length_modifier, "ll") == 0)
		val = (long long)set->data.ll;
	else
		val = (long long)set->data.i;
	return (val);
}

unsigned long long	get_uint_value(t_parse_set *set)
{
	unsigned long long	val;

	val = 0;
	if (!set->length_modifier)
		val = (unsigned long long)set->data.ui;
	else if (ft_strcmp(set->length_modifier, "l") == 0)
		val = (unsigned long long)set->data.ul;
	else if (ft_strcmp(set->length_modifier, "ll") == 0)
		val = (unsigned long long)set->data.ull;
	else
		val = (unsigned long long)set->data.ui;
	return (val);
}

char	*get_formatted_string(t_parse_set *cur)
{
	char	*result;

	result = NULL;
	if (ft_strcmp(cur->conv_type, "c") == 0)
		result = format_char(cur);
	else if (ft_strcmp(cur->conv_type, "s") == 0)
		result = format_string(cur);
	else if (ft_strcmp(cur->conv_type, "p") == 0)
		result = format_pointer(cur);
	else if (ft_strcmp(cur->conv_type, "d") == 0
		|| ft_strcmp(cur->conv_type, "i") == 0)
		result = format_integer(cur);
	else if (ft_strcmp(cur->conv_type, "u") == 0)
		result = format_unsigned(cur);
	else if (ft_strcmp(cur->conv_type, "x") == 0)
		result = format_hex(cur, 0);
	else if (ft_strcmp(cur->conv_type, "X") == 0)
		result = format_hex(cur, 1);
	else if (ft_strcmp(cur->conv_type, "%") == 0)
		result = format_percent(cur);
	if (result && ft_strcmp(cur->conv_type, "c") != 0)
		cur->out_len = ft_strlen(result);
	return (result);
}

void	copy_conv_data(char *res, t_parse_set *cur, size_t *pos)
{
	char	*formatted_str;

	formatted_str = get_formatted_string(cur);
	if (formatted_str)
	{
		ft_memcpy(res + *pos, formatted_str, cur->out_len);
		*pos += cur->out_len;
		free(formatted_str);
	}
}
