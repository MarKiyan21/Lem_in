/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 21:36:08 by mkyianyt          #+#    #+#             */
/*   Updated: 2017/06/21 16:14:06 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft/libft.h"

typedef struct		s_lem
{
	char			**lem_in;
	char			**s_e;
	char			**name_r;
	char			**links;
	char			**as_ar;
	int				indx_i;
	int				indx_j;
	int				*v_rooms;
	int				*way;
	int				*shortest_way;
	int				**all_ways;
	int				nb_ants;
	int				nb_rooms;
	int				nb_links;
	int				get_start;
	int				get_end;
	int				get_links;
	int				len;
	int				find;
}					t_lem;

int					main(int ac, char **av);
void				init_all_default(t_lem *lem);
void				init_default_adjacency_mtrx(t_lem *lem);
void				init_visit_adjacency_mtrx(t_lem *lem);
void				init_for_ways(t_lem *lem);
void				fill_nb_ants(t_lem *lem);
int					str_is_digit(char *str);
void				ft_error(void);
void				read_map(t_lem *lem);
void				fill_continue(t_lem *lem, char *line, int flag);
void				fill_start(t_lem *lem, char *line);
void				fill_end(t_lem *lem, char *line);
void				fill_rooms(t_lem *lem, char *line);
void				fill_links(t_lem *lem, char *line);
int					find_nb_room(char **str, char *room);
char				*find_name_room(t_lem *lem, int index);
int					check_name_room(t_lem *lem, char *name);
int					check_coord_room(char **split);
int					check_name_link(t_lem *lem, char *name);
int					find_valid_rooms(t_lem *lem, char *line);
int					find_valid_links(t_lem *lem, char *line);
void				create_associate_arr(t_lem *lem);
void				find_all_ways(t_lem *lem);
void				remove_line_array(t_lem *lem, int nb_i);
void				print_lem_in(t_lem *lem);

#endif
