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

t_parse_set	*parse_set_init()
{
	t_parse_set	*set;

	set = (t_parse_set *)malloc(sizeof(t_parse_set));
	*set = (t_parse_set) { .precision = -1, };
	return (set);
}

t_parse_set	*set_lstadd_last(set)
{
	if (head == NULL)
	{
		head = set;
		tail = set;
	}
	else
	{
		tail->next = set;
		tail = tail->next;
	}
}

void	parse_set_free()
{
	t_parse_set	*free_ptr;

	while (head)
	{
		free_ptr = head;
		head = head->next;
		free(free_ptr);
	}
}
