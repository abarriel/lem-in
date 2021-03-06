/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 22:55:53 by abarriel          #+#    #+#             */
/*   Updated: 2017/01/29 23:04:15 by abarriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_pow(int s1)
{
	int	i;

	i = 0;
	while (s1 > 0)
	{
		s1 /= 10;
		i++;
	}
	return (i);
}
