/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction_app_flags1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpachy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 10:51:18 by hpachy            #+#    #+#             */
/*   Updated: 2017/05/16 16:01:25 by hpachy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		flags_sharps_app_2(char **str, t_env *env, char c)
{
	char	*tmp;

	if (c == 'i' || c == 'd' || c == 'D')
		return ;
	flags_padding_app(str, env, c);
	if (c == 'X')
	{
		*str = ft_strtrim(*str);
		tmp = *str;
		*str = ft_strjoin("0X", tmp);
		free(tmp);
		if (env->tab.type_0 == 0)
			flags_padding_app(str, env, c);
	}
	else if (c == 'x')
	{
		*str = ft_strtrim(*str);
		tmp = *str;
		*str = ft_strjoin("0x", *str);
		free(tmp);
		if (env->tab.type_0 == 0)
			flags_padding_app(str, env, c);
	}
}

void		flags_sharps_app(char **str, t_env *env, char c)
{
	char	*tmp;

	if (c == 'i' || c == 'd' || c == 'D')
		return ;
	flags_sharps_app_2(str, env, c);
	if (c == 'o' || c == 'O')
	{
		*str = ft_strtrim(*str);
		tmp = *str;
		*str = ft_strjoin("0", *str);
		free(tmp);
		if (env->tab.type_0 == 0)
			flags_padding_app(str, env, c);
	}
	env->padding = 0;
}

char		*flags_zero_app(char *str, t_env *env, char c)
{
	int		tmp;

	tmp = ft_strlen(str);
	if (tmp >= env->padding)
		return (str);
	if (c == 'o' && env->tab.type_sharp == 1)
		return (ft_strcat(
					ft_c_strnew(env->padding - ft_strlen(str) - 1, '0'), str));
	else if (c == 'o')
		return (ft_strcat(
					ft_c_strnew(env->padding - ft_strlen(str), '0'), str));
	else if ((c == 'x' || c == 'X') && env->tab.type_sharp == 1)
		return (ft_strcat(
					ft_c_strnew(env->padding - ft_strlen(str) - 2, '0'), str));
	else if (c == 'x' || c == 'X' || c == 'd' ||
			c == 'D' || c == 'i' || c == 'u' || c == 'U')
		return (ft_strcat(
					ft_c_strnew(env->padding - ft_strlen(str), '0'), str));
		return (NULL);
}

char		*flags_less_app(char *str, t_env *env, char c)
{
	int		tmp;

	tmp = ft_strlen(str);
	if (tmp >= env->padding)
		return (str);
	if (c == 'o' && env->tab.type_sharp == 1)
		return (ft_strcat(str,
					ft_c_strnew(env->padding - ft_strlen(str), ' ')));
	else if (c == 'o')
		return (ft_strcat(str,
					ft_c_strnew(env->padding - ft_strlen(str), ' ')));
	else if ((c == 'x' || c == 'X') && env->tab.type_sharp == 1)
		return (ft_strcat(str,
					ft_c_strnew(env->padding - ft_strlen(str), ' ')));
	else if (c == 'x' || c == 'X' || c == 'd' ||
			c == 'D' || c == 'i' || c == 'u' || c == 'U')
		return (ft_strcat(str,
					ft_c_strnew(env->padding - ft_strlen(str), ' ')));
		return (NULL);
}

void		flags_add_app(char **str, t_env *env, char c)
{
	(void)env;
	(void)c;
	*str = ft_strjoin("+", *str);
}
