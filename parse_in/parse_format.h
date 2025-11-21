#ifndef PARSE_FORMAT_H
# define PARSE_FORMAT_H

# include "basic_struct.h"

/* parse_format */
//size_t  find_next_conv(const char *format, size_t current_idx);
void    parse_format(const char *format, t_parse_set **head, t_parse_set **tail);

#endif