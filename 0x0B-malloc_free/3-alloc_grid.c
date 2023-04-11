#include <stdlib.h>
/**
 * alloc_grid - allocate a 2d array of integers
 * @width: integer
 * @height: integer
 *
 * Return: a pointer to the 2d array, NULL on failure or if
 * one of the parameters is less then or equale to zero.
 */
int **alloc_grid(int width, int height)
{
	int i, j;
	int **grid;

	if (width <= 0 || height <= 0)
		return (NULL);

	grid = malloc(sizeof(int *) * height);

	for (i = 0; i < height; i++)
		grid[i] = malloc(sizeof(int) * width);

	if (grid == NULL)
	{
		free(grid);
		return (NULL);
	}

	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
			grid[i][j] = 0;
	}

	return (grid);
}