/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chess.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaubry <kyaubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 16:57:43 by kylian            #+#    #+#             */
/*   Updated: 2023/06/05 13:56:58 by kyaubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHESS_H
# define CHESS_H

# include "minilibx-linux/mlx.h"
# include <fcntl.h>
# include <pthread.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

# define ERRCODE_MALLOC_FAIL 1
# define ERRCODE_INIT_WIN 2
# define ERRCODE_CREATE_WIN 3
# define ERRCODE_XPM 4

//300    780
//720    1200
# define CHECKMATE 42
# define TESTCHECKMATE 84
# define CHECK 21
# define GOOD 1

# define WHITE 1
# define BLACK 2

typedef struct s_game
{
	void		*mlx;
	void		*win;
	int			map[4][8][8];
	void		*img[6][13];
	void		*img_check[2];
	int			side;
	int			status;
	int			moov_pion;
	pthread_t	tid;
	int			adieux_thread;
}				t_game;

int				print_error(int error_code);

int				mouse_click(int button, int j, int i, t_game *game);

void			write_edge_right(t_game *game);
void			write_edge_up(t_game *game);
void			write_edge_down(t_game *game);
void			write_edge(t_game *game);

void			write_piece(t_game *game);
void			seek_piece(t_game *game, int i, int j);

int				init(t_game **game);
void			map_temp_to_zero(t_game *game);
void			map_temp_to_zero2(t_game *game);
void			map_temp_to_zero3(t_game *game);
int				init_img(t_game *game);
int				init_img2(t_game *game);
int				init_img3(t_game *game);
int				init_img4(t_game *game);
int				init_img5(t_game *game);
int				init_img6(t_game *game);
int				init_img7(t_game *game);
int				init_img8(t_game *game);
int				init_img9(t_game *game);
int				init_img10(t_game *game);
int				init_img11(t_game *game);
int				init_img12(t_game *game);
int				init_map(t_game *game);

int				free_window(t_game *game);
void			free_image(t_game *game);
int				free_game(t_game *game);

int				case_int(t_game *game, int j, int i);
int				get_i(int i);

int				direct_check_black(t_game *game, int j, int i);
int				direct_check_white(t_game *game, int j, int i);
int				look_check(t_game *game, int color);
int				look_checkmate(t_game *game);

void			promotion(t_game *game, int j, int i, int pion);
void			*thread_routine(void *temp);
int				key_hook_promo(int keycode, t_game *game);
int				handle_mouse_click(int button, int x, int y, t_game *game);
int				adieux_in_the_thread(int i);

void			btest(t_game *game, int i, int j, int tempj, int tempi,
					int piece);
void			wtest(t_game *game, int i, int j, int tempj, int tempi,
					int piece);

int				bpawn(t_game *game, int j, int i);
int				bbisho(t_game *game, int j, int i);
int				brook(t_game *game, int j, int i);
int				bqueen(t_game *game, int j, int i);
int				bknight(t_game *game, int j, int i);
int				bking(t_game *game, int j, int i);
int				wpawn(t_game *game, int j, int i);
int				wbisho(t_game *game, int j, int i);
int				wrook(t_game *game, int j, int i);
int				wqueen(t_game *game, int j, int i);
int				wknight(t_game *game, int j, int i);
int				wking(t_game *game, int j, int i);
int				check(t_game *game);

# define GEENBOX 0
# define WHITEBOX 1

# define BPAWN 1
# define BBISHO 2
# define BKNIGHT 3
# define BROOK 4
# define BQUEEN 5
# define BKING 6

# define WPAWN 7
# define WBISHO 8
# define WKNIGHT 9
# define WROOK 10
# define WQUEEN 11
# define WKING 12

# define BROCK 100
# define WROCK 200

# define PIECEMOOV 100

#endif

/*
case_int		vide = 0

black	pawn(pion) = 1
black	bisho(fou) = 2
black	knight(cavalier) = 3
black	rook(tour) = 4
black	queen(Dame) = 5
black	king(roi) = 6

white	pawn(pion) = 7
white	Bisho(fou) = 8
white	knight(cavalier) = 9
white	rook(tour) = 10
white	queen(Dame) = 11
white	king(roi) = 12

*/
