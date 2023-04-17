#ifndef MENU_H
#define MENU_H

#include <osbind.h>
#include <stdio.h>
#include "TYPES.H"
#include "consts.h"
#include "event.h"
#include "start_sc.h"
#include "cont_sc.h"
#include "fail_sc.h"
#include "win_sc.h"
#include "escape.h"
#include "RASTER.H"

/*
Menu options 
*/
#define MENU_CHOICE_NEXT 1


/*
Menu functions 
*/

/*
    Function: 
*/
void menu(UINT32* base);

/*
    Function: 
*/
void process_menu(UINT32* base);


#endif