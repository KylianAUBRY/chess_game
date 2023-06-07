/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bking.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaubry <kyaubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:37:24 by kyaubry           #+#    #+#             */
/*   Updated: 2023/06/05 13:32:54 by kyaubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../chess.h"

void	bking_rock(t_game *game)
{
	if (game->status != GOOD)
		return ;
	if (game->map[0][7][4] != BKING || game->map[2][7][4] > 0)
		return ;
	if (game->map[0][7][0] == BROOK && game->map[2][7][0] == 0
		&& game->map[0][7][1] == 0 && game->map[0][7][2] == 0
		&& game->map[0][7][3] == 0)
	{
		game->map[0][7][0] = 0;
		game->map[0][7][2] = BKING;
		game->map[0][7][3] = BROOK;
		game->map[0][7][4] = 0;
		if (look_check(game, BLACK) == 1)
		{
			game->map[0][7][0] = 0;
			game->map[0][7][2] = 0;
			game->map[0][7][3] = BKING;
			game->map[0][7][4] = 0;
			if (look_check(game, BLACK) == 1)
			{
				game->map[1][7][4] = BROCK;
				game->map[1][7][2] = -1;
			}
		}
		game->map[0][7][0] = BROOK;
		game->map[0][7][2] = 0;
		game->map[0][7][3] = 0;
		game->map[0][7][4] = BKING;
	}
	if (game->map[0][7][7] == BROOK && game->map[2][7][7] == 0
		&& game->map[0][7][6] == 0 && game->map[0][7][5] == 0)
	{
		game->map[0][7][7] = 0;
		game->map[0][7][6] = BKING;
		game->map[0][7][5] = BROOK;
		game->map[0][7][4] = 0;
		if (look_check(game, BLACK) == 1)
		{
			game->map[1][7][4] = BROCK;
			game->map[1][7][6] = -1;
		}
		game->map[0][7][7] = BROOK;
		game->map[0][7][6] = 0;
		game->map[0][7][5] = 0;
		game->map[0][7][4] = BKING;
	}
}

void bking_push(t_game *game, int j, int i)
{
	int tempi;
	int tempj;

	tempi = i - 1;
	tempj = j + 1;
	if (tempi >= 0  && tempj < 8 && (game->map[0][tempi][tempj] > 6 || game->map[0][tempi][tempj] == 0))
		btest(game, i, j, tempj, tempi, BKING);
	tempj = j;
	if (tempi >= 0 && (game->map[0][tempi][tempj] > 6 || game->map[0][tempi][tempj] == 0))
		btest(game, i, j, tempj, tempi, BKING);
	tempj = j - 1;
	if (tempi >= 0 && tempj >= 0 && (game->map[0][tempi][tempj] > 6 || game->map[0][tempi][tempj] == 0))
		btest(game, i, j, tempj, tempi, BKING);
	tempi = i;
	if (tempj >= 0 && (game->map[0][tempi][tempj] > 6 || game->map[0][tempi][tempj] == 0))
		btest(game, i, j, tempj, tempi, BKING);
	tempi = i + 1;
	if (tempj >= 0 && tempi < 8 && (game->map[0][tempi][tempj] > 6 || game->map[0][tempi][tempj] == 0))
		btest(game, i, j, tempj, tempi, BKING);
	tempj = j;
	if (tempi < 8 && (game->map[0][tempi][tempj] > 6 || game->map[0][tempi][tempj] == 0))
		btest(game, i, j, tempj, tempi, BKING);
	tempj = j + 1;
	if (tempj < 8 && tempi < 8 && (game->map[0][tempi][tempj] > 6 || game->map[0][tempi][tempj] == 0))
		btest(game, i, j, tempj, tempi, BKING);
	tempi = i;
	if (tempj < 8 && (game->map[0][tempi][tempj] > 6 || game->map[0][tempi][tempj] == 0))
		btest(game, i, j, tempj, tempi, BKING);
}

int bking(t_game *game, int j, int i)
{
	map_temp_to_zero(game);
	if (game->side == WHITE)
		return (0);
	if (game->status == GOOD)
	{
		game->map[0][i][j] = 0;
		bking_push(game, j, i);
		game->map[0][i][j] = BKING;
		game->status = GOOD;
		bking_rock(game);
		game->status = GOOD;
	}
	else
	{
		game->map[0][i][j] = 0;
		bking_push(game, j, i);
		game->map[0][i][j] = BKING;
	}
	if (game->status != TESTCHECKMATE)
		write_piece(game);
	return (1);
}
