#include "Retro_lib.h"

void clear_slv_reg ()
{
	int i;
	for (i=0;i<50;i++)
	{
		Xil_Out32 (BASEADDR+offset*i,0x00000000);
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


