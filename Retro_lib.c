#include "Retro_lib.h"

void clear_slv_reg ()
{
	int i;
	unsigned int string;
	string = create_object(55,0,0,0,0);
	for (i=0;i<50;i++)
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
	horizontal /= 3;
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


void draw_same_horizontal_objects (int hmin, int distance, int objNum, int vert_const, int object, int color, int size)
{
	// hmin - left top corner of first object [in pixels]
	// distance - distance between objects / 8
	// objNum - number of objects

	unsigned int object_temp;

	unsigned short n[objNum]; //array of left top corners

	for (unsigned short p = 0; p <= objNum; p++){		//
														// filling array
		n[p] = hmin + (p-1) * (size * 8) + distance * 8;    //
	}



	for (unsigned short x=0; x<10; x++){
		object_temp = create_object(object,size,(n[x] * 8),(vert_const * 8), color);
		Xil_Out32(BASEADDR + offset * x, object_temp);
	} //Drawing bricks from left to right side

}

//
//void getBall (int size, int positionX, int positionY, int color )
//{
//
//	unsigned int object_temp;
//
//	object_temp = create_object (BALL, size, positionX, positionY, color);
//	Xil_Out32(BASEADDR + offset * 30, object_temp);
//
//}
//
//void ball_mooving_right_down (int size, int positionX, int positionY, int color)
//{
//	getBall (size, positionX + i, positionY + i, color);
//
//	delay ();
//
//	while (1)
//	{
//		for (int i=0; i< 1000 ; i++)
//		{
//
//
//			if (ball_hit_left_wall)
//				break;
//
//
//		}
//	}
//}
//
//
//int ball_hit_left_wall (int positionX)
//{
//	if ( positionX <= 0 )
//		return true;
//	else
//		return false;
//}
//
//int ball_hit_right_wall (int positionX)
//{
//	if ( positionX >= 639 )
//		return true;
//	else
//		return false;
//}
//
//int ball_hit_top_wall (int positionY)
//{
//	if ( positionY <= 0 )
//		return true;
//	else
//		return false;
//}
//
//int ball_hit_bottom_wall (int positionX)
//{
//	if ( positionX >= 479 )
//		return true;
//	else
//		return false;
//}
//
//void ball_mooving_left_up (int size, int positionX, int positionY, int color)
//{
//
//	for (int i=0; i< 1000 ; i++)
//	{
//		getBall (size, positionX - i, positionY - i, color);
//
//		delay ();
//	}
//}
//
//void ball_mooving_right_up (int size, int positionX, int positionY, int color)
//{
//
//	for (int i=0; i< 1000 ; i++)
//	{
//		getBall (size, positionX + i, positionY - i, color);
//
//		delay ();
//	}
//}
//
//void ball_mooving_left_down (int size, int positionX, int positionY, int color)
//{
//
//	for (int i=0; i< 1000 ; i++)
//	{
//		getBall (size, positionX - i, positionY + i, color);
//
//		delay ();
//	}
//}
//

