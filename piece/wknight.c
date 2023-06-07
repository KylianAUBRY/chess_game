/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wknight.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylian <kylian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:12:43 by kyaubry           #+#    #+#             */
/*   Updated: 2023/06/03 21:30:09 by kylian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../chess.h"

void wknight_push(t_game *game, int j, int i)
{
	int tempi;
	int tempj;

	tempi = i - 2;
	tempj = j - 1;
	if (tempi >= 0 && tempj >= 0 && game->map[0][tempi][tempj] < 7)
		wtest(game, i, j, tempj, tempi, WKNIGHT);
	tempj = j + 1;
	if (tempi >= 0 && tempj < 8 && game->map[0][tempi][tempj] < 7)
		wtest(game, i, j, tempj, tempi, WKNIGHT);
	tempi = i + 2;
	if (tempi < 8 && tempj < 8 && game->map[0][tempi][tempj] < 7)
		wtest(game, i, j, tempj, tempi, WKNIGHT);
	tempj = j - 1;
	if (tempi < 8 && tempj >= 0 && game->map[0][tempi][tempj] < 7)
		wtest(game, i, j, tempj, tempi, WKNIGHT);
	tempi = i - 1;
	tempj = j - 2;
	if (tempi >= 0 && tempj >= 0 && game->map[0][tempi][tempj] < 7)
		wtest(game, i, j, tempj, tempi, WKNIGHT);
	tempi = i + 1;
	if (tempi < 8 && tempj >= 0  && game->map[0][tempi][tempj] < 7)
		wtest(game, i, j, tempj, tempi, WKNIGHT);
	tempj = j + 2;
	if (tempi < 8 && tempj < 8  && game->map[0][tempi][tempj] < 7)
		wtest(game, i, j, tempj, tempi, WKNIGHT);
	tempi = i - 1;
	if (tempi >= 0 && tempj < 8 && game->map[0][tempi][tempj] < 7)
		wtest(game, i, j, tempj, tempi, WKNIGHT);
}

int wknight(t_game *game, int j, int i)
{
	map_temp_to_zero(game);
	if (game->side == BLACK)
		return (0);
	if (game->status == GOOD)
	{
		game->map[0][i][j] = 0;
		wknight_push(game, j, i);
		game->map[0][i][j] = WKNIGHT;
		game->status = GOOD;
	}
	else
	{
		game->map[0][i][j] = 0;
		wknight_push(game, j, i);
		game->map[0][i][j] = WKNIGHT;
	}
	if (game->status != TESTCHECKMATE)
		write_piece(game);
	return (1);
}