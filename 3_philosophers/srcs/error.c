/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojkim <seojkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 14:08:24 by seojkim           #+#    #+#             */
/*   Updated: 2024/08/29 16:34:57 by seojkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	handle_error(int errno)
{
	if (errno == 0)
		printf("Invalid Arguments.\n");
	else if (errno == 1)
		printf("Invalid Philosophers Number.\n");
	else if (errno == 2)
		printf("Malloc Error.\n");
	return (0);
}
