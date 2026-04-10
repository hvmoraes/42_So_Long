/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 22:24:41 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/03/10 15:49:11 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	nbr_enemies_consumables_extra(t_data *data)
{
	if (data->num_enemies == 0 || data->num_consumables == 0)
		return (0);
	return (1);
}

int	nbr_player_exit(t_data *data)
{
	int	i;
	int	j;
	int	p;
	int	e;

	i = -1;
	p = 0;
	e = 0;
	while (data->map->lines[++i])
	{
		j = -1;
		while (data->map->lines[i][++j] && data->map->lines[i][j] != '\n')
		{
			if (data->map->lines[i][j] == 'P')
				p++;
			else if (data->map->lines[i][j] == 'E')
				e++;
		}
	}
	if (p != 1 || e != 1)
		return (0);
	return (1);
}

void	valid_map(t_data *data)
{
	if (nbr_enemies_consumables_extra(data) == 0)
		invalid(data, 0);
	if (nbr_player_exit(data) == 0)
		invalid(data, 1);
	if (map_sizes(data) == 0)
		invalid(data, 2);
	if (closed_map(data) == 0)
		invalid(data, 3);
	if (valid_path(data) == 0)
		invalid(data, 4);
	if (valid_character(data) == 0)
		invalid(data, 5);
}

void	render_exit(t_data *data, int i, int j)
{
	data->exit->pixel_pos.x = i * TILE_SIZE;
	data->exit->pixel_pos.y = j * TILE_SIZE;
	data->exit->curr_pos.x = i;
	data->exit->curr_pos.y = j;
	data->exit->flag = 1;
}

void	set_enemies_vulnerable(t_data *data, int x)
{
	int	i;

	i = 0;
	while (i < data->num_enemies)
	{
		if (x == 0)
			data->enemy[i]->state = 0;
		else
			data->enemy[i]->state = 1;
		i++;
	}
}
