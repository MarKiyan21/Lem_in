/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   associate_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 21:34:55 by mkyianyt          #+#    #+#             */
/*   Updated: 2017/06/20 21:35:02 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	remove_line_array(t_lem *lem, int nb_i)
{
	int		i;
	int		j;
	char	**tmp;

	i = -1;
	j = 0;
	tmp = lem->links;
	lem->links = NULL;
	(lem->nb_links)--;
	lem->links = (char**)malloc(sizeof(char*) * (lem->nb_links + 1));
	while (++i < lem->nb_links)
	{
		if (j == nb_i)
			j++;
		lem->links[i] = ft_strdup(tmp[j]);
		j++;
	}
	lem->links[lem->nb_links] = NULL;
	ft_free_array(tmp);
}

void	create_associate_arr(t_lem *lem)
{
	int	buff;

	buff = lem->nb_links;
	init_default_adjacency_mtrx(lem);
	while (lem->nb_links > 0)
	{
		init_visit_adjacency_mtrx(lem);
		lem->as_ar[lem->indx_i][lem->indx_j] = '1';
		lem->as_ar[lem->indx_j][lem->indx_i] = '1';
	}
	lem->nb_links = buff;
}
