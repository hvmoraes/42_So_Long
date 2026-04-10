/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:45:05 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/03/10 15:45:09 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	get_size(t_data *data)
{
	char	*line;
	int		i;
	int		len;

	i = 0;
	line = get_next_line(data->map->fd);
	while (line && i < MAX_MAP_LINES - 1)
	{
		len = ft_strlen(line);
		if (len > 0 && line[len - 1] == '\n')
			len--;
		data->map->width = len * TILE_SIZE;
		data->map->lines[i] = ft_strdup(line);
		free(line);
		line = get_next_line(data->map->fd);
		i++;
	}
	free(line);
	data->map->lines[i] = NULL;
	data->map->height = i * TILE_SIZE;
}

void	put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static int	count_char_in_map(t_data *data, char c)
{
	int	i;
	int	j;
	int	count;

	j = 0;
	count = 0;
	while (data->map->lines[j])
	{
		i = 0;
		while (data->map->lines[j][i] && data->map->lines[j][i] != '\n')
		{
			if (data->map->lines[j][i] == c)
				count++;
			i++;
		}
		j++;
	}
	return (count);
}

void	count_entities(t_data *data)
{
	data->num_enemies = count_char_in_map(data, 'X');
	data->num_consumables = count_char_in_map(data, 'C');
}

void	draw_circle(int x, int y, int color, t_data *data)
{
	int	i;
	int	j;
	int	center_x;
	int	center_y;
	int	distance_squared;

	center_x = x + TILE_SIZE / 2;
	center_y = y + TILE_SIZE / 2;
	i = center_x - CIRCLE_RADIUS;
	while (i <= center_x + CIRCLE_RADIUS)
	{
		j = center_y - CIRCLE_RADIUS;
		while (j <= center_y + CIRCLE_RADIUS)
		{
			distance_squared = (i - center_x) * (i - center_x)
				+ (j - center_y) * (j - center_y);
			if (distance_squared <= CIRCLE_RADIUS * CIRCLE_RADIUS)
				put_pixel(data, i, j, color);
			j++;
		}
		i++;
	}
}

int	map_sizes(t_data *data)
{
	int	i;
	int	j;
	int	comp_size;

	i = 0;
	comp_size = data->map->width / TILE_SIZE;
	while (data->map->lines[i])
	{
		j = 0;
		while (data->map->lines[i][j] && data->map->lines[i][j] != '\n')
			j++;
		if (j != comp_size)
			return (0);
		i++;
	}
	return (1);
}
