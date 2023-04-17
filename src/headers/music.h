#ifndef MUSIC_H
#define MUSIC_H

#include "psg.h"
#include "types.h"




/*
 * Initializes the channels and volumes of the song
 */
void start_music();

/*
 * Params:  time_elapsed - time elapsed from last update_music(...)
 *	
 * Purpose: updates the song to the next note
 */
bool update_music(UINT32 time_elapsed);

/* 
 *Params: 	ch	-  the channel to be muted
 *
 *Purpose:	stops the music by muting the passed channel
 */
void stop_music(Channel ch);

#endif