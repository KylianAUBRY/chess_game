/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   promotion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaubry <kyaubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 16:05:38 by kyaubry           #+#    #+#             */
/*   Updated: 2023/05/31 19:09:15 by kyaubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chess.h"

int	adieux_in_the_thread(int i)
{
	int	*result_ptr;

	result_ptr = malloc(sizeof(int) * 1);
	if (!result_ptr)
	{
		pthread_exit((void *)result_ptr);
		return (0);
	}
	*result_ptr = i;
	pthread_exit((void *)result_ptr);
	return (0);
}

int	handle_mouse_click(int button, int j, int i, t_game *game)
{
	(void) button;
	int color;

	color = 0;
	if (game->side == WHITE)
		color += 6;
	if (j >= 720 && j < 780 && i >= 800 && i < 860)
		adieux_in_the_thread(color + BQUEEN);
	else if (j >= 780 && j < 840 && i >= 800 && i < 860)
		adieux_in_the_thread(color + BKNIGHT);
	else if (j >= 840 && j < 900 && i >= 800 && i < 860)
		adieux_in_the_thread(color + BROOK);
	else if (j >= 900 && j < 960 && i >= 800 && i < 860)
		adieux_in_the_thread(color + BBISHO);
	return (0);
}

void	*thread_routine(void *temp)
{
	t_game	*game;
	int 	i;

	game = (t_game *)temp;
	i = 0;
	mlx_mouse_hook(game->win, handle_mouse_click, game);
	if (game->side == WHITE)
		i = 6;
	mlx_put_image_to_window(game->mlx, game->win, game->img[0][i + BQUEEN], 720, 800);
	mlx_put_image_to_window(game->mlx, game->win, game->img[1][i + BKNIGHT], 780, 800);
	mlx_put_image_to_window(game->mlx, game->win, game->img[0][i + BROOK], 840, 800);
	mlx_put_image_to_window(game->mlx, game->win, game->img[1][i + BBISHO], 900, 800);
	mlx_loop(game->mlx);
	return (&game->adieux_thread);
}

void clear_promo(t_game *game)
{
	int i;
	int j;

	i = 799;
	while (++i <= 860)
	{
		j = 719;
		while (++j <= 960)
			mlx_pixel_put(game->mlx, game->win, j, i,  0x00000);
	}
}

void promotion(t_game *game, int j, int i, int pion)
{
	int	*result_ptr;
	int res;

	if (pthread_create(&game->tid, NULL, thread_routine, (void *)game) == 0)
	{
		pthread_join(game->tid, (void **)&result_ptr);
		mlx_mouse_hook(game->win, mouse_click, game);
		if (!*result_ptr)
		{
			if (game->side == WHITE)
				res = WQUEEN;
			else
				res = BQUEEN;
		}
		else
		{
			res = *result_ptr;
			free (result_ptr);
		}
		game->map[0][i][j] = res;
	}
	else
	{
		if (pion == WPAWN)
			game->map[0][i][j] = WQUEEN;
		else
			game->map[0][i][j] = BQUEEN;
	}
	clear_promo(game);
}
