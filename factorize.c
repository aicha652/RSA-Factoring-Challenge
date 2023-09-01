#include "main.h"
/**
 * factorize - function that factorize numbers
 * as possible into a product of two smaller numbers
 * @line_count: line number in the file
 * @arg: argument
 * Return: factors
 */
void factorize(int line_count, char *arg)
{
	int n, fact1, fact2, square, i;

	if (arg == NULL || !isdigit(*arg))
	{
		fprintf(stderr, "L%d: Usage: integer\n", line_count);
		exit(EXIT_FAILURE);
	}
	(void)line_count;
	n = atoi(arg);
	square = sqrt(n);
	if (n <= 1)
	{
		fprintf(stderr, "the number should be greater than 1\n");
		exit(EXIT_FAILURE);
	}
	for (i = 2; i <= square; i++)
	{
		if (n % i == 0)
		{
			fact1 = i;
			fact2 = n / i;
		}
	}
	printf("%d=%d*%d\n", n, fact1, fact2);
}
