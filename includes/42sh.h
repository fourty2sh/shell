/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   42sh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphokomp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 20:58:37 by wphokomp          #+#    #+#             */
/*   Updated: 2017/09/22 23:08:08 by wphokomp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	_42SH_H
# define _42SH_H

# include "../lib/libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <dirent.h>
# include <signal.h>
# include <sys/types.h>

typedef struct s_env	t_env;
typedef struct s_search	t_search;

extern pid_t	g_pid;

struct	s_search
{
	int				i;
	char			**path;
	char			*str;
	DIR				*dir;
	struct dirent	*sd;
};

struct	s_env
{
	char	**env;
	char	*ln;
	char	**args;
	char	**cmds;
};

void	ft_echo(t_env *e);
void	run_cmd(t_env *e);
void	get_env(t_env *e);
void	ft_env(t_env *e);
void	ft_setenv(t_env *e);
void	free_tab(char **args);
void	run_exec(char *path, t_env *e);
void	ft_del_env(int *chk, char **env, int y);
char	*ft_getenv(char *str, t_env *e);
char	*ft_replace_env(int *chk, char *args, char *env);
char	**tab_add(char **, char *str);
int		ft_unsetenv(t_env *e);
int		search_paths(t_env *e);

#endif
