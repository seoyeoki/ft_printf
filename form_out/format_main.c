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

static char	*get_formatted_string(t_parse_set *current)
{
	if (!current->conv_type)
		return (NULL);
	
	if (ft_strcmp(current->conv_type, "c") == 0)
		return (format_char(current));
	else if (ft_strcmp(current->conv_type, "s") == 0)
		return (format_string(current));
	else if (ft_strcmp(current->conv_type, "p") == 0)
		return (format_pointer(current));
	else if (ft_strcmp(current->conv_type, "d") == 0 || ft_strcmp(current->conv_type, "i") == 0)
		return (format_integer(current));
	else if (ft_strcmp(current->conv_type, "u") == 0)
		return (format_unsigned(current));
	else if (ft_strcmp(current->conv_type, "x") == 0)
		return (format_hex(current, 0));
	else if (ft_strcmp(current->conv_type, "X") == 0)
		return (format_hex(current, 1));
	else if (ft_strcmp(current->conv_type, "%") == 0)
		return (format_percent(current));
	return (NULL);
}

static size_t	calculate_total_length(t_parse_set *head)
{
	t_parse_set	*current;
	char		*formatted_str;
	size_t		total_len;

	total_len = 0;
	current = head;
	while (current)
	{
		if (current->conv_type)
		{
			formatted_str = get_formatted_string(current);
			if (formatted_str)
			{
				total_len += ft_strlen(formatted_str);
				free(formatted_str);
			}
		}
		else if (current->data.s)
		{
			total_len += ft_strlen(current->data.s);
		}
		current = current->next;
	}
	return (total_len);
}

static void	copy_to_result(char *result, t_parse_set *head)
{
	t_parse_set	*current;
	char		*formatted_str;
	size_t		pos;

	pos = 0;
	current = head;
	while (current)
	{
		if (current->conv_type)
		{
			formatted_str = get_formatted_string(current);
			if (formatted_str)
			{
				size_t len = ft_strlen(formatted_str);
				ft_memcpy(result + pos, formatted_str, len);
				pos += len;
				free(formatted_str);
			}
		}
		else if (current->data.s)
		{
			size_t len = ft_strlen(current->data.s);
			ft_memcpy(result + pos, current->data.s, len);
			pos += len;
		}
		current = current->next;
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
