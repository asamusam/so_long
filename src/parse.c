/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asamuilk <asamuilk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:42:12 by asamuilk          #+#    #+#             */
/*   Updated: 2024/05/29 17:30:34 by asamuilk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>

static void	allocate_map(t_vars *vars, char *file)
{
	char	*line;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		error("Error\nopen map file", PERROR);
	line = ft_getline(fd);
	vars->m_height = 0;
	vars->m_width = (int)ft_strlen(line) - 1;
	while (line)
	{
		if ((int)ft_strlen(line) - 1 != vars->m_width)
			error("Error\nMap is not a rectangle!\n", WRITE);
		free(line);
		line = ft_getline(fd);
		vars->m_height ++;
	}
	free(line);
	vars->map = (char **)malloc(sizeof(char *) * vars->m_height);
	if (!vars->map)
		error("malloc", PERROR);
	if (close(fd) == -1)
		error("close", WRITE);
}

static void	fill_map(t_vars *vars, char *file)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		error("Error\nopen map file", PERROR);
	i = 0;
	line = ft_getline(fd);
	while (line)
	{
		vars->map[i] = line;
		line = ft_getline(fd);
		i ++;
	}
	if (close(fd) == -1)
		error("close", PERROR);
}

void	parse_map(t_vars *vars, char *file)
{
	allocate_map(vars, file);
	check_map_size(vars);
	fill_map(vars, file);
	check_map_content(vars);
	check_path(vars);
}
