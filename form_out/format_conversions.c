/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_conversions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoykim <seoykim@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 05:30:00 by seoykim           #+#    #+#             */
/*   Updated: 2025/07/19 05:30:00 by seoykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "form_out.h"

char	*format_char(t_parse_set *set)
{
	char	*result;
	char	c;

	c = (char)set->data.i;
	result = (char *)malloc(2);
	if (!result)
		return (NULL);
	result[0] = c;
	result[1] = '\0';
	return (apply_width(result, set));
}

char	*format_string(t_parse_set *set)
{
	char	*result;
	char	*str;

	if (set->data.s == NULL)
		str = ft_strdup("(null)");
	else
		str = ft_strdup(set->data.s);

	if (!str)
		return (NULL);

	if (set->precision >= 0 && (size_t)set->precision < ft_strlen(str))
	{
		result = ft_substr(str, 0, set->precision);
		free(str);
		str = result;
	}

	result = apply_width(str, set);

	if (result != str)
		free(str);

	return (result);
}

char	*format_pointer(t_parse_set *set)
{
	char	*result;
	char	*hex_str;

	if (set->data.p == NULL)
		hex_str = ft_strdup("0x0");
	else
	{
		hex_str = ft_utoa_base((unsigned long long)set->data.p, 16, 0);
		result = ft_strjoin("0x", hex_str);
		free(hex_str);
		hex_str = result;
	}

	result = apply_width(hex_str, set);

	if (result != hex_str)
		free(hex_str);

	return (result);
}

char	*format_integer(t_parse_set *set)
{
	char	*result;
	char	*num_str;
	long long value;

	if (set->length_modifier)
	{
		if (ft_strcmp(set->length_modifier, "l") == 0)
			value = set->data.l;
		else if (ft_strcmp(set->length_modifier, "ll") == 0)
			value = set->data.ll;
		else
			value = set->data.i;
	}
	else
		value = set->data.i;

	num_str = ft_itoa((int)value);
	if (!num_str)
		return (NULL);

	result = apply_precision(num_str, set);

	if (result != num_str)
		free(num_str);

	if (value >= 0)
	{
		if (set->flag & PLUS)
		{
			num_str = ft_strjoin("+", result);
			free(result);
			result = num_str;
		}
		else if (set->flag & SPACE)
		{
			num_str = ft_strjoin(" ", result);
			free(result);
			result = num_str;
		}
	}

	num_str = apply_width(result, set);

	if (num_str != result)
		free(result);

	return (num_str);
}

char	*format_unsigned(t_parse_set *set)
{
	char	*result;
	char	*num_str;
	unsigned long long value;

	if (set->length_modifier)
	{
		if (ft_strcmp(set->length_modifier, "l") == 0)
			value = set->data.ul;
		else if (ft_strcmp(set->length_modifier, "ll") == 0)
			value = set->data.ull;
		else
			value = set->data.ui;
	}
	else
		value = set->data.ui;

	num_str = ft_utoa_base(value, 10, 0);
	result = apply_precision(num_str, set);

	if (result != num_str)
		free(num_str);

	result = apply_width(result, set);
	return (result);
}

char	*format_hex(t_parse_set *set, int uppercase)
{
	char	*result;
	char	*hex_str;
	unsigned long long value;

	if (set->length_modifier)
	{
		if (ft_strcmp(set->length_modifier, "l") == 0)
			value = set->data.ul;
		else if (ft_strcmp(set->length_modifier, "ll") == 0)
			value = set->data.ull;
		else
			value = set->data.ui;
	}
	else
		value = set->data.ui;

	hex_str = ft_utoa_base(value, 16, uppercase);
	if (!hex_str)
		return (NULL);

	result = apply_precision(hex_str, set);

	if (result != hex_str)
		free(hex_str);

	if (set->flag & HASH && value != 0)
	{
		hex_str = uppercase ? ft_strjoin("0X", result) : ft_strjoin("0x", result);
		free(result);
		result = hex_str;
	}

	hex_str = apply_width(result, set);

	if (hex_str != result)
		free(result);

	return (hex_str);
}

char	*format_percent(t_parse_set *set)
{
	char	*result;

	result = ft_strdup("%");
	return (apply_width(result, set));
}
