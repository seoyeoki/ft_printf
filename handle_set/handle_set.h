#ifndef HANDLE_SET_H
# define HANDLE_SET_H

#include <stdbool.h>
#include "basic_struct.h"

/* handle_set_util */
t_parse_set	*parse_set_init();
void	    set_lstadd_last(t_parse_set **head, t_parse_set **tail, t_parse_set *set);
void	    parse_set_free(t_parse_set **head, t_parse_set **tail);

/* handle_set_parse */
const char	*substr_moving_idx(const char *format, size_t *cur, size_t end);
void	set_conv(const char *format, size_t *cur, t_parse_set *set);
void	set_str(const char *format, size_t cur, size_t next, t_parse_set *set);

/* condition_check */
bool	is_argnum(const char *format, size_t cur_idx, size_t *end_idx);
bool	is_width(const char *format, size_t cur_idx, size_t *end_idx);
bool	is_length_modifier(const char *format, size_t cur_idx, size_t *end_idx);
bool	is_conversion(const char *format, size_t cur_idx, size_t *end_idx);
bool	is_flag(char c);
bool	is_precision(const char *format, size_t cur_idx, size_t *end_idx);

#endif