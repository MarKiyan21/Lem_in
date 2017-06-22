/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 21:35:57 by mkyianyt          #+#    #+#             */
/*   Updated: 2017/06/21 16:44:02 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_error(void)
{
	ft_putstr("ERROR\n");
	exit(0);
}

void	print_lem_in(t_lem *lem)
{
	int	i;

	i = -1;
	while (lem->lem_in[++i])
	{
		ft_putstr(lem->lem_in[i]);
		ft_putstr("\n");
	}
	ft_putstr("\n");
}

int		main(int ac, char **av)
{
	t_lem	lem;

	if (ac == 1 && av[0])
	{
		init_all_default(&lem);
		fill_nb_ants(&lem);
		read_map(&lem);
		if (lem.get_links == 0)
			ft_error();
		create_associate_arr(&lem);
		find_all_ways(&lem);
		return (0);
	}
	else
		ft_error();
}
