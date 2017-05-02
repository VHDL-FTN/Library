#include "game1_lib.h"
#include "Retro_lib.h"

void draw_main_bar ()
{
	unsigned int object_temp;

	object_temp = create_object(HORIZONTAL_RECTANGLE,2,(32 * 8),(56 * 8), 511);
	Xil_Out32(BASEADDR + offset * 26, object_temp);

	object_temp = create_object(HORIZONTAL_RECTANGLE,2,(35 * 8),(56 * 8), 511);
	Xil_Out32(BASEADDR + offset * 27, object_temp);

	object_temp = create_object(HORIZONTAL_RECTANGLE,2,(38 * 8),(56 * 8), 511);
	Xil_Out32(BASEADDR + offset * 28, object_temp);

	object_temp = create_object(HORIZONTAL_RECTANGLE,2,(41 * 8),(56 * 8), 511);
	Xil_Out32(BASEADDR + offset * 29, object_temp);
}


void getBall (int size, int last_positionX, int last_positionY, int color)
{

	unsigned int object_temp;

	object_temp = create_object (BALL, size, last_positionX, last_positionY, color);
	Xil_Out32(BASEADDR + offset * 30, object_temp);

}

//void getBall_SHADOW (int size, int last_positionX, int last_positionY, int color )
//{
//
//	unsigned int object_temp;
//
//	object_temp = create_object (BALL, size, last_positionX, last_positionY, color);
//	Xil_Out32(BASEADDR + offset * 31, object_temp);
//
//}

void ball_mooving_right_up (int size, int last_positionX, int last_positionY, int color)
{
		getBall (size, (last_positionX), (last_positionY), color);
		//delay ();
}

void ball_mooving_left_up (int size, int last_positionX, int last_positionY, int color)
{

		getBall (size, last_positionX, last_positionY, color);
		//delay ();
}

void ball_mooving_left_down (int size, int last_positionX, int last_positionY, int color)
{
		getBall (size, last_positionX, last_positionY, color);
		//delay ();
}

void ball_mooving_right_down (int size, int last_positionX, int last_positionY, int color)
{
	getBall (size, last_positionX, last_positionY, color);

}



//////////////////////////////////////////////////////////////////////////////////////////////

