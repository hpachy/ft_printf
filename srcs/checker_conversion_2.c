/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction_convertion_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpachy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 17:05:35 by hpachy            #+#    #+#             */
/*   Updated: 2017/04/18 17:05:38 by hpachy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*conver_hexa(char *str, t_env *env, va_list *ap)
{
	char		*tmp;

	tmp = flags_modif_itoa(str, env, ap);
	if (tmp[0] == '0')
	{
		env->tab.type_sharp = 0;
		tmp[0] = '0';
		tmp[1] = '\0';
	}
	if (tmp[0] == '0' && env->tab.type_point == -1)
		tmp[0] = '\0';
	if (str[env->index] == 'X')
		ft_toupper(tmp);
	if (env->precision)
		flags_precision_app(&tmp, env, str[env->index]);
	if (env->padding > env->precision)
		flags_padding_app(&tmp, env, str[env->index]);
	if (!env->padding && !env->precision)
		flags_precision_app(&tmp, env, str[env->index]);
	if (env->tab.type_sharp == 1)
		flags_sharps_app(&tmp, env, str[env->index]);
	return (tmp);
}

char			*conver_unicode_string(char *str, t_env *env, va_list *ap)
{
	(void)str;
	(void)env;
	va_arg(*ap, char*);
	return (NULL);
}

char			*conver_unicode_char(char *str, t_env *env, va_list *ap)
{
	(void)str;
	(void)env;
	va_arg(*ap, char*);
	return (NULL);
}

static	void	write_pourcent(char *tmp, t_env *env)
{
	if (env->tab.type_less == 0)
	{
		fill_tab(env->buff, ft_strlen(tmp) - 1, env, tmp);
		fill_tab_char(env, '%');
	}
	else if (env->tab.type_less == 1)
	{
		fill_tab_char(env, '%');
		fill_tab(env->buff, ft_strlen(tmp) - 1, env, tmp);
	}
}

char			*conver_pourcent(char *str, t_env *env, va_list *ap)
{
	char	*tmp;
	int		tmp_2;

	(void)str;
	(void)ap;
	tmp_2 = 0;
	if (env->padding >= env->precision)
		tmp_2 = env->padding - env->precision;
	else if (env->padding > env->precision)
		tmp_2 = env->precision - env->padding;
	if (tmp_2 == 0)
		tmp_2 = 1;
	if (env->tab.type_0)
		tmp = ft_c_strnew(tmp_2, '0');
	if (!env->tab.type_0)
		tmp = ft_c_strnew(tmp_2, ' ');
	write_pourcent(tmp, env);
	return (NULL);
}
