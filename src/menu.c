#include "headers/menu.h"
#include "headers/render.h"
int choice = 0 	;


void menu(UINT32* base) {

    process_menu(base);
}

void process_menu(UINT32* base) {


    unsigned long input;
	plot_room(base, start_sc);
	
    input = get_user_input();
	clear_buff();
	while(input != ENTER_KEY) {
		input = get_user_input();
	}
	plot_room(base, cont_sc);
	
	input = get_user_input();
	clear_buff();
	
	while(input != ENTER_KEY) {
		input = get_user_input();
	}
	game_loop();
	
}


	


