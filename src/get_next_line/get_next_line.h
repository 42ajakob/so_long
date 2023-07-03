/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajakob <ajakob@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 00:13:53 by ajakob            #+#    #+#             */
/*   Updated: 2023/06/17 19:32:16 by ajakob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

void			ft1_strlcpy(char *dst, const char *src, size_t dstsize);
char			*ft1_strjoin(char *s1, char *s2);
char			*ft1_substr(char *s, unsigned int start, size_t len);
char			*ft1_not_free_substr(char *s, unsigned int start, size_t len);
char			*get_next_line(int fd);

#endif