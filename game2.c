void creating_objects_game2 ()
{
    unsigned int object_temp;

    Xil_Out32(BASEADDR,0x000003f3); // Background

    object_temp = create_object(CAR,3,(37*8-8),(53*8-8),501); // 511 is 1 1111 1111
    Xil_Out32(BASEADDR+offset*1,object_temp); // car

    object_temp = create_object(STONE_3,3,(29*8-8),(45*8-8),411);
    Xil_Out32(BASEADDR+offset*2,object_temp); // stone1

    object_temp = create_object(STONE_1,3,(37*8-8),(37*8-8),411);
    Xil_Out32(BASEADDR+offset*3,object_temp); // stone2

    object_temp = create_object(STONE_2,3,(45*8-8),(5*8-8),411);
    Xil_Out32(BASEADDR+offset*4,object_temp); // stone3

    object_temp = create_object(SQUARE,3,(29*8-8),0,511);
    Xil_Out32(BASEADDR+offset*5,object_temp); // road1

    object_temp = create_object(SQUARE,3,(37*8-8),0,511);
    Xil_Out32(BASEADDR+offset*6,object_temp); // road2

    object_temp = create_object(SQUARE,3,(45*8-8),0,511);
    Xil_Out32(BASEADDR+offset*7,object_temp); // road3

    object_temp = create_object(SQUARE,3,(29*8-8),(5*8-8),511);
    Xil_Out32(BASEADDR+offset*8,object_temp); // road4

    object_temp = create_object(SQUARE,3,(37*8-8),(5*8-8),511);
    Xil_Out32(BASEADDR+offset*9,object_temp); // road5

    object_temp = create_object(SQUARE,3,(45*8-8),(5*8-8),511);
    Xil_Out32(BASEADDR+offset*10,object_temp); // road6

    object_temp = create_object(SQUARE,3,(29*8-8),(13*8-8),511);
    Xil_Out32(BASEADDR+offset*41,object_temp); // road7

    object_temp = create_object(SQUARE,3,(37*8-8),(13*8-8),511);
    Xil_Out32(BASEADDR+offset*12,object_temp); // road8

    object_temp = create_object(SQUARE,3,(45*8-8),(13*8-8),511);
    Xil_Out32(BASEADDR+offset*13,object_temp); // road9

    object_temp = create_object(SQUARE,3,(29*8-8),(21*8-8),511);
    Xil_Out32(BASEADDR+offset*14,object_temp); // road10

    object_temp = create_object(SQUARE,3,(37*8-8),(21*8-8),511);
    Xil_Out32(BASEADDR+offset*15,object_temp); // road11

    object_temp = create_object(SQUARE,3,(45*8-8),(21*8-8),511);
    Xil_Out32(BASEADDR+offset*16,object_temp); // road12

    object_temp = create_object(SQUARE,3,(29*8-8),(29*8-8),511);
    Xil_Out32(BASEADDR+offset*17,object_temp); // road13

    object_temp = create_object(SQUARE,3,(37*8-8),(29*8-8),511);
    Xil_Out32(BASEADDR+offset*18,object_temp); // road14

    object_temp = create_object(SQUARE,3,(45*8-8),(29*8-8),511);
    Xil_Out32(BASEADDR+offset*19,object_temp); // road15

    object_temp = create_object(SQUARE,3,(29*8-8),(37*8-8),511);
    Xil_Out32(BASEADDR+offset*20,object_temp); // road16

    object_temp = create_object(SQUARE,3,(37*8-8),(37*8-8),511);
    Xil_Out32(BASEADDR+offset*21,object_temp); // road17

    object_temp = create_object(SQUARE,3,(45*8-8),(37*8-8),511);
    Xil_Out32(BASEADDR+offset*22,object_temp); // road18

    object_temp = create_object(SQUARE,3,(29*8-8),(45*8-8),511);
    Xil_Out32(BASEADDR+offset*23,object_temp); // road19

    object_temp = create_object(SQUARE,3,(37*8-8),(45*8-8),511);
    Xil_Out32(BASEADDR+offset*24,object_temp); // road20

    object_temp = create_object(SQUARE,3,(45*8-8),(45*8-8),511);
    Xil_Out32(BASEADDR+offset*25,object_temp); // road21

    object_temp = create_object(SQUARE,3,(29*8-8),(53*8-8),511);
    Xil_Out32(BASEADDR+offset*26,object_temp); // road22

    object_temp = create_object(SQUARE,3,(37*8-8),(53*8-8),511);
    Xil_Out32(BASEADDR+offset*27,object_temp); // road23

    object_temp = create_object(SQUARE,3,(45*8-8),(53*8-8),511);
    Xil_Out32(BASEADDR+offset*28,object_temp); // road24

	object_temp = create_object(WHOLE_HEART,2,(1*8-8),(1*8-8),101);
    Xil_Out32(BASEADDR+offset*29,object_temp); // heart1

	object_temp = create_object(WHOLE_HEART,2,(5*8-8),(1*8-8),101);
    Xil_Out32(BASEADDR+offset*30,object_temp); // heart2
}