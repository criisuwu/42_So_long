#ifndef SO_LONG_H
#define SO_LONH_H

#include <MLX42/MLX42.h>

typedef struct game_src
{
    int     coin;
    int     status;
    char    **map;
    void    *player_img;
    void    *exit_img;
    void    *coin_img;
    void    *wall_img;
    void    *mlx;
    void    *floor;
}t_map;


#endif