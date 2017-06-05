/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpachy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 14:39:24 by hpachy            #+#    #+#             */
/*   Updated: 2017/05/16 14:58:39 by hpachy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

static	t_flags	g_flags_tab[11] = {
	{'0', &flags_zero},
	{'#', &flags_sharps},
	{'-', &flags_less},
	{'+', &flags_add},
	{' ', &flags_blank},
	{'h', &flags_h_hh},
	{'l', &flags_l_ll},
	{'j', &flags_j},
	{'z', &flags_z},
	{'.', &flags_precision},
	{'\0', NULL}
};

static	t_conv	g_conversion_tab[16] = {
	{'s', &conver_string},
	{'S', &conver_unicode_string},
	{'p', &conver_pointer},
	{'d', &conver_int},
	{'D', &conver_d},
	{'i', &conver_int},
	{'o', &conver_octet},
	{'O', &conver_o},
	{'u', &conver_u},
	{'U', &conver_lu},
	{'x', &conver_hexa},
	{'X', &conver_hexa},
	{'c', &conver_char},
	{'C', &conver_unicode_char},
	{'%', &conver_pourcent},
	{'\0', NULL}
};

static	int		check_flags(char *str, t_env *env)
{
	int		a;

	a = 0;
	while (g_flags_tab[a].c != '\0')
	{
		if (g_flags_tab[a].c == str[env->index])
		{
			g_flags_tab[a].flags(str, env);
			return (1);
		}
		else if (str[env->index] >= 48 && str[env->index] <= 57)
			ft_padding(str, env);
		a++;
	}
	return (0);
}

static	int		check_convertion(char *str, t_env *env, va_list *ap)
{
	int		a;
	char	*tmp;

	a = 0;
	while (g_conversion_tab[a].c != '\0')
	{
		if (g_conversion_tab[a].c == str[env->index])
		{
			tmp = g_conversion_tab[a].conv(str, env, ap);
			init_flags(env);
			fill_tab(env->buff, ft_strlen(tmp), env, tmp);
			return (1);
		}
		a++;
	}
	return (0);
}

static	void	checker_str_flags_convertion(t_env *env,
											int pars_end,
											char *str,
											va_list *ap)
{
	while (pars_end != 1)
	{
		env->index++;
		check_flags(str, env);
		if (check_convertion(str, env, ap))
		{
			env->index++;
			pars_end = 1;
		}
		else if (!check_convertion(str, env, ap) && !check_flags(str, env))
		{
			if (env->padding && !env->tab.type_less)
			{
				if (env->tab.type_0)
					fill_tab(env->buff, env->padding - 1,
						env, ft_c_strnew(env->padding, '0'));
				else
					fill_tab(env->buff, env->padding - 1,
						env, ft_c_strnew(env->padding, ' '));
			}
			break ;
		}
		else
			pars_end = 0;
	}
}

static	void	check_char_padding(t_env *env, char *str)
{
	fill_tab_char(env, str[env->index]);
	if (env->padding && env->tab.type_less)
	{
		if (env->tab.type_0)
			fill_tab(env->buff, env->padding - 1,
				env, ft_c_strnew(env->padding, '0'));
		else
			fill_tab(env->buff, env->padding - 1,
				env, ft_c_strnew(env->padding, ' '));
		init_flags(env);
	}
	env->index++;
}

int				parser(char *str, t_env *env, va_list *ap)
{
	int		pars_end;

	pars_end = 0;
	init_env(env);
	if ((int)ft_strlen(str) == 1 && str[0] == '%')
	{
		print_tab(env);
		return (0);
	}
	while (str[env->index] != '\0')
	{
		if (str[env->index] == '%')
		{
			pars_end = 0;
			checker_str_flags_convertion(env, pars_end, str, ap);
			pars_end = 1;
		}
		else
			check_char_padding(env, str);
	}
	if (env->index_buff != 0)
		print_tab(env);
	return (0);
}
