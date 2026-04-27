# Gusfood-restaurant

This project is a restaurant game where the player has to make food as fast as possible. 

## Technical details

The game is coded with C++ 17 using Raylib for the graphical interface.

- The MVC (Model View Controler) pattern is used to unlink the model from the view and other future observers.
- Configuration variables (default parameters, size of the window, ect...) are all settable in the top CMakeLists.txt file.
- All parameters and attributes have custom types in order to facilitate maintenability.
- Interfaces of each file are supposed to be crystal clear

## Why is this code bad ?

There are several reasons why this code could be improved :

- No comments
- The view still depends on the model (will be fixed fastly)
- The raylib path set in CMakeLists.txt is my personnal one, it won't work for you
- No version of raylib is described
- The model is implemented for only one player, it is not extensible if we add other players --> SOLID method not applied
-...
  
There must be 1 000 other reasons, don't hesitate to notify me.

## How to compile ?

The code currently does not compile.

However, please install raylib to prepare yourself !

