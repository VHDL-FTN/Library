#ifndef SRC_RETRO_LIB_H_
#define SRC_RETRO_LIB_H_
#include <stdio.h>
#include "platform.h"
#include "xparameters.h"
#include "xil_printf.h"
#include "xil_io.h"


#include "object_define.h"

#define BASEADDR XPAR_GRAPH_IP_0_S00_AXI_BASEADDR
#define offset 4


void clear_slv_reg ();
unsigned int create_object (int, int, int, int, int);

void draw_same_horizontal_objects (int, int, int, int, int, int, int);
//
//void getBall (int, int, int, int);
//
//int ball_hit_left_wall ();
//int ball_hit_right_wall ();
//int ball_hit_top_wall ();
//int ball_hit_bottom_wall ();
//
//void ball_mooving_left_up (int size, int positionX, int positionY, int color);
//void ball_mooving_roght_up (int size, int positionX, int positionY, int color);
//void ball_mooving_left_down (int size, int positionX, int positionY, int color);
//void ball_mooving_right_down (int size, int positionX, int positionY, int color);

#endif /* SRC_RETRO_LIB_H_ */
