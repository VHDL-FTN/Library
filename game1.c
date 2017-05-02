#include "game1_lib.h"
#include "Retro_lib.h"


void creating_objects_game4 ();
void creating_objects_game1 ();
void creating_objects_game2 ();

int game2_start()
{
    init_platform();
    clear_slv_reg ();
    print("Hello World\n\r");

    creating_objects_game1 ();

    cleanup_platform();

    return 0;
}

void creating_objects_game1 ()
{

	//draw_same_horizontal_objects (4, HORIZONTAL_RECTANGLE, 511, 3);

	//draw_main_bar ();




	//int object_on = 1;
	int positionX = 500;
	int positionY = 300;
	int movType = 1;

	while (1)
	{

		switch (movType)
		{
			case 1: //right_up
				ball_mooving_right_up (1, positionX, positionY, 511);
				positionX = positionX + 1;
				positionY = positionY - 1;


				if ((positionX) >= 626)
					movType = 2; //left_up


				if ((positionY) <= 16)
					movType = 4; //right_down

				break;

			case 2: //left_up
				ball_mooving_left_up (1, positionX, positionY, 511);
				positionX = positionX - 1;
				positionY = positionY - 1;

				if ((positionX) <= 0)
					movType = 3; //left_down


				if ((positionY) <= 0)
					movType = 1; //right_up

				break;

			case 3: //left_down
				ball_mooving_left_up (1, positionX, positionY, 511);
				positionX = positionX - 1;
				positionY = positionY + 1;

				if ((positionX) <= 0)
					movType = 4; //right_down


				if ((positionY) >= 466)
					movType = 2; //left_up

				break;

			case 4: //right_down
				ball_mooving_left_up (1, positionX, positionY, 511);
				positionX = positionX + 1;
				positionY = positionY + 1;

				if ((positionX) >= 626)
					movType = 3; //left_down


				if ((positionY) >= 466)
					movType = 1; //right_up

				break;


			default:
				break;



		}



		for (int z=0; z<= 900000; z++);
	}

}






