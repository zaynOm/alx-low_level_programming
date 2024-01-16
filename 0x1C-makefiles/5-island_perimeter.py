#!/usr/bin/python3
"Defines a function that calculate the perimeter of an island."


def island_perimeter(grid):
    """Calculats the perimeter of the island described in grid.

    Args:
        grid (list of list of int):  Describies the island.

    Returns:
        int: Returns the perimeter of the island.
    """

    prmtr = 0
    lenght = len(grid)
    bottom = lenght - 1
    for i in range(lenght):
        right = len(grid[i]) - 1
        for j in range(right + 1):
            if grid[i][j] == 1:
                if i > 0 and grid[i - 1][j] == 0:
                    prmtr += 1
                if j > 0 and grid[i][j - 1] == 0:
                    prmtr += 1
                if i < bottom and grid[i + 1][j] == 0:
                    prmtr += 1
                if j < right and grid[i][j + 1] == 0:
                    prmtr += 1
                if i == 0 or j == 0 or i == bottom or j == right:
                    prmtr += 1

    return prmtr
