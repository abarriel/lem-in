/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 11:33:15 by abarriel          #+#    #+#             */
/*   Updated: 2017/02/23 16:57:46 by abarriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	check_room(t_room *tmp)
{
	t_room	*begin_list;
	int		i;
	int		u;

	i = 0;
	u = 0;
	begin_list = tmp;
	while (tmp)
	{
		if (tmp->start == 1)
			u++;
		if (tmp->end == 1)
			i++;
		tmp = tmp->next;
	}
	if (u != 1)
		ft_exit("Missing Start");
	if (i != 1)
		ft_exit("Missing End");
	tmp = begin_list;
}

int		check_stopping(t_room *tmp, char *line, int index)
{
	t_room	*begin_list;
	int		u;

	begin_list = tmp;
	u = 0;
	while (tmp)
	{
		if (!ft_strncmp(line, tmp->name, index))
			u++;
		tmp = tmp->next;
	}
	tmp = begin_list;
	if (u == 0)
		return (1);
	return (0);
}

void	print_room(t_room *r)
{
	ft_printf("\n");
	while (r)
	{
		if (r->start == 1)
			ft_printf("{RED}%s%s", r->name, " = Start");
		else if (r->end == 1)
			ft_printf("{RED}%s%s", r->name, " = End");
		else
			ft_printf("{GRE}%s", r->name);
		if (r->tube == NULL)
			r = r->next;
		else
		{
			while (r->tube)
			{
					ft_printf("{YEL} - %s", r->tube->name);
				r->tube = r->tube->next;
			}
			r = r->next;
		}
		ft_printf("\n");
	}
}

int		parser(void)
{
	char	*line;
	t_room	*r;
	t_ant	*a;
	int		i;
	int		stop;

	stop = 0;
	i = 0;
	get_next_line(0, &line);
	a = init_ant(line);
	while (get_next_line(0, &line) > 0 && stop != 1)
	{
		if (*line != '#' && (i = if_so_('-', line)))
			stop = add_tube(&r, line, i);
		else if (!ft_strcmp("##start", line) && get_next_line(0, &line) == 1)
			add_back_room(&r, line, 1);
		else if (!ft_strcmp("##end", line) && get_next_line(0, &line) == 1)
			add_back_room(&r, line, 2);
		else
			add_back_room(&r, line, 0);
	}
	start_algo(r, a);
	return (0);
}
