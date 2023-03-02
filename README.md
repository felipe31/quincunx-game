## Quincunx Game ![GitHub](https://img.shields.io/github/license/Felipe31/quincunx-game?style=flat-square)

This game was made using SFML. It was an interview challenge and also a way for me to learn about SFML.

![App execution gif](./quincunx-game.gif?raw=true)

### Running the game

You will need to have G++ and SFML (2.5.1 or newer) installed. SFML can be downloaded [here](https://www.sfml-dev.org/download.php).

For macs:

```sh
brew install sfml
```

To build and run the game, go to the project's folder and run:

```Makefile
 make run
```

A binary file is also provided in the `bin` folder.

### Possible improvements

I believe the game's collision detection is where there is more room to improve. Whenever the balls collide with any white dot, it randomly chooses which side to go to, but if the ball touches the dot again in the next couple of frames, it can choose to go to the other side.
That is what makes the ball bounce over that white dot.
