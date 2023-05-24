#include "shell.h"

int stringlen(const char *so);
char *stringcopy(char *destin, const char *source);
char *_stringcat(char *destin, const char *source);
char *_stringcat(char *destin, const char *source, size_t no);

/**
 * stringlen - Returns the length of a string.
 * @so: A pointer to the characters string.
 *
 * Return: The length of the character string.
 */
int stringlen(const char *so)
{
	int ourlengthsize = 0;

	if (!so)
	return (ourlengthsize);

	for (ourlengthsize = 0; so[ourlengthsize]; ourlengthsize++);

	return (ourlengthsize);
}

/**
 * stringcopy - Copies the string pointed to by src, including the
 *           terminating null byte, to the buffer pointed by des.
 * @destin: Pointer to the destination of copied string.
 * @source: Pointer to the sourse of the source string.
 *
 * Return: Pointer to dest.
 */

/* done to this point */

char *stringcopy(char *destin, const char *source)
{
	size_t q;

	for (q = 0; source[q] != '\0'; q++)
		destin[q] = source[q];
	destin[q] = '\0';
	return (destin);
}

/**
 * _stringcat - Concantenates two strings.
 * @destin: Pointer to destination string.
 * @source: Pointer to source string.
 *
 * Return: Pointer to destination string.
 */
char *_stringcat(char *destin, const char *source)
{
	char *destinTemp;
	const char *sourrceTemp;

	destinTemp = destin;
	sourceTemp =  source;

	while (*destinTemp != '\0')
		destinTemp++;

	while (*sourceTemp != '\0')
		*destinTemp++ = *sourceTemp++;
	*destinTemp = '\0';
	return (destin);
}
/* i am here */

/**
 * _stringcat - Concantenates two strings where n number
 *            of bytes are copied from source.
 * @destin: Pointer to destination string.
 * @source: Pointer to source string.
 * @no: no bytes to copy from src.
 *
 * Return: Pointer to destination string.
 */
char *_stringcat(char *destin, const char *source, size_t no)
{
	size_t destin_len = stringlen(destin);
	size_t q;

	for (q = 0; q < no && source[q] != '\0'; q++)
		destin[destin_len + q] = source[q];
	destin[destin_len + q] = '\0';

	return (destin);
}
