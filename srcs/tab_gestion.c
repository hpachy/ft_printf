/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_gestion.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpachy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 12:17:20 by hpachy            #+#    #+#             */
/*   Updated: 2017/04/18 12:17:21 by hpachy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"
#include "ft_printf.h"

void	print_tab(t_env *env)
{
	write(1, env->buff, env->index_buff);
	ft_bzero(env->buff, env->index_buff);
	env->tab_return += env->index_buff;
	env->index_buff = 0;
}

void	fill_tab(char *tab, int size, t_env *env, const char *str)
{
	double		nb_size;
	int			n;

	nb_size = (double)size / (double)BUFF_SIZE;
	size = (nb_size - (int)nb_size) * BUFF_SIZE;
	n = 0;
	if (env->index_buff + (nb_size * (double)BUFF_SIZE) >= BUFF_SIZE)
	{
		print_tab(env);
		while (n < (int)nb_size)
		{
			ft_strncpy(&tab[env->index_buff], str, BUFF_SIZE);
			env->index_buff += BUFF_SIZE;
			print_tab(env);
			n++;
		}
		ft_strncpy(&tab[env->index_buff], str, size);
		env->index_buff += size;
	}
	else
	{
		ft_strncpy(&tab[env->index_buff], str, size);
		env->index_buff += size;
	}
}

void	fill_tab_char(t_env *env, char c)
{
	if (env->index_buff + 1 > 4096)
	{
		print_tab(env);
		env->index_buff = 0;
	}
	env->buff[env->index_buff] = c;
	env->index_buff += 1;
}
