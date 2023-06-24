/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <qwer10897@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 22:54:24 by minjeon2          #+#    #+#             */
/*   Updated: 2023/06/24 22:06:09 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
	int 	fd;
	char 	*line;

	fd = open("/Users/minjeon2/francinette/tests/get_next_line/fsoares/multiple_nl.txt", O_RDONLY);
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
