# The Maze

The Maze is 3D game built using SDL and Raycasting. On the map, the player can move in all four directions using keys ```W```, ```A```, ```S```, and ```D```. 

The player can move through the maze and turn left or right as desired.

If the player hits a wall, they cannot move unless they change their direction.

The player can move on several directions and rotate in the same time.
This project makes use of gcc and make for the compilation process.

### Windows
Ensure you have gcc, and make(Can install using chocolatey). Then run the following command:

```bash 
make
```
### Linux
First make sure SDL is installed. If you haven't install SDL by running ``` make linux_install ```. Then run the following command:

```bash
make linux 
```
to compile.

### Mac
Ensure sdl is installed. Then run the following command:

```bash
make mac
```
## Running
After successfully compiling run the program using following command:

```bash
./maze MAP
```

where ```MAP``` is the name of the file found in the maps folder. You can create other maps and pass them while running program as above. Map files accept only the allowed characters.

## Controls

```W``` - Moving forward

```S``` - Moving backward

```A``` - Look left

```D``` - Look right

```Mouse move left/right``` - look left or right

```M``` - Turn off map visibility. The 2D map won't be visible on clicking

```N``` - Turn on map visibility. The 2D map will be visible again if it wasn't


## Contributing

- Read the source files in ```src``` folder and the header files in ```inc``` folder.
- Add a feature, fix a bug, or refactor some code :)
- Write/update tests for the changes you made, if necessary.
- Update README.md if necessary.
- Open a Pull Request with a comprehensive description of changes.

## Related

*[The Maze](https://alx-intranet.hbtn.io/concepts/133)* - Holberton Project Page

## License
**BSD**


# Authors

Mahmoud Tarek <mahmoud_ta_rek@outlook.com>

