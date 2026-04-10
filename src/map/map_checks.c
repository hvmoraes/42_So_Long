/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 22:00:03 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/03/10 16:01:25 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	closed_map(t_data *data)
{
	int	i;
	int	map_width;
	int	map_height;

	map_height = data->map->height / TILE_SIZE;
	map_width = data->map->width / TILE_SIZE;
	i = 0;
	while (i < map_width && data->map->lines[0][i] != '\n')
	{
		if (data->map->lines[0][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < map_width && data->map->lines[map_height - 1][i] != '\0')
	{
		if (data->map->lines[map_height - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	return (verify_height(data, map_height, map_width, i));
}

int	invalid_character(t_data *data, int i, int j)
{
	if (data->map->lines[i][j] != 'X'
				&& data->map->lines[i][j] != 'C'
				&& data->map->lines[i][j] != '0'
				&& data->map->lines[i][j] != '1')
	{
		if (data->map->lines[i][j] == '\0')
		{
			if (data->map->lines[i][j - 1] == '\n')
			{
				if (data->map->lines[i][j - 2] != '1')
					return (0);
			}
			else if (data->map->lines[i][j - 1] != '1')
				return (0);
		}
		else if (data->map->lines[i][j] == '\n')
		{
			if (data->map->lines[i][j - 1] != '1')
				return (0);
		}
		else
			return (0);
	}
	return (1);
}

int	valid_character(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map->lines[i])
	{
		j = 0;
		while (data->map->lines[i][j])
		{
			if (data->map->lines[i][j] != 'P' && data->map->lines[i][j] != 'E')
				if(invalid_character(data, i, j) == 0)
				 	return (0);
			j++;
		}
		i++;
	}
	return (1);
}
