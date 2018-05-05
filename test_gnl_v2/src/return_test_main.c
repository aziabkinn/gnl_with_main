/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_test_main.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuksa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 14:13:48 by vkuksa            #+#    #+#             */
/*   Updated: 2017/12/15 14:13:51 by vkuksa           ###   ########.fr       */
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

int		main(void)
{
	char	*line;
	int		ret;
	int		ret_count;
	int		fd;
	int		fd2;

	line = NULL;
	ret = 0;

	printf("\n%s\n", "Negative fd test 1:");
	if ((ret = get_next_line(-1, &line)) != -1)
	{
		printf("%s%d%s\n", ANSI_COLOR_RED "Error, your function returned ", ret, " instead of -1" ANSI_COLOR_RESET);
		if (ret == 1)
			free(line);
		line = NULL;
	}
	else
		printf(ANSI_COLOR_GREEN "OK" ANSI_COLOR_RESET "\n");
	//system("leaks returtn_test_gnl");
	// system("if [[ $(leaks return_test_gnl | grep \" leaked \") = \"Process \"*\": 0 leaks for 0 total leaked bytes.\" ]];\nthen echo $(tput setaf 2)\"No Memory Leaks\"$(tput sgr0)\nelse echo $(tput setaf 1)\"Memory Leaks Detected\"$(tput sgr0)\nleaks return_test_gnl | grep \" leaked \"\nfi");

	printf("\n%s\n", "Negative fd test 2:");
	if ((ret = get_next_line(-42, &line)) != -1)
	{
		printf("%s%d%s\n", ANSI_COLOR_RED "Error, your function returned ", ret, " instead of -1" ANSI_COLOR_RESET);
		if (ret == 1)
			free(line);
		line = NULL;
	}
	else
		printf(ANSI_COLOR_GREEN "OK" ANSI_COLOR_RESET "\n");
	//system("leaks returtn_test_gnl");
	// system("if [[ $(leaks return_test_gnl | grep \" leaked \") = \"Process \"*\": 0 leaks for 0 total leaked bytes.\" ]];\nthen echo $(tput setaf 2)\"No Memory Leaks\"$(tput sgr0)\nelse echo $(tput setaf 1)\"Memory Leaks Detected\"$(tput sgr0)\nleaks return_test_gnl | grep \" leaked \"\nfi");

	printf("\n%s\n", "Invalid fd test 1:");
	if ((ret = get_next_line(100, &line)) != -1)
	{
		printf("%s%d%s\n", ANSI_COLOR_RED "Error, your function returned ", ret, " instead of -1" ANSI_COLOR_RESET);
		if (ret == 1)
			free(line);
		line = NULL;
	}
	else
		printf(ANSI_COLOR_GREEN "OK" ANSI_COLOR_RESET "\n");
	//system("leaks returtn_test_gnl");
	// system("if [[ $(leaks return_test_gnl | grep \" leaked \") = \"Process \"*\": 0 leaks for 0 total leaked bytes.\" ]];\nthen echo $(tput setaf 2)\"No Memory Leaks\"$(tput sgr0)\nelse echo $(tput setaf 1)\"Memory Leaks Detected\"$(tput sgr0)\nleaks return_test_gnl | grep \" leaked \"\nfi");

	printf("\n%s\n", "Invalid fd test 2:");
	if ((ret = get_next_line(42, &line)) != -1)
	{
		printf("%s%d%s\n", ANSI_COLOR_RED "Error, your function returned ", ret, " instead of -1" ANSI_COLOR_RESET);
		if (ret == 1)
			free(line);
		line = NULL;
	}
	else
		printf(ANSI_COLOR_GREEN "OK" ANSI_COLOR_RESET "\n");
	//system("leaks returtn_test_gnl");
	// system("if [[ $(leaks return_test_gnl | grep \" leaked \") = \"Process \"*\": 0 leaks for 0 total leaked bytes.\" ]];\nthen echo $(tput setaf 2)\"No Memory Leaks\"$(tput sgr0)\nelse echo $(tput setaf 1)\"Memory Leaks Detected\"$(tput sgr0)\nleaks return_test_gnl | grep \" leaked \"\nfi");

	ret_count = 0;
	fd = open("./tests/test_1", O_RDONLY);

	printf("\n%s\n", "Empty input test 1:");
	if ((ret = get_next_line(fd, &line)) != 0)
	{
		printf("%s%d%s\n", ANSI_COLOR_RED "Error, your function returned ", ret, " instead of 0" ANSI_COLOR_RESET);
		if (ret == 1)
			free(line);
		line = NULL;
	}
	else
		printf(ANSI_COLOR_GREEN "OK" ANSI_COLOR_RESET "\n");
	//system("leaks returtn_test_gnl");
	// system("if [[ $(leaks return_test_gnl | grep \" leaked \") = \"Process \"*\": 0 leaks for 0 total leaked bytes.\" ]];\nthen echo $(tput setaf 2)\"No Memory Leaks\"$(tput sgr0)\nelse echo $(tput setaf 1)\"Memory Leaks Detected\"$(tput sgr0)\nleaks return_test_gnl | grep \" leaked \"\nfi");

	printf("\n%s\n", "Empty input test 2:");
	for (int i = 0; i < 10; i++)
	{
		ret = get_next_line(fd, &line);
		ret_count += (ret < 0 ? -ret : ret);
		if (ret == 1)
			free(line);
		line = NULL;
	}
	if (ret_count == 0)
		printf(ANSI_COLOR_GREEN "OK" ANSI_COLOR_RESET "\n");
	else
		printf(ANSI_COLOR_RED "Error, your function should have retutned 0 ten times" ANSI_COLOR_RESET "\n");
	//system("leaks returtn_test_gnl");
	// system("if [[ $(leaks return_test_gnl | grep \" leaked \") = \"Process \"*\": 0 leaks for 0 total leaked bytes.\" ]];\nthen echo $(tput setaf 2)\"No Memory Leaks\"$(tput sgr0)\nelse echo $(tput setaf 1)\"Memory Leaks Detected\"$(tput sgr0)\nleaks return_test_gnl | grep \" leaked \"\nfi");

	ret_count = 0;
	fd2 = open("./tests/test_4", O_RDONLY);

	printf("\n%s\n", "Readable input test 1:");
	if ((ret = get_next_line(fd2, &line)) != 1)
	{
		printf("%s%d%s\n", ANSI_COLOR_RED "Error, your function returned ", ret, " instead of 1" ANSI_COLOR_RESET);
		line = NULL;
	}
	else
	{
		free(line);
		printf(ANSI_COLOR_GREEN "OK" ANSI_COLOR_RESET "\n");
	}
	//system("leaks returtn_test_gnl");
	// system("if [[ $(leaks return_test_gnl | grep \" leaked \") = \"Process \"*\": 0 leaks for 0 total leaked bytes.\" ]];\nthen echo $(tput setaf 2)\"No Memory Leaks\"$(tput sgr0)\nelse echo $(tput setaf 1)\"Memory Leaks Detected\"$(tput sgr0)\nleaks return_test_gnl | grep \" leaked \"\nfi");

	printf("\n%s\n", "Readable input test 2:");
	for (int i = 0; i < 10; i++)
	{
		ret = get_next_line(fd2, &line);
		ret_count += (ret < 0 ? -ret : ret);
		if (ret == 1)
			free(line);
		else
			break;
		line = NULL;
	}
	if (ret_count == 10)
		printf(ANSI_COLOR_GREEN "OK" ANSI_COLOR_RESET "\n");
	else
		printf(ANSI_COLOR_RED "Error, your function should have retutned 1 ten times" ANSI_COLOR_RESET "\n");
	//system("leaks returtn_test_gnl");
	// system("if [[ $(leaks return_test_gnl | grep \" leaked \") = \"Process \"*\": 0 leaks for 0 total leaked bytes.\" ]];\nthen echo $(tput setaf 2)\"No Memory Leaks\"$(tput sgr0)\nelse echo $(tput setaf 1)\"Memory Leaks Detected\"$(tput sgr0)\nleaks return_test_gnl | grep \" leaked \"\nfi");

	ret_count = 0;

	printf("\n%s\n", "Readable input test 3:");
	for (int i = 0; i < 24; i++)
	{
		ret = get_next_line(fd2, &line);
		ret_count += (ret < 0 ? -ret : ret);
		if (ret == 1)
			free(line);
		else
			break;
		line = NULL;
	}
	if (ret_count == 24)
		printf(ANSI_COLOR_GREEN "OK" ANSI_COLOR_RESET "\n");
	else
		printf(ANSI_COLOR_RED "Error, your function should have retutned 1 twenty four times" ANSI_COLOR_RESET "\n");
	//system("leaks returtn_test_gnl");
	// system("if [[ $(leaks return_test_gnl | grep \" leaked \") = \"Process \"*\": 0 leaks for 0 total leaked bytes.\" ]];\nthen echo $(tput setaf 2)\"No Memory Leaks\"$(tput sgr0)\nelse echo $(tput setaf 1)\"Memory Leaks Detected\"$(tput sgr0)\nleaks return_test_gnl | grep \" leaked \"\nfi");

	ret_count = 0;

	printf("\n%s\n", "Readable input test 4:");
	for (int i = 0; i < 10; i++)
	{
		ret = get_next_line(fd2, &line);
		ret_count += (ret < 0 ? -ret : ret);
		if (ret == 1)
			free(line);
		line = NULL;
	}
	if (ret_count == 0)
		printf(ANSI_COLOR_GREEN "OK" ANSI_COLOR_RESET "\n");
	else
		printf(ANSI_COLOR_RED "Error, your function should have retutned 0 ten times" ANSI_COLOR_RESET "\n");
	//system("leaks returtn_test_gnl");
	system("if [[ $(leaks return_test_gnl | grep \" leaked \") = \"Process \"*\": 0 leaks for 0 total leaked bytes.\" ]];\nthen echo $(tput setaf 2)\"No Memory Leaks\"$(tput sgr0)\nelse echo $(tput setaf 1)\"Memory Leaks Detected\"$(tput sgr0)\nleaks return_test_gnl | grep \" leaked \"\nfi");


	close(fd);
	close(fd2);

	return (0);
}
