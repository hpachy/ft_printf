/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction_convertion_4.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpachy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 17:05:25 by hpachy            #+#    #+#             */
/*   Updated: 2017/04/18 17:05:26 by hpachy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

static	int		fonction_signe(char *tmp)
{
	int			index;

	index = 0;
	if ((tmp[0] >= '0' && tmp[0] <= '9') || tmp[0] == ' ')
	{
		if (tmp[0] == ' ')
		{
			while (tmp[index] != '\0')
			{
				if (tmp[index + 1] >= '0' && tmp[index + 1] <= '9')
					break ;
				index++;
			}
		}
		return (index);
	}
	while (tmp[index] != '\0')
	{
		if (tmp[index] == '-' || tmp[index] == '+')
			return (index);
		if (tmp[index] == '0')
			return (index);
		index++;
	}
	return (index);
}

static	char	*modif_str(char *str)
{
	int		index;
	int		stock;

	index = 0;
	stock = (int)ft_strlen(str);
	if (str[index] == '-')
	{
		while (index != stock)
		{
			str[index] = str[index + 1];
			index++;
		}
		return (str);
	}
	else
		return (str);
}

char			*negatif(char *tmp, t_env *env)
{
	char		*tmp_2;

	if (env->signe == '-')
	{
		if (fonction_signe(tmp) <= 0)
		{
			tmp_2 = tmp;
			tmp = ft_strjoin("-", tmp);
			free(tmp_2);
		}
		else
			tmp[fonction_signe(tmp)] = '-';
	}
	return (tmp);
}

char			*conver_int(char *str, t_env *env, va_list *ap)
{
	char		*tmp;

	env->signe = '-';
	if (!(tmp = flags_modif_itoa(str, env, ap)))
		return (NULL);
	if (tmp[ft_strlen(tmp) - 1] == '0' && env->tab.type_point)
		tmp[0] = '\0';
	if (tmp[0] == '-')
	{
		env->padding -= 1;
		env->tab.type_add = 0;
		env->tab.type_blank = 0;
		tmp = modif_str(tmp);
	}
	else
		env->signe = '+';
	if (env->precision)
		flags_precision_app(&tmp, env, str[env->index]);
	if (env->padding > env->precision)
		flags_padding_app(&tmp, env, str[env->index]);
	if (!env->padding && !env->precision)
		flags_precision_app(&tmp, env, str[env->index]);
	if (env->signe == '-')
		tmp = negatif(tmp, env);
	return (tmp);
}
