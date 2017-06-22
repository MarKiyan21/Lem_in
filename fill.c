/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 21:35:20 by mkyianyt          #+#    #+#             */
/*   Updated: 2017/06/21 15:52:56 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	fill_nb_ants(t_lem *lem)
{
	char	*line;

	while (get_next_line(0, &line) > 0)
	{
		if (line[0] == '#' && line[1] != '#')
		{
			lem->lem_in = ft_merge_array(lem->lem_in, line);
			free(line);
		}
		else if (str_is_digit(line))
		{
			if (ft_atoi(line) > 2147483647 || ft_atoi(line) <= 0)
				ft_error();
			lem->nb_ants = ft_atoi(line);
			lem->lem_in = ft_merge_array(lem->lem_in, line);
			free(line);
			break ;
		}
		else
		{
			free(line);
			ft_error();
		}
	}
}

void	fill_start(t_lem *lem, char *line)
{
	lem->lem_in = ft_merge_array(lem->lem_in, line);
	while (get_next_line(0, &line))
	{
		if (line[0] == '#')
		{
			if (line[1] == '#')
				ft_error();
			lem->lem_in = ft_merge_array(lem->lem_in, line);
			free(line);
		}
		else
			break ;
	}
	if (!(*line))
		ft_error();
	fill_continue(lem, line, 1);
	free(line);
}

void	fill_end(t_lem *lem, char *line)
{
	lem->lem_in = ft_merge_array(lem->lem_in, line);
	while (get_next_line(0, &line))
	{
		if (line[0] == '#')
		{
			if (line[1] == '#')
				ft_error();
			lem->lem_in = ft_merge_array(lem->lem_in, line);
			free(line);
		}
		else
			break ;
	}
	if (!(*line))
		ft_error();
	fill_continue(lem, line, 0);
	free(line);
}

void	fill_rooms(t_lem *lem, char *line)
{
	char	**split;

	split = ft_strsplit(line, ' ');
	lem->name_r = ft_merge_array(lem->name_r, split[0]);
	lem->lem_in = ft_merge_array(lem->lem_in, line);
	(lem->nb_rooms)++;
	ft_free_array(split);
}

void	fill_links(t_lem *lem, char *line)
{
	lem->links = ft_merge_array(lem->links, line);
	lem->lem_in = ft_merge_array(lem->lem_in, line);
	(lem->nb_links)++;
	lem->get_links = 1;
}
