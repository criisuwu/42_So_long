#ifndef SO_LONG_H
#define SO_LONG_H
#define COIN 
#define WALL
#define PLAYER "./image/duck.xpm"
#define EXIT
#define FLOOR

#include <stdio.h>
#include <mlx.h>
#include "libft.h"
#include "printf.h"
#include "get_next_line.h"

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
    char **map;
    void *player_img;
    void *exit_img;
    void *coin_img;
    void *wall_img;
    void *floor;
    void *mlx;
    void *mlx_wind;
    size_t map_w;
    size_t map_f;
}t_map;

#endif