/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaubry <kyaubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 16:59:04 by kylian            #+#    #+#             */
/*   Updated: 2023/06/01 14:11:45 by kyaubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chess.h"

int	key_hook(int keycode, t_game *game)
{
	if (keycode == 65307)
		free_game(game);
	return (0);
}

int get_i(int i)
{
	if (i == 0)
		return (7);
	if (i == 1)
		return (6);
	if (i == 2)
		return (5);
	if (i == 3)
		return (4);
	if (i == 4)
		return (3);
	if (i == 5)
		return (2);
	if (i == 6)
		return (1);
	if (i == 7)
		return (0);
	return (0);
}

int	mouse_click(int button, int j, int i, t_game *game)
{
	(void) button;
	(void) game;
	if (i < 300 || i > 780 || j < 720 || j > 1200)
		return (0);
	i = (i - 300) / 60;
	j = (j - 720) / 60;
	i = get_i(i);
	case_int(game, j, i);
	return (0);
}

int	game_boucle(t_game *game)
{
	mlx_key_hook(game->win, key_hook, game);
	mlx_hook(game->win, 17, 1L << 17, free_game, game);
	mlx_mouse_hook(game->win, mouse_click, game);
	mlx_loop(game->mlx);
	return (0);
}

int	main(void)
{
	t_game	*game;

	if (init(&game) == 0)
		return (0);
	write_edge(game);
	write_piece(game);
	game->moov_pion = -1;
	game->status = GOOD;
	game->side = WHITE;
	game_boucle(game);
}
