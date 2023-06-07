/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaubry <kyaubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 17:03:51 by kylian            #+#    #+#             */
/*   Updated: 2023/05/30 18:06:05 by kyaubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chess.h"

int free_window(t_game *game)
{
	print_error(ERRCODE_CREATE_WIN);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free(game);
	exit(0);
	return (0);
}

void free_image(t_game *game)
{
	int i;
	int j;

	i = -1;
	j = -1;
	while (++i < 6)
	{
		j = -1;
		while (++j < 13)
		{
			if (game->img[i][j])
				mlx_destroy_image(game->mlx, game->img[i][j]);
		}
	}
	if (game->img_check[0])
		mlx_destroy_image(game->mlx, game->img_check[0]);
	if (game->img_check[1])
		mlx_destroy_image(game->mlx, game->img_check[1]);
}

int free_game(t_game *game)
{
	free_image(game);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free(game);
	exit (0);
	return (0);
}
