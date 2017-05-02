#include "game4_lib.h"
#include "Retro_lib.h"
#include "spi_timer.h"
#include <math.h>

typedef enum Hit_States {up_left,up_right,down_left,down_right,out_of_screen} Hit_States;
enum States {idle,place_tank1,place_tank2,play,game_over} states;
enum Player_States {player1,player2,end_of_round};

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
    int tank_place_mark;
    int player1_score,player2_score;
    first_screen_color_flash = 542;
    unsigned int object_temp;

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

		            object_temp = create_object(LETTER_P,1,TANK_LEFT_POSITION_X,TANK_LEFT_POSITION_Y-64-32,411);
					Xil_Out32(BASEADDR+offset*19,object_temp); // Player mark

		            if (position.fsButtons==2)
		            {
		            	delay_ms(1000);
						if(position.fsButtons==2){
							while(position.fsButtons==2);
							//clear_slv_reg ();
							states = place_tank2;

						}
		            }else states = place_tank1;
		            break;

				case place_tank2:
					//print("state: place_tank1 \n");
					TANK_RIGHT_POSITION_X = tank_poition (TANK_RIGHT_POSITION_X);
					creating_objects_game4(TANK_LEFT_POSITION_X,TANK_LEFT_POSITION_Y,TANK_RIGHT_POSITION_X,TANK_RIGHT_POSITION_Y);

					object_temp = create_object(LETTER_P,1,TANK_RIGHT_POSITION_X,TANK_RIGHT_POSITION_Y-64-32,411);
					Xil_Out32(BASEADDR+offset*19,object_temp); // Player mark

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
					object_temp = create_object(60,3,TANK_LEFT_POSITION_X,64*2,411);
					Xil_Out32(BASEADDR+offset*19,object_temp); // Delete letter P

					tank_place_mark = play_game4(TANK_LEFT_POSITION_X,TANK_LEFT_POSITION_Y,TANK_RIGHT_POSITION_X,TANK_RIGHT_POSITION_Y);
					if(tank_place_mark==1)
					{
						player1_score ++;
					}
					else if(tank_place_mark==2)
					{
						player2_score ++;
					}
					if(tank_place_mark==3)
					{
						player1_score ++;
						player2_score ++;
					}
					else if(tank_place_mark==4)
					{
						player1_score = player1_score;
						player2_score = player2_score;
					}

					if (player1_score==3 || player2_score==3)
					{
						states = game_over;
					}
					else
					{
						states = place_tank1;
					}
					printf("\n\n player1_score = %d \n\n",player1_score);
					printf("\n\n player2_score = %d \n\n",player2_score);
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
					strength(player1_score);
					angle(player2_score);
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

    Xil_Out32(BASEADDR,542); // Background
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

//    object_temp = create_object(BALL,0,(8*8-8),(45*8-8),411);
//    Xil_Out32(BASEADDR+offset*19,object_temp); // Ball

//    object_temp = create_object(LETTER_S,1,(1*8-8),(1*8-8),411);
//    Xil_Out32(BASEADDR+offset*20,object_temp); // S
//
//    object_temp = create_object(LETTER_T,1,(3*8-8),(1*8-8),411);
//    Xil_Out32(BASEADDR+offset*21,object_temp); // T
//
//    object_temp = create_object(LETTER_R,1,(5*8-8),(1*8-8),411);
//    Xil_Out32(BASEADDR+offset*22,object_temp); // R
//
//    object_temp = create_object(LETTER_E,1,(7*8-8),(1*8-8),411);
//    Xil_Out32(BASEADDR+offset*23,object_temp); // E
//
//    object_temp = create_object(LETTER_N,1,(9*8-8),(1*8-8),411);
//    Xil_Out32(BASEADDR+offset*24,object_temp); // N
//
//    object_temp = create_object(LETTER_G,1,(11*8-8),(1*8-8),411);
//    Xil_Out32(BASEADDR+offset*25,object_temp); // G
//
//    object_temp = create_object(LETTER_T,1,(13*8-8),(1*8-8),411);
//    Xil_Out32(BASEADDR+offset*26,object_temp); // T
//
//    object_temp = create_object(LETTER_H,1,(15*8-8),(1*8-8),411);
//    Xil_Out32(BASEADDR+offset*27,object_temp); // H
//
//    object_temp = create_object(COLON,1,(17*8-8),(1*8-8),411);
//    Xil_Out32(BASEADDR+offset*28,object_temp); // :
//
//    strength(0);
//
//    object_temp = create_object(LETTER_A,1,(1*8-8),(3*8-8),411);
//    Xil_Out32(BASEADDR+offset*32,object_temp); // A
//
//    object_temp = create_object(LETTER_N,1,(3*8-8),(3*8-8),411);
//    Xil_Out32(BASEADDR+offset*33,object_temp); // N
//
//    object_temp = create_object(LETTER_G,1,(5*8-8),(3*8-8),411);
//    Xil_Out32(BASEADDR+offset*34,object_temp); // G
//
//    object_temp = create_object(LETTER_L,1,(7*8-8),(3*8-8),411);
//    Xil_Out32(BASEADDR+offset*35,object_temp); // L
//
//    object_temp = create_object(LETTER_E,1,(9*8-8),(3*8-8),411);
//    Xil_Out32(BASEADDR+offset*36,object_temp); // E
//
//    object_temp = create_object(COLON,1,(11*8-8),(3*8-8),411);
//    Xil_Out32(BASEADDR+offset*37,object_temp); // :
//
//    angle(00);
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
	return first_screen_color += 2;
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
				if( (TANK_POSITION_X<=0) || ((TANK_POSITION_X >= 4*64) && (TANK_POSITION_X <= 6*64) ) )////////////////////////////4
				{
					TANK_POSITION_X = TANK_POSITION_X;
				}
				else
				{
					TANK_POSITION_X -= 12;
				}
			}else if (position.X > 600)
			{
				if( (TANK_POSITION_X+64>=640) || ((TANK_POSITION_X+64 >= 4*64) && (TANK_POSITION_X+64 <= 6*64)) )////////////////////////////
				{
					TANK_POSITION_X = TANK_POSITION_X;
				}
				else
				{
					TANK_POSITION_X += 12;
				}
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
			if (strength_value>0)strength_value -= 1;
			strength(strength_value);
			delay_ms(1000);
		}else if (position.Y > 600)
		{
			if (strength_value<100)strength_value += 1;
			strength(strength_value);
			delay_ms(1000);
		}else
		{
			strength_value = strength_value;
			delay_ms(1000);
		}

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
	int angle_value;
	angle_value=0;
	while(position.fsButtons-2)
	{
		print("\n\n 2 \n\n");
		if(position.Y < 450)
		{
			if (angle_value>0)angle_value -= 1;
			angle(angle_value);
			delay_ms(1000);
		}else if (position.Y > 600)
		{
			if (angle_value<90)angle_value += 1;
			angle(angle_value);
			delay_ms(1000);
		}else
		{
			angle_value = angle_value;
			delay_ms(1000);
		}

	}
	if (position.fsButtons==2)
	{
		delay_ms(1000);
		if(position.fsButtons==2){
			while(position.fsButtons==2);
		}
	}
	return angle_value;
}

Hit_States hit_detection(int ball_x,int ball_y,int H1,int H2,int D1,int D2,int d,Hit_States ball_direction)
{
	Hit_States next_ball_direction;
	next_ball_direction = ball_direction;

	if( ( (ball_x+8 >= (33*8-8) && ball_x+8 <= (33*8)) && ball_y >= (29*8-8) ) || ball_x+8>=640 ) //Hit from left side of wall or right side of screen
	{
		if(ball_direction == up_right)
		{
			next_ball_direction = up_left;
		}
		else if (ball_direction == down_right)
		{
			next_ball_direction = down_left;
		}
	}
	else if( ( (ball_x <= (48*8) && ball_x >= (48*8-8)) && ball_y >= (29*8-8) ) || ball_x<=0 ) //Hit from right side of wall or left side of screen
	{
		if(ball_direction == up_left)
		{
			next_ball_direction = up_right;
		}
		else if (ball_direction == down_left)
		{
			next_ball_direction = down_right;
		}
	}else if( (ball_y+8 >= (480-64)) || ( (ball_y+8>=(29*8-8) && ball_y+8<=(29*8)) && (ball_x>=(33*8-8) && ball_x+8<=(48*8)) ) ) //Hit from top side of wall
	{
		if(ball_direction == down_left)
		{
			next_ball_direction = up_left;
		}
		else if (ball_direction == down_right)
		{
			next_ball_direction = up_right;
		}
	}else if( ball_y <= 0 ) //Hit up
	{
		if(ball_direction == up_left)
		{
			next_ball_direction = down_left;
		}
		else if (ball_direction == up_right)
		{
			next_ball_direction = down_right;
		}
	}
//	else if( ball_x <= 0 || ball_x+8 >= 640 ) //Out of screen
//	{
//		next_ball_direction = out_of_screen;
//	}

	return next_ball_direction;
}

int tank_hit_detection (int player,int ball_x,int ball_y,int H1,int H2,int D1,int D2,int d,int TANK_POSITION_X,int TANK_POSITION_Y)
{
	int hit;
	if (player == 1)
	{
		if ( (ball_x+4>=TANK_POSITION_X+D1+64 && ball_x+4<=TANK_POSITION_X+D1+d+64) && (ball_y+4>=TANK_POSITION_Y && ball_y<=TANK_POSITION_Y+H1) )
		{
			hit=1;
		}
	}
	else if (player == 2)
	{
		if ( (ball_x+4>=TANK_POSITION_X-D1-d && ball_x+4<=TANK_POSITION_X-D1) && (ball_y+4>=TANK_POSITION_Y && ball_y<=TANK_POSITION_Y+H1) )
		{
			hit=1;
		}
	}

	return hit;
}

/*
int shoot_game4(int player_score,int H1,int H2,int D1,int D2,int d,int T,int strength,int angle,int g_force,int TANK_POSITION_X,int TANK_POSITION_Y)
{
	int ball_x0,ball_y0;
	int ball_x_speed0,ball_y_speed0;
	int ball_x,ball_y; // Ball coordinates
	unsigned int object_temp;
	int score;
	int ball_size,ball_color;
	int hit;
	//int T_temp;

	score = player_score; // Initial state for score
	ball_size = 0; // Initial state for ball size
	ball_color = 411; // Initial state for ball color

	strength /= 1.111;

	// INITIAL CONDITIONS
	ball_x0 = TANK_POSITION_X; // Initial state for ball_x(t=0)
	ball_y0 = TANK_POSITION_Y; // Initial state for ball_y(t=o)
	ball_x_speed0 = (strength)*round(cos(angle)); // Initial state for ball_x_speed(t=0)
	ball_y_speed0 = -((strength)*round(sin(angle))); // Initial state for ball_y_speed(t=0)

	//T_temp -= (count()/300);
	T=0;

	while(1)
	{
		T ++;
		delay_ms(300);
		ball_x = (ball_x_speed0*T+ball_x0)/100;
		ball_y = (480+((1/2)*g_force*10*(T^2) +ball_y_speed0*T+ball_y0))/40;

		hit = object_hit_detection(ball_x,ball_y,H1,H2,D1,D2,d);

		object_temp = create_object(BALL,ball_size,ball_x,ball_y,ball_color);
		Xil_Out32(BASEADDR+offset*19,object_temp); // Ball

		if(hit==1)
		{
			score ++;
			break;
		}
	}

	return score;
}
//FUNKCIJU IZNAD ZA SAD NE KORISTIMO
*/

int shoot_game4_basic (int player,int player_score,int H1,int H2,int D1,int D2,int d,int TANK_POSITION_X,int TANK_POSITION_Y)
{
		int ball_x,ball_y; // Ball coordinates
		unsigned int object_temp;
		int score;
		int ball_size,ball_color;
		int hit;
		enum Hit_States ball_direction;

		hit=0;

		score = player_score; // Initial state for score
		ball_size = 0; // Initial state for ball size
		ball_color = 411; // Initial state for ball color

		if (player==1)
		{
			ball_x = TANK_POSITION_X+63;
			ball_y = TANK_POSITION_Y;
			ball_direction = up_right;
		}
		else if (player==2)
		{
			ball_x = TANK_POSITION_X;
			ball_y = TANK_POSITION_Y;
			ball_direction = up_left;
		}

		while(1)
		{
			switch(ball_direction)
			{
			case up_left:
				ball_x -= 1;
				ball_y -= 1;
			break;

			case up_right:
				ball_x += 1;
				ball_y -= 1;
			break;

			case down_left:
				ball_x -= 1;
				ball_y += 1;
			break;

			case down_right:
				ball_x += 1;
				ball_y += 1;
			break;

			case out_of_screen:
				ball_x = ball_x;
				ball_y = ball_y;
			break;
			}

			hit = tank_hit_detection(player,ball_x,ball_y,H1,H2,D1,D2,d,TANK_POSITION_X,TANK_POSITION_Y);

			object_temp = create_object(BALL,ball_size,ball_x,ball_y,ball_color);
			Xil_Out32(BASEADDR+offset*19,object_temp); // Ball

			ball_direction = hit_detection(ball_x,ball_y,H1,H2,D1,D2,d,ball_direction);

			delay_ms(10); //Speed of ball

			if(hit==1)
			{
				score ++;
				break;
			}
			//if(ball_direction == out_of_screen)break;
			if((count()/10000) == 1)break;
		}

		return score;

}


int play_game4 (int TANK_LEFT_POSITION_X,int TANK_LEFT_POSITION_Y,int TANK_RIGHT_POSITION_X,int TANK_RIGHT_POSITION_Y)
{
	enum Player_States states_game4 = player1;
	int player1_score,player2_score;
	int tank_place_mark;
	tank_place_mark=0; 	// 1 if only tank 1 get a hit
						// 2 if only tank 2 get a hit
						// 3 if both tanks get hit
						// 4 if non of tanks get hit

	player1_score = player2_score=0;

	//Projectile Motion Variables
	int H1,H2,D1,D2,d,T,strength,angle,g_force;// For now both tanks must be size 3 for properly working of this function
	H1 = 64; // Height of tank
	H2 = 64*4; // Height of 4 blocks
	D1 = TANK_RIGHT_POSITION_X - TANK_LEFT_POSITION_X - 64; // Distance between two tanks
	D2 = 64*2; // Width of wall
	d = 64; // Width of tank
	T = 0; // We need function for track of time later in code
	g_force = 10;
	unsigned int object_temp;

	while((position.fsButtons - 1))
	{
		switch(states_game4)
		{
		case player1:
			print("\n\n 1 \n\n");

			object_temp = create_object(LETTER_P,1,TANK_LEFT_POSITION_X,TANK_LEFT_POSITION_Y-64-32,411);
			Xil_Out32(BASEADDR+offset*19,object_temp); // Player mark

			//strength = set_strength();
			//angle = set_angle();

			//player1_score = shoot_game4(player1_score,H1,H2,D1,D2,d,T,strength,angle,g_force,TANK_LEFT_POSITION_X + 64,TANK_LEFT_POSITION_Y);//OVO NE RADI NISTA ZA SAD

			player1_score = shoot_game4_basic(1,player1_score,H1,H2,D1,D2,d,TANK_LEFT_POSITION_X,TANK_LEFT_POSITION_Y);

			states_game4 = player2;

		break;

		case player2:
			object_temp = create_object(LETTER_P,1,TANK_RIGHT_POSITION_X,TANK_RIGHT_POSITION_Y-64-32,411);
			Xil_Out32(BASEADDR+offset*19,object_temp); // Player mark

			//strength = set_strength();
			//angle = set_angle();

			//player2_score = shoot_game4(player2_score,H1,H2,D1,D2,d,T,strength,angle,g_force,TANK_RIGHT_POSITION_X,TANK_RIGHT_POSITION_Y);

			player2_score = shoot_game4_basic(2,player2_score,H1,H2,D1,D2,d,TANK_RIGHT_POSITION_X ,TANK_RIGHT_POSITION_Y);

			if(player2_score == 0 && player1_score == 1)
			{
				tank_place_mark = 1;
				return tank_place_mark;
			}
			else if(player2_score == 1 && player1_score == 0)
			{
				tank_place_mark = 2;
				return tank_place_mark;
			}
			else if(player2_score == 1 && player1_score == 1)
			{
				tank_place_mark = 3;
				return tank_place_mark;
			}
			else if (player2_score == 0 && player1_score == 0)
			{
				tank_place_mark = 4;
				return tank_place_mark;
			}
		break;

		case end_of_round:

			//LOGIKA MOZDA ZA ISPIS SAMO REZULTATA

			if (position.fsButtons==2)
			{
				delay_ms(1000);
				if(position.fsButtons==2){
					while(position.fsButtons==2);
					clear_slv_reg ();
					states_game4 = game_over; // OVO JE POGRESNA LOGIKA DAJ BOZE DA RADI
				}
			}else states_game4 = end_of_round;
		break;

		}
		delay_ms(500); // OVAJ DELAY SLUZI DA BI STIGAO DA SE PRITISNE ANALOGNI DzOJSTIK, SREDITI KASNIJE
	}
	return 0;
}

