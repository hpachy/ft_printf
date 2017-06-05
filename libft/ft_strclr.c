/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpachy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 17:19:48 by hpachy            #+#    #+#             */
/*   Updated: 2016/11/06 17:19:49 by hpachy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_strclr(char *s)
{
	int	a;

	a = 0;
	if (s == NULL)
		return ;
	while (s[a])
		a++;
	while (a >= 0)
	{
		s[a] = '\0';
		a--;
	}
}