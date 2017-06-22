/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 21:35:45 by mkyianyt          #+#    #+#             */
/*   Updated: 2017/06/21 15:54:15 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	init_all_default(t_lem *lem)
{
	lem->lem_in = (char**)malloc(sizeof(char*));
	lem->lem_in[0] = NULL;
	lem->s_e = (char**)malloc(sizeof(char*) * 3);
	lem->s_e[0] = NULL;
	lem->s_e[1] = NULL;
	lem->s_e[2] = NULL;
	lem->name_r = (char**)malloc(sizeof(char*) * 3);
	lem->name_r[0] = NULL;
	lem->name_r[1] = NULL;
	lem->name_r[2] = NULL;
	lem->links = (char**)malloc(sizeof(char*));
	lem->links[0] = NULL;
	lem->nb_ants = 0;
	lem->nb_rooms = 0;
	lem->nb_links = 0;
	lem->get_start = 0;
	lem->get_end = 0;
	lem->get_links = 0;
}

void	init_default_adjacency_mtrx(t_lem *lem)
{
	int	i;
	int j;

	i = -1;
	lem->as_ar = (char**)malloc(sizeof(char*) * (lem->nb_rooms + 1));
	while (++i < lem->nb_rooms)
	{
		j = -1;
		lem->as_ar[i] = (char*)malloc(sizeof(char) * (lem->nb_rooms + 1));
		while (++j < lem->nb_rooms)
			lem->as_ar[i][j] = '0';
		lem->as_ar[i][j] = '\0';
	}
	lem->as_ar[i] = NULL;
	lem->indx_i = 0;
	lem->indx_j = 0;
}

void	init_visit_adjacency_mtrx(t_lem *lem)
{
	int		i;
	char	**split;

	i = -1;
	split = ft_strsplit(lem->links[0], '-');
	if (ft_strcmp(split[0], split[1]) == 0)
	{
		ft_free_array(split);
		ft_error();
	}
	while (++i < lem->nb_rooms)
	{
		if (ft_strcmp(lem->name_r[i], split[0]) == 0)
			lem->indx_i = i;
		else if (ft_strcmp(lem->name_r[i], split[1]) == 0)
			lem->indx_j = i;
	}
	remove_line_array(lem, 0);
	ft_free_array(split);
}

void	init_for_ways(t_lem *lem)
{
	int	i;

	i = -1;
	lem->way = (int*)malloc(sizeof(int) * lem->nb_rooms);
	lem->shortest_way = 0;
	lem->v_rooms = (int*)malloc(sizeof(int) * lem->nb_rooms);
	lem->all_ways = (int**)malloc(sizeof(int*) * 10000);
	lem->indx_i = 0;
	lem->indx_j = 0;
	lem->len = 0;
	while (++i < lem->nb_rooms)
		lem->v_rooms[i] = 0;
}
