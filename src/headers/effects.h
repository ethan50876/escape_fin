#ifndef EFFECTS_H
#define EFFECTS_H

#include "psg.h"
#include "TYPES.H"


/* Param:  none
*  Return: void
*  Purpose: plays the death sound effect. Does not stop the channel
*  so stop_music() must be called afterwards to disable the channel
*/
void death_sound();

#endif