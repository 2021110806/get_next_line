/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <qwer10897@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 22:54:24 by minjeon2          #+#    #+#             */
/*   Updated: 2023/06/23 23:18:25 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
	int 	fd;
	char 	*line;

	fd = open("../tmp", O_RDONLY);
	line = get_next_line(fd);
 	while (line)
    {
		printf("%s",line);
		free(line);
    	line = get_next_line(fd);
	}
	//system("leaks a.out");
	return (0);
} 
