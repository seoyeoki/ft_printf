/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoykim <seoykim@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 05:30:00 by seoykim           #+#    #+#             */
/*   Updated: 2025/07/19 05:30:00 by seoykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "form_out.h"

char	*format_percent(t_parse_set *set)
{
	(void)set;
	return (ft_strdup("%"));
}

static size_t	calculate_total_length(t_parse_set *head)
{
	t_parse_set	*cur;
	char		*formatted_str;
	size_t		total_len;

	total_len = 0;
	cur = head;
	while (cur)
	{
		if (cur->conv_type)
		{
			formatted_str = get_formatted_string(cur);
			if (formatted_str)
			{
				total_len += cur->out_len;
				free(formatted_str);
			}
		}
		else if (cur->data.s)
			total_len += ft_strlen(cur->data.s);
		cur = cur->next;
	}
	return (total_len);
}

static void	copy_to_result(char *result, t_parse_set *head)
{
	t_parse_set	*cur;
	size_t		pos;
	size_t		len;

	pos = 0;
	cur = head;
	while (cur)
	{
		if (cur->conv_type)
			copy_conv_data(result, cur, &pos);
		else if (cur->data.s)
		{
			len = ft_strlen(cur->data.s);
			ft_memcpy(result + pos, cur->data.s, len);
			pos += len;
		}
		cur = cur->next;
	}
	result[pos] = '\0';
}

char	*construct_final_output(t_parse_set *head)
{
	char	*result;
	size_t	total_len;

	total_len = calculate_total_length(head);
	result = (char *)malloc(total_len + 1);
	if (!result)
		return (NULL);
	copy_to_result(result, head);
	return (result);
}
