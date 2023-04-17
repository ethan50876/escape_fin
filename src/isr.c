#include "headers/isr.h" 
#include "headers/render.h"
#include "headers/asm.h"

int MUSIC_TIMER = 0;
bool RENDER_REQUEST = true;



Vector vbl_vector;
Vector ikbd_vector;

volatile UINT8* const isr_control = 0xfffc00;
volatile UINT8* const isr_status = 0xfffc00;
volatile UINT8* const isr_reader = 0xfffc02;
volatile UINT8* const isr_mfp = 0xfffa11;

volatile UINT8* const ascii = 0xFFFE829C;

UINT8 input_buffer[MAX_BUFFER];
unsigned int b_head = 0;
unsigned int b_tail = 0;
int mouse_state = 0;

unsigned long repeated_key;

bool key_repeat = false;



Vector install_vector(int num, Vector vector) {
  Vector* vectp = (Vector *) ((long) num << 2);
  Vector orig;
  long old_ssp = Super(0);

  orig = *vectp;
  *vectp = vector;

  Super(old_ssp);
  return orig;
}


void install_vectors() {
  vbl_vector = install_vector(VBL_ISR, vbl_isr);
  ikbd_vector = install_vector(IKBD_ISR, ikbd_isr);
}

void remove_vectors() {
  install_vector(VBL_ISR, vbl_vector);
  install_vector(IKBD_ISR, ikbd_vector);
}


bool ikbd_waiting() {
  return b_head != b_tail;
}


void write_buffer(UINT8 scancode) {
  if (b_tail == MAX_BUFFER - 1) {
    b_tail = 0;
  }
  input_buffer[b_tail] = scancode;
  b_tail++;
}

unsigned long read_buffer() {
  unsigned long ch;
  long old_ssp = Super(0);

  if (b_head >= MAX_BUFFER - 1) {
    b_head = 0;
  }
  *isr_mfp &= MFB_MASK_OFF;

  ch = input_buffer[b_head];
  ch <<= 16;
  ch += *(ascii + input_buffer[b_head++]);
  repeated_key = ch;

  *isr_mfp |= MFB_MASK_ON; 
  Super(old_ssp);
  return ch;
}

void clear_buff() {
	int i = 0;
	while (i < 256) {
	input_buffer[i] = 0x00;
	i++;
	}
}


UINT8 get_repeated_key() {
  return repeated_key;
}

void vbl_req() {
  MUSIC_TIMER++;
  

  RENDER_REQUEST = true;
  
  
}

void ikbd_req() {
	
	 UINT8 scancode = 0;

    *isr_control = 0x16;

    if (*isr_status & 0x1) {
        scancode = *isr_reader;

        switch (mouse_state) {

            case MOUSE_STATE_0:

                if ((scancode & 0x80) == 0x00) {

                    write_buffer(scancode);
                    key_repeat = true;
		

                } else if ((scancode & 0x80) == 0x80){

                    key_repeat = false;

                }

                break;
				
			default:
			break;
        }

        *isr_mfp &= MFB_MASK_OFF;
    }

    *isr_control = 0x96;

}
