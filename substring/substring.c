#include <stdlib.h>
#include <string.h>
#include "substring.h"

/**
 * all_used - check that every word appears exactly once in a window
 * @s: string to scan
 * @start: starting index of the window
 * @word_len: length of each word
 * @words: array of words
 * @nb_words: number of words
 *
 * Return: 1 if valid, 0 otherwise
 */
static int all_used(char const *s, int start, int word_len,
		char const **words, int nb_words)
{
	int *used;
	int i;
	int j;
	int found;

	used = calloc(nb_words, sizeof(int));
	if (!used)
		return (0);

	for (i = 0; i < nb_words; i++)
	{
		found = 0;
		for (j = 0; j < nb_words; j++)
		{
			if (!used[j] &&
				strncmp(s + start + i * word_len, words[j], word_len) == 0)
			{
				used[j] = 1;
				found = 1;
				break;
			}
		}
		if (!found)
		{
			free(used);
			return (0);
		}
	}
	free(used);
	return (1);
}

/**
 * find_substring - find all starting indices of substring(s) that is a
 *                  concatenation of each word in words exactly once
 * @s: string to scan
 * @words: array of words
 * @nb_words: number of elements in words
 * @n: address to store the number of results
 *
 * Return: allocated array of indices, or NULL if none found
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int s_len;
	int word_len;
	int window_len;
	int *indices;
	int count;
	int i;

	*n = 0;
	if (!s || !words || nb_words <= 0)
		return (NULL);

	s_len = strlen(s);
	word_len = strlen(words[0]);
	window_len = word_len * nb_words;

	if (window_len > s_len)
		return (NULL);

	indices = malloc((s_len - window_len + 1) * sizeof(int));
	if (!indices)
		return (NULL);

	count = 0;
	for (i = 0; i <= s_len - window_len; i++)
	{
		if (all_used(s, i, word_len, words, nb_words))
			indices[count++] = i;
	}

	*n = count;
	if (count == 0)
	{
		free(indices);
		return (NULL);
	}
	return (indices);
}
