/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gif.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:12:06 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/03/11 09:31:34 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	pacman_gif(t_data *data, int flag)
{
	int				pos_x;
	int				pos_y;

	pos_x = data->pacman->pixel_pos.x;
	pos_y = data->pacman->pixel_pos.y;
	if (flag == 1)
		data->pacman->mouth_open = !data->pacman->mouth_open;
	if (data->pacman->mouth_open)
		mlx_put_image_to_window(data->mlx, data->win,
			data->pacman->img_file[data->pacman->image_index], pos_x, pos_y);
	else
		mlx_put_image_to_window(data->mlx, data->win,
			data->pacman->img_file[4], pos_x, pos_y);
}

void	enemy_gif(t_data *data, int flag)
{
	int				pos_x;
	int				pos_y;
	int				i;

	i = 0;
	while (i < data->num_enemies)
	{
		pos_x = data->enemy[i]->pixel_pos.x;
		pos_y = data->enemy[i]->pixel_pos.y;
		if (flag == 1)
			data->enemy[i]->mouth_open = !data->enemy[i]->mouth_open;
		if (data->enemy[i]->mouth_open && data->enemy[i]->print)
			mlx_put_image_to_window(data->mlx, data->win,
				data->enemy[i]->img_file[0], pos_x, pos_y);
		else if (data->enemy[i]->print)
			mlx_put_image_to_window(data->mlx, data->win,
				data->enemy[i]->img_file[1], pos_x, pos_y);
		i++;
	}
}

void	consumable(t_data *data)
{
	int	pos_x;
	int	pos_y;
	int	i;

	i = 0;
	while (i < data->num_consumables)
	{
		if (data->consumable[i]->print)
		{
			pos_x = data->consumable[i]->pixel_pos.x;
			pos_y = data->consumable[i]->pixel_pos.y;
			draw_circle(pos_x, pos_y, WHITE_PIXEL, data);
		}
		i++;
	}
}

void	end_exit(t_data *data)
{
	if (data->pacman->nbr_consumables == data->num_consumables
		&& data->exit->print)
		draw_square(data->exit->pixel_pos.x, data->exit->pixel_pos.y,
			BLUE_PIXEL, data);
}

int	gif(t_data *data)
{
	struct timeval	now;
	int				elapsed_time;
	int				vulnerable_time;

	gettimeofday(&now, NULL);
	elapsed_time = (now.tv_sec - data->pacman->last_gif.tv_sec) * 1000
		+ (now.tv_usec - data->pacman->last_gif.tv_usec) / 1000;
	vulnerable_time = (now.tv_sec - data->pacman->last_vulnerable.tv_sec)
		* 1000
		+ (now.tv_usec - data->pacman->last_vulnerable.tv_usec) / 1000;
	if (vulnerable_time >= VULNERABLE_DURATION || vulnerable_time < 0)
		set_enemies_vulnerable(data, 1);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	display_movements(data);
	pacman_gif_utils(data, elapsed_time, now);
	consumable(data);
	end_exit(data);
	move_enemy(data);
	return (0);
}
