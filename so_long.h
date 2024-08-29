#ifndef SO_LONG_H
#define SO_LONH_H

#include "libft.h"
#include <MLX42/MLX42.h>

typedef struct game_src
{
    int     coin;
    int     exit;
    int     movements;
    int     n_players;
    int     status;
    int     exit_x;
    int     exit_y;
    int     player_x;
    int     player_y;
    int     coin_cop;
    int     player_copy;
    int     coin_cop_2;
    char    **map;
    void    *player_img;
    void    *exit_img;
    void    *coin_img;
    void    *wall_img;
    void    *mlx;
    void    *floor;
    size_t  map_wid;
    size_t  map_hei;
}t_map;

#endif