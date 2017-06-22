/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 21:35:29 by mkyianyt          #+#    #+#             */
/*   Updated: 2017/06/21 15:48:41 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		find_valid_rooms(t_lem *lem, char *line)
{
	char	**split;

	if (ft_strchr(line, ' ') != NULL && ft_strchr(line, '-') == NULL)
	{
		split = ft_strsplit(line, ' ');
		if (!split[1] || !split[2] || *split[0] == 'L' || *split[0] == '#' ||
			check_name_room(lem, split[0]) || !check_coord_room(split))
			ft_error();
		if (!str_is_digit(split[1]) || !str_is_digit(split[2]) || split[3])
			ft_error();
		else if (str_is_digit(split[1]) && str_is_digit(split[2]))
		{
			ft_free_array(split);
			return (1);
		}
	}
	return (0);
}

int		find_valid_links(t_lem *lem, char *line)
{
	int		ret;
	char	**split;

	ret = 0;
	if (ft_strchr(line, '-') != NULL && ft_strchr(line, ' ') == NULL)
	{
		split = ft_strsplit(line, '-');
		if (split[1] && !split[2])
			if (!check_name_link(lem, line) && check_name_room(lem, split[0]) &&
				check_name_room(lem, split[1]))
				ret++;
		ft_free_array(split);
	}
	return (ret == 1 ? 1 : 0);
}

char	*find_name_room(t_lem *lem, int index)
{
	int	i;

	i = lem->way[index];
	return (lem->name_r[i]);
}

int		find_nb_room(char **str, char *room)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (ft_strcmp(str[i], room) == 0)
			return (i);
	}
	ft_error();
	return (0);
}
