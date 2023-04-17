#include "headers/model.h"


void move_player(Player *player, Room *room, Direction direction) {
	switch (direction) {
		case left:
		if (is_in_bounds(player, room, direction))
			player->x -= GRID_VALUE;
			
		break;
		case right:
		if (is_in_bounds(player, room, direction))
			player->x += GRID_VALUE;
		break;
		case up:
		if (is_in_bounds(player, room, direction))
			player->y -= GRID_VALUE;
		break;
		case down:
		if (is_in_bounds(player, room, direction))
			player->y += GRID_VALUE;
		break;
		default:
		break;
	}

}


void set_player(Player *player, int x, int y) {
	
	player->x = x;
	player->y = y;
	
}

void initialize_player(Player *player) {

	set_player(player, 320, 300);
	player->heldslot_ID = 0;

}


void initialize_game(Model *model){
	
	initialize_array(model);
	initialize_player(&model->player);

	
	
}


void initialize_room0(Room *room) {
	 
	 room->up_bound.x1 = 0;
	 room->up_bound.x2 = 640;
	 room->up_bound.y1 = 0;
	 room->up_bound.y2 = 16;
	 
	 room->right_bound.x1 = 608;
	 room->right_bound.x2 = 640;
	 room->right_bound.y1 = 0;
	 room->right_bound.y2 = 400;
	 
	 room->left_bound.x1 = 0;
	 room->left_bound.x2 = 16;
	 room->left_bound.y1 = 0;
	 room->left_bound.y2 = 400;
	 
	 room->down_bound.x1 = 0;
	 room->down_bound.x2 = 640;
	 room->down_bound.y1 = 352;
	 room->down_bound.y2 = 400;
	 
	 room->door_array[0].locked = true;
	 room->door_array[0].door_ID = 1;
	 room->door_array[0].rotate = 0;
	 room->door_array[0].door_box.x1 = 288;
	 room->door_array[0].door_box.x2 = 320;
	 room->door_array[0].door_box.y1 = 0;
	 room->door_array[0].door_box.y2 = 32;
	 room->actual_doors = 1;
	 
	 room->item.on_stage = true;
	 room->item.item_ID = 1;
	 room->item.item_box.x1 = 352;
	 room->item.item_box.x2 = 384;
	 room->item.item_box.y1 = 320;
	 room->item.item_box.y2 = 352;
	 


}
void initialize_room1(Room *room) {
	 
	 room->up_bound.x1 = 0;
	 room->up_bound.x2 = 640;
	 room->up_bound.y1 = 0;
	 room->up_bound.y2 = 16;
	 
	 room->right_bound.x1 = 608;
	 room->right_bound.x2 = 640;
	 room->right_bound.y1 = 0;
	 room->right_bound.y2 = 400;
	 
	 room->left_bound.x1 = 0;
	 room->left_bound.x2 = 16;
	 room->left_bound.y1 = 0;
	 room->left_bound.y2 = 400;
	 
	 room->down_bound.x1 = 0;
	 room->down_bound.x2 = 640;
	 room->down_bound.y1 = 368;
	 room->down_bound.y2 = 400;
	 
	 room->door_array[0].locked = false;
	 room->door_array[0].door_box.x1 = 304;
	 room->door_array[0].door_box.x2 = 336;
	 room->door_array[0].door_box.y1 = 0;
	 room->door_array[0].door_box.y2 = 32; 
	 
	 room->door_array[1].locked = false;
	 room->door_array[1].door_box.x1 = 304;
	 room->door_array[1].door_box.x2 = 336;
	 room->door_array[1].door_box.y1 = 368;
	 room->door_array[1].door_box.y2 = 400;
	 
	 room->proj_array[0].direction = left;
	 room->proj_array[0].proj_box.x1 = 576;
	 room->proj_array[0].proj_box.x2 = 608; 
	 room->proj_array[0].proj_box.y1 = 296;
	 room->proj_array[0].proj_box.y2 = 328; 
	 
	 room->proj_array[1].direction = right;
	 room->proj_array[1].proj_box.x1 = 64;
	 room->proj_array[1].proj_box.x2 = 96; 
	 room->proj_array[1].proj_box.y1 = 264;
	 room->proj_array[1].proj_box.y2 = 296; 
	 
	 room->proj_array[2].direction = left;
	 room->proj_array[2].proj_box.x1 = 576;
	 room->proj_array[2].proj_box.x2 = 608; 
	 room->proj_array[2].proj_box.y1 = 200;
	 room->proj_array[2].proj_box.y2 = 232; 
	 
	 room->proj_array[3].direction = right;
	 room->proj_array[3].proj_box.x1 = 64;
	 room->proj_array[3].proj_box.x2 = 96; 
	 room->proj_array[3].proj_box.y1 = 136;
	 room->proj_array[3].proj_box.y2 = 168; 
	 
	 room->proj_array[4].direction = left;
	 room->proj_array[4].proj_box.x1 = 576;
	 room->proj_array[4].proj_box.x2 = 608; 
	 room->proj_array[4].proj_box.y1 = 104;
	 room->proj_array[4].proj_box.y2 = 136; 
	 
	 
	 
}


void initialize_room2(Room *room) {
	 
	 room->up_bound.x1 = 0;
	 room->up_bound.x2 = 640;
	 room->up_bound.y1 = 0;
	 room->up_bound.y2 = 16;
	 
	 room->right_bound.x1 = 400;
	 room->right_bound.x2 = 640;
	 room->right_bound.y1 = 0;
	 room->right_bound.y2 = 400;
	 
	 room->left_bound.x1 = 0;
	 room->left_bound.x2 = 224;
	 room->left_bound.y1 = 0;
	 room->left_bound.y2 = 400;
	 
	 room->down_bound.x1 = 0;
	 room->down_bound.x2 = 640;
	 room->down_bound.y1 = 368;
	 room->down_bound.y2 = 400;
	 
	 room->door_array[0].locked = false;
	 room->door_array[0].door_box.x1 = 288;
	 room->door_array[0].door_box.x2 = 320;
	 room->door_array[0].door_box.y1 = 0;
	 room->door_array[0].door_box.y2 = 32; 
	 
	 room->door_array[1].locked = false;
	 room->door_array[1].door_box.x1 = 288;
	 room->door_array[1].door_box.x2 = 320;
	 room->door_array[1].door_box.y1 = 368;
	 room->door_array[1].door_box.y2 = 400;
	 

	 
	 
}

void initialize_room3(Room *room) {
	 
	 room->up_bound.x1 = 0;
	 room->up_bound.x2 = 640;
	 room->up_bound.y1 = 0;
	 room->up_bound.y2 = 16;
	 
	 room->right_bound.x1 = 608;
	 room->right_bound.x2 = 640;
	 room->right_bound.y1 = 0;
	 room->right_bound.y2 = 400;
	 
	 room->left_bound.x1 = 0;
	 room->left_bound.x2 = 16;
	 room->left_bound.y1 = 0;
	 room->left_bound.y2 = 400;
	 
	 room->down_bound.x1 = 0;
	 room->down_bound.x2 = 640;
	 room->down_bound.y1 = 368;
	 room->down_bound.y2 = 400;
	 
	 room->door_array[0].locked = true;
	 room->door_array[0].door_box.x1 = 304;
	 room->door_array[0].door_box.x2 = 336;
	 room->door_array[0].door_box.y1 = 0;
	 room->door_array[0].door_box.y2 = 36; 
	 room->door_array[0].door_ID = 3;

	 
	  
	 room->door_array[1].locked = false;
	 room->door_array[1].door_box.x1 = 608;
	 room->door_array[1].door_box.x2 = 640;
	 room->door_array[1].door_box.y1 = 184;
	 room->door_array[1].door_box.y2 = 216; 
	 
	 room->door_array[2].locked = false;
	 room->door_array[2].door_box.x1 = 304;
	 room->door_array[2].door_box.x2 = 336;
	 room->door_array[2].door_box.y1 = 368;
	 room->door_array[2].door_box.y2 = 400;
	 
	 room->door_array[3].locked = true;
	 room->door_array[3].rotate = true;
	 room->door_array[3].door_ID = 2;
	 room->door_array[3].door_box.x1 = 0;
	 room->door_array[3].door_box.x2 = 32;
	 room->door_array[3].door_box.y1 = 184;
	 room->door_array[3].door_box.y2 = 216; 

	room->actual_doors = 4;
	 
}

void initialize_room4(Room *room) {
	 
	 room->up_bound.x1 = 0;
	 room->up_bound.x2 = 640;
	 room->up_bound.y1 = 0;
	 room->up_bound.y2 = 16;
	 
	 room->right_bound.x1 = 608;
	 room->right_bound.x2 = 640;
	 room->right_bound.y1 = 0;
	 room->right_bound.y2 = 400;
	 
	 room->left_bound.x1 = 0;
	 room->left_bound.x2 = 24;
	 room->left_bound.y1 = 0;
	 room->left_bound.y2 = 400;
	 
	 room->down_bound.x1 = 0;
	 room->down_bound.x2 = 640;
	 room->down_bound.y1 = 368;
	 room->down_bound.y2 = 400;
	 
	  
	 room->door_array[0].locked = false;
	 room->door_array[0].door_box.x1 = 464;
	 room->door_array[0].door_box.x2 = 496;
	 room->door_array[0].door_box.y1 = 368;
	 room->door_array[0].door_box.y2 = 400;
	 
	 room->door_array[1].locked = false;
	 room->door_array[1].door_box.x1 = 304;
	 room->door_array[1].door_box.x2 = 336;
	 room->door_array[1].door_box.y1 = 368;
	 room->door_array[1].door_box.y2 = 400;
	 
	 room->door_array[2].locked = false;
	 room->door_array[2].door_box.x1 = 144;
	 room->door_array[2].door_box.x2 = 176;
	 room->door_array[2].door_box.y1 = 368;
	 room->door_array[2].door_box.y2 = 400; 


	 room->door_array[3].locked = false;
	 room->door_array[3].door_box.x1 = 0;
	 room->door_array[3].door_box.x2 = 48;
	 room->door_array[3].door_box.y1 = 184;
	 room->door_array[3].door_box.y2 = 216; 
	 
	  	 
	 
}


void initialize_room5(Room *room) {
	 
	 room->up_bound.x1 = 0;
	 room->up_bound.x2 = 640;
	 room->up_bound.y1 = 0;
	 room->up_bound.y2 = 16;
	 
	 room->right_bound.x1 = 608;
	 room->right_bound.x2 = 640;
	 room->right_bound.y1 = 0;
	 room->right_bound.y2 = 400;
	 
	 room->left_bound.x1 = 0;
	 room->left_bound.x2 = 16;
	 room->left_bound.y1 = 0;
	 room->left_bound.y2 = 400;
	 
	 room->down_bound.x1 = 0;
	 room->down_bound.x2 = 640;
	 room->down_bound.y1 = 368;
	 room->down_bound.y2 = 400;
	 
	 
	  
	 room->door_array[0].locked = false;
	 room->door_array[0].door_box.x1 = 304;
	 room->door_array[0].door_box.x2 = 336;
	 room->door_array[0].door_box.y1 = 0;
	 room->door_array[0].door_box.y2 = 32;
	 
	 room->door_array[1].locked = false;
	 room->door_array[1].door_box.x1 = 464;
	 room->door_array[1].door_box.x2 = 496;
	 room->door_array[1].door_box.y1 = 368;
	 room->door_array[1].door_box.y2 = 400;
	 
	 room->door_array[2].locked = false;
	 room->door_array[2].door_box.x1 = 304;
	 room->door_array[2].door_box.x2 = 336;
	 room->door_array[2].door_box.y1 = 368;
	 room->door_array[2].door_box.y2 = 400;
	 
	 room->door_array[3].locked = false;
	 room->door_array[3].door_box.x1 = 144;
	 room->door_array[3].door_box.x2 = 176;
	 room->door_array[3].door_box.y1 = 368;
	 room->door_array[3].door_box.y2 = 400;  
	 
	  
	room->actual_doors = 4;
	 
}

void initialize_room6(Room *room) {
	 
	 room->up_bound.x1 = 0;
	 room->up_bound.x2 = 640;
	 room->up_bound.y1 = 0;
	 room->up_bound.y2 = 16;
	 
	 room->right_bound.x1 = 608;
	 room->right_bound.x2 = 640;
	 room->right_bound.y1 = 0;
	 room->right_bound.y2 = 400;
	 
	 room->left_bound.x1 = 0;
	 room->left_bound.x2 = 16;
	 room->left_bound.y1 = 0;
	 room->left_bound.y2 = 400;
	 
	 room->down_bound.x1 = 0;
	 room->down_bound.x2 = 640;
	 room->down_bound.y1 = 368;
	 room->down_bound.y2 = 400;
	 
	  
	 room->door_array[0].locked = false;
	 room->door_array[0].door_box.x1 = 304;
	 room->door_array[0].door_box.x2 = 336;
	 room->door_array[0].door_box.y1 = 0;
	 room->door_array[0].door_box.y2 = 32;
	 
	 room->door_array[1].locked = false;
	 room->door_array[1].door_box.x1 = 608;
	 room->door_array[1].door_box.x2 = 640;
	 room->door_array[1].door_box.y1 = 80;
	 room->door_array[1].door_box.y2 = 112;
	 
	 room->door_array[2].locked = false;
	 room->door_array[2].door_box.x1 = 608;
	 room->door_array[2].door_box.x2 = 640;
	 room->door_array[2].door_box.y1 = 240;
	 room->door_array[2].door_box.y2 = 272;
		   
	room->actual_doors = 3;
	 
}

void initialize_room7(Room *room) {
	 
	 room->up_bound.x1 = 0;
	 room->up_bound.x2 = 640;
	 room->up_bound.y1 = 0;
	 room->up_bound.y2 = 16;
	 
	 room->right_bound.x1 = 608;
	 room->right_bound.x2 = 640;
	 room->right_bound.y1 = 0;
	 room->right_bound.y2 = 400;
	 
	 room->left_bound.x1 = 0;
	 room->left_bound.x2 = 16;
	 room->left_bound.y1 = 0;
	 room->left_bound.y2 = 400;
	 
	 room->down_bound.x1 = 0;
	 room->down_bound.x2 = 640;
	 room->down_bound.y1 = 368;
	 room->down_bound.y2 = 400;
	 
	  
	 room->door_array[0].locked = false;
	 room->door_array[0].door_box.x1 = 0;
	 room->door_array[0].door_box.x2 = 32;
	 room->door_array[0].door_box.y1 = 184;
	 room->door_array[0].door_box.y2 = 216;
	 
	 room->item.on_stage = true;
	 room->item.item_ID = 2;
	 room->item.item_box.x1 = 352;
	 room->item.item_box.x2 = 384;
	 room->item.item_box.y1 = 320;
	 room->item.item_box.y2 = 352;

		   
	room->actual_doors = 1;
	 
}
void initialize_room8(Room *room) {
	 
	 room->up_bound.x1 = 0;
	 room->up_bound.x2 = 640;
	 room->up_bound.y1 = 0;
	 room->up_bound.y2 = 16;
	 
	 room->right_bound.x1 = 608;
	 room->right_bound.x2 = 640;
	 room->right_bound.y1 = 0;
	 room->right_bound.y2 = 400;
	 
	 room->left_bound.x1 = 0;
	 room->left_bound.x2 = 16;
	 room->left_bound.y1 = 0;
	 room->left_bound.y2 = 400;
	 
	 room->down_bound.x1 = 0;
	 room->down_bound.x2 = 640;
	 room->down_bound.y1 = 368;
	 room->down_bound.y2 = 400;
	 
	 room->door_array[0].locked = false;
	 room->door_array[0].door_box.x1 = 608;
	 room->door_array[0].door_box.x2 = 640;
	 room->door_array[0].door_box.y1 = 184;
	 room->door_array[0].door_box.y2 = 216; 
	 
	 room->door_array[1].locked = false;
	 room->door_array[1].door_box.x1 = 0;
	 room->door_array[1].door_box.x2 = 32;
	 room->door_array[1].door_box.y1 = 184;
	 room->door_array[1].door_box.y2 = 216;

	 room->proj_array[0].direction = down;
	 room->proj_array[0].proj_box.x1 = 512;
	 room->proj_array[0].proj_box.x2 = 544; /*608 */
	 room->proj_array[0].proj_box.y1 = 32;
	 room->proj_array[0].proj_box.y2 = 64; /*328 */
	 
	 room->proj_array[1].direction = up;
	 room->proj_array[1].proj_box.x1 = 400;
	 room->proj_array[1].proj_box.x2 = 432; /* 96*/
	 room->proj_array[1].proj_box.y1 = 336;
	 room->proj_array[1].proj_box.y2 = 368; /* 296*/
	 
	 room->proj_array[2].direction = down;
	 room->proj_array[2].proj_box.x1 = 288;
	 room->proj_array[2].proj_box.x2 = 320; /*608 */
	 room->proj_array[2].proj_box.y1 = 32;
	 room->proj_array[2].proj_box.y2 = 64; /*232 */
	 
	 room->proj_array[3].direction = up;
	 room->proj_array[3].proj_box.x1 = 176;
	 room->proj_array[3].proj_box.x2 = 208; /*96*/
	 room->proj_array[3].proj_box.y1 = 136;
	 room->proj_array[3].proj_box.y2 = 168; /*168 */
	 
	
	 room->proj_array[4].proj_box.x1 = 0;
	 room->proj_array[4].proj_box.x2 = 0; 
	 room->proj_array[4].proj_box.y1 = 0;
	 room->proj_array[4].proj_box.y2 = 0; 
	 
	 
}

void initialize_room9(Room *room) {
	 
	 room->up_bound.x1 = 0;
	 room->up_bound.x2 = 640;
	 room->up_bound.y1 = 0;
	 room->up_bound.y2 = 16;
	 
	 room->right_bound.x1 = 608;
	 room->right_bound.x2 = 640;
	 room->right_bound.y1 = 0;
	 room->right_bound.y2 = 400;
	 
	 room->left_bound.x1 = 0;
	 room->left_bound.x2 = 16;
	 room->left_bound.y1 = 0;
	 room->left_bound.y2 = 400;
	 
	 room->down_bound.x1 = 0;
	 room->down_bound.x2 = 640;
	 room->down_bound.y1 = 368;
	 room->down_bound.y2 = 400;
	 
	 room->door_array[0].locked = false;
	 room->door_array[0].door_box.x1 = 608;
	 room->door_array[0].door_box.x2 = 640;
	 room->door_array[0].door_box.y1 = 184;
	 room->door_array[0].door_box.y2 = 216; 
	 
	 room->item.on_stage = true;
	 room->item.item_ID = 3;
	 room->item.item_box.x1 = 352;
	 room->item.item_box.x2 = 384;
	 room->item.item_box.y1 = 320;
	 room->item.item_box.y2 = 352;
	 
}

void initialize_room10(Room *room) {
	 
	 room->up_bound.x1 = 0;
	 room->up_bound.x2 = 640;
	 room->up_bound.y1 = 0;
	 room->up_bound.y2 = 16;
	 
	 room->right_bound.x1 = 608;
	 room->right_bound.x2 = 640;
	 room->right_bound.y1 = 0;
	 room->right_bound.y2 = 400;
	 
	 room->left_bound.x1 = 0;
	 room->left_bound.x2 = 16;
	 room->left_bound.y1 = 0;
	 room->left_bound.y2 = 400;
	 
	 room->down_bound.x1 = 0;
	 room->down_bound.x2 = 640;
	 room->down_bound.y1 = 368;
	 room->down_bound.y2 = 400;
	 
	 room->door_array[0].locked = false;
	 room->door_array[0].door_box.x1 = 144;
	 room->door_array[0].door_box.x2 = 176;
	 room->door_array[0].door_box.y1 = 0;
	 room->door_array[0].door_box.y2 = 32; 
	 
	 room->door_array[1].locked = false;
	 room->door_array[1].door_box.x1 = 304;
	 room->door_array[1].door_box.x2 = 336;
	 room->door_array[1].door_box.y1 = 0;
	 room->door_array[1].door_box.y2 = 32; 

	  
	 room->door_array[2].locked = false;
	 room->door_array[2].door_box.x1 = 464;
	 room->door_array[2].door_box.x2 = 496;
	 room->door_array[2].door_box.y1 = 0;
	 room->door_array[2].door_box.y2 = 32;
	 
	 room->door_array[3].locked = false;
	 room->door_array[3].door_box.x1 = 304;
	 room->door_array[3].door_box.x2 = 336;
	 room->door_array[3].door_box.y1 = 368;
	 room->door_array[3].door_box.y2 = 400;
	 
	
	 
}

void initialize_room11(Room *room) {
	 
	 room->up_bound.x1 = 0;
	 room->up_bound.x2 = 640;
	 room->up_bound.y1 = 0;
	 room->up_bound.y2 = 16;
	 
	 room->right_bound.x1 = 608;
	 room->right_bound.x2 = 640;
	 room->right_bound.y1 = 0;
	 room->right_bound.y2 = 400;
	 
	 room->left_bound.x1 = 0;
	 room->left_bound.x2 = 16;
	 room->left_bound.y1 = 0;
	 room->left_bound.y2 = 400;
	 
	 room->down_bound.x1 = 0;
	 room->down_bound.x2 = 640;
	 room->down_bound.y1 = 368;
	 room->down_bound.y2 = 400;
	 
	 room->door_array[0].locked = false;
	 room->door_array[0].door_box.x1 = 304;
	 room->door_array[0].door_box.x2 = 336;
	 room->door_array[0].door_box.y1 = 368;
	 room->door_array[0].door_box.y2 = 400; 
	 
	 room->item.on_stage = true;
	 room->item.item_ID = 4;
	 room->item.item_box.x1 = 304;
	 room->item.item_box.x2 = 336;
	 room->item.item_box.y1 = 64;
	 room->item.item_box.y2 = 96;
}


void initialize_array(Model *model){
	
	initialize_room0(&(model->room_array[0]));
	initialize_room1(&(model->room_array[1]));
	initialize_room2(&(model->room_array[2]));
	initialize_room3(&(model->room_array[3]));
	initialize_room4(&(model->room_array[4]));
	initialize_room5(&(model->room_array[5]));
	initialize_room6(&(model->room_array[6]));
	initialize_room7(&(model->room_array[7]));
	initialize_room8(&(model->room_array[8]));
	initialize_room9(&(model->room_array[9]));
	initialize_room10(&(model->room_array[10]));
	initialize_room11(&(model->room_array[11]));







}

bool is_in_bounds(Player *player, Room *room, Direction direction) {
	
	switch (direction) {
		
		case left: 
		if (player->x - 16 > room->left_bound.x2)
			return true;
			else
				return false;
		
		case right:
		if ((player->x) + 16 < room->right_bound.x1)
			return true;
			else
				return false;
		
		case down:
		if ((player->y) + 16 < room->down_bound.y1)
			return true;
			else
				return false;
		
		case up:
		if ((player->y) - 16 > room->up_bound.y2)
			return true;
			else
				return false;
		
		default:
		break;
	}
	
	
}

bool collided (Player *player, Bound *bound) {
	
	if ((player->x >= bound->x1) && (player->x <= bound->x2)) {
		if (((player->y >= bound->y1) && (player->y <= bound->y2)) || ((player->y + 16 >= bound->y1) && (player->y + 16 <= bound->y2)) ) {
			return true;
		} 
	} else if ((player->x + 16 >= bound->x1) && (player->x + 16 <= bound->x2)) {
		if (((player->y >= bound->y1) && (player->y <= bound->y2)) || ((player->y + 16 >= bound->y1) && (player->y + 16 <= bound->y2)) ) {
			return true;
		}
	}
		return false;
	


}

void update_heldslot (Player *player, Item *item) {
	
	player->heldslot_ID = item->item_ID;
}





