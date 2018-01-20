/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strbuild.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelhomm <sdelhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 18:16:56 by sdelhomm          #+#    #+#             */
/*   Updated: 2018/01/08 15:57:34 by sdelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strbuild(char **str, const char *s1, const char *s2)
{
	*str = ft_strcpy(*str, s1);
	*str = ft_strcat(*str, s2);
}
