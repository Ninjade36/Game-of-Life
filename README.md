# Game-of-Life
made a mini version of game of life written in C language

# The universe of the Game of Life is an infinite, two-dimensional orthogonal grid of square cells, each of which is in one of two possible states, live or dead (or populated and unpopulated, respectively). Every cell interacts with its eight neighbours, which are the cells that are horizontally, vertically, or diagonally adjacent. At each step in time, the following transitions occur:

Any live cell with fewer than two live neighbours dies, as if by underpopulation.

Any live cell with two or three live neighbours lives on to the next generation.

Any live cell with more than three live neighbours dies, as if by overpopulation.

Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.

# These rules, which compare the behavior of the automaton to real life, can be condensed into the following:


Any live cell with two or three live neighbours survives.

Any dead cell with three live neighbours becomes a live cell.

All other live cells die in the next generation. Similarly, all other dead cells stay dead.

The initial pattern constitutes the seed of the system. The first generation is created by applying the above rules simultaneously to every cell in the seed, live or dead; births and deaths occur simultaneously, and the discrete moment at which this happens is sometimes called a tick.[nb 1] Each generation is a pure function of the preceding one. The rules continue to be applied repeatedly to create further generations.

# there are a lot of patterns that can be played with and displayed on the border of the game i chose 3 patterns to work with: 

1)Loaf pattern

......

..OO..

.O..O.

..O.O.

...O..

......

2)beacon pattern

......

.OO...

.OO...

...OO.

...OO.

......

3)glider pattern

......

...O..

.O.O..

..OO..

......

......


for additional information and wide explination of the game i suggest to read more on this link https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life
