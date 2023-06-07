/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaubry <kyaubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 04:33:29 by kylian            #+#    #+#             */
/*   Updated: 2023/05/31 14:49:25 by kyaubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chess.h"

void	seek_piece(t_game *game, int i, int j)
{
	int	tps;
	int itps;

	itps = get_i(i);
	tps = 0;
	if (i % 2 == 1)
	{
		if (j % 2 == 0)
			tps = GEENBOX;
		else
			tps = WHITEBOX;
	}
	else
	{
		if (j % 2 == 1)
			tps = GEENBOX;
		else
			tps = WHITEBOX;
	}
	if (game->map[1][itps][j] == -1)
		tps = tps + 2;
	else if (game->map[1][itps][j] > 0)
		tps = tps + 4;
	else if (game->map[3][itps][j] != 0)
		tps = tps + 4;
	if (game->status != GOOD && game->map[0][itps][j] == BKING && game->side == BLACK)
		mlx_put_image_to_window(game->mlx, game->win, game->img_check[0], (j * 60) + 720, (i * 60) + 300);
	else if (game->status != GOOD && game->map[0][itps][j] == WKING && game->side == WHITE)
		mlx_put_image_to_window(game->mlx, game->win, game->img_check[1], (j * 60) + 720, (i * 60) + 300);
	else
		mlx_put_image_to_window(game->mlx, game->win, game->img[tps][game->map[0][itps][j]], (j * 60) + 720, (i * 60) + 300);
}

void	write_piece(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 8)
	{
		j = -1;
		while (++j < 8)
			seek_piece(game, i, j);
	}
}
