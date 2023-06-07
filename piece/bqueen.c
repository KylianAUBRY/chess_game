/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bqueen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylian <kylian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 21:05:21 by kyaubry           #+#    #+#             */
/*   Updated: 2023/06/03 21:30:09 by kylian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../chess.h"

void bqueen_push2(t_game *game, int j, int i)
{
	int tempi;
	int tempj;

	tempi = i;
	tempj = j;
	while (++tempi < 8 && ++tempj < 8 && game->map[0][tempi][tempj] == 0)
		btest(game, i, j, tempj, tempi, BQUEEN);
	if (tempi < 8 && tempj < 8 && game->map[0][tempi][tempj] > 6)
		btest(game, i, j, tempj, tempi, BQUEEN);
	tempi = i;
	tempj = j;
	while (++tempi < 8 && --tempj >= 0 && game->map[0][tempi][tempj] == 0)
		btest(game, i, j, tempj, tempi, BQUEEN);
	if (tempi < 8 && tempj >= 0 && game->map[0][tempi][tempj] > 6)
		btest(game, i, j, tempj, tempi, BQUEEN);
	tempi = i;
	tempj = j;
	while (--tempi >= 0 && --tempj >= 0 && game->map[0][tempi][tempj] == 0)
		btest(game, i, j, tempj, tempi, BQUEEN);
	if (tempi >= 0 && tempj >= 0 && game->map[0][tempi][tempj] > 6)
		btest(game, i, j, tempj, tempi, BQUEEN);
	tempi = i;
	tempj = j;
	while (--tempi >= 0 && ++tempj < 8 && game->map[0][tempi][tempj] == 0)
		btest(game, i, j, tempj, tempi, BQUEEN);
	if (tempi >= 0 && tempj < 8 && game->map[0][tempi][tempj] > 6)
		btest(game, i, j, tempj, tempi, BQUEEN);
}

void bqueen_push(t_game *game, int j, int i)
{
	int tempi;
	int tempj;

	tempi = i;
	tempj = j;
	while (--tempj >= 0 && game->map[0][tempi][tempj] == 0)
		btest(game, i, j, tempj, tempi, BQUEEN);
	if (tempj >= 0 && game->map[0][tempi][tempj] > 6)
		btest(game, i, j, tempj, tempi, BQUEEN);
	tempj = j;
	while (++tempj < 8 && game->map[0][tempi][tempj] == 0)
		btest(game, i, j, tempj, tempi, BQUEEN);
	if (tempj < 8 && game->map[0][tempi][tempj] > 6)
		btest(game, i, j, tempj, tempi, BQUEEN);
	tempj = j;
	while (++tempi < 8 && game->map[0][tempi][tempj] == 0)
		btest(game, i, j, tempj, tempi, BQUEEN);
	if (tempi < 8&& game->map[0][tempi][tempj] > 6)
		btest(game, i, j, tempj, tempi, BQUEEN);
	tempi = i;
	while (--tempi >= 0 && game->map[0][tempi][tempj] == 0)
		btest(game, i, j, tempj, tempi, BQUEEN);
	if (tempi >= 0 && game->map[0][tempi][tempj] > 6)
		btest(game, i, j, tempj, tempi, BQUEEN);
}

int bqueen(t_game *game, int j, int i)
{
	map_temp_to_zero(game);
	if (game->side == WHITE)
		return (0);
	if (game->status == GOOD)
	{
		game->map[0][i][j] = 0;
		bqueen_push(game, j, i);
		bqueen_push2(game, j, i);
		game->map[0][i][j] = BQUEEN;
		game->status = GOOD;
	}
	else
	{
		game->map[0][i][j] = 0;
		bqueen_push(game, j, i);
		bqueen_push2(game, j, i);
		game->map[0][i][j] = BQUEEN;
	}
	if (game->status != TESTCHECKMATE)
		write_piece(game);
	return (1);
}
