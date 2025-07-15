/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_set_parse.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 01:06:37 by seoykim           #+#    #+#             */
/*   Updated: 2025/07/16 03:04:04 by seoykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handle_set.h"

const char	*substr_moving_idx(format, size_t *cur, size_t end)
{
	const char	*substr;

	substr = (const char *)ft_substr(format, *cur, end - *cur);
	*cur = end;
	return (substr);
}

void	set_conv(const char *format, size_t *cur, parse_set *set) // 이건 parse mandatory, bonus 시에는 파일 자체를 바꿔 껴야 함
{
	size_t	start;
	size_t	end;

	start = *cur;
	*cur++;
	end = *cur;
	if (is_argnum(format, *cur, &end))
	{
		set->pos_conversion = ft_atoi(substr_moving_idx(format, cur, end)); // 해당할 때만 cur 이동
		(*cur)++; // $ 고려
	}
	if (is_width(format, *cur, &end))
		set->width = ft_atoi(substr_moving_idx(format, cur, end));
	if (is_length_modifier(format, *cur, &end))
	{
		set->length_modifier = substr_moving_idx(format, cur, end);
	if (is_conversion(format, *cur, &end))
		set->conv_type = substr_moving_idx(format, cur, end);
	else
	{
		set_str(format, start, end, set);
		*cur = end;
	}
}

void	set_str(const char *format, size_t cur, size_t next, parse_set *set)
{
	*set = (parse_set) { 0, };
	set->form = ft_substr(format, cur, next - cur);
}
