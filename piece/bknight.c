/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bknight.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylian <kylian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:12:32 by kyaubry           #+#    #+#             */
/*   Updated: 2023/06/03 21:30:09 by kylian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../chess.h"

void bknight_push(t_game *game, int j, int i)
{
	int tempi;
	int tempj;

	tempi = i - 2;
	tempj = j - 1;
	if (tempi >= 0 && tempj >= 0 && (game->map[0][tempi][tempj] > 6 || game->map[0][tempi][tempj] == 0))
		btest(game, i, j, tempj, tempi, BKNIGHT);
	tempj = j + 1;
	if (tempi >= 0 && tempj < 8 && (game->map[0][tempi][tempj] > 6 || game->map[0][tempi][tempj] == 0))
		btest(game, i, j, tempj, tempi, BKNIGHT);
	tempi = i + 2;
	if (tempi < 8 && tempj < 8 && (game->map[0][tempi][tempj] > 6 || game->map[0][tempi][tempj] == 0))
		btest(game, i, j, tempj, tempi, BKNIGHT);
	tempj = j - 1;
	if (tempi < 8 && tempj >= 0 && (game->map[0][tempi][tempj] > 6 || game->map[0][tempi][tempj] == 0))
		btest(game, i, j, tempj, tempi, BKNIGHT);
	//
	tempi = i - 1;
	tempj = j - 2;
	if (tempi >= 0 && tempj >= 0 && (game->map[0][tempi][tempj] > 6 || game->map[0][tempi][tempj] == 0))
		btest(game, i, j, tempj, tempi, BKNIGHT);
	tempi = i + 1;
	if (tempi < 8 && tempj >= 0  && (game->map[0][tempi][tempj] > 6 || game->map[0][tempi][tempj] == 0))
		btest(game, i, j, tempj, tempi, BKNIGHT);
	tempj = j + 2;
	if (tempi < 8 && tempj < 8  && (game->map[0][tempi][tempj] > 6 || game->map[0][tempi][tempj] == 0))
		btest(game, i, j, tempj, tempi, BKNIGHT);
	tempi = i - 1;
	if (tempi >= 0 && tempj < 8 && (game->map[0][tempi][tempj] > 6 || game->map[0][tempi][tempj] == 0))
		btest(game, i, j, tempj, tempi, BKNIGHT);
}

int bknight(t_game *game, int j, int i)
{
	map_temp_to_zero(game);
	if (game->side == WHITE)
		return (0);
	if (game->status == GOOD)
	{
		game->map[0][i][j] = 0;
		bknight_push(game, j, i);
		game->map[0][i][j] = BKNIGHT;
		game->status = GOOD;
	}
	else
	{
		game->map[0][i][j] = 0;
		bknight_push(game, j, i);
		game->map[0][i][j] = BKNIGHT;
	}
	if (game->status != TESTCHECKMATE)
		write_piece(game);
	return (1);
}
