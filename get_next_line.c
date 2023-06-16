/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <qwer10897@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 17:00:26 by minjeon2          #+#    #+#             */
/*   Updated: 2023/06/16 22:05:02 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*backup;
	char		buf[BUFFER_SIZE + 1];
	char		*return_value;
	//char		*temp;
	//char		*new_backup;
	int			backup_idx;	
	int			readsize;
	int			return_value_idx;
	//int			start_idx;

	return_value = (void *)0;
	backup_idx = 0;
	return_value_idx = 0;
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (0); //invalid BufferSize && fd
	while ((readsize = read(fd, buf, BUFFER_SIZE)) > 0) //buf에 BUFFER_SIZE만큼 읽어들인다.
	{
		buf[readsize] =  0; //buf 끝에 null 붙이기
		//buf = change_nl_to_null(buf);
		if (!(backup))
			backup = ft_strdup("");
		backup = ft_strjoin(backup, buf);
		//if (!temp)
		//{
	//		backup = 0;
	//		free(backup);
	//		return (0);
	//	}
		//if (backup)
		//	free(backup);
		//backup = temp;
		//start_idx = ft_strchr(backup, '\n');
		if (ft_strchr(backup,'\n'))
			break;
	}
	if (readsize < 0)
			return (0);
	buf[readsize] = 0;
	return_value = (char *) malloc (sizeof (char) * ft_strlen(backup));//인덱스 센 만큼 malloc
	while (backup[backup_idx] && backup[backup_idx] != '\n' && backup[backup_idx] != '\0')
	{
		return_value[return_value_idx] = backup[backup_idx];
		return_value_idx++;
		backup_idx++;
	}
	//new_backup = (char *) malloc (sizeof (char) * (backup_idx - start_idx + 1));
	if (!(*backup))
		return ((void *) 0);
	backup = &(backup[++backup_idx]);
	//if (backup):
	//	free(backup);
	//backup = new_backup;
	if (!backup)
		return ((void *) 0);
	return (return_value);
} 
#include <stdio.h>
int main(void)
{
	int 	fd;
	char 	*line;


	fd = 0;
	fd = open("../tmp", O_RDONLY);
	line = get_next_line(fd);
 	while (line)
    {
		printf("%s\n",line);
    	line = get_next_line(fd);
	}
	return (0);
}
