/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pacman.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:55:13 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/03/11 09:22:40 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	upgrade_pos_render_map_pacman(t_data *data, int x, int y, int i)
{
	data->pacman->pixel_pos.x += x;
	data->pacman->curr_pos.x += x / TILE_SIZE;
	data->pacman->pixel_pos.y += y;
	data->pacman->curr_pos.y += y / TILE_SIZE;
	if (i != data->pacman->image_index)
		data->pacman->image_index = i;
	render_map(data, -1, 0, 0);
}

int	move_character(int keycode, t_data *data)
{
	if (keycode == KEY_A && !is_wall_pacman(data, -1, 0))
		upgrade_pos_render_map_pacman(data, -TILE_SIZE, 0, 1);
	else if (keycode == KEY_D && !is_wall_pacman(data, 1, 0))
		upgrade_pos_render_map_pacman(data, TILE_SIZE, 0, 0);
	else if (keycode == KEY_S && !is_wall_pacman(data, 0, 1))
		upgrade_pos_render_map_pacman(data, 0, TILE_SIZE, 3);
	else if (keycode == KEY_W && !is_wall_pacman(data, 0, -1))
		upgrade_pos_render_map_pacman(data, 0, -TILE_SIZE, 2);
	else
		return (0);
	data->movements++;
	handle_pacman_collisions(data);
	if (data->pacman->curr_pos.x == data->exit->curr_pos.x
		&& data->pacman->curr_pos.y == data->exit->curr_pos.y
		&& data->pacman->nbr_consumables == data->num_consumables)
		win(data);
	return (0);
}

int	is_wall_pacman(t_data *data, int x, int y)
{
	int	pos_y;
	int	pos_x;

	pos_y = data->pacman->curr_pos.y + y;
	pos_x = data->pacman->curr_pos.x + x;
	if (data->map->lines[pos_y][pos_x] == '1')
		return (1);
	else
		return (0);
}
