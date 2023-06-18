/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <qwer10897@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 17:06:34 by minjeon2          #+#    #+#             */
/*   Updated: 2023/06/18 23:01:56 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

size_t	ft_strlen(char *s, int	only_null);
char	*get_next_line(int fd);
char	*change_nl_to_null(char *buf);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *s, int c);
void	*free_ptr(char **ptr);
int	copy_to_return(char **backup, char **return_value);