/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_varg.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoykim <seoykim@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 03:27:40 by seoykim           #+#    #+#             */
/*   Updated: 2025/07/19 04:43:46 by seoykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MANAGE_VARG
# define MANAGE_VARG

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include "basic_struct.h"

#define flag_num (1 << 0)
#define flag_str (1 << 1)

/* Function declarations */
void	set_varg(t_parse_set **vlist_p, va_list args);
bool	valid_varg(t_parse_set **vlist_p);
int		manage_args(va_list args, t_parse_set ***vlist, size_t *vlist_size);
t_parse_set	***set_varg_list(t_parse_set *head, size_t *vlist_size);
void	vlist_free(t_parse_set ***vlist, size_t vlist_size);
void	resize_vlist(t_parse_set ****vlist, size_t *s);
size_t	find_first_blank(t_parse_set ***vlist);
size_t	varg_num(t_parse_set **vlist_pos);
t_parse_set	***vlist_init(size_t vlist_size);
void	insert_vlist(t_parse_set *set, t_parse_set ***vlist, size_t pos, size_t *s);
void	insert_vlist_blank(t_parse_set *set, t_parse_set ***vlist, size_t *s);

/* Helper functions for set_varg */
size_t	find_max_type_size(t_parse_set *current);
t_data	extract_arg(va_list args, size_t max_type_size);
void	assign_data_to_nodes(t_parse_set *current, t_data arg);

#endif
