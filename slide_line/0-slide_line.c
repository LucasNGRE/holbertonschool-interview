#include "slide_line.h"

/**
 * slide_left - Fait glisser et fusionne les nombres vers la gauche
 * @line: Pointeur vers le tableau d'entiers
 * @size: Nombre d'éléments dans @line
 *
 * Return: 1 en cas de succès, 0 en cas d'échec
 */
int slide_left(int *line, size_t size)
{
	size_t i, j = 0;
	/* Déplacer tous les éléments non nuls vers la gauche */
	for (i = 0; i < size; i++)
	{
		if (line[i] != 0)
		{
			line[j++] = line[i];
		}
	}
	/* Remplir le reste du tableau avec des zéros */
	for (; j < size; j++)
	{
		line[j] = 0;
	}
	/* Fusionner les éléments identiques */
	for (i = 0; i < size - 1; i++)
	{
		if (line[i] == line[i + 1] && line[i] != 0)
		{
			line[i] *= 2;
			line[i + 1] = 0;
			i++; /* Passer à l'élément suivant */
		}
	}
	/* Réorganiser à nouveau les éléments non nuls vers la gauche */
	j = 0;
	for (i = 0; i < size; i++)
	{
		if (line[i] != 0)
		{
			line[j++] = line[i];
		}
	}
	for (; j < size; j++)
	{
		line[j] = 0;
	}
	return (1);
}

/**
 * slide_right - Fait glisser et fusionne les nombres vers la droite
 * @line: Pointeur vers le tableau d'entiers
 * @size: Nombre d'éléments dans @line
 *
 * Return: 1 en cas de succès, 0 en cas d'échec
 */
int slide_right(int *line, size_t size)
{
	size_t i, j = size - 1;
	/* Déplacer tous les éléments non nuls vers la droite */
	for (i = size - 1; i < size; i--)
	{
		if (line[i] != 0)
		{
			line[j--] = line[i];
		}
	}
	/* Remplir le reste du tableau avec des zéros */
	for (; j < size; j++)
	{
		line[j] = 0;
	}
	/* Fusionner les éléments identiques */
	for (i = size - 1; i > 0; i--)
	{
		if (line[i] == line[i - 1] && line[i] != 0)
		{
			line[i] *= 2;
			line[i - 1] = 0;
			i--; /* Passer à l'élément suivant après fusion */
		}
	}
	/* Réorganiser à nouveau les éléments non nuls vers la droite */
	j = size - 1;
	for (i = size - 1; i < size; i--)
	{
		if (line[i] != 0)
		{
			line[j--] = line[i];
		}
	}
	for (; j < size; j++)
	{
		line[j] = 0;
	}

	return (1);
}

/**
 * slide_line - Gère le déplacement des nombres dans le tableau
 * @line: Pointeur vers le tableau d'entiers
 * @size: Nombre d'éléments dans @line
 * @direction: Direction du mouvement (SLIDE_LEFT ou SLIDE_RIGHT)
 *
 * Return: 1 en cas de succès, 0 en cas d'échec
 */
int slide_line(int *line, size_t size, int direction)
{
	if (direction == SLIDE_LEFT)
	{
		return (slide_left(line, size));
	}
	else if (direction == SLIDE_RIGHT)
	{
		return (slide_right(line, size));
	}
	return (0); /* Direction invalide */
}
