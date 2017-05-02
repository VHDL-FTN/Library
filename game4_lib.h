#ifndef SRC_GAME4_LIB_H_
#define SRC_GAME4_LIB_H_

void game4_start ();
void creating_objects_game4 (int TANK_LEFT_POSITION_X,int TANK_LEFT_POSITION_Y,int TANK_RIGHT_POSITION_X,int TANK_RIGHT_POSITION_Y);
void strength (int number);
void angle (int number);
int creating_objects_welcome(int first_screen_color);
int creating_objects_game_over(int first_screen_color);
int tank_poition(int TANK_POSITION_X);
int play_game4 (int TANK_LEFT_POSITION_X,int TANK_LEFT_POSITION_Y,int TANK_RIGHT_POSITION_X,int TANK_RIGHT_POSITION_Y);
int set_strength ();
int set_angle ();
//int shoot_game4(int player_score,int H1,int H2,int D1,int D2,int d,int T,int strength,int angle,int g_force,int TANK_POSITION_X,int TANK_POSITION_Y);
//Hit_States hit_detection(int ball_x,int ball_y,int H1,int H2,int D1,int D2,int d,Hit_States State);
int shoot_game4_basic (int player,int player_score,int H1,int H2,int D1,int D2,int d,int TANK_POSITION_X,int TANK_POSITION_Y);
int tank_hit_detection (int player,int ball_x,int ball_y,int H1,int H2,int D1,int D2,int d,int TANK_POSITION_X,int TANK_POSITION_Y);

#endif /* SRC_GAME4_LIB_H_ */
