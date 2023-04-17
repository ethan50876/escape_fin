/**
 * File Name:	escape.c
 * Authors:		Ethan Ai & Harbir Deo
 * Prof:		Paul Pospisil
 * Asg:			GAME
 * Purpose:		Main driver of the game with main function and game_loop()
 * Date:		4/5/2023
 *
 */
#include "headers/escape.h"

#include <osbind.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int curr_room = 0;
const UINT32 buffer[32256]; /*Second Screen for double buffering */
const UINT32 buffer3[32000]; /*3rd buffer*/
bool room_changed = false;
int door_counter;
int actual_counter;
int game_time = 0;
int game_seconds;
bool game_running = true;
bool game_won = false;
unsigned long input;

 
extern int MUSIC_TIMER;

extern bool RENDER_REQUEST;
extern bool key_repeat;
extern unsigned long repeated_key;



void start() {


    UINT16* base;
	long oldSSP;
    oldSSP = Super(0);
    base = get_video_base();
    Super(oldSSP);

	menu((UINT32*)base);

	game_loop();
}


/* MAIN HERE */
int main() {
	
	install_vectors();
    start();
    remove_vectors();
    return 0;
}

void on_switch_room(Model *model) {
	
	
	switch (curr_room) {
		
		case 0: 
	
		if (switch_room(&model->player, &model->room_array[curr_room].door_array[0]) && (model->room_array[curr_room].door_array[0].locked == false)) {
			set_player(&model->player, 320, 336);
			curr_room = 1;
			room_changed = true;
		}
		break;
		
		case 1:
		if ((switch_room(&model->player, &model->room_array[curr_room].door_array[1])) && (model->room_array[curr_room].door_array[1].locked == false)) {
			set_player(&model->player, 288, 64);
			curr_room = 0;
			room_changed = true;
		} else if (switch_room(&model->player, &model->room_array[curr_room].door_array[0]) && (model->room_array[curr_room].door_array[0].locked == false)) {
			set_player(&model->player, 320, 336);
			curr_room = 2;
			room_changed = true;
		}
		break;
		
		case 2:
		if ((switch_room(&model->player, &model->room_array[curr_room].door_array[1])) && (model->room_array[curr_room].door_array[1].locked == false)) {
			set_player(&model->player, 288, 64);
			curr_room = 1;
			room_changed = true;
		} else if (switch_room(&model->player, &model->room_array[curr_room].door_array[0]) && (model->room_array[curr_room].door_array[0].locked == false)) {
			set_player(&model->player, 320, 336);
			curr_room = 3;
			room_changed = true;
		}
		break;
		
		case 3:
		if ((switch_room(&model->player, &model->room_array[curr_room].door_array[0])) && (model->room_array[curr_room].door_array[0].locked == false)) {
			set_player(&model->player, 320, 336);
			curr_room = 10; 
			room_changed = true;
		} else if (switch_room(&model->player, &model->room_array[curr_room].door_array[1]) && (model->room_array[curr_room].door_array[1].locked == false)) {
			set_player(&model->player, 64, 208);
			curr_room = 4;
			room_changed = true;
		} else if (switch_room(&model->player, &model->room_array[curr_room].door_array[2]) && (model->room_array[curr_room].door_array[2].locked == false)) {
			set_player(&model->player, 288, 64);
			curr_room = 2;
			room_changed = true;
		} else if (switch_room(&model->player, &model->room_array[curr_room].door_array[3]) && (model->room_array[curr_room].door_array[3].locked == false)) {
			set_player(&model->player, 576, 208);
			curr_room = 8; 
			room_changed = true;
		}
		break;
		
		
		case 4:
		if ((switch_room(&model->player, &model->room_array[curr_room].door_array[0])) && (model->room_array[curr_room].door_array[0].locked == false)) {
			set_player(&model->player, 288, 64);
			curr_room = 5; 
			room_changed = true;
		} else if (switch_room(&model->player, &model->room_array[curr_room].door_array[1]) && (model->room_array[curr_room].door_array[1].locked == false)) {
			set_player(&model->player, 64, 208);
		
		} else if (switch_room(&model->player, &model->room_array[curr_room].door_array[2]) && (model->room_array[curr_room].door_array[2].locked == false)) {
			set_player(&model->player, 64, 208);
			
		} else if (switch_room(&model->player, &model->room_array[curr_room].door_array[3]) && (model->room_array[curr_room].door_array[3].locked == false)) {
			set_player(&model->player, 576, 208);
			curr_room = 3; 
			room_changed = true;
		
		}
		break;

		case 5:
		if ((switch_room(&model->player, &model->room_array[curr_room].door_array[0])) && (model->room_array[curr_room].door_array[0].locked == false)) {
			set_player(&model->player, 64 , 208);
			curr_room = 4; 
			room_changed = true;
		} else if (switch_room(&model->player, &model->room_array[curr_room].door_array[1]) && (model->room_array[curr_room].door_array[1].locked == false)) {
			set_player(&model->player, 64, 208);
			curr_room = 4;
			room_changed = true;
		
		} else if (switch_room(&model->player, &model->room_array[curr_room].door_array[2]) && (model->room_array[curr_room].door_array[2].locked == false)) {
			set_player(&model->player, 288, 64);
			curr_room = 6; 
			room_changed = true;	
		} else if (switch_room(&model->player, &model->room_array[curr_room].door_array[3]) && (model->room_array[curr_room].door_array[3].locked == false)) {	
			set_player(&model->player, 64, 208);
			curr_room = 4;
			room_changed = true;
		
		}
		break;
		
		case 6:
		if ((switch_room(&model->player, &model->room_array[curr_room].door_array[0])) && (model->room_array[curr_room].door_array[0].locked == false)) {
			set_player(&model->player, 64 , 208);
			curr_room = 4; 
			room_changed = true;
		} else if (switch_room(&model->player, &model->room_array[curr_room].door_array[1]) && (model->room_array[curr_room].door_array[1].locked == false)) {
			set_player(&model->player, 64, 208);
			curr_room = 4;
			room_changed = true;
		
		} else if (switch_room(&model->player, &model->room_array[curr_room].door_array[2]) && (model->room_array[curr_room].door_array[2].locked == false)) {
			set_player(&model->player, 64, 208);
			curr_room = 7; 
			room_changed = true;	
		} 
		break;
		
		case 7:
		if ((switch_room(&model->player, &model->room_array[curr_room].door_array[0])) && (model->room_array[curr_room].door_array[0].locked == false)) {
			set_player(&model->player, 64 , 208);
			curr_room = 4; 
			room_changed = true;
		} 
		break;
		
		case 8:
		if ((switch_room(&model->player, &model->room_array[curr_room].door_array[0])) && (model->room_array[curr_room].door_array[0].locked == false)) {
			set_player(&model->player, 64 , 208);
			curr_room = 3; 
			room_changed = true;
		} else if (switch_room(&model->player, &model->room_array[curr_room].door_array[1]) && (model->room_array[curr_room].door_array[1].locked == false)) {
			set_player(&model->player, 576 , 208);
			curr_room = 9;
			room_changed = true;
		
		}
		break;
		
		case 9:
		if ((switch_room(&model->player, &model->room_array[curr_room].door_array[0])) && (model->room_array[curr_room].door_array[0].locked == false)) {
			set_player(&model->player, 64 , 208);
			curr_room = 8; 
			room_changed = true;
		} 
		break;
		
		
		case 10:
		if ((switch_room(&model->player, &model->room_array[curr_room].door_array[0])) && (model->room_array[curr_room].door_array[0].locked == false)) {
			set_player(&model->player, 320, 336);
			
		} else if (switch_room(&model->player, &model->room_array[curr_room].door_array[1]) && (model->room_array[curr_room].door_array[1].locked == false)) {
			set_player(&model->player, 320, 336);
			
		
		} else if (switch_room(&model->player, &model->room_array[curr_room].door_array[2]) && (model->room_array[curr_room].door_array[2].locked == false)) {
			set_player(&model->player, 320, 336);
			curr_room = 11; 
			room_changed = true;	
		} else if (switch_room(&model->player, &model->room_array[curr_room].door_array[3]) && (model->room_array[curr_room].door_array[3].locked == false)) {	
			set_player(&model->player, 320, 64);
			curr_room = 3;
			room_changed = true;
		
		}
		break;
		
		case 11:
		if ((switch_room(&model->player, &model->room_array[curr_room].door_array[0])) && (model->room_array[curr_room].door_array[0].locked == false)) {
			set_player(&model->player, 320 , 64);
			curr_room = 10; 
			room_changed = true;
		} 
		break;
		
		
		default:
		break;
	}
	
}
	

void async_events(Model *model, UINT32 *base) {
		
	unsigned long input;
		
	
	if(has_user_input() == true || key_repeat == true) {

		if (has_user_input() == true) {
			input = get_user_input();
		
		} else {
			input = repeated_key;
		}
		
		on_esc(input, &game_running);
		player_movement(&model->player, &model->room_array[curr_room], input);
		interact(&model->player, &model->room_array[curr_room], input);
		on_switch_room(model);
	
	}
	
	


			
}

void sync_events(Model *model, UINT32 *base) {
	
	on_proj_vmove(&model->room_array[curr_room], base, curr_room);
	on_proj_move(&model->room_array[curr_room], base, curr_room);
	on_proj_hit(&model->player, &model->room_array[curr_room], &game_running);
}

UINT8 *get_screen1(UINT8 *buffer) {
	UINT8 *screen1;
	UINT16 difference;
	screen1 = buffer;
	difference = (int) screen1;
	difference %= 0x100;
	difference = 0x100 - difference;
	return screen1 + difference;
}


void game_loop() {

	
	long oldSSP;

	bool swap_buffer = false;
	Model model;
	UINT32 *screen1;
	UINT32 *screen2;
	UINT32 *screen3;
	UINT32 *curr_screen;
	
	
	oldSSP = Super(0);
	screen1 = (UINT32*) get_video_base();
	Super(oldSSP);
	
	screen2 = (UINT32*) get_screen1((UINT8*)buffer);
	
	screen3 = (UINT32*) get_screen1((UINT8*)buffer3);
	
	
	curr_screen = screen1;
	
	
	
	initialize_game(&model);
	start_music();
	
	render_curr_room(screen3, &model, curr_room);
	memcpy((void*) curr_screen, screen3, 32000);


	while(game_running == true) {

	if(update_music(MUSIC_TIMER)) {
		
		MUSIC_TIMER = 0;
	}

	if (RENDER_REQUEST == true) {
		
		if (room_changed == true) {
			render_curr_room(screen3, &model, curr_room);

			room_changed = false;
		}

		if (swap_buffer == true){
			curr_screen = screen1;
		} else {
			curr_screen = screen2;						
		}
				
		
		sync_events(&model, curr_screen);
		async_events(&model, curr_screen);
								

		memcpy((void*) curr_screen, screen3, 32000);
		render_player(curr_screen, &model.player);	
		door_counter = 0;
		actual_counter = model.room_array[curr_room].actual_doors;
		while (door_counter < actual_counter) {
			if (model.room_array[curr_room].door_array[door_counter].locked == true) {
				render_door(curr_screen, &model.room_array[curr_room].door_array[door_counter]);
				if(model.room_array[3].door_array[0].locked == true && curr_room == 3) {
					plot_bitmap_32(curr_screen, horz_door, 320, 0, 32);
				}
				if(model.room_array[3].door_array[3].locked == true && curr_room == 3) {
					plot_bitmap_32(curr_screen, vert_door, 0, 192, 32);
				}
			}
			door_counter ++;
		} 
		if (model.room_array[curr_room].item.on_stage == true) {
			render_item(curr_screen, &model.room_array[curr_room].item);
		}
		render_statue (curr_screen, curr_room);
				
		render_heldslot(curr_screen, &model.player);
		if (model.player.heldslot_ID == 4) {
			game_won = true;
			game_running = false;
		}
		render_projectiles(curr_screen, &model.room_array[curr_room]);
	
		oldSSP = Super(0);
		set_video_base((UINT16*)curr_screen);
		Super(oldSSP); 
			
		RENDER_REQUEST = false;
		swap_buffer = !swap_buffer;			
			
	}
			
	oldSSP = Super(0);
	set_video_base((UINT16*)curr_screen);
	Super(oldSSP);
	

	}
	
	stop_music(ch_c);
	if (game_won == false) {		
		plot_room(curr_screen, fail_sc);
		stop_music(ch_b);

		input = get_user_input();
		
		clear_buff();
		while(input != ENTER_KEY) {
			input = get_user_input();
		}
		curr_room = 0;
		initialize_game(&model);
		game_running = true;
		
		menu(curr_screen);
	
	} else if (game_won == true) {
		exit(1);
	}
		
	
	
	
}





