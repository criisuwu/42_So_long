#ifndef SO_LONG_H
#define SO_LONG_H
#define COIN 
#define WALL "./image/bush.xpm"
#define PLAYER "./image/duck.xpm"
#define EXIT "./image/exit.xpm"
#define FLOOR "./image/floor.xpm"
#define A 0
#define S 1
#define D 2
#define W 13
#define ESC 53

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
void map_is_valid(t_map game);
void has_one_player(t_map game);
void has_one_exit(t_map game);
void has_collect(t_map game);
void put_wall(t_map game);
void put_floor(t_map game);
void put_exit(t_map game);
void ft_err_arg();
int get_map_height(t_map game);
int get_map_width(t_map game);
int key_hook(int keycode, t_map game);
char **read_map(char **argv, t_map game);

#endif