/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_ll_nvof.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 17:46:31 by bguillau          #+#    #+#             */
/*   Updated: 2023/08/09 17:46:33 by bguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "../libft.h"

/*	- atoi nptr into nb passed by reference
	- nb is set to 0
	- accepts single '+' or single '-'
	- returns 0 if ovlf ; 1 if ok	*/

int	ft_atoc_novf(const char *nptr, char *nb)
{
	int		sign;
	char	prev_nb;

	if (!ft_strcmp(nptr, CHAR_MIN_STR))
		return (*nb = -127 -1, 1);
	sign = 1;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign *= -1;
		nptr++;
	}
	*nb = 0;
	prev_nb = 0;
	while (*nptr >= '0' && *nptr <= '9')
	{
		*nb = *nb * 10 + (*nptr++ - '0');
		if (*nb < prev_nb)
			return (0);
		prev_nb = *nb;
	}
	*nb = *nb * sign;
	return (1);
}
