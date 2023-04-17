#ifndef RENDER_H
#define RENDER_H

#include <osbind.h>
#include "raster.h"
#include "bitmaps.h"
#include "rooms.h"
#include "model.h"

/* Game Renders
 *
 * Renders using the plotting functions from raster.c
 *
 * IF the bitmap is not a room nor splash screen, then it can be found in src\bitmaps\bitmaps.h
 * OTHERWISE if it is a room, then it can be found in src\bitmaps\rooms.h
 * OTHERWISE the splash screens can be found in src\bitmaps\ ending in *_sc.c
 *
 * All room/splash screens are 640x400 and are rendered using plot_room(...);
 * The player is rendered in 16x16 and is rendered using plot_bitmap_16(...);
 * All other bitmaps are in 32x32 and are rendered using plot_bitmap)32(...);
 */
 
void render_room1 (UINT32 *base, Model *model);
void render_player(UINT32 *base, Player *player);
void render_key_r1 (UINT32 *base);
void render_door_r1 (UINT32 *base);
void render_map (UINT32 *base);
void render_player_test (UINT32 *base, Player *player);
void render_curr_room (UINT32 *base, Model *model, int curr);
void render_door (UINT32 *base, Door *door);
void render_item (UINT32 *base, Item *item);
void render_heldslot (UINT32 *base, Player *player);
void render_projectiles(UINT32 *base, Room *room);
void render_trapdoor1a(UINT32 *base);
void render_trapdoor1b(UINT32 *base);
void render_trapdoor1c(UINT32 *base);
void render_right_key_room(UINT32 *base);
void render_hallway(UINT32 *base);
void render_crossroads(UINT32 *base);
void render_proj_room2(UINT32 *base);
void render_trapdoor2(UINT32 *base);
void render_end_room(UINT32 *base);
void render_statue(UINT32 *base, int curr_room);




#endif