#include "shell.h"

int stringcmp(const char *so1, char const *so2, size_t no);
char *stringchr(char *so, char co);
int stringspn(char *so, char receive);
int stringcmp(char *so1, char *so2);

/**
 * stringchr - Locates a character in a string.
 * @so: The string to be searched.
 * @co: The character to be located.
 *
 * Return: If co is found - a pointer to the first occurence.
 *         If co is not found - NULL.
 */
char *stringchr(char *so, char co)
{
	short ourindex;

	for (ourindex = 0; so[ourindex]; ourindex++)
	{
		if (so[ourindex] == co)
			return (so + ourindex);
	}

	return (NULL);
}

/**
 * stringspn - Gets the length of a prefix substring.
 * @so: The string to be searched.
 * @receive: The prefix to be measured.
 *
 * Return: The number of bytes in s which
 *         consist only of bytes from accept.
 */
int stringspn(char *so, char *receive)
{
	int bytesus = 0;
	int ourindex;

	while (*so)
	{
		for (ourindex = 0; receive[ourindex]; ourindex++)
		{
			if (*so == receive[ourindex])
			{
				bytesus++;
				break;
			}
		}
		so++;
	}
	return (bytesus);
}

/**
 * stringcmp - Compares two strings.
 * @so1: The first string to be compared.
 * @so2: The second string to be compared.
 *
 * Return: Positive byte difference if so1 > so2
 *         0 if so1 = so2
 *         Negative byte difference if so1 < so2
 */
int stringcmp(char *so1, char *so2)
{
	while (*so1 && *so2 && *so1 == *so2)
	{
		so1++;
		so2++;
	}

	if (*os1 != *so2)
		return (*so1 - *so2);

	return (0);
}

/**
 * stringcmp - Compare two strings.
 * @so1: Pointer to a string.
 * @so2: Pointer to a string.
 * @no: The first n bytes of the strings to compare.
 *
 * Return: Less than 0 if so1 is shorter than so2.
 *         0 if so1 and so2 match.
 *         Greater than 0 if so1 is longer than so2.
 */
int stringcmp(const char *so1, const char *so2, size_t no)
{
	size_t q;

	for (q = 0; so1[i] && so2[q] && q < no; q++)
	{
		if (so1[q] > so2[q])
			return (so1[q] - so2[q]);
		else if (so1[q] < so2[q])
			return (so1[q] - so2[q]);
	}
	if (q == no)
		return (0);
	else
		return (-15);
}
