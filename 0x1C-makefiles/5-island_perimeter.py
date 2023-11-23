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

    for i in range(len(grid)):
        for j in range(len(grid[i])):
            if grid[i][j] == 1:
                if i > 0 and grid[i - 1][j] == 0:
                    prmtr += 1
                if j > 0 and grid[i][j - 1] == 0:
                    prmtr += 1
                if i < len(grid) - 1 and grid[i + 1][j] == 0:
                    prmtr += 1
                if j < len(grid[i]) - 1 and grid[i][j + 1] == 0:
                    prmtr += 1

    return prmtr
