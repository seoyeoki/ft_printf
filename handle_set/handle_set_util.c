/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_set_util.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 00:52:31 by seoykim           #+#    #+#             */
/*   Updated: 2025/07/16 01:06:23 by seoykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handle_set.h"

t_parse_set	*parse_set_init(void)
{
	t_parse_set	*set;

	set = (t_parse_set *)malloc(sizeof(t_parse_set));
	if (!set)
		return (NULL);
	*set = (t_parse_set){0};
	set->precision = -1;
	return (set);
}

void	set_lstadd_last(t_parse_set **head, t_parse_set **tail,
			t_parse_set *set)
{
	if (*head == NULL)
	{
		*head = set;
		*tail = set;
	}
	else
	{
		(*tail)->next = set;
		*tail = (*tail)->next;
	}
}

void	parse_set_free(t_parse_set **head, t_parse_set **tail)
{
	t_parse_set	*free_ptr;

	while (*head)
	{
		free_ptr = *head;
		*head = (*head)->next;
		if (free_ptr->length_modifier)
			free(free_ptr->length_modifier);
		if (free_ptr->conv_type)
			free(free_ptr->conv_type);
		if (free_ptr->data.s && !free_ptr->conv_type)
			free(free_ptr->data.s);
		free(free_ptr);
	}
	*head = NULL;
	*tail = NULL;
}

const char	*substr_moving_idx(const char *format, size_t *cur, size_t end)
{
	const char	*substr;

	substr = (const char *)ft_substr(format, *cur, end - *cur);
	*cur = end;
	return (substr);
}

void	set_str(const char *format, size_t cur, size_t next, t_parse_set *set)
{
	if (set->length_modifier)
		free(set->length_modifier);
	if (set->conv_type)
		free(set->conv_type);
	if (set->data.s)
		free(set->data.s);
	*set = (t_parse_set){.precision = -1, };
	set->data.s = ft_substr(format, cur, next - cur);
}
