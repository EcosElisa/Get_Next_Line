/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobrinh <esobrinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 16:11:11 by esobrinh          #+#    #+#             */
/*   Updated: 2022/10/25 18:34:34 by esobrinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
//#include "get_next_line.h"
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

// int main()
// {
// 	int	fd;
// 	char *line;
	
// 	line = "";
// 	fd = open("teste3.txt", O_RDONLY);
// 	if (fd == -1)
// 	{
// 		printf("Failed to open and read the file.\n");
// 		return (1);
// 	}
// 	while (line)
// 	{
// 		line = get_next_line(fd);
// 		printf("%s", line);
// 		free (line);
// 	}
// 	close(fd);
// 	return (0);
// }

int main()
{
	int fd;
	int	fd2;
	int fd3;
	char *line = "";
	char *line2 = "";
	char *line3 = "";

	fd = open("teste1.txt", O_RDONLY);
	fd2 = open("teste2.txt", O_RDONLY);
	fd3 = open("teste3.txt", O_RDONLY);
	if (fd == -1 || fd2 == -1 || fd3 == -1)
	{
		printf("Failed to open and read the file.\n");
		return (1);
	}
	while (line && line2 && line3)
	{
		line = get_next_line(fd);
		line2 = get_next_line(fd2);
		line3 = get_next_line(fd3);
		printf("%s", line);
		printf("%s", line2);
		printf("%s", line3);
		free (line);
		free (line2);
		free (line3);
	}
	close(fd);
	close(fd2);
	close(fd3);
	return (0);
}