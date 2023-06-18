/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <qwer10897@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 17:00:26 by minjeon2          #+#    #+#             */
/*   Updated: 2023/06/19 00:33:03 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>
int	copy_to_return(char **backup, char **return_value)
{
	int	return_value_idx;
	int	backup_idx;

	return_value_idx = 0;
	backup_idx = 0;
	if (!return_value)
		return (-1);
	while ((*backup)[backup_idx] && (*backup)[backup_idx] != '\n' && (*backup)[backup_idx] != '\0')
	{
		(*return_value)[return_value_idx] = (*backup)[backup_idx];
		return_value_idx++;
		backup_idx++;
	}
	return (backup_idx);
}

void make_new_backup(char **new_backup, char **backup)
{
	int	new_backup_idx;
	int	backup_len;

	new_backup_idx = 0;
	backup_len = ft_strlen(*backup, 1);
	new_backup_idx = ft_strlen(*backup, 0);
	while (new_backup_idx < backup_len)
	{
		(*new_backup)[new_backup_idx] = (*backup)[new_backup_idx];
		new_backup_idx++; 
	}
	(*new_backup)[new_backup_idx] = 0;
	free_ptr(backup);
	backup = new_backup;
	free(*new_backup);
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		buf[BUFFER_SIZE + 1];
	char		*return_value;
	int			readsize;
	char		*new_backup;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (0);
	readsize = read(fd, buf, BUFFER_SIZE);
	if (readsize == -1)
	{
		(free_ptr(&backup));
		return (0);
	}
	while (readsize >= 0)
	{	
		buf[readsize] = 0;
		if (!(backup) || !(*backup))
			backup = ft_strdup("");
		new_backup = ft_strjoin(backup, buf);
		if (!new_backup)
			return (free_ptr(&backup));
		free(backup);
		backup = new_backup;
		if (ft_strchr(backup, '\n') || (readsize == 0))
			break ;
		readsize = read(fd, buf, BUFFER_SIZE);
	}
	return_value = malloc (sizeof (char) * ft_strlen(backup, 0));
	if (!return_value)
		return (free_ptr(&backup));
	copy_to_return(&backup, &return_value);
	if (readsize == 0 && (!(*backup) || !backup))
	{
		free(return_value);
		return (free_ptr(&backup));
	}
	new_backup = malloc (sizeof (char) * \
	(ft_strlen(backup, 0) - ft_strlen(backup, 1)) + 1);
	make_new_backup(&new_backup, &backup);
	return (return_value);
}

// #include <stdio.h>
// int main(void)
// {
// 	int 	fd;
// 	char 	*line;

// 	fd = open("../tmp", O_RDONLY);
// 	line = get_next_line(fd);
//  	while (line)
//     {
// 		printf("%s\n",line);
// 		free(line);
//     	line = get_next_line(fd);
// 	}
// //system("leaks a.out");
// 	return (0);
// } 