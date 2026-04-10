/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:07:59 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/03/11 09:37:12 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	close_window(t_data *data)
{
	printf("Window closed!\n");
	clear_all(data);
	exit(0);
}

int	die(t_data *data)
{
	printf("Too bad!\nYou died!\n");
	clear_all(data);
	exit(0);
}

int	invalid(t_data *data, int code)
{
	if (code == 0)
		printf("Error\nToo few Enemies or Consumables!\n");
	else if (code == 1)
		printf("Error\nMore or less than 1 Player or Exit!\n");
	else if (code == 2)
		printf("Error\nWrong map sizes!\n");
	else if (code == 3)
		printf("Error\nMap not closed!\n");
	else if (code == 4)
		printf("Error\nNo valid path\n");
	else if (code == 5)
		printf("Error\nInvalid character\n");
	clear_map(data);
	exit(0);
}

int	win(t_data *data)
{
	printf("Congrats!\nYou won!\nYou finished the game with %i "
		"movements.\nYou killed a total of %i enemies.\n", data->movements, data->nbr_enemies_killed);
	clear_all(data);
	exit(0);
}
