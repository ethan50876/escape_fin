#ifndef EVENT_H
#define EVENT_H

#include <stdio.h>
#include <osbind.h>
#include "TYPES.H"
#include "model.h"
#include "isr.h"
#include "asm.h"
#include "effects.h"

/* 
Params: unsigned long, a bool pointer - to the game_running flag
Returns: none
Purpose: Calls exit_game on esc key press

*/
void on_esc(unsigned long key_press, bool *game_running);

/* 
Params: a bool pointer, to the game_running flag
Returns: none
Purpose: Stops the game from running

*/
void exit_game(bool *game_running);

/* 
Params: a Player struct, a Room struc, an unsigned long 
Returns: none
Purpose: Provides a switch-case method for the calls of the move_player function from the model.c file.

*/
void player_movement(Player *player, Room *room, unsigned long key_press);

/* 
Params: a Player struct, a Door struct
Return: a bool (typedef int - 0 representing false and 1 representing true)
Purpose: uses the collided() function from model.c to check for collision with a door
and allowing the player to switch the next respective room
*/
bool switch_room(Player *player, Door *door);

/* 
Params: a Player struct, a Door struct
Return: a bool (typedef int - 0 representing false and 1 representing true)
Purpose: Checks if the held_slot item can unlock a locked door
*/
bool unlock_door(Player *player, Door *door);

/* 
Params: a Player struct, a Room struct, an unsigned long
Return: none
Purpose: Allows the player to interact with items and locked doors
*/
void interact(Player *player, Room *room, unsigned long key_press);

/* 
Params: a Room struct, base, an int 
Return: none
Purpose: Moves the projectiles horizontally, flipping directions once it hits a wall boundary
*/
void on_proj_move(Room *room, UINT32 *base, int curr_room);

/*
Params: a Room struct, base, an int 
Return: none
Purpose: Moves the projectiles vertically, flipping directions once it hits a wall boundary
*/
void on_proj_vmove(Room *room, UINT32 *base, int curr_room);

/* 
Params: a Player struct, a Room struct, a bool
Return: none
Purpose: If the player collides with a projectile, the game is stopped
*/
void on_proj_hit(Player *player, Room *room, bool *game_running);

bool has_user_input();

unsigned long get_user_input();


#endif