/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mallocs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 16:12:07 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/03/10 15:23:05 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	enemy_mallocs(t_data *data)
{
	int	i;

	i = 0;
	data->enemy = malloc(data->num_enemies * sizeof(t_enemy *));
	if (!data->enemy)
		return ;
	while (i < data->num_enemies)
	{
		data->enemy[i] = malloc(sizeof(t_enemy));
		if (!data->enemy[i])
			return ;
		data->enemy[i]->img_file = malloc(ENEMY_IMG_COUNT * sizeof(void *));
		if (!data->enemy[i]->img_file)
			return ;
		i++;
	}
}

void	consumable_mallocs(t_data *data)
{
	int	i;

	i = 0;
	data->consumable = malloc(data->num_consumables * sizeof(t_consumable *));
	if (!data->consumable)
		return ;
	while (i < data->num_consumables)
	{
		data->consumable[i] = malloc(sizeof(t_consumable));
		if (!data->consumable[i])
			return ;
		i++;
	}
}

void	exit_mallocs(t_data *data)
{
	data->exit = malloc(sizeof(t_exit));
	if (!data->exit)
		return ;
}

void	pacman_mallocs(t_data *data)
{
	data->pacman = malloc(sizeof(t_pacman));
	if (!data->pacman)
		return ;
	data->pacman->img_file = malloc(PACMAN_IMG_COUNT * sizeof(void *));
	if (!data->pacman->img_file)
		return ;
	enemy_mallocs(data);
	consumable_mallocs(data);
	exit_mallocs(data);
}
