#include "Retro_lib.h"

void creating_objects_game4 ();

int main()
{
    init_platform();
    clear_slv_reg ();
    print("Hello World\n\r");

    //Variables

    // Background
   // Xil_Out32(BASEADDR,0x00000333); // Background

    //Creating objects
   creating_objects_game4();

    //unsigned int object_temp;

   // object_temp = create_object(SQUARE,3,0,0,511);
	//Xil_Out32(BASEADDR+offset*2,object_temp); // Green brick 2

	//object_temp = create_object(SQUARE,3,(640-64),(480-64),511);
	//Xil_Out32(BASEADDR+offset*3,object_temp); // Green brick 3

    cleanup_platform();
    return 0;
}

void creating_objects_game4 ()
{
    unsigned int object_temp;

    Xil_Out32(BASEADDR,0x000003f3); // Background
    							//53*8-8 is vertical position looking excel document for 4th game
    object_temp = create_object(SQUARE,3,0,(53*8-8),511); // 511 is 1 1111 1111
    Xil_Out32(BASEADDR+offset*1,object_temp); // Green brick 1

    object_temp = create_object(SQUARE,3,(9*8-8),(53*8-8),511);
    Xil_Out32(BASEADDR+offset*2,object_temp); // Green brick 2

    object_temp = create_object(SQUARE,3,(17*8-8),(53*8-8),511);
    Xil_Out32(BASEADDR+offset*3,object_temp); // Green brick 3

    object_temp = create_object(SQUARE,3,(25*8-8),(53*8-8),511);
    Xil_Out32(BASEADDR+offset*4,object_temp); // Green brick 4

    object_temp = create_object(SQUARE,3,(33*8-8),(53*8-8),511);
    Xil_Out32(BASEADDR+offset*5,object_temp); // Green brick 5

    object_temp = create_object(SQUARE,3,(41*8-8),(53*8-8),511);
    Xil_Out32(BASEADDR+offset*6,object_temp); // Green brick 6

    object_temp = create_object(SQUARE,3,(49*8-8),(53*8-8),511);
    Xil_Out32(BASEADDR+offset*7,object_temp); // Green brick 7

    object_temp = create_object(SQUARE,3,(57*8-8),(53*8-8),511);
    Xil_Out32(BASEADDR+offset*8,object_temp); // Green brick 8

    object_temp = create_object(SQUARE,3,(65*8-8),(53*8-8),511);
    Xil_Out32(BASEADDR+offset*9,object_temp); // Green brick 9

    object_temp = create_object(SQUARE,3,(73*8-8),(53*8-8),511);
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

    object_temp = create_object(TANK_RIGHT,3,(1*8-8),(45*8-8),511);
    Xil_Out32(BASEADDR+offset*17,object_temp); // Left tank

    //object_temp = create_object(TANK_LEFT,3,(73*8-8),(45*8-8),511);
    object_temp = create_object(TANK_LEFT,3,(73*8-8),(45*8-8),511);
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

    object_temp = create_object(NUMBER_1,1,(19*8-8),(1*8-8),411);
    Xil_Out32(BASEADDR+offset*29,object_temp); // 1

    object_temp = create_object(NUMBER_0,1,(21*8-8),(1*8-8),411);
    Xil_Out32(BASEADDR+offset*30,object_temp); // 0

    object_temp = create_object(NUMBER_0,1,(23*8-8),(1*8-8),411);
    Xil_Out32(BASEADDR+offset*31,object_temp); // 0

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

    object_temp = create_object(NUMBER_9,1,(13*8-8),(3*8-8),411);
    Xil_Out32(BASEADDR+offset*38,object_temp); // 9

    object_temp = create_object(NUMBER_0,1,(15*8-8),(3*8-8),411);
    Xil_Out32(BASEADDR+offset*39,object_temp); // 0

}
