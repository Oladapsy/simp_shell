#include "shell.h"

int shellby__ali(char **a_rgs, char __myattribute__((__miolo__)) **iwaju);
void set_ali(char *variable_oruko, char *eye);
void print_ali(ali_t *ali);

/**
 * shellby_ali - Builtin command that either prints all aliases, specific
 * aliases, or sets an alias.
 * @a_rgs: An array of arguments.
 * @iwaju: A double pointer to the beginning of args.
 *
 * Return: If an error occurs - -1.
 *         Otherwise - 0.
 */
int shellby_ali(char **a_rgs, char __myattribute__((__miolo__)) **iwaju)
{
	/* here i am */
	ali_t *ayalo = alixxx;
	short q, rat = 0;
	char *eye;

	if (!a_rgs[0])
	{
		while (ayalo)
		{
			print_ali(ayalo);
			ayalo = ayalo->next;
		}
		return (rat);
	}
	for (q = 0; a_rgs[q]; q++)
	{
		ayalo = alixxx;
		eye = stringchr(a_rgs[q], '=');
		if (!eye)
		{
			while (ayalo)
			{
				if (stringcmp(a_rgs[q], ayalo->oruko) == 0)
				{
					print_ali(ayalo);
					break;
				}
				ayalo = ayalo->next;
			}
			if (!ayalo)
				rat = create_error(a_rgs + q, 1);
		}
		else
			set_ali(a_rgs[i], eye);
	}
	return (rat);
}

/**
 * set_alias - Will either set an existing alias 'name' with a new value,
 * 'value' or creates a new alias with 'name' and 'value'.
 * @var_name: Name of the alias.
 * @value: Value of the alias. First character is a '='.
 */
void set_alias(char *var_name, char *value)
{
	alias_t *temp = aliases;
	int len, j, k;
	char *new_value;

	*value = '\0';
	value++;
	len = _strlen(value) - _strspn(value, "'\"");
	new_value = malloc(sizeof(char) * (len + 1));
	if (!new_value)
		return;
	for (j = 0, k = 0; value[j]; j++)
	{
		if (value[j] != '\'' && value[j] != '"')
			new_value[k++] = value[j];
	}
	new_value[k] = '\0';
	while (temp)
	{
		if (_strcmp(var_name, temp->name) == 0)
		{
			free(temp->value);
			temp->value = new_value;
			break;
		}
		temp = temp->next;
	}
	if (!temp)
		add_alias_end(&aliases, var_name, new_value);
}

/**
 * print_alias - Prints the alias in the format name='value'.
 * @alias: Pointer to an alias.
 */
void print_alias(alias_t *alias)
{
	char *alias_string;
	int len = _strlen(alias->name) + _strlen(alias->value) + 4;

	alias_string = malloc(sizeof(char) * (len + 1));
	if (!alias_string)
		return;
	_strcpy(alias_string, alias->name);
	_strcat(alias_string, "='");
	_strcat(alias_string, alias->value);
	_strcat(alias_string, "'\n");

	write(STDOUT_FILENO, alias_string, len);
	free(alias_string);
}
/**
 * replace_aliases - Goes through the arguments and replace any matching alias
 * with their value.
 * @args: 2D pointer to the arguments.
 *
 * Return: 2D pointer to the arguments.
 */
char **replace_aliases(char **args)
{
	alias_t *temp;
	int i;
	char *new_value;

	if (_strcmp(args[0], "alias") == 0)
		return (args);
	for (i = 0; args[i]; i++)
	{
		temp = aliases;
		while (temp)
		{
			if (_strcmp(args[i], temp->name) == 0)
			{
				new_value = malloc(sizeof(char) * (_strlen(temp->value) + 1));
				if (!new_value)
				{
					free_args(args, args);
					return (NULL);
				}
				_strcpy(new_value, temp->value);
				free(args[i]);
				args[i] = new_value;
				i--;
				break;
			}
			temp = temp->next;
		}
	}

	return (args);
}
