#ifndef SO_LONG_H
#define SO_LONG_H
#define COIN 
#define WALL
#define PLAYER "./image/duck.xpm"
#define EXIT
#define FLOOR
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

void    ft_err();
int get_map_height(t_map game);
int get_map_width(t_map game);
char **read_map(char **argv, t_map game);

#endif