#ifndef	ASM_H
#define	ASM_H
#include "types.h"

void ikbd_isr();
void vbl_isr();

/*
	Physbase() replacements
*/
UINT16* get_video_base();
void set_video_base(UINT16 *base);

#endif