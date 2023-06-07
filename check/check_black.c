/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_black.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaubry <kyaubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:16:03 by kyaubry           #+#    #+#             */
/*   Updated: 2023/06/05 12:37:49 by kyaubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../chess.h"

int direct_check_black6(t_game *game, int j, int i)
{
	int tempi;
	int tempj;

	tempi = i - 1;
	tempj = j + 1;
	if (tempi >= 0  && tempj < 8 && (game->map[0][tempi][tempj] == WKING || game->map[0][tempi][tempj] == WQUEEN))
		return (check(game));
	tempj = j;
	if (tempi >= 0 && (game->map[0][tempi][tempj] == WKING || game->map[0][tempi][tempj] == WQUEEN))
		return (check(game));
	tempj = j - 1;
	if (tempi >= 0 && tempj >= 0 && (game->map[0][tempi][tempj] == WKING || game->map[0][tempi][tempj] == WQUEEN))
		return (check(game));
	tempi = i;
	if (tempj >= 0 && (game->map[0][tempi][tempj] == WKING || game->map[0][tempi][tempj] == WQUEEN))
		return (check(game));
	tempi = i + 1;
	if (tempj >= 0 && tempi < 8 && (game->map[0][tempi][tempj] == WKING || game->map[0][tempi][tempj] == WQUEEN))
		return (check(game));
	tempj = j;
	if (tempi < 8 && (game->map[0][tempi][tempj] == WKING || game->map[0][tempi][tempj] == WQUEEN))
		return (check(game));
	tempj = j + 1;
	if (tempj < 8 && tempi < 8 && (game->map[0][tempi][tempj] == WKING || game->map[0][tempi][tempj] == WQUEEN))
		return (check(game));
	tempi = i;
	if (tempj < 8 && (game->map[0][tempi][tempj] == WKING || game->map[0][tempi][tempj] == WQUEEN))
		return (check(game));
	return (1);
}

int	direct_check_black5(t_game *game, int j, int i)
{
	int	tempi;
	int	tempj;

	tempi = i - 2;
	tempj = j - 1;
	if (tempj >= 0 && tempi >= 0 && game->map[0][tempi][tempj] == WKNIGHT)
		return (check(game));
	tempj = j + 1;
	if (tempj < 8 && tempi >= 0 && game->map[0][tempi][tempj] == WKNIGHT)
		return (check(game));
	tempi = i + 2;
	if (tempj < 8 && tempi < 8 && game->map[0][tempi][tempj] == WKNIGHT)
		return (check(game));
	tempj = j - 1;
	if (tempj >= 0 && tempi < 8 && game->map[0][tempi][tempj] == WKNIGHT)
		return (check(game));
	//
	tempi = i - 1;
	tempj = j - 2;
	if (tempj >= 0 && tempi >= 0 && game->map[0][tempi][tempj] == WKNIGHT)
		return (check(game));
	tempi = i + 1;
	if (tempj >= 0 && tempi < 8 && game->map[0][tempi][tempj] == WKNIGHT)
		return (check(game));
	tempj = j + 2;
	if (tempj < 8 && tempi < 8 && game->map[0][tempi][tempj] == WKNIGHT)
		return (check(game));
	tempi = i - 1;
	if (tempj < 8 && tempi >= 0 && game->map[0][tempi][tempj] == WKNIGHT)
		return (check(game));
	return (direct_check_black6(game, j, i));
}

int	direct_check_black4(t_game *game, int j, int i)
{
	int	tempi;
	int	tempj;

	tempi = i;
	tempj = j;
	while (++tempi < 8 && --tempj >= 0 && game->map[0][tempi][tempj] == 0)
		;
	if (tempi < 8 && tempj >= 0 && (game->map[0][tempi][tempj] == WQUEEN
		|| game->map[0][tempi][tempj] == WBISHO))
		return (check(game));
	tempi = i;
	tempj = j;
	while (++tempi < 8 && ++tempj < 8 && game->map[0][tempi][tempj] == 0)
		;
	if (tempi < 8 && tempj < 8 && (game->map[0][tempi][tempj] == WQUEEN
		|| game->map[0][tempi][tempj] == WBISHO))
		return (check(game));
	return (direct_check_black5(game, j, i));
}

int	direct_check_black3(t_game *game, int j, int i)
{
	int	tempi;
	int	tempj;

	tempi = i;
	tempj = j;
	while (--tempi >= 0 && --tempj >= 0 && game->map[0][tempi][tempj] == 0)
		;
	if (tempi >= 0 && tempj >= 0 && (game->map[0][tempi][tempj] == WQUEEN
		|| game->map[0][tempi][tempj] == WBISHO
		|| (game->map[0][tempi][tempj] == WPAWN && tempi + 1 == i && tempj + 1 == j)))
		return (check(game));
	tempi = i;
	tempj = j;
	while (--tempi >= 0 && ++tempj < 8 && game->map[0][tempi][tempj] == 0)
		;
	if (tempi >= 0 && tempj < 8 && (game->map[0][tempi][tempj] == WQUEEN
		|| game->map[0][tempi][tempj] == WBISHO
		|| (game->map[0][tempi][tempj] == WPAWN && tempi + 1 == i && tempj - 1 == j)))
		return (check(game));
	return (direct_check_black4(game, j, i));
}

int	direct_check_black2(t_game *game, int j, int i)
{
	int	tempi;

	tempi = i;
	while (--tempi >= 0 && game->map[0][tempi][j] == 0)
		;
	if (tempi >= 0 && (game->map[0][tempi][j] == WQUEEN
			|| game->map[0][tempi][j] == WROOK))
		return (check(game));
	tempi = j;
	while (++tempi < 8 && game->map[0][tempi][j] == 0)
		;
	if (tempi < 8 && (game->map[0][tempi][j] == WQUEEN
			|| game->map[0][tempi][j] == WROOK))
		return (check(game));
	return (direct_check_black3(game, j, i));
}

int	direct_check_black(t_game *game, int j, int i)
{
	int	tempj;

	tempj = j;
	while (--tempj >= 0 && game->map[0][i][tempj] == 0)
		;
	if (tempj >= 0 && (game->map[0][i][tempj] == WQUEEN
			|| game->map[0][i][tempj] == WROOK))
		return (check(game));
	tempj = j;
	while (++tempj < 8 && game->map[0][i][tempj] == 0)
		;
	if (tempj < 8 && (game->map[0][i][tempj] == WQUEEN
			|| game->map[0][i][tempj] == WROOK))
		return (check(game));
	return (direct_check_black2(game, j, i));
}
