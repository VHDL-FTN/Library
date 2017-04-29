/*
 * game4_lib.h
 *
 *  Created on: Apr 27, 2017
 *      Author: Stefan
 */

#ifndef SRC_GAME4_LIB_H_
#define SRC_GAME4_LIB_H_

void game4_start ();
void creating_objects_game4 (int TANK_LEFT_POSITION_X,int TANK_LEFT_POSITION_Y,int TANK_RIGHT_POSITION_X,int TANK_RIGHT_POSITION_Y);
void strength (int number);
void angle (int number);
int creating_objects_welcome(int first_screen_color);
int creating_objects_game_over(int first_screen_color);
int tank_poition(int TANK_POSITION_X);
void play_game4 ();
int set_strength ();
int set_angle ();

#endif /* SRC_GAME4_LIB_H_ */
