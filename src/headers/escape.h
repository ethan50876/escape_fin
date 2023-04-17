#ifndef ESCAPE_H
#define ESCAPE_H

#include <stdio.h>
#include <osbind.h>
#include "TYPES.H"
#include "event.h"
#include "isr.h"
#include "asm.h"
#include "menu.h"
#include "render.h"
#include "music.h"


/* 
Params: Model struct
Returns: none
Purpose: switch case to handle room switching

*/
void on_switch_room(Model *model);

/* 
Params: Model struct, base
Returns: none
Purpose: handles asynchronous events

*/
void async_events(Model* model, UINT32* base);

/* 
Params: Model struct, base
Returns: none
Purpose: handles synchronous events

*/
void sync_events(Model *model, UINT32 *base);

/* 
Purpose: Main game loop
*/
void game_loop();

/* 
Params: buffer
Returns: unsigned char
Purpose: returns the base of the passed buffer

*/
UINT8 *get_base(UINT8 *buffer);


#endif