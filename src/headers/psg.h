#ifndef PSG_H
#define PSG_H

#include <osbind.h>
#include "types.h"


/*retrieved from*/

#define CH_A_TONE 0x0
#define CH_B_TONE 0x2
#define CH_C_TONE 0x4

#define CH_A_ROUGH_TONE 0x1
#define CH_B_ROUGH_TONE 0x3
#define CH_C_ROUGH_TONE 0x5

#define CH_A_VOL 0x8
#define CH_B_VOL 0x9
#define CH_C_VOL 0xa


#define MIXER_ALL_OFF 0xff
#define MIXER_TONE_CH_A 0x3e
#define MIXER_TONE_CH_B 0x3d
#define MIXER_TONE_CH_C 0x3b
#define MIXER_NOISE_CH_A 0x37
#define MIXER_NOISE_CH_B 0x2f
#define MIXER_NOISE_CH_C 0x1f

#define NOISE_FREQUENCY_REG 0x6
#define MIXER_REG 0x7

#define ENVELOPE_FINE_REG 0xb
#define ENVELOPE_ROUGH_REG 0xc
#define ENVELOPE_SHAPE_CONTROL_REG 0xd

#define ENV_SAW_SHAPE 0xc
#define ENV_SAW_SHAPE_INV 0x8
#define ENV_SAW_PERIOD_SHAPE  0xf
#define ENV_TRIANGLE_SHAPE 0xe
#define ENV_TRIANGLE_INV_SHAPE 0xa
#define ENV_TRIANGLE_PERIOD_SHAPE  0xd
#define ENV_TRIANGLE_INV_PERIOD_SHAPE 0x00


#define reg_is_valid(reg) (reg >= 0 && reg <= 15)

extern volatile char* psg_reg_select = 0xFF8800;
extern volatile char* psg_reg_write  = 0xFF8802;


void write_psg(int reg, UINT8 val);

int read_psg(int reg);

/*
	Plays the notes at tuning Hz on the passed channel
*/
void set_tone(Channel channel, int tuning);

void set_noise(int tuning);

void set_envelope(Envenlope shape, UINT16 sustain);


/*
	Sets the volume at the passed channel
*/
void set_volume(Channel channel, int vol);

/*
	enables a channel to play sound
*/
void enable_channel(Channel channel, bool tone_on, bool noise_on);

void enable_channel_(int channel, bool tone_on, bool noise_on);

void stop_sound();

#endif 