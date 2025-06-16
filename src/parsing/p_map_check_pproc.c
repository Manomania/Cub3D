/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_map_check_pproc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <elagouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 16:58:02 by elagouch          #+#    #+#             */
/*   Updated: 2025/06/16 16:59:49 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#ifdef BONUS

bool	invalid_char(char c)
{
	return (c != '0' && c != '1' && c != 'N' && c != 'S'
		&& c != 'E' && c != 'W' && c != ' ' && c != '\n' && c != 'D');
}
#else

bool	invalid_char(char c)
{
	return (c != '0' && c != '1' && c != 'N' && c != 'S'
		&& c != 'E' && c != 'W' && c != ' ' && c != '\n');
}
#endif
