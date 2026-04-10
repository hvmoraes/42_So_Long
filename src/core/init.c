/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:24:49 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/03/10 15:35:01 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	init_enemy(t_data *data)
{
	int	width;
	int	height;
	int	i;

	width = TILE_SIZE;
	height = TILE_SIZE;
	i = 0;
	while (i < data->num_enemies)
	{
		data->enemy[i]->mouth_open = false;
		data->enemy[i]->print = 1;
		data->enemy[i]->state = 1;
		i++;
	}
	init_images_enemy(data, width, height);
}

void	init_pacman(t_data *data)
{
	int	width;
	int	height;

	width = TILE_SIZE;
	height = TILE_SIZE;
	data->pacman->mouth_open = false;
	data->pacman->nbr_consumables = 0;
	init_images_pacman(data, width, height);
}

void	init_consumable(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_consumables)
	{
		data->consumable[i]->print = 1;
		i++;
	}
	data->exit->print = 1;
}

void	init_map(t_data *data)
{
	render_map(data, -1, 0, 0);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
