#include "game4_lib.h"
#include "Retro_lib.h"
#include "spi_timer.h"

enum States {idle,place_tank1,place_tank2,play,game_over};
enum Player_States {player1,player2};
//u32 time .....time = count();
void game4_start ()
{
    clear_slv_reg (); // CLEAR ALL AXI SLAVE REGISTERS

    enum States states = idle;

    int TANK_LEFT_POSITION_X = (1*8-8);
    int TANK_LEFT_POSITION_Y = (45*8-8);
    int TANK_RIGHT_POSITION_X = (73*8-8);
    int TANK_RIGHT_POSITION_Y = (45*8-8);
    int first_screen_color_flash;
    first_screen_color_flash = 542;

	while (1) //Ovde mozda ubaciti umesto jedan while(!(position.fsButtons - 1))
	{
		switch (states)
		        {
			   case idle:
					//print("state: idle \n");
					first_screen_color_flash=creating_objects_welcome(first_screen_color_flash);
					if (position.fsButtons==2)
					{
						delay_ms(1000);
						if(position.fsButtons==2){
							while(position.fsButtons==2);
							clear_slv_reg ();
							states = place_tank1;
						}
					}else states = idle;
				break;

		        case place_tank1:
		            //print("state: start \n");
		            TANK_LEFT_POSITION_X = tank_poition (TANK_LEFT_POSITION_X);
		            creating_objects_game4(TANK_LEFT_POSITION_X,TANK_LEFT_POSITION_Y,TANK_RIGHT_POSITION_X,TANK_RIGHT_POSITION_Y);
		            if (position.fsButtons==2)
		            {
		            	delay_ms(1000);
						if(position.fsButtons==2){
							while(position.fsButtons==2);
							clear_slv_reg ();
							states = place_tank2;

						}
		            }else states = place_tank1;
		            break;

				case place_tank2:
					//print("state: place_tank1 \n");
					TANK_RIGHT_POSITION_X = tank_poition (TANK_RIGHT_POSITION_X);
					creating_objects_game4(TANK_LEFT_POSITION_X,TANK_LEFT_POSITION_Y,TANK_RIGHT_POSITION_X,TANK_RIGHT_POSITION_Y);
					if (position.fsButtons==2)
					{
						delay_ms(1000);
						if(position.fsButtons==2){
							while(position.fsButtons==2);
							//clear_slv_reg (); // Za sad verovatno ne treba ali neka ga
							states = play;
						}
					}else states = place_tank2;
					break;

				case play:
					//print("state: play \n");
					play_game4();
					states = game_over;
//					if (position.fsButtons==2)
//					{
//						delay_ms(1000);
//						if(position.fsButtons==2){
//							while(position.fsButtons==2);
//							clear_slv_reg ();
//							states = game_over;
//						}
//					}else states = play;
					break;

				case game_over:
					//print("state: game_over \n");
					clear_slv_reg (); // Ovo je potrebno jer je gore onaj deo zakomentarisan
					first_screen_color_flash=creating_objects_game_over(first_screen_color_flash);
					if (position.fsButtons==2)
					{
						delay_ms(1000);
						if(position.fsButtons==2){
							while(position.fsButtons==2);
							clear_slv_reg ();
							states = idle;
						}
					}else states = game_over;
					break;
				}
	}

}

void creating_objects_game4 (int TANK_LEFT_POSITION_X,int TANK_LEFT_POSITION_Y,int TANK_RIGHT_POSITION_X,int TANK_RIGHT_POSITION_Y)
{
    unsigned int object_temp;

    Xil_Out32(BASEADDR,0x000003f3); // Background
    							//53*8-8 is vertical position looking excel document for 4th game
    object_temp = create_object(SQUARE,3,0*64,(53*8-8),511); // 511 is 1 1111 1111
    Xil_Out32(BASEADDR+offset*1,object_temp); // Green brick 1

    object_temp = create_object(SQUARE,3,1*64,(53*8-8),511);
    Xil_Out32(BASEADDR+offset*2,object_temp); // Green brick 2

    object_temp = create_object(SQUARE,3,(2*64),(53*8-8),511);
    Xil_Out32(BASEADDR+offset*3,object_temp); // Green brick 3

    object_temp = create_object(SQUARE,3,(3*64),(53*8-8),511);
    Xil_Out32(BASEADDR+offset*4,object_temp); // Green brick 4

    object_temp = create_object(SQUARE,3,4*64,(53*8-8),511);
    Xil_Out32(BASEADDR+offset*5,object_temp); // Green brick 5

    object_temp = create_object(SQUARE,3,5*64,(53*8-8),511);
    Xil_Out32(BASEADDR+offset*6,object_temp); // Green brick 6

    object_temp = create_object(SQUARE,3,6*64,(53*8-8),511);
    Xil_Out32(BASEADDR+offset*7,object_temp); // Green brick 7

    object_temp = create_object(SQUARE,3,7*64,(53*8-8),511);
    Xil_Out32(BASEADDR+offset*8,object_temp); // Green brick 8

    object_temp = create_object(SQUARE,3,8*64,(53*8-8),511);
    Xil_Out32(BASEADDR+offset*9,object_temp); // Green brick 9

    object_temp = create_object(SQUARE,3,9*64,(53*8-8),511);
    Xil_Out32(BASEADDR+offset*10,object_temp); // Green brick 10

    object_temp = create_object(SQUARE,3,(33*8-8),(45*8-8),511);
    Xil_Out32(BASEADDR+offset*11,object_temp); // Green brick 11

    object_temp = create_object(SQUARE,3,(41*8-8),(45*8-8),511);
    Xil_Out32(BASEADDR+offset*12,object_temp); // Green brick 12

    object_temp = create_object(SQUARE,3,(33*8-8),(37*8-8),511);
    Xil_Out32(BASEADDR+offset*13,object_temp); // Green brick 13

    object_temp = create_object(SQUARE,3,(41*8-8),(37*8-8),511);
    Xil_Out32(BASEADDR+offset*14,object_temp); // Green brick 14

    object_temp = create_object(SQUARE,3,(33*8-8),(29*8-8),511);
    Xil_Out32(BASEADDR+offset*15,object_temp); // Green brick 15

    object_temp = create_object(SQUARE,3,(41*8-8),(29*8-8),511);
    Xil_Out32(BASEADDR+offset*16,object_temp); // Green brick 16

    object_temp = create_object(TANK_RIGHT,3,TANK_LEFT_POSITION_X,TANK_LEFT_POSITION_Y,105);
    Xil_Out32(BASEADDR+offset*17,object_temp); // Left tank

    object_temp = create_object(TANK_LEFT,3,TANK_RIGHT_POSITION_X,TANK_RIGHT_POSITION_Y,205);
    Xil_Out32(BASEADDR+offset*18,object_temp); // Right tank

    object_temp = create_object(BALL,0,(8*8-8),(45*8-8),411);
    Xil_Out32(BASEADDR+offset*19,object_temp); // Ball

    object_temp = create_object(LETTER_S,1,(1*8-8),(1*8-8),411);
    Xil_Out32(BASEADDR+offset*20,object_temp); // S

    object_temp = create_object(LETTER_T,1,(3*8-8),(1*8-8),411);
    Xil_Out32(BASEADDR+offset*21,object_temp); // T

    object_temp = create_object(LETTER_R,1,(5*8-8),(1*8-8),411);
    Xil_Out32(BASEADDR+offset*22,object_temp); // R

    object_temp = create_object(LETTER_E,1,(7*8-8),(1*8-8),411);
    Xil_Out32(BASEADDR+offset*23,object_temp); // E

    object_temp = create_object(LETTER_N,1,(9*8-8),(1*8-8),411);
    Xil_Out32(BASEADDR+offset*24,object_temp); // N

    object_temp = create_object(LETTER_G,1,(11*8-8),(1*8-8),411);
    Xil_Out32(BASEADDR+offset*25,object_temp); // G

    object_temp = create_object(LETTER_T,1,(13*8-8),(1*8-8),411);
    Xil_Out32(BASEADDR+offset*26,object_temp); // T

    object_temp = create_object(LETTER_H,1,(15*8-8),(1*8-8),411);
    Xil_Out32(BASEADDR+offset*27,object_temp); // H

    object_temp = create_object(COLON,1,(17*8-8),(1*8-8),411);
    Xil_Out32(BASEADDR+offset*28,object_temp); // :

    strength(0);

    object_temp = create_object(LETTER_A,1,(1*8-8),(3*8-8),411);
    Xil_Out32(BASEADDR+offset*32,object_temp); // A

    object_temp = create_object(LETTER_N,1,(3*8-8),(3*8-8),411);
    Xil_Out32(BASEADDR+offset*33,object_temp); // N

    object_temp = create_object(LETTER_G,1,(5*8-8),(3*8-8),411);
    Xil_Out32(BASEADDR+offset*34,object_temp); // G

    object_temp = create_object(LETTER_L,1,(7*8-8),(3*8-8),411);
    Xil_Out32(BASEADDR+offset*35,object_temp); // L

    object_temp = create_object(LETTER_E,1,(9*8-8),(3*8-8),411);
    Xil_Out32(BASEADDR+offset*36,object_temp); // E

    object_temp = create_object(COLON,1,(11*8-8),(3*8-8),411);
    Xil_Out32(BASEADDR+offset*37,object_temp); // :

    angle(00);
}

void strength (int number)
{
	unsigned int object_temp;
	int x,y,z;

	if (number > 100) number = 0;

	x = number / 100;
	y = number % 100;
	y /= 10;
	z = number % 10;

	object_temp = create_object(NUMBER_0+x,1,(19*8-8),(1*8-8),411);
	Xil_Out32(BASEADDR+offset*29,object_temp); // 1

	object_temp = create_object(NUMBER_0+y,1,(21*8-8),(1*8-8),411);
	Xil_Out32(BASEADDR+offset*30,object_temp); // 0

	object_temp = create_object(NUMBER_0+z,1,(23*8-8),(1*8-8),411);
	Xil_Out32(BASEADDR+offset*31,object_temp); // 0
}

void angle (int number)
{
	unsigned int object_temp;
	int x,y;

	if (number > 90) number = 0;

	x = number % 100;
	x /= 10;
	y = number % 10;

	object_temp = create_object(NUMBER_0+x,1,(13*8-8),(3*8-8),411);
	Xil_Out32(BASEADDR+offset*38,object_temp); // 9

	object_temp = create_object(NUMBER_0+y,1,(15*8-8),(3*8-8),411);
	Xil_Out32(BASEADDR+offset*39,object_temp); // 0
}

int creating_objects_welcome(int first_screen_color)
{
	unsigned int object_temp;

	Xil_Out32(BASEADDR,first_screen_color); // Background
								//53*8-8 is vertical position looking excel document for 4th game
	object_temp = create_object(LETTER_W,3,1*64+32,((480/2)-32),511); // 511 is 1 1111 1111
	Xil_Out32(BASEADDR+offset*1,object_temp); // LETTER W

	object_temp = create_object(LETTER_E,3,2*64+32,((480/2)-32),511);
	Xil_Out32(BASEADDR+offset*2,object_temp); // LETTER E

	object_temp = create_object(LETTER_L,3,3*64+32,((480/2)-32),511);
	Xil_Out32(BASEADDR+offset*3,object_temp); // LETTER L

	object_temp = create_object(LETTER_C,3,4*64+32,((480/2)-32),511);
	Xil_Out32(BASEADDR+offset*4,object_temp); // LETTER C

	object_temp = create_object(LETTER_O,3,5*64+32,((480/2)-32),511);
	Xil_Out32(BASEADDR+offset*5,object_temp); // LETTER O

	object_temp = create_object(LETTER_M,3,6*64+32,((480/2)-32),511);
	Xil_Out32(BASEADDR+offset*6,object_temp); // LETTER M

	object_temp = create_object(LETTER_E,3,7*64+32,((480/2)-32),511);
	Xil_Out32(BASEADDR+offset*7,object_temp); // LETTER E

	delay_ms(1000*5);
	return first_screen_color += 5;
}

int creating_objects_game_over(int first_screen_color)
{
	unsigned int object_temp;

	Xil_Out32(BASEADDR,first_screen_color); // Background
								//53*8-8 is vertical position looking excel document for 4th game
	object_temp = create_object(LETTER_G,3,3*64,((480/2)-96),511); // 511 is 1 1111 1111
	Xil_Out32(BASEADDR+offset*1,object_temp); // LETTER W

	object_temp = create_object(LETTER_A,3,4*64,((480/2)-96),511);
	Xil_Out32(BASEADDR+offset*2,object_temp); // LETTER E

	object_temp = create_object(LETTER_M,3,5*64,((480/2)-96),511);
	Xil_Out32(BASEADDR+offset*3,object_temp); // LETTER L

	object_temp = create_object(LETTER_E,3,6*64,((480/2)-96),511);
	Xil_Out32(BASEADDR+offset*4,object_temp); // LETTER C

	object_temp = create_object(LETTER_O,3,3*64,((480/2)+32),511);
	Xil_Out32(BASEADDR+offset*5,object_temp); // LETTER O

	object_temp = create_object(LETTER_V,3,4*64,((480/2)+32),511);
	Xil_Out32(BASEADDR+offset*6,object_temp); // LETTER M

	object_temp = create_object(LETTER_E,3,5*64,((480/2)+32),511);
	Xil_Out32(BASEADDR+offset*7,object_temp); // LETTER E

	object_temp = create_object(LETTER_R,3,6*64,((480/2)+32),511);
	Xil_Out32(BASEADDR+offset*8,object_temp); // LETTER E

	delay_ms(1000*5);
	return first_screen_color += 5;
}

int tank_poition(int TANK_POSITION_X)
{
			if(position.X < 450)
			{
				TANK_POSITION_X -= 12;
			}else if (position.X > 600)
			{
				TANK_POSITION_X += 12;
			}else
			{
				TANK_POSITION_X = TANK_POSITION_X;
			}

			delay_ms(1000);
			return TANK_POSITION_X;
}

int set_strength ()
{
	int strength_value;
	strength_value=0;
	while(position.fsButtons-2)
	{
		print("\n\n 2 \n\n");
		if(position.Y < 450)
		{
			strength_value -= 5;
			strength(strength_value);
		}else if (position.Y > 600)
		{
			strength_value += 5;
			strength(strength_value);
		}else;

	}
	if (position.fsButtons==2)
	{
		delay_ms(1000);
		if(position.fsButtons==2){
			while(position.fsButtons==2);
		}
	}
	return strength_value;
}

int set_angle ()
{

}

void play_game4 ()
{
	enum Player_States states = player1;
	int player1_score,player2_score;
	player1_score=0;
	player2_score=0;

	//Projectile Motion Variables
	int H,D,T,strength,angle,g_force;

	while((position.fsButtons - 1))
	{
		switch(states)
		{
		case player1:
			print("\n\n 1 \n\n");
			strength = set_strength();
			angle = set_angle();

			states = player2;
		break;

		case player2:
			strength = set_strength();
			angle = set_angle();

		break;
		}
		delay_ms(5000);
	}

}
