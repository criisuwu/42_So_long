/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chomobon <chomobon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:40:36 by chomobon          #+#    #+#             */
/*   Updated: 2024/08/28 12:54:28 by chomobon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//Verifica que los argumentos requeridos para abrir el mapa o iniciar el juego
void     check_args(int argc, char *argv, t_map *map)
{
    size_t  len;

    if(argc != 2)
        ft_error(7, map);
    else
    {
        len = ft_strlen(argv);
        if (len < 4)
            ft_error(1, map);
        if (ft_strncmp(".ber", argv + (len - 4), 4))
            ft_error(2, map);
    }
}

//Esta funcion son todos los posibles errores que puede haber
void    ft_error(int i, t_map *map)
{
    if (i == 1)
        ft_printf("Archivo no encontrado en el directorio\n");
    else if (i == 2)
        ft_printf("Extension incorrecta, verifica por favor\n");
    else if (i == 3)
        ft_printf("El mapa tiene caracteres invalidos\n");
    else if (i == 4)
        ft_printf("El mapa no es un rectangulo\n");
    else if (i == 5)
        ft_printf("El mapa esta abierto y necesita paredes...\n");
    else if (i == 6)
        ft_printf("Faltan elementos wey\n");
    else if (i == 7)
        ft_printf("Por favor solo dos elementos\n");
    else if (i == 8)
        ft_printf("No hay un camino valido, como planeas ganar un juego imposible?\n");
    else if (i == 9)
        ft_printf("No he logrado abrir la imagen\n");
    if (map->status == 1)
        free_map(map);
    exit(i);
}

//Esta funcion termina el juego cerrando la ventana
int end_game(void)
{
    exit(0);
    return(0);
}

//Esta funcion cuenta las monedas e indica que has encontrado todas
//las monedas para ir a la salida
void    coin_counter(t_map *map)
{
    map->coin--;
    if (map->coin == 0)
        ft_printf("YAY! Has encontrado todas las monedas, ve a la salida");
}