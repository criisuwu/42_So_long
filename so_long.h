#ifndef SO_LONG_H
#define SO_LONG_H
#define COIN "./image/hat.xpm"
#define WALL "./image/bush.xpm"
#define PLAYER "./image/duck.xpm"
#define EXIT "./image/exit.xpm"
#define FLOOR "./image/floor.xpm"
#define A 97
#define S 115
#define D 100
#define W 119
#define ESC 65307

#include <stdio.h>
#include "minilibx-linux/mlx.h"
#include "libft/libft.h"
#include "printf.h"
#include "libft/get_next_line.h"

typedef struct game{
    int coin;
    int exit;
    int mvs;
    int n_players;
    int status;
    int exit_x;
    int exit_y;
    int player_x;
    int player_y;
    int wall_w;
    int wall_h;
    int floor_w;
    int floor_h;
    int exit_w;
    int exit_h;
    int player_w;
    int player_h;
    int coin_w;
    int coin_h;
    char **map;
    void *player_img;
    void *exit_img;
    void *coin_img;
    void *wall_img;
    void *floor;
    void *mlx;
    void *mlx_wind;
    size_t map_w;
    size_t map_h;
}t_map;

void ft_err(int option);
void ft_err_arg();
void map_is_valid(t_map game);
void move_player(t_map *game, int new_x, int new_y);
void has_one_player(t_map game);
void has_one_exit(t_map game);
void has_collect(t_map game);
void put_wall(t_map game);
void put_floor(t_map game);
void put_exit(t_map game);
void put_player(t_map game);
void put_coin(t_map game);
void redraw_map(t_map *game);
void	init_player_position(t_map *game);
int get_map_height(t_map game);
int get_map_width(t_map game);
int key_hook(int keycode, t_map *game);
int mouse_hook(int mouse, t_map game);
int not_wall(t_map *game, int x, int y);
char **read_map(char **argv, t_map game);

#endif