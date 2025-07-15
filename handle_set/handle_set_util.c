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

parse_set	*parse_set_init()
{
	parse_set	*set;

	set = (parse_set *)malloc(sizeof(parse_set));
	*set = (parse_set) { 0, };
	return (set);
}

parse_set	*set_lstadd_last(set)
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
