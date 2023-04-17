#include "headers/effects.h"

void death_sound() {

   
    set_noise(120);
    
    enable_channel(ch_b, false, true);

    set_volume(ch_b, 15);

    set_envelope(triangle_inv_period, 50);
    
}