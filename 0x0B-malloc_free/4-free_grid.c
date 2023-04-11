#include <stdlib.h>
/**
 * free_grid - frees a 2d grid
 * @grid: 2d array
 * @height: integer
 */
void free_grid(int **grid, int height)
{
	int i, j;

	for (i = 0; i < height; i++)
	{
		for (j = 0; grid[i][j]; j++)
			free(grid[j]);

		free(grid);
	}


}
