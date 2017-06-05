/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpachy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 16:17:55 by hpachy            #+#    #+#             */
/*   Updated: 2017/04/05 16:33:01 by hpachy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>
#include <locale.h>

int		ft_printf(char *fmt, ...)
{
	va_list			ap;
	int				ret;
	t_env			*env;

	va_start(ap, fmt);
	if (!(env = malloc(sizeof(t_env))))
		return (-1);
	if (parser(fmt, env, &ap) == -1)
		return (-1);
	va_end(ap);
	ret = env->tab_return;
	free(env);
	return (ret);
}
