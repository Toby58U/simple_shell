#include "shell.h"

/**
 * _strlen - returns the length of a string
 * @z: the string whose length to check
 *
 * Return: integer length of string
 */
int _strlen(char *z)
{
	int n = 0;

	if (!z)
		return (0);

	while (*z++)
		n++;
	return (n);
}

/**
 * _strcmp - performs lexicogarphic comparison of two strangs.
 * @z1: the first strang
 * @z2: the second strang
 *
 * Return: negative if z1 < z2, positive if z1 > z2, zero if z1 == z2
 */
int _strcmp(char *z1, char *z2)
{
	while (*z1 && *z2)
	{
		if (*z1 != *z2)
			return (*z1 - *z2);
		z1++;
		z2++;
	}
	if (*z1 == *z2)
		return (0);
	else
		return (*z1 < *z2 ? -1 : 1);
}

/**
 * starts_with - checks if needle starts with haystack
 * @haystack: string to search
 * @needle: the substring to find
 *
 * Return: address of next char of haystack or NULL
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strcat - concatenates two strings
 * @destbuff: the destination buffer
 * @srcbuff: the source buffer
 *
 * Return: pointer to destination buffer
 */
char *_strcat(char *destbuff, char *srcbuff)
{
	char *ret = destbuff;

	while (*destbuff)
		destbuff++;
	while (*srcbuff)
		*destbuff++ = *srcbuff++;
	*destbuff = *srcbuff;
	return (ret);
}
