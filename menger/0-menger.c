#include <stdio.h>
#include <math.h>
#include "menger.h"

static int is_filled(int x, int y)
{
	while (x > 0 || y > 0)
	{
		if (x % 3 == 1 && y % 3 == 1)
			return (0);
		x /= 3;
		y /= 3;
	}
	return (1);
}

void menger(int level)
{
	int size, x, y;

	if (level < 0)
		return;

	size = pow(3, level);

	for (y = 0; y < size; y++)
	{
		for (x = 0; x < size; x++)
		{
			if (is_filled(x, y))
				putchar('#');
			else
				putchar(' ');
		}
		putchar('\n');
	}
}
