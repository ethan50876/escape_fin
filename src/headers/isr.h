#ifndef ISR_H
#define ISR_H
#include "types.h"


#define VBL_ISR 28
#define IKBD_ISR 70

#define IKBD_DEFAULT 0xfffc96
#define IKBD_INTERRUPT_OFF 0xfffc16

#define MFB_MASK_ON 0x40
#define MFB_MASK_OFF 0xbf

#define MOUSE_STATE_0 0
#define MOUSE_STATE_1 1
#define MOUSE_STATE_2 2

#define MOUSE_MOVE_CODE 0xf8
#define MOUSE_LEFT_BUTTON_CODE 0xfa

#define MAX_BUFFER 256

typedef void (*Vector) ();

/*
 * Timers, used by VBL
 *	MUSIC_TIMER 	- the timer that updates the music array
 */
extern int MUSIC_TIMER;



/*
 * Requests, used by escape.c
 * RENDER_REQUEST	- the flag that is responsible for asynchronous rendering
 */
extern bool RENDER_REQUEST;



extern UINT8 mouse_button;


extern bool key_repeat;
extern bool mouse_moved;


/* 
 * ikbd buffer declarations
 */
extern UINT8 input_buffer[MAX_BUFFER];
extern unsigned int b_head;
extern unsigned int b_tail;
extern unsigned long repeated_key;

extern Vector vbl_vector;
extern Vector ikbd_vector;


/*
 * vbl_req does following:
 *    - times the rendering on the current screen;
 *    - times the music music;
 */
void vbl_req();

/*
 * Processes keyboard and mouse inputs :
 *    - handles keyboard scancodes
 *    - handles incoming mouse packets
 */
void ikbd_req();


/*
 * 
 *   Called by the install_vectors and remove_vectors functions
 */
Vector install_vector(int num, Vector vector);

/*
 * Installs vector vbl and ikbd vectors
 */
void install_vectors();

/*
 * Removes vectors
 */
void remove_vectors();


/*
 * Returns true if keyboard is waiting for input
 *	else false
 */
bool ikbd_waiting();


/*
 * Clears the entire keyboard buffer - no exceptions
 */
void clear_buff();

/*
 * Write keyboard value to keyboard buffer.
 * 
 * Params:scancode - code representing the keyboard value
 */
void write_buffer(UINT8 scancode);

/*
 * Read keyboard value from keyboard buffer
 * 
 * Returns: keyboard scancode
 */
unsigned long read_buffer();

#endif 