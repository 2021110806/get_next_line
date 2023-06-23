/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <qwer10897@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 17:00:26 by minjeon2          #+#    #+#             */
/*   Updated: 2023/06/23 23:24:51 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

int	is_invalid_input(int fd, char buf[], char **backup, int *readsize)
{
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (1);
	*readsize = read(fd, buf, BUFFER_SIZE);
	if (*readsize == -1)
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

void make_new_backup(char **new_backup, char **backup)
{
	int	new_backup_idx;
	int	backup_idx;
	int	backup_len;

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
}

int	join_backup_and_buf(char **backup, char **new_backup, char buf[])
{
	if (!(*backup) || !(**backup))
		*backup = ft_strdup("");
	*new_backup = ft_strjoin(*backup, buf);
	if (!(*new_backup))
	{
		free_ptr(backup);
		//printf("?");
		return (0);
	}
	free_ptr(backup);
	*backup = *new_backup;
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
	while (readsize >= 0)
	{	
		buf[readsize] = 0;
		if (!join_backup_and_buf(&backup, &new_backup, buf))
			return ((void *)0);
		if (ft_strchr(backup, '\n') || (readsize == 0))
			break ;
		readsize = read(fd, buf, BUFFER_SIZE);
	}
	int is_two;
	if (ft_strchr(backup, '\n'))
		is_two = 2;
	else
		is_two = 1;
	return_value = malloc (sizeof(char) * ft_strlen(backup, 0) + is_two);
	if (!copy_to_return(&backup, &return_value, readsize))
		return ((void *)0);
	new_backup = malloc (sizeof (char) * \
	(ft_strlen(backup, 1) - ft_strlen(backup, 0)));
	if (!new_backup)
	{
		free (return_value);
		return (free_ptr(&backup));
	}
	make_new_backup(&new_backup, &backup);
	//printf("!");
	return (return_value);
}
