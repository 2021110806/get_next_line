/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <qwer10897@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 17:06:34 by minjeon2          #+#    #+#             */
/*   Updated: 2023/06/24 22:21:03 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

int	is_invalid_input(int fd, char buf[], char **backup, int *readsize);
int	make_new_backup(char **new_backup, char **backup);
size_t	ft_strlen(char *s, int	only_null);
char	*get_next_line(int fd);
int	join_backup_and_buf(char **backup, char buf[]);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *s1);
int		ft_strchr(const char *s, int c);
void	*free_ptr(char **ptr);
int		copy_to_return(char **backup, char **return_value, int readsize);