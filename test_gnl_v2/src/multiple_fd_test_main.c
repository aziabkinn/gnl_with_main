/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple_fd_test_main.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuksa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 16:18:58 by vkuksa            #+#    #+#             */
/*   Updated: 2017/12/15 16:19:05 by vkuksa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../.tmp_dir/get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_RESET   "\x1b[0m"

mode_t mode = S_IRUSR | S_IWUSR;

int		main(void)
{
	int		fd1;
	int		fd2;
	int		fd3;
	int		fd4;
	int		fd5;
	int		fd_res;
	int		gnl_ret;
	char	*line;

	gnl_ret = 0;
	line = NULL;
	fd1 = open("./tests/test_3", O_RDONLY);
	fd2 = open("./tests/test_4", O_RDONLY);
	fd3 = open("./tests/test_5", O_RDONLY);
	fd4 = open("./tests/test_6", O_RDONLY);
	fd5 = open("./tests/test_16", O_RDONLY);
	fd_res = open(".tmp_dir/multiple_fd_test",  O_RDWR | O_CREAT | O_APPEND, mode);

	if ((gnl_ret = get_next_line(fd1, &line)) != 1)
	{
		printf("%s\n", ANSI_COLOR_RED "Error, your function didn't return 1 on the 1st read" ANSI_COLOR_RESET);
		return (0);
	}
	else
	{
		write(fd_res, line, strlen(line));
		free(line);
		line = NULL;
	}

	if ((gnl_ret = get_next_line(fd2, &line)) != 1)
	{
		printf("%s\n", ANSI_COLOR_RED "Error, your function didn't return 1 on the 2nd read" ANSI_COLOR_RESET);
		return (0);
	}
	else
	{
		write(fd_res, line, strlen(line));
		free(line);
		line = NULL;
	}

	if ((gnl_ret = get_next_line(fd3, &line)) != 1)
	{
		printf("%s\n", ANSI_COLOR_RED "Error, your function didn't return 1 on the 3rd read" ANSI_COLOR_RESET);
		return (0);
	}
	else
	{
		write(fd_res, line, strlen(line));
		free(line);
		line = NULL;
	}

	if ((gnl_ret = get_next_line(fd4, &line)) != 1)
	{
		printf("%s\n", ANSI_COLOR_RED "Error, your function didn't return 1 on the 4th read" ANSI_COLOR_RESET);
		return (0);
	}
	else
	{
		write(fd_res, line, strlen(line));
		free(line);
		line = NULL;
	}

	if ((gnl_ret = get_next_line(fd5, &line)) != 1)
	{
		printf("%s\n", ANSI_COLOR_RED "Error, your function didn't return 1 on the 5th read" ANSI_COLOR_RESET);
		return (0);
	}
	else
	{
		write(fd_res, line, strlen(line));
		free(line);
		line = NULL;
	}

	if ((gnl_ret = get_next_line(fd4, &line)) != 1)
	{
		printf("%s\n", ANSI_COLOR_RED "Error, your function didn't return 1 on the 7th read" ANSI_COLOR_RESET);
		return (0);
	}
	else
	{
		write(fd_res, line, strlen(line));
		free(line);
		line = NULL;
	}

	if ((gnl_ret = get_next_line(fd3, &line)) != 1)
	{
		printf("%s\n", ANSI_COLOR_RED "Error, your function didn't return 1 on the 8th read" ANSI_COLOR_RESET);
		return (0);
	}
	else
	{
		write(fd_res, line, strlen(line));
		free(line);
		line = NULL;
	}

	if ((gnl_ret = get_next_line(fd2, &line)) != 1)
	{
		printf("%s\n", ANSI_COLOR_RED "Error, your function didn't return 1 on the 9th read" ANSI_COLOR_RESET);
		return (0);
	}
	else
	{
		write(fd_res, line, strlen(line));
		free(line);
		line = NULL;
	}

	if ((gnl_ret = get_next_line(fd1, &line)) != 1)
	{
		printf("%s\n", ANSI_COLOR_RED "Error, your function didn't return 1 on the 10th read" ANSI_COLOR_RESET);
		return (0);
	}
	else
	{
		write(fd_res, line, strlen(line));
		free(line);
		line = NULL;
	}

	if ((gnl_ret = get_next_line(fd3, &line)) != 1)
	{
		printf("%s\n", ANSI_COLOR_RED "Error, your function didn't return 1 on the 11th read" ANSI_COLOR_RESET);
		return (0);
	}
	else
	{
		write(fd_res, line, strlen(line));
		free(line);
		line = NULL;
	}

	if ((gnl_ret = get_next_line(fd5, &line)) != 1)
	{
		printf("%s\n", ANSI_COLOR_RED "Error, your function didn't return 1 on the 12th read" ANSI_COLOR_RESET);
		return (0);
	}
	else
	{
		write(fd_res, line, strlen(line));
		free(line);
		line = NULL;
	}

	if ((gnl_ret = get_next_line(fd2, &line)) != 1)
	{
		printf("%s\n", ANSI_COLOR_RED "Error, your function didn't return 1 on the 13th read" ANSI_COLOR_RESET);
		return (0);
	}
	else
	{
		write(fd_res, line, strlen(line));
		free(line);
		line = NULL;
	}

	if ((gnl_ret = get_next_line(fd4, &line)) != 1)
	{
		printf("%s\n", ANSI_COLOR_RED "Error, your function didn't return 1 on the 14th read" ANSI_COLOR_RESET);
		return (0);
	}
	else
	{
		write(fd_res, line, strlen(line));
		free(line);
		line = NULL;
	}

	if ((gnl_ret = get_next_line(fd1, &line)) != 1)
	{
		printf("%s\n", ANSI_COLOR_RED "Error, your function didn't return 1 on the last read" ANSI_COLOR_RESET);
		return (0);
	}
	else
	{
		write(fd_res, line, strlen(line));
		free(line);
		line = NULL;
	}

	close(fd1);
	close(fd2);
	close(fd3);
	close(fd4);
	close(fd5);
	close(fd_res);

	system("if [[ $(leaks multiple_fd_test | grep \" leaked \") = \"Process \"*\": 0 leaks for 0 total leaked bytes.\" ]];\nthen echo $(tput setaf 2)\"No Memory Leaks\"$(tput sgr0)\nelse echo $(tput setaf 1)\"Memory Leaks Detected\"$(tput sgr0)\nleaks multiple_fd_test | grep \" leaked \"\nfi");
	return (0);
}
