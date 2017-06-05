/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction_flags_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpachy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 11:26:04 by hpachy            #+#    #+#             */
/*   Updated: 2017/04/18 11:26:05 by hpachy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		flags_sharps(char *str, t_env *env)
{
	(void)str;
	env->tab.type_sharp = 1;
	return (1);
}

int		flags_zero(char *str, t_env *env)
{
	(void)str;
	env->tab.type_0 = 1;
	return (1);
}

int		flags_less(char *str, t_env *env)
{
	(void)str;
	env->tab.type_less = 1;
	return (1);
}

int		flags_add(char *str, t_env *env)
{
	(void)str;
	env->tab.type_add = 1;
	return (1);
}

int		flags_blank(char *str, t_env *env)
{
	(void)str;
	env->tab.type_blank = 1;
	return (1);
}
