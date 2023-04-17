#include "headers/event.h"




void exit_game(bool *game_running) {
	(*game_running) = false;
	
}

void on_esc(unsigned long key_press, bool *game_running){
	switch (key_press) {
		case ESC_KEY:
		exit_game(game_running);
		break;
		
		default:
		break;
	}
}

void player_movement(Player *player, Room *room, unsigned long key_press) {
	switch (key_press) {
		
        case LEFT_KEY:
        move_player(player, room, left);
		break;
        case RIGHT_KEY:
        move_player(player, room, right);
		break;
        case UP_KEY:
        move_player(player, room, up);
		break;
        case DOWN_KEY:
        move_player(player, room, down);
		break;
        default:
        break;
    }
	
}

bool switch_room(Player *player, Door *door) {
	
	if ((collided(player, &door->door_box) == true)) {
		return true;
	} else {
		return false;
	}
	

		
}

void on_proj_hit(Player *player, Room *room, bool *game_running) {
	
	int counter = 0;
	
	while (counter < MAX_PROJ) {
		if(collided(player, &room->proj_array[counter].proj_box) == true) {
			death_sound();
			exit_game(game_running);
		}
		counter ++;
	}

}

bool unlock_door(Player *player, Door *door) {
	
	if (player->heldslot_ID == door->door_ID) {
		return true;
	} else {
		return false;
	}
}

void interact(Player *player, Room *room, unsigned long key_press) {
	switch (key_press) {
		
		case SPACE_KEY:
		if ((room->item.on_stage == true) && (collided(player, &room->item.item_box))) {
			room->item.on_stage = false; 
			update_heldslot(player, &room->item);	
		} else {
			int counter = 0;
			while (counter < (room->actual_doors)) {
				if ((room->door_array[counter].locked == true) && (collided(player, &room->door_array[counter].door_box) == true) 
					&& (unlock_door(player, &room->door_array[counter]) == true) ) {		
					room->door_array[counter].locked = false;
					player->heldslot_ID = 0;
				}
				counter ++;
			}
		}
		
		break;
		default:
		break;
	}
	
}

void on_proj_move(Room *room, UINT32 *base, int curr_room){
	if (curr_room == 1) {
		int counter = 0;
		while (counter < MAX_PROJ) {
			if(room->proj_array[counter].direction == left){
				if (room->proj_array[counter].proj_box.x1 <= room->left_bound.x2) {
					room->proj_array[counter].direction = right;
					room->proj_array[counter].proj_box.x1 += GRID_VALUE;	
					room->proj_array[counter].proj_box.x2 += GRID_VALUE;					
				} else {
					room->proj_array[counter].proj_box.x1 -= GRID_VALUE;
					room->proj_array[counter].proj_box.x2 -= GRID_VALUE;
				}
			} else if (room->proj_array[counter].direction == right){
					if (room->proj_array[counter].proj_box.x2 >= room->right_bound.x1) {
						room->proj_array[counter].direction = left;
						room->proj_array[counter].proj_box.x2 -= GRID_VALUE;
						room->proj_array[counter].proj_box.x1 -= GRID_VALUE;
					} else {
						room->proj_array[counter].proj_box.x2 += GRID_VALUE;
						room->proj_array[counter].proj_box.x1 += GRID_VALUE;
					}
				
			}
		counter ++;
		}
	}
	
}

void on_proj_vmove(Room *room, UINT32 *base, int curr_room){
	if (curr_room == 8) {
		int counter = 0;
		while (counter < MAX_PROJ) {
			if(room->proj_array[counter].direction == up){
				if (room->proj_array[counter].proj_box.y1 <= room->up_bound.y2) {
					room->proj_array[counter].direction = down;
					room->proj_array[counter].proj_box.y1 += GRID_VALUE;	
					room->proj_array[counter].proj_box.y2 += GRID_VALUE;					
				} else {
					room->proj_array[counter].proj_box.y1 -= GRID_VALUE;
					room->proj_array[counter].proj_box.y2 -= GRID_VALUE;
				}
			} else if (room->proj_array[counter].direction == down){
					if (room->proj_array[counter].proj_box.y2 >= room->down_bound.y1) {
						room->proj_array[counter].direction = up;
						room->proj_array[counter].proj_box.y2 -= GRID_VALUE;
						room->proj_array[counter].proj_box.y1 -= GRID_VALUE;
					} else {
						room->proj_array[counter].proj_box.y2 += GRID_VALUE;
						room->proj_array[counter].proj_box.y1 += GRID_VALUE;
					}
				
			}
		counter ++;
		}
	}
	
}

bool has_user_input() {
	
	return ikbd_waiting();
	
}

unsigned long get_user_input() {

	return read_buffer();
	
}
