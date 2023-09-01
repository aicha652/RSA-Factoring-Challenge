#include "main.h"
/**
 * main - function
 * @argc: size of arguments
 * @argv: array of arguments
 * Return: Success or Failure
 */
int main(int argc, char *argv[])
{
	FILE *fptr;
	char *line = NULL, *token = NULL;
	size_t line_sz = 0;
	int line_count = 0;


	if (argc != 2)
	{
		fprintf(stderr, "Usage: factors <file>\n");
		exit(EXIT_FAILURE);
	}
	fptr = fopen(argv[1], "r");
	if (fptr == NULL)
	{
		fprintf(stderr, "Failed to open file\n");
		exit(EXIT_FAILURE);
	}
	while (getline(&line, &line_sz, fptr) != -1)
	{
		line_count++;
		token = strtok(line, "\t\r\n ");
		while (token != NULL)
		{
			factorize(line_count, token);
			token = strtok(NULL, "\t\r\n ");
		}
	}
	free(line);
	fclose(fptr);
	exit(EXIT_SUCCESS);
}
