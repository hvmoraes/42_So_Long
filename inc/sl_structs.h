/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_structs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:12:56 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/03/11 09:35:30 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SL_STRUCTS_H
# define SL_STRUCTS_H

# include <stdbool.h>
# include <sys/time.h>

typedef struct s_pos
{
	int	x;
	int	y;
}		t_pos;

typedef struct s_pacman
{
	t_pos			pixel_pos;
	t_pos			curr_pos;
	struct timeval	last_gif;
	struct timeval	last_vulnerable;
	void			**img_file;
	int				image_index;
	bool			mouth_open;
	int				flag;
	int				nbr_consumables;
}			t_pacman;

typedef struct s_enemy
{
	t_pos			pixel_pos;
	t_pos			curr_pos;
	struct timeval	last_movement;
	void			**img_file;
	bool			mouth_open;
	int				flag;
	int				print;
	int				state;
}					t_enemy;

typedef struct s_consumable
{
	t_pos	pixel_pos;
	t_pos	curr_pos;
	int		flag;
	int		print;
}			t_consumable;

typedef struct s_exit
{
	t_pos	pixel_pos;
	t_pos	curr_pos;
	int		flag;
	int		print;
}			t_exit;

typedef struct s_map
{
	int		color;
	int		width;
	int		height;
	int		fd;
	char	**lines;
}			t_map;

typedef struct s_data
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	t_map			*map;
	t_pacman		*pacman;
	t_enemy			**enemy;
	t_consumable	**consumable;
	t_exit			*exit;
	int				movements;
	int				nbr_enemies_killed;
	int				num_enemies;
	int				num_consumables;
}			t_data;

#endif
