/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_integer.c                                    :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: seoykim <seoykim@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 05:30:00 by seoykim           #+#    #+#             */
/*   Updated: 2025/07/19 05:30:00 by seoykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "form_out.h"

static char	*create_num_str_from_val(long long val)
{
	char	*num_str;

	if (val < 0)
		num_str = ft_utoa_base((unsigned long long)(-val), 10, 0);
	else
		num_str = ft_utoa_base((unsigned long long)val, 10, 0);
	return (num_str);
}

static char	*apply_sign_flags(char *result, t_parse_set *set, int is_neg)
{
	char	*temp;

	if (is_neg)
	{
		temp = ft_strjoin("-", result);
		free(result);
		result = temp;
	}
	else
		result = apply_flags(result, set);
	return (result);
}

static char	*process_non_zero_int(long long val, t_parse_set *set)
{
	char	*num_str;
	char	*result;
	int		is_neg;

	is_neg = (val < 0);
	num_str = create_num_str_from_val(val);
	if (!num_str)
		return (NULL);
	result = apply_precision(num_str, set);
	result = apply_sign_flags(result, set, is_neg);
	return (result);
}

char	*format_integer(t_parse_set *set)
{
	char		*result;
	char		*temp;
	long long	val;

	val = get_int_value(set);
	if (val == 0 && set->precision == 0)
		result = ft_strdup("");
	else
		result = process_non_zero_int(val, set);
	if (!result)
		return (NULL);
	temp = apply_width(result, set);
	return (temp);
}

