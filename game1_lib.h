#ifndef SRC_GAME1_LIB_H_
#define SRC_GAME1_LIB_H_
#include <stdio.h>
#include "platform.h"
#include "xparameters.h"
#include "xil_printf.h"
#include "xil_io.h"
#include <stdlib.h>
#include "object_define.h"

void draw_same_horizontal_objects ( int, int, int, int);

void draw_main_bar ();

void getBall (int, int, int, int);

void getBall_SHADOW (int, int, int, int);

void ball_mooving_left_up(int, int, int, int); // 2
void ball_mooving_right_up (int , int , int , int); // 1
void ball_mooving_left_down (int , int , int , int); // 3
void ball_mooving_right_down (int , int , int , int); // 4



void ball_mooving (int, int, int, int , int);

int ball_hit_left_wall ();
//int ball_hit_right_wall ();
int ball_hit_top_wall ();
//int ball_hit_bottom_wall ();
//





#endif /* SRC_GAME1_LIB_H_ */
