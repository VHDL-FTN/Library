#include "game1_lib.h"
#include "Retro_lib.h"


void clear_slv_reg ()
{
	int i;
	unsigned int string;
	string = create_object(55,0,0,0,0);
	for (i=0;i<100;i++)
	{
		Xil_Out32 (BASEADDR+offset*i,string);
	}
}

unsigned int create_object (int object, int size, int horizontal, int vertical, int color)
{
	unsigned int string;
	string = 0x00000000;

	//adjusting object type in 32 bits (31 downto 26)
	object &= 0x0000003F;
	object <<= 26;
	string |= object;

	//adjusting size of object in 32 bits (25 downto 24)
	size &= 0x00000003;
	size <<= 24;
	string |= size;

	//adjusting horizontal position of object in 32 bits (23 downto 16)
	horizontal /= 4;
	horizontal &= 0x000000ff;
	horizontal <<= 16;
	string |= horizontal;

	//adjusting vertical position of object in 32 bits (15 downto 9)
	vertical /= 4;
	vertical &= 0x0000007f;
	vertical <<= 9;
	string |= vertical;

	//adjusting colour position of object in 32 bits (8 downto 0)
	color &= 0x000001ff;
	string |= color;

	return string;
}

void draw_same_horizontal_objects (int hmin, int object, int color, int size)
{
	unsigned int object_temp;

	int n[24] = {0, 10, 20, 30, 40, 50, 60, 70, 0, 10, 20, 30, 40, 50, 60, 70, 0, 10, 20, 30, 40, 50, 60, 70};
	int vert_const = 1;

	for (unsigned short x=0; x<24; x++){
		object_temp = create_object(object,size,(n[x] * 8 + 4),(vert_const * 8), color);

		if (x == 7)
			vert_const = 6;

		if (x == 15)
			vert_const = 11;
		Xil_Out32(BASEADDR + offset * (x+1), object_temp);
	} //Drawing bricks from left to right side

}

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

