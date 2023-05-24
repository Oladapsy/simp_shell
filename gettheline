#include "shell.h"

ssize_t gettheline(char **lineptr, t_size *n, FILE *stream)
void *myreallocate(void *ptr, unsigned int theoldsize, unsigned int thenewsize);
void theassignlinepointer(char **lineptr, t_size *n, char *buffer, t_size b);

/**
 * reallocate - This will Reallocates a memory block using the  malloc function and free.
 * @pointme: A pointer to the memory previously allocated.
 * @theoldsize: The size in bytes of the allocated space for ptr which is the pointer
 * @theoldsize: The size in bytes for the newly memory block.
 *
 * Return: If thenewsize == theoldsize - ptr.
 *         If thenewsize == 0 and ptr is not NULL - NULL.
 *         Otherwise - a pointer to the reallocated memory block.
 */
void *reallocate(void *pointme, unsigned int theoldsize, unsigned int thenewsize)
{
	void *memo;
	char *ptrcopy, *myfiller;
	unsigned int ourindex;

	if (thenewsize == theoldsize)
		return (pointme);

	if (pointme == NULL)
	{
		memo = malloc(thenewsize);
		if (memo == NULL)
			return (NULL);

		return (memo);
	}
/* done fore now=== last update */
	if (thenewsize == 0 && pointme != NULL)
	{
		free(pointme);
		return (NULL);
	}

	pointmecopy = pointme;
	memo = malloc(sizeof(*ptrcopy) * thenewsize);
	if (memo == NULL)
	{
		free(pointme);
		return (NULL);
	}

	myfiller = memo;

	for (ourindex = 0; ourindex < theoldsize && ourindex < thenewsize; ourindex++)
		myfiller[ourindex] = *ptrcopy++;

	free(pointme);
	return (memo);
}

/* done to this point */
/**
 * lineptrassign - Reassigns the lineptr variable for _getline.
 * @_lineptr: A buffer to store an input string.
 * @no: The size of lineptr.
 * @buffer: The string to assign to lineptr.
 * @bo: The size of buffer.
 */
void lineptrassign(char **_lineptr, t_size *no, char *buffer, t_size bo)
{
	if (*_lineptr == NULL)
	{
		if (bo > 120)
			*no = bo;
		else
			*no = 120;
		*_lineptr = buffer;
	}
	else if (*no < bo)
	{
		if (bo > 120)
			*no = bo;
		else
			*no = 120;
		*_lineptr = buffer;
	}
	else
	{
		stringcopy(*_lineptr, buffer);
		free(buffer);
	}
}

/**
 * gettheline - Reads input from a stream.
 * @_lineptr: A buffer to store the input.
 * @no: The size of lineptr.
 * @stream: The stream to read from.
 *
 * Return: The number of bytes read.
 */
ssize_t gettheline(char **_lineptr, t_size *n, FILE *stream)
{
	static ssize_t input;
	ssize_t ret;
	char co = 'x', *buffer;
	int ro;

	if (input == 0)
		fflush(stream);
	else
		return (-1);
	input = 0;

	buffer = malloc(sizeof(char) * 120);
	if (!buffer)
		return (-1);

	while (co != '\n')
	{
		ro = read(STDIN_FILENO, &co, 1);
		if (ro == -1 || (ro == 0 && input == 0))
		{
			free(buffer);
			return (-1);
		}
		if (ro == 0 && input != 0)
		{
			input++;
			break;
		}
		if (input >= 120)
			buffer = _realloc(buffer, input, input + 1);

		buffer[input] = c;
		input++;
	}
	buffer[input] = '\0';

	lineptrassign(_lineptr, no, buffer, input);

	ret = input;
	if (ro != 0)
		input = 0;
	return (ret);
}
