/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wbisho.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylian <kylian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:25:50 by kyaubry           #+#    #+#             */
/*   Updated: 2023/06/03 21:30:09 by kylian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../chess.h"

void wbisho_push(t_game *game, int j, int i)
{
	int tempi;
	int tempj;

	tempi = i;
	tempj = j;
	while (++tempi < 8 && ++tempj < 8 && game->map[0][tempi][tempj] == 0)
		wtest(game, i, j, tempj, tempi, WBISHO);
	if (tempi < 8 && tempj < 8 && game->map[0][tempi][tempj] < 6 && game->map[0][tempi][tempj] > 0)
		wtest(game, i, j, tempj, tempi, WBISHO);
	tempi = i;
	tempj = j;
	while (++tempi < 8 && --tempj >= 0 && game->map[0][tempi][tempj] == 0)
		wtest(game, i, j, tempj, tempi, WBISHO);
	if (tempi < 8 && tempj >= 0 && game->map[0][tempi][tempj] < 6 && game->map[0][tempi][tempj] > 0)
		wtest(game, i, j, tempj, tempi, WBISHO);
	tempi = i;
	tempj = j;
	while (--tempi >= 0 && --tempj >= 0 && game->map[0][tempi][tempj] == 0)
		wtest(game, i, j, tempj, tempi, WBISHO);
	if (tempi >= 0 && tempj >= 0 && game->map[0][tempi][tempj] < 6 && game->map[0][tempi][tempj] > 0)
		wtest(game, i, j, tempj, tempi, WBISHO);
	tempi = i;
	tempj = j;
	while (--tempi >= 0 && ++tempj < 8 && game->map[0][tempi][tempj] == 0)
		wtest(game, i, j, tempj, tempi, WBISHO);
	if (tempi >= 0 && tempj < 8 && game->map[0][tempi][tempj] < 6 && game->map[0][tempi][tempj] > 0)
		wtest(game, i, j, tempj, tempi, WBISHO);
}

int wbisho(t_game *game, int j, int i)
{
	map_temp_to_zero(game);
	if (game->side == BLACK)
		return (0);
	if (game->status == GOOD)
	{
		game->map[0][i][j] = 0;
		wbisho_push(game, j, i);
		game->map[0][i][j] = WBISHO;
		game->status = GOOD;
	}
	else
	{
		game->map[0][i][j] = 0;
		wbisho_push(game, j, i);
		game->map[0][i][j] = WBISHO;
	}
	if (game->status != TESTCHECKMATE)
		write_piece(game);
	return (1);
}
