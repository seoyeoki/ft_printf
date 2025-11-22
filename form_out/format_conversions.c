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

char	*format_string(t_parse_set *set)
{
	char	*result;
	char	*str;

	if (!set->data.s)
	{
		if (set->precision >= 0 && set->precision < 6)
			str = ft_strdup("");
		else
			str = ft_strdup("(null)");
	}
	else
		str = ft_strdup(set->data.s);
	if (!str)
		return (NULL);
	if (set->precision >= 0
		&& (size_t)set->precision < ft_strlen(str))
	{
		result = ft_substr(str, 0, set->precision);
		free(str);
		str = result;
	}
	result = apply_width(str, set);
	return (result);
}

char	*format_pointer(t_parse_set *set)
{
	char	*result;
	char	*hex_str;

	if (set->data.p == NULL)
		hex_str = ft_strdup("(nil)");
	else
	{
		hex_str = ft_utoa_base((unsigned long long)set->data.p, 16, 0);
		result = ft_strjoin("0x", hex_str);
		free(hex_str);
		hex_str = result;
	}
	result = apply_width(hex_str, set);
	return (result);
}

char	*format_unsigned(t_parse_set *set)
{
	char				*result;
	char				*num_str;
	unsigned long long	val;

	val = get_uint_value(set);
	if (val == 0 && set->precision == 0)
	{
		result = ft_strdup("");
		if (!result)
			return (NULL);
	}
	else
	{
		num_str = ft_utoa_base(val, 10, 0);
		result = apply_precision(num_str, set);
	}
	result = apply_width(result, set);
	return (result);
}

char	*format_hex(t_parse_set *set, int up)
{
	char				*result;
	char				*hex_str;
	unsigned long long	val;

	val = get_uint_value(set);
	if (val == 0 && set->precision == 0)
	{
		result = ft_strdup("");
		if (!result)
			return (NULL);
	}
	else
	{
		hex_str = ft_utoa_base(val, 16, up);
		if (!hex_str)
			return (NULL);
		result = apply_precision(hex_str, set);
		result = apply_hash_to_hex(result, set, val, up);
	}
	hex_str = apply_width(result, set);
	return (hex_str);
}
