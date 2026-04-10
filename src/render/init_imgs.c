/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_imgs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 21:59:11 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/03/09 14:41:01 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	init_images_pacman(t_data *data, int width, int height)
{
	char	*imgs[PACMAN_IMG_COUNT];
	int		i;

	i = 0;
	imgs[0] = IMG_PACMAN_RIGHT;
	imgs[1] = IMG_PACMAN_LEFT;
	imgs[2] = IMG_PACMAN_UP;
	imgs[3] = IMG_PACMAN_DOWN;
	imgs[4] = IMG_PACMAN_CLOSE;
	while (i < PACMAN_IMG_COUNT)
	{
		data->pacman->img_file[i]
			= mlx_xpm_file_to_image(data->mlx, imgs[i], &width, &height);
		i++;
	}
}

void	init_images_enemy(t_data *data, int width, int height)
{
	int		i;

	i = 0;
	while (i < data->num_enemies)
	{
		data->enemy[i]->img_file[0]
			= mlx_xpm_file_to_image(data->mlx, IMG_ENEMY_1, &width, &height);
		data->enemy[i]->img_file[1]
			= mlx_xpm_file_to_image(data->mlx, IMG_ENEMY_2, &width, &height);
		i++;
	}
}
