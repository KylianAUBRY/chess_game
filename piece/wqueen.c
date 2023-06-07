/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wqueen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylian <kylian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 21:06:15 by kyaubry           #+#    #+#             */
/*   Updated: 2023/06/03 21:30:09 by kylian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../chess.h"

void wqueen_push2(t_game *game, int j, int i)
{
	int tempi;
	int tempj;

	tempi = i;
	tempj = j;
	while (++tempi < 8 && ++tempj < 8 && game->map[0][tempi][tempj] == 0)
		wtest(game, i, j, tempj, tempi, WQUEEN);
	if (tempi < 8 && tempj < 8 && game->map[0][tempi][tempj] < 6 && game->map[0][tempi][tempj] > 0)
		wtest(game, i, j, tempj, tempi, WQUEEN);
	tempi = i;
	tempj = j;
	while (++tempi < 8 && --tempj >= 0 && game->map[0][tempi][tempj] == 0)
		wtest(game, i, j, tempj, tempi, WQUEEN);
	if (tempi < 8 && tempj >= 0 && game->map[0][tempi][tempj] < 6 && game->map[0][tempi][tempj] > 0)
		wtest(game, i, j, tempj, tempi, WQUEEN);
	tempi = i;
	tempj = j;
	while (--tempi >= 0 && --tempj >= 0 && game->map[0][tempi][tempj] == 0)
		wtest(game, i, j, tempj, tempi, WQUEEN);
	if (tempi >= 0 && tempj >= 0 && game->map[0][tempi][tempj] < 6 && game->map[0][tempi][tempj] > 0)
		wtest(game, i, j, tempj, tempi, WQUEEN);
	tempi = i;
	tempj = j;
	while (--tempi >= 0 && ++tempj < 8 && game->map[0][tempi][tempj] == 0)
		wtest(game, i, j, tempj, tempi, WQUEEN);
	if (tempi >= 0 && tempj < 8 && game->map[0][tempi][tempj] < 6 && game->map[0][tempi][tempj] > 0)
		wtest(game, i, j, tempj, tempi, WQUEEN);
}

void wqueen_push(t_game *game, int j, int i)
{
	int tempi;
	int tempj;

	tempi = i;
	tempj = j;
	while (--tempj >= 0 && game->map[0][tempi][tempj] == 0)
		wtest(game, i, j, tempj, tempi, WQUEEN);
	if (tempj >= 0 && game->map[0][tempi][tempj] < 6 && game->map[0][tempi][tempj] > 0)
		wtest(game, i, j, tempj, tempi, WQUEEN);
	tempj = j;
	while (++tempj < 8 && game->map[0][tempi][tempj] == 0)
		wtest(game, i, j, tempj, tempi, WQUEEN);
	if (tempj < 8 && game->map[0][tempi][tempj] < 6 && game->map[0][tempi][tempj] > 0)
		wtest(game, i, j, tempj, tempi, WQUEEN);
	tempj = j;
	while (++tempi < 8 && game->map[0][tempi][tempj] == 0)
		wtest(game, i, j, tempj, tempi, WQUEEN);
	if (tempi < 8&& game->map[0][tempi][tempj] < 6 && game->map[0][tempi][tempj] > 0)
		wtest(game, i, j, tempj, tempi, WQUEEN);
	tempi = i;
	while (--tempi >= 0 && game->map[0][tempi][tempj] == 0)
		wtest(game, i, j, tempj, tempi, WQUEEN);
	if (tempi >= 0 && game->map[0][tempi][tempj] < 6 && game->map[0][tempi][tempj] > 0)
		wtest(game, i, j, tempj, tempi, WQUEEN);
}

int wqueen(t_game *game, int j, int i)
{
	map_temp_to_zero(game);
	if (game->side == BLACK)
		return (0);
	if (game->status == GOOD)
	{
		game->map[0][i][j] = 0;
		wqueen_push(game, j, i);
		wqueen_push2(game, j, i);
		game->map[0][i][j] = WQUEEN;
		game->status = GOOD;
	}
	else
	{
		game->map[0][i][j] = 0;
		wqueen_push(game, j, i);
		wqueen_push2(game, j, i);
		game->map[0][i][j] = WQUEEN;
	}
	if (game->status != TESTCHECKMATE)
		write_piece(game);
	return (1);
}
