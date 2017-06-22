/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_continue.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 21:59:49 by mkyianyt          #+#    #+#             */
/*   Updated: 2017/06/21 16:33:53 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	fill_continue(t_lem *lem, char *line, int flag)
{
	char	**split;

	split = ft_strsplit(line, ' ');
	if (!split[1] || !split[2] || check_name_room(lem, split[0]) ||
		!check_coord_room(split))
		ft_error();
	else
	{
		(lem->nb_rooms)++;
		if (flag == 1)
			lem->get_start = 1;
		else if (flag == 0)
			lem->get_end = 1;
	}
	if (flag == 1)
		lem->s_e[0] = ft_strdup(split[0]);
	else if (flag == 0)
		lem->s_e[1] = ft_strdup(split[0]);
	lem->name_r = ft_merge_array(lem->name_r, split[0]);
	lem->lem_in = ft_merge_array(lem->lem_in, line);
	ft_free_array(split);
}
