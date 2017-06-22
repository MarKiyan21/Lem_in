/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 21:36:16 by mkyianyt          #+#    #+#             */
/*   Updated: 2017/06/21 15:50:43 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	read_map(t_lem *lem)
{
	char	*line;

	while (get_next_line(0, &line) > 0)
	{
		if (!line)
			ft_error();
		if (ft_strcmp(line, "##start") == 0 && lem->get_start == 0)
			fill_start(lem, line);
		else if (ft_strcmp(line, "##end") == 0 && lem->get_end == 0)
			fill_end(lem, line);
		else if (line[0] == '#' && line[1] != '#')
			lem->lem_in = ft_merge_array(lem->lem_in, line);
		else if (find_valid_rooms(lem, line) && lem->get_links == 0)
			fill_rooms(lem, line);
		else if (find_valid_links(lem, line) && lem->get_start == 1 &&
				lem->get_end == 1)
			fill_links(lem, line);
		else
			ft_error();
		free(line);
	}
}
