/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <qwer10897@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 17:00:26 by minjeon2          #+#    #+#             */
/*   Updated: 2023/06/24 18:40:45 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

int	is_invalid_input(int fd, char buf[], char **backup, int *readsize)
{
	/*코드가 어떻게 작성되었는지는 모르지만 저같은 경우에는 처음 인자 받을때 
	read(fd, NULL, 0) < 0 일 경우에 정적변수가 비어있지 않으면 free해주는 조건을 붙였더니 해결되었습니다!*/
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (1);
	*readsize = read(fd, buf, BUFFER_SIZE);
	// if (!(*backup))
	// {
	// 	free_ptr(backup);
	// 	return (0);
	// }
	if (*readsize == -1 )
	{
		free_ptr(backup);
		//printf("?");
		return (1);
	}
	return (0);
}

int	copy_to_return(char **backup, char **return_value, int readsize)
{
	int	idx;

	idx = 0;
	if (!(*return_value))
	{
		free(*return_value);
		free_ptr(backup);
		//printf("?");
		return (0);
	}
	while ((*backup)[idx])
	{
		(*return_value)[idx] = (*backup)[idx];
		if ((*backup)[idx] == '\n')
		{
			(*return_value)[idx] = '\n';
			idx++;
			break;
		}
		idx++;
	}
	if (readsize == 0 && (!(**backup) || !(*backup)))
	{
		free(*return_value);
		free_ptr(backup);
		//printf("?");
		return (0);
	}
	(*return_value)[idx] = 0;
	return (1);
}

int	make_new_backup(char **new_backup, char **backup, char **return_value)
{
	int	new_backup_idx;
	int	backup_idx;
	int	backup_len;

	if (!new_backup)
	{
		free (*return_value);
		free_ptr(backup);
		return (0);
	}
	new_backup_idx = 0;
	backup_idx = ft_strlen(*backup, 0) + 1;
	backup_len = ft_strlen(*backup, 1);
	while (backup_idx < backup_len)
	{
		(*new_backup)[new_backup_idx] = (*backup)[backup_idx];
		new_backup_idx++;
		backup_idx++;
	}
	(*new_backup)[new_backup_idx] = 0;
	free_ptr(backup);
	*backup = *new_backup;
	return (1);
}

int	join_backup_and_buf(char **backup, char buf[])
{
	char *backup_saver;

	if (!(*backup) || !(**backup))
		*backup = ft_strdup("");
	backup_saver = ft_strjoin(*backup, buf);
	if (!backup_saver)
	{
		free_ptr(backup);
		//printf("?");
		return (0);
	}
	free_ptr(backup);
	*backup = backup_saver;
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		buf[BUFFER_SIZE + 1];
	char		*return_value;
	int			readsize;
	char		*new_backup;

	if (is_invalid_input(fd, buf, &backup, &readsize))
		return ((void *)0);
	if (readsize == 0 && !backup)
		return ((void *)0);
	while (readsize > 0)
	{	
		buf[readsize] = 0;
		if (!join_backup_and_buf(&backup, buf))
			return ((void *)0);
		if (ft_strchr(backup, '\n') || (readsize == 0))
			break ;
		readsize = read(fd, buf, BUFFER_SIZE);
	}
	return_value = malloc (sizeof(char) * ft_strlen(backup, 0) + ft_strchr(backup, '\n') + 1) ;
	if (!copy_to_return(&backup, &return_value, readsize))
		return ((void *)0);
	new_backup = malloc (sizeof (char) * \
	(ft_strlen(backup, 1) - ft_strlen(backup, 0)));
	if (!new_backup)
	{
		free(return_value);
		free_ptr(&backup);
		return ((void *)0);
	}
	if (!make_new_backup(&new_backup, &backup, &return_value))
		return ((void *)0);
	//printf("!");
	return (return_value);
}
