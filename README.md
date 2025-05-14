# RPG Game Project

This is a text-based turn-based RPG game project implemented in C++. The goal is to create a multiplayer game that supports online battles, starting with a text-based version and potentially upgrading to a GUI version in the future.

## Project Structure

- **Game.cpp**: Main implementation of the game logic.
- **Character.h**: Defines character attributes and behaviors.
- **DBHelper.cpp**: Code for connecting to and interacting with the database.
- **RPGloginGUI/**: Design and implementation of the game's login interface.
- **build_and_run.sh**: Script to compile and run the project.
- **sql.cpp**: Code for SQL query handling.
- **.gitignore**: Specifies files to be excluded from version control.

## Features

- **Character Creation**: Players can create multiple characters and select different character classes.
- **Turn-based Combat**: A turn-based system for combat.
- **Database Support**: MySQL is used to store character and game data.

## How to Run

1. Clone the project:

   ```bash
   git clone https://github.com/ImSiSi/RPG.git
