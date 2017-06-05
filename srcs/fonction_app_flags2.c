/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction_app_flags2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpachy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 10:51:31 by hpachy            #+#    #+#             */
/*   Updated: 2017/04/20 10:51:32 by hpachy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define TYPE env->tab

char	*flags_padd_app(char *str, t_env *env, char c)
{
	int		tmp;

	tmp = ft_strlen(str);
	if (tmp >= env->padding)
		return (str);
	if (c == 'o' || c == 'O')
	{
		tmp = env->padding - ft_strlen(str);
		if (tmp < 0)
			tmp = -tmp;
		return (ft_strcat(ft_c_strnew(tmp, ' '), str));
	}
	if (c == 'x' || c == 'X' || c == 'u' || c == 'U'
		|| c == 'd' || c == 'i')
	{
		tmp = env->padding - ft_strlen(str);
		if (tmp < 0)
			tmp = -tmp;
		return (ft_strcat(ft_c_strnew(tmp, ' '), str));
	}
	return (NULL);
}

char	*flags_zero_precission_app(char *str, t_env *env, char c)
{
	int		tmp;

	tmp = ft_strlen(str);
	if (tmp >= env->precision)
		return (str);
	if (c == 'x' || c == 'X' || c == 'd' || c == 'D'
		|| c == 'i' || c == 'u' || c == 'U' || c == 'O' || c == 'o')
		return (ft_strcat(ft_c_strnew(
			env->precision - ft_strlen(str), '0'), str));
		return (str);
}

char	*flags_zero_padding_app(char *str, t_env *env, char c)
{
	int		tmp;

	tmp = ft_strlen(str);
	if (tmp >= env->padding)
		return (str);
	else
		TYPE.type_less = 0;
	if (c == 'x' || c == 'X' || c == 'd' || c == 'D' ||
		c == 'i' || c == 'u' || c == 'U' || c == 'o' || c == 'O')
		return (ft_strcat(
			ft_c_strnew(env->padding - ft_strlen(str), '0'), str));
		return (str);
}

void	flags_padding_app(char **str, t_env *env, char c)
{
	if (c == 'x' || c == 'X' || c == 'o' || c == 'u' || c == 'U' || c == 'O')
	{
		if (TYPE.type_add)
			TYPE.type_add = 0;
		if (TYPE.type_blank)
			TYPE.type_blank = 0;
		if (TYPE.type_add && TYPE.type_blank)
			TYPE.type_blank = 0;
		if (TYPE.type_less && TYPE.type_0)
			TYPE.type_0 = 0;
		padding_x_x_o(str, env, c);
	}
	else if (c == 'i' || c == 'D' || c == 'd')
	{
		if (TYPE.type_add && TYPE.type_blank)
			TYPE.type_blank = 0;
		if (TYPE.type_less && TYPE.type_0)
			TYPE.type_0 = 0;
		padding_i_d_d(str, env, c);
	}
	else if (c == 's' || c == 'c')
		padding_c_s(str, env, c);
}

void	flags_blank_app(char **str, t_env *env, char c)
{
	(void)env;
	(void)c;
	if (c == 'd' || c == 'i' || c == 'D')
		*str = ft_strjoin(" ", *str);
}
