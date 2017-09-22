/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphokomp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 21:49:30 by wphokomp          #+#    #+#             */
/*   Updated: 2017/09/22 23:56:32 by wphokomp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/42sh.h"

char	*ft_trim(char const *s)
{
	int		i;
	int		x;
	char	*ret;

	i = -1;
	x = ft_strlen(s) - 1;
	while (s[x] == '"')
		x--;
	if (x == 0)
		return ("");
	while (s[++i] == '"')
		;
	ret = ft_strsub(s, i, (x - 1) + 1);
	return (ret);
}

void	ft_echo(t_env *e)
{
	int		i;
	char	*str;

	i = 0;
	while (e->args[++i])
	{
		if (e->args[i + 1])
		{
			str = ft_strjoin(e->args[i], ft_strjoin(" ", e->args[i + 1]));
			free(e->args[i + 1]);
			e->args[i + 1] = NULL;
		}
		if (e->args[i][0] == '$')
		{
			str = ft_getenv(&e->args[i][1], e);
			if (str)
				ft_putendl(str);
		}
		else
			ft_putendl(ft_trim(str));
	}
}

int		search_paths(t_env *e)
{
	t_search	s;

	s.path = ft_strsplit(ft_getenv("PATH", e), ':');
	s.i = 0;
	while (s.i > -1 && s.path[s.i])
	{
		s.dir = opendir(s.path[s.i]);
		while ((s.sd = readdir(s.dir)))
			if (!ft_strcmp(s.sd->d_name, e->args[0]))
			{
				s.str = ft_strjoin(s.path[s.i], "/");
				run_exec(ft_strjoin(s.str, s.sd->d_name), e);
				ft_strdel(&s.str);
				s.i = -2;
			}
		closedir(s.dir);
		s.i++;
	}
	free_tab(s.path);
	return (s.i);
}

void	run_cmd(t_env *e)
{
	char	**tab;
	char	*path;
	int		len;

	tab = ft_strsplit(e->args[0], '/');
	len = 0;
	path = ft_strdup(e->args[0]);
	while (tab[len])
		len++;
	ft_strdel(&e->args[0]);
	e->args[0] = ft_strdup(tab[len + 1]);
	run_exec(path, e);
	free_tab(tab);
}
