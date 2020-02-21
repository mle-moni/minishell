/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gel-kasr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 14:26:16 by gel-kasr          #+#    #+#             */
/*   Updated: 2020/02/21 14:40:43 by gel-kasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _MINISHELL_H
# define _MINISHELL_H

# define RED		"\033[1;31m"
# define WHITE		"\033[0;m"
# define GREEN		"\033[1;32m"
# define BLUE		"\033[1;34m"
# define YELLOW		"\033[1;33m"

# define MALLOC_ERROR 2

# define DEBUG 0

# include "libft.h"

void		display_prompt(void);

#endif
