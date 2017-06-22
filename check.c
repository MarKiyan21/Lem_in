/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 21:35:10 by mkyianyt          #+#    #+#             */
/*   Updated: 2017/06/20 21:35:11 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		str_is_digit(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (!ft_isdigit(str[i]))
			return (0);
	return (1);
}

int		check_name_room(t_lem *lem, char *name)
{
	int	i;
	int	ret;

	i = -1;
	ret = 0;
	if (lem->nb_rooms > 0)
	{
		while (++i < lem->nb_rooms)
			if (ft_strcmp(lem->name_r[i], name) == 0)
			{
				ret = 1;
				break ;
			}
	}
	return (ret == 1 ? 1 : 0);
}

int		check_coord_room(char **split)
{
	int	x;
	int	y;

	if (*split[0] == 'L' || *split[0] == '#')
		return (0);
	if (str_is_digit(split[1]) && str_is_digit(split[2]) && !split[3])
	{
		x = ft_atoi(split[1]);
		y = ft_atoi(split[2]);
		if (x > 2147483647 || x < 0 || y > 2147483647 || y < 0)
			return (0);
		return (1);
	}
	else
		return (0);
}

int		check_name_link(t_lem *lem, char *name)
{
	int	i;

	i = -1;
	while (++i < lem->nb_links)
		if (ft_strcmp(lem->links[i], name) == 0)
			return (1);
	return (0);
}
