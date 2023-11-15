#include "tshell.h"

/**
 * **strtowrd - splits a string into words. Repeat delimiters are ignored
 * @string: the input string
 * @d: the delimeter string
 * Return: a pointer to an array of strings, or NULL on failure
 */

char **strtowrd(char *string, char *d)
{
	int n, j, k, m, numwords = 0;
	char **z;

	if (string == NULL || string[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (n = 0; string[i] != '\0'; n++)
		if (!is_delim(string[n], d) && (is_delim(string[n + 1], d) || !string[n + 1]))
			numwords++;

	if (numwords == 0)
		return (NULL);
	z = malloc((1 + numwords) * sizeof(char *));
	if (!z)
		return (NULL);
	for (i = 0, j = 0; j < numwords; j++)
	{
		while (is_delim(string[n], d))
			n++;
		k = 0;
		while (!is_delim(string[n + k], d) && string[n + k])
			k++;
		z[j] = malloc((k + 1) * sizeof(char));
		if (!z[j])
		{
			for (k = 0; k < j; k++)
				free(z[k]);
			free(z);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			z[j][m] = string[i++];
		z[j][m] = 0;
	}
	z[j] = NULL;
	return (z);
}

/**
 * **strtowrdii - splits a string into words
 * @string: the input string
 * @d: the delimeter
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **strtowrdii(char *string, char d)
{
	int n, j, k, m, numwords = 0;
	char **z;

	if (string == NULL || string[0] == 0)
		return (NULL);
	for (n = 0; string[n] != '\0'; n++)
		if ((string[n] != d && string[n + 1] == d) ||
		    (string[n] != d && !string[n + 1]) || string[n + 1] == d)
			numwords++;
	if (numwords == 0)
		return (NULL);
	z = malloc((1 + numwords) * sizeof(char *));
	if (!z)
		return (NULL);
	for (n = 0, j = 0; j < numwords; j++)
	{
		while (string[n] == d && string[n] != d)
			n++;
		k = 0;
		while (string[n + k] != d && string[n + k] && string[n + k] != d)
			k++;
		z[j] = malloc((k + 1) * sizeof(char));
		if (!z[j])
		{
			for (k = 0; k < j; k++)
				free(z[k]);
			free(z);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			z[j][m] = string[n++];
		z[j][m] = 0;
	}
	z[j] = NULL;
	return (z);
}
