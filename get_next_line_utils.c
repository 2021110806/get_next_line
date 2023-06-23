/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <qwer10897@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 23:32:07 by minjeon2          #+#    #+#             */
/*   Updated: 2023/06/23 19:54:10 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s, int	only_null)
{
	size_t	return_value;

	return_value = 0;
	if (only_null)
	{
		while (s && *s)
		{
			return_value++;
			s++;
		}
		return (return_value);
	}
	while (s && (*s && *s !='\n'))
	{
		return_value++;
		s++;
	}
	return (return_value);
}

void	*free_ptr(char **ptr)
{
	if (*ptr != 0)
	{
		free(*ptr);
		*ptr = NULL;
	}
	return ((void *) 0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		s1_len;
	int		s2_len;
	int		return_value_i;
	int		s_i;
	char	*return_value;

	s_i = 0;
	return_value_i = 0;
	s1_len = ft_strlen(s1, 1);
	s2_len = ft_strlen(s2, 1);
	return_value = (char *) malloc (sizeof (char) * (s1_len + s2_len) + 1);
	if (!return_value)
		return ((void *)0);
	while (return_value_i < s1_len)
		return_value[return_value_i++] = s1[s_i++];
	s_i = 0;
	while (return_value_i < s2_len + s1_len)
	{
		return_value[return_value_i] = s2[s_i];
		return_value_i++;
		s_i++;
	}
	return_value[return_value_i] = '\0';
	return (return_value);
}
char	*ft_strdup(const char *s1)
{
	char	*copy;
	char	*ret;
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (s1[len])
		len++;
	copy = (char *) malloc (len * sizeof (char) + 1);
	if (!copy)
		return ((void *)0);
	ret = copy;
	i = 0;
	while (*s1)
	{
		*copy = *s1;
		copy++;
		s1++;
	}
	*copy = '\0';
	return (ret);
}
char	*ft_strchr(const char *s, int c)
{
	char	*return_value;
	char	*char_s;

	char_s = (char *) s;
	return_value = (void *) 0;
	while (*char_s != '\0')
	{
		if (*char_s == (char)c)
		{
			return_value = char_s;
			break ;
		}
		char_s++;
	}
	if ((char)c == 0)
		return (char_s);
	return (return_value);
}

void	*ft_calloc(size_t count, size_t size)
{
	char			*return_value;
	unsigned long	i;

	i = 0;
	return_value = (char *) malloc (sizeof (char) * count * size);
	if (!return_value)
		return ((void *)0);
	while (i < count * size)
		return_value[i++] = 0;
	return ((void *)return_value);
}