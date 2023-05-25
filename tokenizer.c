#include "monty.h"

/**
 * words_counter - count the number of words in a line
 * @s: string to evaluate
 * Return: word count
 */
int words_counter(char *str)
{
	int flag, i, word;

	flag = 0;
	word = 0;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == ' ')
			flag = 0;
		else if (flag == 0)
		{
			flag = 1;
			word++;
		}
	}

	return (word);
}
/**
 * **strtow - splits a string into words
 * @str: string to split
 * Return: pointer to an array of strings
 */
char **strtow(char *str)
{
	char **ptr, *tmp;
	int i, k = 0, len = 0, words, c = 0, start, end;

	len = strlen(str);
	words = words_counter(str);
	if (words == 0)
		return (NULL);

	ptr = (char **) malloc(sizeof(char *) * (words + 1));
	if (ptr == NULL)
		return (NULL);

	for (i = 0; i <= len; i++)
	{
		if (isspace(str[i]) || str[i] == '\0' || str[i] == '\n')
		{
			if (c)
			{
				end = i;
				tmp = (char *) malloc(sizeof(char) * (c + 1));
				if (tmp == NULL)
					return (NULL);
				while (start < end)
					*tmp++ = str[start++];
				*tmp = '\0';
				ptr[k] = tmp - c;
				k++;
				c = 0;
			}
		}
		else if (c++ == 0)
			start = i;
	}

	ptr[k] = NULL;

	return (ptr);
}
