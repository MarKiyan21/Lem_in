/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_all_ways.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 21:35:38 by mkyianyt          #+#    #+#             */
/*   Updated: 2017/06/21 15:52:04 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	put_way(t_lem *lem)
{
	int		i;

	i = -1;
	if (lem->len == 0)
		lem->len = lem->indx_j;
	lem->all_ways[lem->indx_i] = (int*)malloc(sizeof(int) * lem->nb_rooms);
	while (++i < lem->indx_j)
		lem->all_ways[lem->indx_i][i] = lem->way[i];
	if (lem->len > lem->indx_j)
	{
		i = -1;
		lem->len = lem->indx_j;
		if (lem->shortest_way)
			free(lem->shortest_way);
		lem->shortest_way = (int*)malloc(sizeof(int) * (lem->len));
		while (++i < lem->len)
			lem->shortest_way[i] = lem->way[i];
	}
	(lem->indx_i)++;
	lem->find = 1;
}

void	search(t_lem *lem, int current, int end)
{
	int i;

	lem->v_rooms[current] = 1;
	lem->way[lem->indx_j] = current;
	(lem->indx_j)++;
	if (current == end)
		put_way(lem);
	else
	{
		i = -1;
		while (++i < lem->nb_rooms)
			if (lem->v_rooms[i] == 0 && lem->as_ar[current][i] == '1')
				search(lem, i, end);
	}
	lem->v_rooms[current] = 0;
	(lem->indx_j)--;
}

void	kostyliaka(t_lem *lem, int *rooms, int *ant)
{
	ft_putstr("L");
	ft_putnbr(*ant);
	ft_putstr("-");
	ft_putstr(find_name_room(lem, *rooms));
	ft_putstr(" ");
	(*rooms)--;
	if (*(rooms) > 0)
		(*ant)++;
}

void	print_way(t_lem *lem, int i, int j, int ant)
{
	int last;
	int	rooms;

	rooms = 1;
	while (++ant <= lem->nb_ants)
	{
		while (rooms <= lem->len)
		{
			last = ant;
			while (rooms > 0)
			{
				kostyliaka(lem, &rooms, &ant);
				if (ant > lem->nb_ants)
					break ;
			}
			ft_putstr("\n");
			rooms += i++;
			ant = last;
			if (rooms >= lem->len)
				break ;
		}
		rooms = lem->len - 1;
		j += lem->len;
	}
}

void	find_all_ways(t_lem *lem)
{
	lem->find = 0;
	init_for_ways(lem);
	search(lem, find_nb_room(lem->name_r, lem->s_e[0]),
			find_nb_room(lem->name_r, lem->s_e[1]));
	if (lem->find == 0)
		ft_error();
	print_lem_in(lem);
	print_way(lem, 2, 0, 0);
}
