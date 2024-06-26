/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:40:07 by yutsong           #+#    #+#             */
/*   Updated: 2024/06/26 15:49:30 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{
	int idx1;
	int idx2;

	idx1 = 0;
	idx2 = 0;
	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	while (argv[1][idx1])
	{
		if (argv[1][idx1] == argv[2][idx2])
			write(1, &argv[1][idx1], 1);
		idx1 ++;
		idx2 ++;
	}
	write(1, "\n", 1);
}