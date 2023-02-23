<h1 align="center">
  <br>
  <a href="http://www.github.com/ArthurCrespy"><img src="https://42.fr/wp-content/uploads/2021/05/42-Final-sigle-seul.svg" alt="42" width="200"></a>
  <br><br>
  so_long
  <br>
</h1>

<h3 align="center">And thanks for all the fish!</h3>

<h4 align="center">This project is a very small 2D game. Its purpose is to make you work with textures, sprites, and some other very basic gameplay elements.</a></h4>

<p align="center">
    <a href="https://github.com/ArthurCrespy/so_long/search?l=c"> <img alt="Language: C" src="https://img.shields.io/badge/language-C-orange"></a>
        <a href="https://github.com/ArthurCrespy/so_long"> <img alt="Lines of code" src="https://img.shields.io/tokei/lines/github/ArthurCrespy/so_long"></a>
    <a href="https://github.com/ArthurCrespy/so_long/commits"> <img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/ArthurCrespy/so_long?color=yellow"></a>
    <a href="https://github.com/ArthurCrespy/so_long/watchers"> <img alt="GitHub watchers" src="https://img.shields.io/github/watchers/ArthurCrespy/so_long?color=ff69b4"></a>
    <a href="https://projects.intra.42.fr/42cursus-so_long/acrespy"> <img alt="Result: NA/100" src="https://img.shields.io/badge/result-NA/100-brightgreen"></a>

</p>

<p align="center">
  <a href="#introduction">Introduction</a> •
  <a href="#how-to-use">How To Use</a> •
  <a href="#description">Description</a> •
  <a href="#about-42-cursus">About 42 Cursus</a> •
  <a href="#you-may-also-like">Related</a> •
  <a href="#license">License</a>
</p>

## Introduction



## How To Use

To clone and run this project, you'll need [Git](https://git-scm.com) and [Clang](https://clang.llvm.org/) installed on your computer. From your command line:

```bash
# Clone this repository via HTTPS
$ git clone https://github.com/ArthurCrespy/so_long
# OR clone this repository via SSH
$ git clone git@github.com:ArthurCrespy/so_long.git

# Go into the repository
$ cd so_long/files

# Run the Makefile
$ make

# Run the program
$ ./so_long [MAP].ber

# Please, use esc or the red cross to quit the game in order to avoid memory leaks :)
```

> **Note**
> The Makefile will compile using ```clang``` with flags ```-Wall -Wextra -Werror``` and will be named ```so_long```. Use the following keys to move the player: ```W``` ```A``` ```S``` ```D``` or ```↑``` ```←``` ```↓``` ```→```

### Makefile

- ```make``` or ```make all``` : Compile the program.
- ```make clean``` : Delete all objects files.
- ```make fclean``` : Delete all objects files and the instances.
- ```make re``` : Delete all files (except sources, of course) and recompile it.

## Description

The map is composed by a rectangle of 1 or more tiles. It must be closed/surrounded by walls. The map must contain at least one exit, one collectible item, and one player. The map must be composed only by the following characters:

| Character | Description |
| :-------: | :---------: |
| ```0``` | Empty space, can be walked on |
| ```1``` | Wall, can't be walked on |
| ```C``` | Collectible item, can be walked on. Collecting it gives one point |
| ```E``` | Exit, can be walked on. Exiting the map with at least one collectible item gives one point |
| ```P``` | Player, can be walked on. The player can't walk through walls or other sprites. The player can walk on collectible items and exit |

### Game

The game is composed by a window with a map, a counter of collected items, and a counter of moves. The game can be closed by using the red cross or the ```ESC``` key. The player can move using the ```WASD``` or the arrow keys. The game ends when the player exits the map with all the collectible items.

### Errors

The program display an error and quit properly in the following cases:

- The map isn't composed by a rectangle of 1 or more tiles.
- The map isn't closed/surrounded by walls.
- The map doesn't contain at least one exit, one collectible item, and one player.
- The map contains a character which isn't ```0```, ```1```, ```C```, ```E```, or ```P```.
- The map contains multiple players.
- The map contains multiple exits.
- The map contains multiple collectible items.
- The map contains an invalid file extension.
- The program receives multiple arguments.
- The program receives no arguments.
- The program can't open the map file.
- The program can't read the map file.
- The program can't close the map file.
- The program can't allocate memory.
- The program receives an invalid argument.

## About 42 Cursus

This project is part of the 2nd Core. The goal is to make a small game using the [minilibx](https://github.com/42Paris/minilibx-linux) library, wich is a simplified version of the [Xlib](https://www.x.org/releases/X11R7.7/doc/libX11/libX11/libX11.html) library.

## You may also like...

- [minitalk](https://github.com/ArthurCrespy/minitalk) - Small data exchange program using UNIX signals.
- [push_swap](https://github.com/ArthurCrespy/push_swap) - Because Swap_push isn’t as natural

## License

For now, all rights are reserved.

---
<p align="center">
    <a href="https://github.com/ArthurCrespy"> <img alt="Made by ArthurCrespy" src="https://img.shields.io/badge/made%20by-ArthurCrespy-blue"></a>
    <a href="https://42.fr"><img alt="42 Website" src="https://img.shields.io/badge/website-42.fr-blue"></a>
    <br>
    Github <a href="https://github.com/ArthurCrespy" target="_blank">@Thur'</a> |
    LinkedIn<a href="https://fr.linkedin.com/in/crespyarthur" target="_blank"> @Arthur Crespy</a> |
    Instagram<a href="https://instagram.com/arthurcrespy" target="_blank"> @crespyarthur</a> 
</p>
