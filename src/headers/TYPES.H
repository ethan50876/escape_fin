#ifndef TYPES_H
#define TYPES_H

#include "consts.h"

typedef unsigned char UINT8;
typedef unsigned int  UINT16;
typedef unsigned long UINT32;

typedef int bool;
#define true 1
#define false 0

typedef enum {
    left, right, up, down
} Direction;

typedef enum {
    ch_a, ch_b, ch_c
} Channel;

typedef enum {
    saw, saw_inv, saw_period, saw_inv_period,
    triangle, triangle_inv, triangle_period, triangle_inv_period
} Envenlope;


/*
Struct: Note
Fields: int freq - frequency of the note in Hz
		int duration - duration of note in number of VBL requests
*/
typedef struct {
    int freq;
    int duration;
} Note;


/*
Struct: Player
Fields: int x - x-cord of top-left vertex
		int y - y-cord of top-left vertex
		Direction direction - the direction the player is moving in (strictly cardinal direction)
*/
typedef struct{
    int x;				
	int y;
	int heldslot_ID;
    Direction direction;

} Player;

/* 
Struct: Bound
Purpose: Represents a rectangle box as a hitbox/bound for items/doors
Fields: int x1 -  left boundary
		int x2 -  right boundary
		int y1 -  top boundary
		int y2 -  bottom boundary
*/
typedef struct {
    int x1;
	int x2;
    int y1;
	int y2;
} Bound;

/* 
Struct: Door
Fields: Bound door_box - Bound struct representing the boundaries/hitbox of the door
	bool locked - int typedef representing the locked status of the door
*/
typedef struct {
	Bound door_box;
	bool locked;
	int door_ID;
	bool rotate; /*0 for horizontal orientation, 1 for vertical */
} Door;

/*
Struct: Item
Fields: Bound door_box - Bound struct representing the boundaries/hitbox of the door
		bool on_stage - indicating if the item is ON stage or picked up
		int item_ID - the ID corresponding to ID of heldslot and door
*/
typedef struct {
	Bound item_box;
	bool on_stage;
	int item_ID;
} Item;


/*
Struct: Proj
Fields: Direction direction	- enum representing the direction of the projectile's velocity
		Bound proj_box - hitbox of the projectile
*/
typedef struct {
	Direction direction;
	Bound proj_box;
	
}Proj;


/* 
Struct: Room
Fields: Bound left_bound - rectangle of left wall in room
	Bound right_bound - rectangle of right wall in room
	Bound up_bound - rectangle of top wall in room
	Bound down_bound - rectangle of bottom wall in room
	Item item - the possible item struct in a room
	Door door_array[MAX_DOORS] - Door array representing the present doors in a room
	int actual_doors - the count of real doors in a room
	Proj proj_array - the array containing the projectiles (Proj)

*/
typedef struct {
    Bound left_bound; /* each bound has 3 unused fields for checking.  simplify later */
	Bound right_bound;
	Bound up_bound;
	Bound down_bound;
	Item item;       
	Door door_array[MAX_DOORS];
	int actual_doors;
	Proj proj_array[MAX_PROJ]; 
} Room;



/* 
Struct: Model
	Fields: Player player - a Player struct representing the controllable player
	Room room_array[MAX_ROOMS] - a Room array representing the entire collection of rooms in the game
*/
typedef struct { 
    Player player;
	Room room_array[MAX_ROOMS];
	
} Model;


#endif
