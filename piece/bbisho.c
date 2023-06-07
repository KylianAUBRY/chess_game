/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bbisho.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaubry <kyaubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:25:02 by kyaubry           #+#    #+#             */
/*   Updated: 2023/06/05 11:53:36 by kyaubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../chess.h"

void bbisho_push(t_game *game, int j, int i)
{
	int tempi;
	int tempj;

	tempi = i;
	tempj = j;
	while (++tempi < 8 && ++tempj < 8 && game->map[0][tempi][tempj] == 0)
		btest(game, i, j, tempj, tempi, BBISHO);
	if (tempi < 8 && tempj < 8 && game->map[0][tempi][tempj] > 6)
		btest(game, i, j, tempj, tempi, BBISHO);
	tempi = i;
	tempj = j;
	while (++tempi < 8 && --tempj >= 0 && game->map[0][tempi][tempj] == 0)
		btest(game, i, j, tempj, tempi, BBISHO);
	if (tempi < 8 && tempj >= 0 && game->map[0][tempi][tempj] > 6)
		btest(game, i, j, tempj, tempi, BBISHO);
	tempi = i;
	tempj = j;
	while (--tempi >= 0 && --tempj >= 0 && game->map[0][tempi][tempj] == 0)
		btest(game, i, j, tempj, tempi, BBISHO);
	if (tempi >= 0 && tempj >= 0 && game->map[0][tempi][tempj] > 6)
		btest(game, i, j, tempj, tempi, BBISHO);
	tempi = i;
	tempj = j;
	while (--tempi >= 0 && ++tempj < 8 && game->map[0][tempi][tempj] == 0)
		btest(game, i, j, tempj, tempi, BBISHO);
	if (tempi >= 0 && tempj < 8 && game->map[0][tempi][tempj] > 6)
		btest(game, i, j, tempj, tempi, BBISHO);
}

int bbisho(t_game *game, int j, int i)
{
	map_temp_to_zero(game);
	if (game->side == WHITE)
		return (0);
	if (game->status == GOOD)
	{
		game->map[0][i][j] = 0;
		bbisho_push(game, j, i);
		game->map[0][i][j] = BBISHO;
		game->status = GOOD;
	}
	else
	{
		game->map[0][i][j] = 0;
		bbisho_push(game, j, i);
		game->map[0][i][j] = BBISHO;
	}
	if (game->status != TESTCHECKMATE)
		write_piece(game);
	return (1);
}
