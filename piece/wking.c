/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wking.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaubry <kyaubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:37:08 by kyaubry           #+#    #+#             */
/*   Updated: 2023/06/05 13:38:29 by kyaubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../chess.h"

void	wking_rock(t_game *game)
{
	if (game->status != GOOD)
		return ;
	if (game->map[0][0][4] != WKING || game->map[2][0][4] > 0)
		return ;
	if (game->map[0][0][0] == WROOK && game->map[2][0][0] == 0
		&& game->map[0][0][1] == 0 && game->map[0][0][2] == 0
		&& game->map[0][0][3] == 0)
	{
		game->map[0][0][0] = 0;
		game->map[0][0][2] = WKING;
		game->map[0][0][3] = WROOK;
		game->map[0][0][4] = 0;
		if (look_check(game, WHITE) == 1)
		{
			game->map[0][0][0] = 0;
			game->map[0][0][2] = 0;
			game->map[0][0][3] = WKING;
			game->map[0][0][4] = 0;
			if (look_check(game, WHITE) == 1)
			{
				game->map[1][0][4] = WROCK;
				game->map[1][0][2] = -1;
			}
		}
		game->map[0][0][0] = WROOK;
		game->map[0][0][2] = 0;
		game->map[0][0][3] = 0;
		game->map[0][0][4] = WKING;
	}
	if (game->map[0][0][7] == WROOK && game->map[2][0][7] == 0
		&& game->map[0][0][6] == 0 && game->map[0][0][5] == 0)
	{
		game->map[0][0][7] = 0;
		game->map[0][0][6] = WKING;
		game->map[0][0][5] = WROOK;
		game->map[0][0][4] = 0;
		if (look_check(game, WHITE) == 1)
		{
			game->map[1][0][4] = WROCK;
			game->map[1][0][6] = -1;
		}
		game->map[0][0][7] = WROOK;
		game->map[0][0][6] = 0;
		game->map[0][0][5] = 0;
		game->map[0][0][4] = WKING;
	}
}

void wking_push(t_game *game, int j, int i)
{
	int tempi;
	int tempj;

	tempi = i - 1;
	tempj = j + 1;
	if (tempi >= 0  && tempj < 8 && game->map[0][tempi][tempj] < 7)
		wtest(game, i, j, tempj, tempi, WKING);
	tempj = j;
	if (tempi >= 0 && game->map[0][tempi][tempj] < 7)
		wtest(game, i, j, tempj, tempi, WKING);
	tempj = j - 1;
	if (tempi >= 0 && tempj >= 0 && game->map[0][tempi][tempj] < 7)
		wtest(game, i, j, tempj, tempi, WKING);
	tempi = i;
	if (tempj >= 0 && game->map[0][tempi][tempj] < 7)
		wtest(game, i, j, tempj, tempi, WKING);
	tempi = i + 1;
	if (tempj >= 0 && tempi < 8 && game->map[0][tempi][tempj] < 7)
		wtest(game, i, j, tempj, tempi, WKING);
	tempj = j;
	if (tempi < 8 && game->map[0][tempi][tempj] < 7)
		wtest(game, i, j, tempj, tempi, WKING);
	tempj = j + 1;
	if (tempj < 8 && tempi < 8 && game->map[0][tempi][tempj] < 7)
		wtest(game, i, j, tempj, tempi, WKING);
	tempi = i;
	if (tempj < 8 && game->map[0][tempi][tempj] < 7)
		wtest(game, i, j, tempj, tempi, WKING);
}

int wking(t_game *game, int j, int i)
{
	map_temp_to_zero(game);
	if (game->side == BLACK)
		return (0);
	if (game->status == GOOD)
	{
		game->map[0][i][j] = 0;
		wking_push(game, j, i);
		game->map[0][i][j] = WKING;
		game->status = GOOD;
		wking_rock(game);
		game->status = GOOD;
	}
	else
	{
		game->map[0][i][j] = 0;
		wking_push(game, j, i);
		game->map[0][i][j] = WKING;
	}
	if (game->status != TESTCHECKMATE)
		write_piece(game);
	return (1);
}
