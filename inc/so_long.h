/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:12:56 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/03/11 09:35:30 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "../Libft/inc/libft.h"
# include "sl_macros.h"
# include "sl_structs.h"
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include <time.h>
# include <fcntl.h>

char	*get_next_line(int fd);
void	init_pacman(t_data *data);
void	init_enemy(t_data *data);
void	init_consumable(t_data *data);
void	init_map(t_data *data);
void	get_size(t_data *data);
void	put_pixel(t_data *data, int x, int y, int color);
void	render_map(t_data *data, int j, int x, int c);
int		move_character(int keycode, t_data *data);
int		close_window(t_data *data);
int		die(t_data *data);
int		invalid(t_data *data, int code);
int		win(t_data *data);
int		gif(t_data *data);
int		is_wall_pacman(t_data *data, int x, int y);
int		is_wall_enemy(t_data *data, int x, int y, int i);
void	count_entities(t_data *data);
void	enemy_mallocs(t_data *data);
void	pacman_mallocs(t_data *data);
int		move_enemy(t_data *data);
void	init_images_enemy(t_data *data, int width, int height);
void	init_images_pacman(t_data *data, int width, int height);
void	draw_circle(int x, int y, int color, t_data *data);
void	draw_square(int x, int y, int color, t_data *data);
void	valid_map(t_data *data);
void	render_exit(t_data *data, int i, int j);
void	set_enemies_vulnerable(t_data *data, int x);
int		map_sizes(t_data *data);
int		closed_map(t_data *data);
int		valid_character(t_data *data);
void	rand_nbr_enemy(t_data *data, int i);
void	upgrade_pos_render_map_enemy(t_data *data, int x, int y, int i);
void	draw_render(t_data *data, int i, int j);
void	render_pacman(t_data *data, int i, int j);
void	handle_pacman_collisions(t_data *data);
int		verify_height(t_data *data, int map_height, int map_width, int i);
void	pacman_gif_utils(t_data *data, int elapsed_time, struct timeval now);
void	enemy_gif(t_data *data, int flag);
void	pacman_gif(t_data *data, int flag);
int		valid_path(t_data *data);
void	clear_all(t_data *data);
void	clear_map(t_data *data);
void	display_movements(t_data *data);
#endif
