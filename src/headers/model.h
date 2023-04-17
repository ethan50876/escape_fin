#ifndef MODEL_H
#define MODEL_H

#include <stdio.h>
#include <osbind.h>
#include "TYPES.H"
#include "render.h"




/* Param:  Player Struct, Room struct, Direction struct
*  Return: Void
*  Purpose: uses direction to change the players coordinates on the grid to allow movement. 
*/
void move_player(Player *player, Room *room, Direction direction);

/* Param:  Player struct, int, int
*  Return: Void
*  Purpose: sets players coordinates on the grid 
*/
void set_player(Player *player, int x, int y);

/* Param:  Player struct
*  Return: void
*  Purpose: initializes the player for the first room.
*/
void initialize_player(Player *player);

/* Param:  Model struct
*  Return: void
*  Purpose: initializes the different bitmaps and values in the rooms. 
*/
void initialize_game(Model *model);

/* Param:  Room struct
*  Return: void
*  Purpose: initializes the boundaries and items in each room
*/

/*
ROOM LEGEND
-----------
0	-	start_room
1	-	proj_room1
2	- 	hallway
3	-	crossroads
4	- 	trapdoor1a
5	-	trapdoor1b
6	- 	trapdoor1c
7	-	right_key_room
8	-	proj_room2
9	-	left_key_room
10	-	trapdoor2
11	-	end_room
------------
*/
void initialize_room0(Room *room);
void initialize_room1(Room *room);
void initialize_room2(Room *room);
void initialize_room3(Room *room);
void initialize_room4(Room *room);
void initialize_room5(Room *room);
void initialize_room6(Room *room);
void initialize_room7(Room *room);
void initialize_room8(Room *room);
void initialize_room9(Room *room);
void initialize_room10(Room *room);
void initialize_room11(Room *room);


/* Param:  Model struct
*  Return: void
*  Purpose: initializes the room_array
*/
void initialize_array(Model *model);

/* Param:  Player struct, Room struct, Direction struct
*  Return: a bool (typedef int - 0 representing false and 1 representing true)
*  Purpose: Checks if the player is in the rooms' bounds
*/
bool is_in_bounds(Player *player, Room *room, Direction direction);

/* Param:  Player struct, Bound struct
*  Return: a bool (typedef int - 0 representing false and 1 representing true)
*  Purpose: Checks for collison between the player and the Bound struct
*/
bool collided (Player *player, Bound *bound);

/* Param:  Player struct, Item struct
*  Return: void
*  Purpose: updates the heldslot with the item that was picked up
*/
void update_heldslot (Player *player, Item *item);

#endif
