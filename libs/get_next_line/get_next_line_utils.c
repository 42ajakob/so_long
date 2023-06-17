/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajakob <ajakob@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 00:13:57 by ajakob            #+#    #+#             */
/*   Updated: 2023/06/17 19:33:20 by ajakob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft1_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

static size_t	ft1_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;
	size_t	dstlen;
	size_t	i;

	srclen = ft1_strlen(src);
	i = 0;
	while (i < dstsize && dst[i])
		i++;
	dstlen = i;
	if (dstlen == dstsize)
		return (dstlen + srclen);
	ft1_strlcpy(&dst[dstlen], src, dstsize - dstlen);
	return (dstlen + srclen);
}

char	*ft1_strjoin(char *s1, char *s2)
{
	char	*str;
	char	*str_p;
	size_t	size;

	if (!s1 && !s2)
		return (NULL);
	size = ft1_strlen(s1) + ft1_strlen(s2) + 1;
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	str_p = str;
	while (size--)
	{
		str_p = 0;
		str_p++;
	}
	ft1_strlcpy(str, s1, ft1_strlen(s1) + 1);
	ft1_strlcat(str, s2, size);
	free(s1);
	free(s2);
	return (str);
}

char	*ft1_substr(char *s, unsigned int start, size_t len)
{
	char	*str;

	str = ft1_not_free_substr(s, start, len);
	free(s);
	return (str);
}

char	*ft1_not_free_substr(char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	srclen;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	srclen = ft1_strlen(s);
	if (srclen > start)
	{
		while (i < len && s[start + i])
			i++;
		len = i;
	}
	else
		return (NULL);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	ft1_strlcpy(str, &s[start], len + 1);
	return (str);
}
