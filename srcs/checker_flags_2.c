/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction_flags_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpachy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 11:53:49 by hpachy            #+#    #+#             */
/*   Updated: 2017/04/18 11:53:50 by hpachy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		flags_h_hh(char *str, t_env *env)
{
	if (str[env->index] == 'h' && str[env->index + 1] == 'h')
	{
		env->tab.type_hh = 1;
		env->index++;
		return (1);
	}
	else if (str[env->index] == 'h' && str[env->index - 1] != 'h')
	{
		env->tab.type_h = 1;
		return (1);
	}
	return (1);
}

int		flags_l_ll(char *str, t_env *env)
{
	if (str[env->index] == 'l' && str[env->index + 1] == 'l')
	{
		env->tab.type_ll = 1;
		env->index++;
		return (1);
	}
	else if (str[env->index] == 'l' && str[env->index - 1] != 'l')
	{
		env->tab.type_l = 1;
		return (1);
	}
	return (1);
}

int		flags_j(char *str, t_env *env)
{
	(void)str;
	env->tab.type_j = 1;
	return (1);
}

int		flags_z(char *str, t_env *env)
{
	(void)str;
	env->tab.type_z = 1;
	return (1);
}

int		flags_precision(char *str, t_env *env)
{
	int		precision;

	precision = 0;
	env->precision = 0;
	if (str[env->index] == '.')
	{
		env->index++;
		while (str[env->index] >= 48 && str[env->index] <= 57)
		{
			precision = precision * 10;
			precision = precision + str[env->index] - 48;
			env->index++;
		}
		if (precision == 0)
			return ((env->tab.type_point = -1));
		env->precision = precision;
		env->tab.type_0 = 0;
		return (1);
	}
	else
	{
		env->precision = 0;
		return (0);
	}
}
