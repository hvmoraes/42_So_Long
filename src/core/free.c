/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 14:45:49 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/03/10 15:22:37 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	clear_map(t_data *data)
{
	int	i;

	i = 0;
	if (!data->map)
		return ;
	if (data->map->lines)
	{
		while (data->map->lines[i])
		{
			free(data->map->lines[i]);
			i++;
		}
		free(data->map->lines);
		data->map->lines = NULL;
	}
	if (data->map->fd >= 0)
		close(data->map->fd);
}

void	clear_pacman(t_data *data)
{
	int	i;

	if (!data->pacman)
		return ;
	if (data->pacman->img_file)
	{
		i = 0;
		while (i < PACMAN_IMG_COUNT)
		{
			if (data->pacman->img_file[i])
				mlx_destroy_image(data->mlx, data->pacman->img_file[i]);
			i++;
		}
		free(data->pacman->img_file);
	}
	free(data->pacman);
}

void	clear_enemy(t_data *data)
{
	int	i;

	if (!data->enemy)
		return ;
	i = 0;
	while (i < data->num_enemies)
	{
		if (data->enemy[i])
		{
			if (data->enemy[i]->img_file)
			{
				if (data->enemy[i]->img_file[0])
					mlx_destroy_image(data->mlx, data->enemy[i]->img_file[0]);
				if (data->enemy[i]->img_file[1])
					mlx_destroy_image(data->mlx, data->enemy[i]->img_file[1]);
				free(data->enemy[i]->img_file);
			}
			free(data->enemy[i]);
		}
		i++;
	}
	free(data->enemy);
}

void	clear_consumable_exit(t_data *data)
{
	int	i;

	if (data->consumable)
	{
		i = 0;
		while (i < data->num_consumables)
		{
			if (data->consumable[i])
				free(data->consumable[i]);
			i++;
		}
		free(data->consumable);
	}
	if (data->exit)
		free(data->exit);
}

void	clear_all(t_data *data)
{
	clear_pacman(data);
	clear_enemy(data);
	clear_map(data);
	clear_consumable_exit(data);
	if (data->img)
		mlx_destroy_image(data->mlx, data->img);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->map)
		free(data->map);
	free(data);
}
