/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:13:57 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/03/11 09:23:36 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	key_press(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
	{
		printf("Window closed!\n");
		clear_all(data);
		exit(0);
	}
	else if (keycode == KEY_A || keycode == KEY_S
		|| keycode == KEY_D || keycode == KEY_W)
		move_character(keycode, data);
	return (1);
}

int	key_release(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		key_press(KEY_ESC, data);
	return (0);
}

void	general_init(t_data *data)
{
	char	**lines;

	lines = malloc(MAX_MAP_LINES * sizeof(char *));
	if (!lines)
	{
		free(data->map);
		free(data);
		exit(1);
	}
	ft_bzero(lines, MAX_MAP_LINES * sizeof(char *));
	data->map->lines = lines;
	data->movements = 0;
	data->nbr_enemies_killed = 0;
	get_size(data);
	count_entities(data);
	valid_map(data);
	pacman_mallocs(data);
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->map->width,
			data->map->height, "PacMan");
	data->img = mlx_new_image(data->mlx, data->map->width,
			data->map->height);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	init_map(data);
	init_pacman(data);
	init_enemy(data);
	init_consumable(data);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc == 2)
	{
		data = malloc(sizeof(t_data));
		if (!data)
			return (1);
		data->map = malloc(sizeof(t_map));
		if (!data->map)
		{
			free(data);
			return (1);
		}
		data->map->fd = open(argv[1], O_RDONLY);
		if (data->map->fd == -1)
		{
			free(data->map);
			free(data);
			return (1);
		}
		general_init(data);
		mlx_loop_hook(data->mlx, gif, data);
		mlx_hook(data->win, 2, 0, key_press, data);
		mlx_hook(data->win, 3, 1, key_release, data);
		mlx_hook(data->win, 17, 17, close_window, data);
		mlx_loop(data->mlx);
	}
	else if (argc > 2)
		printf("Error\nToo many arguments!\n");
	else
		printf("Error\nUsage: ./so_long <map_file.ber>\n");
	return (0);
}
