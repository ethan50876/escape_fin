#include "headers/raster.h"

void plot_bitmap_8(UINT8 *base, UINT8 *bitmap, int x, int y, int height) {
  int i;
  UINT8 *loc = base + (y * 80) + (x >> 3);
  for (i = 0; i < height; i++) {
    *loc |= *(bitmap++);
    loc += 80;
  }
}


void plot_bitmap_16(UINT16 *base, UINT16 *bitmap, int x, int y, int height) {
  int i;
  UINT16 *loc = base + (y * 40) + (x >> 4);	
  for (i = 0; i < height; i++) {
    *loc |= *(bitmap++);
    loc += 40;
  }
}

void plot_bitmap_32(UINT32 *base, UINT32 *bitmap, int x, int y, int height) {
  int i;
  UINT32 *loc = base + (y * 20) + (x >> 5);	
  for (i = 0; i < height; i++) {
    *loc |= *(bitmap++);
    loc += 20;
  }
}


void plot_room(UINT32 *base, UINT32 *room) {
  int i;
  for(i = 0; i < 8000; i++)
	*(base + i) = room[i];
 }
