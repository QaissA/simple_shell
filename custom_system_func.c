#include "shell.h"

/**
  * _strcat - a pointer function that concatenates
  * @dest: string parameter
  * @src: string parameter
  * Return: char
  */

char *_strcat(char *dest, char *src)
{
	int destlen = 0;
	int srclen = 0;
	int i;

	for (i = 0; dest[i] != '\0'; i++)
		destlen++;
	for (i = 0; src[i] != '\0'; i++)
		srclen++;
	for (i = 0; i <= srclen; i++)
		dest[destlen + i] = src[i];
	return (dest);
}

/**
  * _strcpy - copies string
  * @dest: parameter
  * @src: parameter
  * Return: dest
  */

char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

/**
  * _strdup - a function that returns a pointer to memory
  * @str: a string parameter
  * Return: NULL or a pointer
  */

char *_strdup(char *str)
{
	char *copy;
	int length = 0;
	int i;

	if (str == NULL)
		return (NULL);

	for (i = 0; str[i] != '\0'; i++)
		length++;

	copy = malloc(sizeof(char) * length + 1);

	if (copy == NULL)
		return (NULL);

	for (i = 0; str[i] != '\0'; i++)
		copy[i] = str[i];
	return (copy);
}

/**
  * _strlen - finds the length of a string
  * @s: parameter for string
  * Return: (0) (Success)
  */

int _strlen(char *s)
{
	int i;
	int count = 0;

	for (i = 0; s[i] != '\0'; i++)
	count++;
	return (count);
}

/**
  * _putchar - writes the character c to stdout
  * @c: The character to print
  *
  * Return: On success 1.
  * On error, -1 is returned, and errno is set appropriately.
  */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
