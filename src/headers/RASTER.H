#ifndef RASTER_H
#define RASTER_H

#include "types.h"



/* Param:  base, a bitmap, int - x cord, int - y cord, int - height
*  Return: void
*  Purpose: plots the passed bitmap to the base at the (x,y) cord at a height of 8
*/
void plot_bitmap_8(UINT8 *base, UINT8 *bitmap, int x, int y, int height);

/* Param:  base, a bitmap, int - x cord, int - y cord, int - height
*  Return: void
*  Purpose: plots the passed bitmap to the base at the (x,y) cord at a height of 16
*/
void plot_bitmap_16(UINT16 *base, UINT16 *bitmap, int x, int y, int height);

/* Param:  base, a bitmap, int - x cord, int - y cord, int - height
*  Return: void
*  Purpose: plots the passed bitmap to the base at the (x,y) cord at a height of 32
*/
void plot_bitmap_32(UINT32 *base, UINT32 *bitmap, int x, int y, int height);

/* Param:  base, a bitmap
*  Return: void
*  Purpose: plots the passed bitmap to the entire screen 
*  			-	the bitmap is assumed to be 640x400
*/
void plot_room(UINT32 *base, UINT32 *room);


#endif
