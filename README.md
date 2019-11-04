# SDL-Pong
Classic Pong game using SDL2 and OO design

This is an OO re-creation of the classic computer game Pong.
Contains classes:

1.) Paddle
2.) Ball
3.) Player
4.) Screen
5.) GameManager

Each has a single function.

Paddle handles creation and movement of the paddles (2).

Ball handles creation and movement of the ball (1).

Player handles the score of each player.

Screen handles creation, destruction, updating and closing. The only setPixel method is in this class.

The GameManager class brings this all together handling collision events of other objects aswell as updating the score
and showing pre-launch instructions.

This keeps main() free of clutter and includes.


/*
 * TODO:
 * 	- Win conditions
 * 	- Scale all sizes to the screen dimensions
 * 	- Inputs for difficulty, length of game etc.
 * 	- Pause function
 * 	- Look at inheritance! (maybe Paddle and Ball can extend Screen) or using arrays to pass around key object data
 * 	- Look at encapsulation and removing standard namespace dependency
 * 	- Game managers
 * 	- Fix bugs with weird paddle collisions
 */
