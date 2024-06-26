/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:53:43 by yutsong           #+#    #+#             */
/*   Updated: 2024/06/26 20:08:19 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void unions(char *a, char *b)
{
	int idx1;
	int idx2;
	int flag;

	idx1 = 0;
	while (a[idx1])
	{
		flag = 0;
		idx2 = 0;
		while (idx2 < idx1)
		{
			if (a[idx1] == a[idx2])
				flag = 1;
			idx2 ++;
		}
		if (flag != 1)
			write(1, &a[idx1], 1);
		idx1 ++;
	}
	idx1 = 0;
	while (b[idx1])
	{
		flag = 0;
		idx2 = 0;
		while (a[idx2])
		{
			if (b[idx1] == a[idx2])
				flag = 1;
			idx2 ++;
		}
		idx2 = 0;
		while (idx2 < idx1)
		{
			if (b[idx1] == b[idx2])
				flag = 1;
			idx2 ++;
		}
		if (flag != 1)
			write(1, &b[idx1], 1);
		idx1 ++;
	}
}

int main(int argc, char **argv)
{
	if (argc == 3)
		unions(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}