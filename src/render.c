#include "headers/render.h"
#include "headers/rooms.h"





void render_map (UINT32 *base) {
	
	plot_room(base, start_room);
	
}


void render_proj_room (UINT32 *base) {
	
	plot_room(base, proj_room1);

	
}

void render_hallway(UINT32 *base) {
	
	plot_room(base, hallway);
}

void render_crossroads(UINT32 *base) {
	plot_room(base, crossroads);
}

void render_trapdoor1a(UINT32 *base) {
	plot_room(base, trapdoor1a);
}

void render_trapdoor1b(UINT32 *base) {
	plot_room(base, trapdoor1b);
}

void render_trapdoor1c(UINT32 *base) {
	plot_room(base, trapdoor1c);
}

void render_right_key_room(UINT32 *base) {
	plot_room(base, right_key_room);
}
void render_proj_room2(UINT32 *base) {
	plot_room(base, proj_room2);
}

void render_left_key_room(UINT32 *base) {
	plot_room(base, left_key_room);
}


void render_trapdoor2(UINT32 *base) {
	plot_room(base, trapdoor2);
}

void render_end_room(UINT32 *base) {
	plot_room(base, end_room);
}

void render_player(UINT32 *base, Player *player) {

	plot_bitmap_16((UINT16*) base, player16x16, player->x, player->y, 16);

}

void render_key_r0 (UINT32 *base) {

	plot_bitmap_32(base, key_demo, 352, 320, 32);
	
}



void render_door (UINT32 *base, Door *door) {
	
	if (door->rotate == 0) {
		plot_bitmap_32(base, horz_door, door->door_box.x1, door->door_box.y1, 32);
	} else {
		plot_bitmap_32(base, vert_door, door->door_box.x1, door->door_box.y1, 32);
	}
}

void render_item (UINT32 *base, Item *item) {
	
	int ID = item->item_ID;
	switch (ID) {
		
	case 0 : 
	/* ID == 0 is the ID representing NO item */
	break;
	case 1:	
	plot_bitmap_32(base, key_demo, item->item_box.x1, item->item_box.y1, 32);
	break;
	
	case 2:	
	plot_bitmap_32(base, key_demo, item->item_box.x1, item->item_box.y1, 32);
	break;
	
	case 3:	
	plot_bitmap_32(base, key_demo, item->item_box.x1, item->item_box.y1, 32);
	break;
	 
	case 4:
	plot_bitmap_32(base, trophey, item->item_box.x1, item->item_box.y1, 32);
	break;
	
	default:
	break;
	
	}
}

void render_statue (UINT32 *base, int curr_room) {
	
	switch (curr_room) {
	
	/* statues only need to be rendered in rooms 4-6 */
	case 4:	
	plot_bitmap_32(base, star, 560, 48, 32);
	break;	
	
	case 5:
	plot_bitmap_32(base, sword, 560, 48, 32);
	break;
	
	case 6:
	plot_bitmap_32(base, shield, 560, 48, 32);
	break;

	default:
	break;
	}
	
}


void render_heldslot (UINT32 *base, Player *player) {
	
	int ID = player->heldslot_ID;
	switch (ID) {
		
	case 0 : 
	plot_bitmap_32(base, heldslot, 580, 300, 32);
	
	break;
	case 1:	
	plot_bitmap_32(base, key_heldslot, 580, 300, 32);
	break;
	
	case 2:	
	plot_bitmap_32(base, key_heldslot, 580, 300, 32);
	break;
	
	case 3:	
	plot_bitmap_32(base, key_heldslot, 580, 300, 32);
	break;
	
	case 4:
	/*ID == 4 is representative of the trophey, but there is no need to 
	render anything as the game is ending */
	break;
	
	default:
	plot_bitmap_32(base, heldslot, 580, 300, 32);
	break;
	
	}
}

void render_held_r0 (UINT32 *base) {
	
	plot_bitmap_32(base, heldslot, 580, 300, 32);
	
}
void render_player_test (UINT32 *base, Player *player) {

	plot_bitmap_16((UINT16*)base, player16x16, 320, 336, 16);

}

void render_room0 (UINT32 *base, Model *model) {
	
	render_map(base);

	
	
}
void render_projectiles(UINT32 *base, Room *room) {
	

	plot_bitmap_32(base, projectile, room->proj_array[0].proj_box.x1, room->proj_array[0].proj_box.y1, 32);
	plot_bitmap_32(base, projectile, room->proj_array[1].proj_box.x1, room->proj_array[1].proj_box.y1, 32);
	plot_bitmap_32(base, projectile, room->proj_array[2].proj_box.x1, room->proj_array[2].proj_box.y1, 32);
	plot_bitmap_32(base, projectile, room->proj_array[3].proj_box.x1, room->proj_array[3].proj_box.y1, 32);
	plot_bitmap_32(base, projectile, room->proj_array[4].proj_box.x1, room->proj_array[4].proj_box.y1, 32);
	

}

void render_curr_room (UINT32 *base, Model *model, int curr) {
	
	/*curr is current room the player is in */
	switch (curr) {
		
		case 0: 
		render_room0(base, model);		
		break;
		
		case 1: 
		render_proj_room(base);
		break;
		
		case 2:
		render_hallway(base);
		break;
		
		case 3:
		render_crossroads(base);
		break;
		
		case 4:
		render_trapdoor1a(base);
		break;
		
		case 5:
		render_trapdoor1b(base);
		break;
		
		case 6:
		render_trapdoor1c(base);
		break;
		
		case 7:
		render_right_key_room(base);
		break;
		
		case 8:
		render_proj_room2(base);
		break;
		
		case 9:
		render_left_key_room(base);
		break;
		
		case 10:
		render_trapdoor2(base);
		break;
		
		case 11:
		render_end_room(base);
		break;
		
		
		default:
		break;
	}
	


	
}