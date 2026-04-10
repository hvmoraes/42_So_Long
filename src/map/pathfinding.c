/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 13:15:40 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/03/11 12:29:22 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	pacman_gif_utils(t_data *data, int elapsed_time, struct timeval now)
{
	if (elapsed_time >= GIF_RATE || elapsed_time < 0)
	{
		enemy_gif(data, 1);
		pacman_gif(data, 1);
		data->pacman->last_gif = now;
	}
	else
	{
		enemy_gif(data, 0);
		pacman_gif(data, 0);
	}
}

static char	**array_dup(char **array)
{
	char	**new;
	int		i;

	i = 0;
	while (array[i])
		i++;
	new = malloc(sizeof(char *) * (i + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (array[i])
	{
		new[i] = ft_strdup(array[i]);
		i++;
	}
	new[i] = NULL;
	return (new);
}

static void	free_array_dup(char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

static int	can_p(char **lines, int x, int y, int dir)
{
	char	**map_dup;
	int		result;

	if (dir == 0)
	{
		map_dup = array_dup(lines);
		if (!map_dup)
			return (0);
		result = can_p(map_dup, x, y, 5);
		free_array_dup(map_dup);
		return (result);
	}
	if (x < 0 || y < 0 || !lines[x] || !lines[x][y]
		|| lines[x][y] == '1' || lines[x][y] == '\n')
		return (0);
	if (lines[x][y] == 'P')
		return (1);
	lines[x][y] = '1';
	if (dir != 2 && can_p(lines, x, y + 1, 1))
		return (1);
	if (dir != 1 && can_p(lines, x, y - 1, 2))
		return (1);
	if (dir != 4 && can_p(lines, x + 1, y, 3))
		return (1);
	if (dir != 3 && can_p(lines, x - 1, y, 4))
		return (1);
	return (0);
}

int	valid_path(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map->lines[i])
	{
		j = 0;
		while (data->map->lines[i][j] && data->map->lines[i][j] != '\n')
		{
			if ((data->map->lines[i][j] == 'C'
					|| data->map->lines[i][j] == 'E')
				&& !can_p(data->map->lines, i, j, 0))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	display_movements(t_data *data)
{
	char	*str;

	str = ft_itoa(data->movements);
	if (!str)
		return ;
	mlx_string_put(data->mlx, data->win, 10, 10, BLACK_PIXEL, "Movements: ");
	mlx_string_put(data->mlx, data->win, 110, 10, BLACK_PIXEL, str);
	free(str);
}
