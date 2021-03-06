/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gel-kasr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 03:17:22 by gel-kasr          #+#    #+#             */
/*   Updated: 2019/08/06 15:29:32 by gel-kasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int		diff;
	int		i;

	i = 0;
	diff = 'A' - 'a';
	while (str[i])
	{
		str[i] = (str[i] >= 'A' && str[i] <= 'Z') ? str[i] - diff : str[i];
		i++;
	}
	return (str);
}
