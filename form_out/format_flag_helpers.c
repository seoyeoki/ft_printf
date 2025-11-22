/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_flag_helpers.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoykim <seoykim@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 05:30:00 by seoykim           #+#    #+#             */
/*   Updated: 2025/07/19 05:30:00 by seoykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "form_out.h"

char	*apply_sign_to_int(char *str, t_parse_set *set, long long val)
{
	char	*res;

	if (val < 0)
		return (str);
	if (set->flag & PLUS)
	{
		res = ft_strjoin("+", str);
		free(str);
		return (res);
	}
	else if (set->flag & SPACE)
	{
		res = ft_strjoin(" ", str);
		free(str);
		return (res);
	}
	return (str);
}

char	*apply_hash_to_hex(char *str, t_parse_set *set, \
		unsigned long long val, int up)
{
	char	*res;

	if (!(set->flag & HASH) || val == 0)
		return (str);
	if (up)
		res = ft_strjoin("0X", str);
	else
		res = ft_strjoin("0x", str);
	free(str);
	return (res);
}
