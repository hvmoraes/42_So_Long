/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:49:24 by hcorrea-          #+#    #+#             */
/*   Updated: 2026/04/10 13:33:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	draw_square(int x, int y, int color, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	if (x + TILE_SIZE > data->map->width
		|| y + TILE_SIZE > data->map->height)
		return ;
	while (i < TILE_SIZE)
	{
		j = 0;
		while (j < TILE_SIZE)
		{
			put_pixel(data, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

void	render_pacman(t_data *data, int i, int j)
{
	data->pacman->pixel_pos.x = i * TILE_SIZE;
	data->pacman->pixel_pos.y = j * TILE_SIZE;
	data->pacman->curr_pos.x = i;
	data->pacman->curr_pos.y = j;
	data->pacman->flag = 1;
}

void	render_enemy(t_data *data, int x, int y, int count)
{
	data->enemy[count]->pixel_pos.x = x * TILE_SIZE;
	data->enemy[count]->pixel_pos.y = y * TILE_SIZE;
	data->enemy[count]->curr_pos.x = x;
	data->enemy[count]->curr_pos.y = y;
	data->enemy[count]->flag = 1;
}

void	render_consumable(t_data *data, int x, int y, int count)
{
	data->consumable[count]->pixel_pos.x = x * TILE_SIZE;
	data->consumable[count]->pixel_pos.y = y * TILE_SIZE;
	data->consumable[count]->curr_pos.x = x;
	data->consumable[count]->curr_pos.y = y;
	data->consumable[count]->flag = 1;
}

void	render_map(t_data *data, int j, int x, int c)
{
	int	i;

	j = -1;
	x = 0;
	c = 0;
	while (data->map->lines[++j])
	{
		i = -1;
		while (data->map->lines[j][++i])
		{
			draw_render(data, i, j);
			if (data->map->lines[j][i] == 'X' && data->enemy[x]->flag != 1)
			{
				render_enemy(data, i, j, x);
				x++;
			}
			if (data->map->lines[j][i] == 'C' && data->consumable[c]->flag != 1)
			{
				render_consumable(data, i, j, c);
				c++;
			}
		}
	}
}
