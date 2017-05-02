/*
 * spi_controller.h
 *
 *  Created on: Mar 5, 2017
 *      Author: damjan
 */

#ifndef SRC_SPI_CONTROLLER_H_
#define SRC_SPI_CONTROLLER_H_

#include "platform.h"
#include "xparameters.h"
#include "xil_printf.h"



#define SPI_DELAY_REG 0x00000000
#define SPI_CNTRL_REG 0x00000001
#define SPI_INT_REG 0x00000002
#define SPI_DATAI_0_REG 0x00000003
#define SPI_DATAI_1_REG 0x00000004
#define SPI_DATAI_2_REG 0x00000005
#define SPI_DATAI_3_REG 0x00000006
#define SPI_DATAI_4_REG 0x00000007
#define SPI_DATAO_0_REG 0x00000008
#define SPI_DATAO_1_REG 0x00000009
#define SPI_DATAO_2_REG 0x0000000A
#define SPI_DATAO_3_REG 0x0000000B
#define SPI_DATAO_4_REG 0x0000000C
#define SPI_INTR_EN_REG 0x0000000D


struct Coordinates{
	int X;
	int Y;
	int fsButtons;
};
int spi_ready();

void init_position(struct Coordinates *position);

void print_position(struct Coordinates position);

void reset_SPI_and_set_delay(int delay);

void turn_on_off_Green_LED (int on_off);

void set_Led_RGB (int duty_R, int duty_G, int duty_B);

void read_X_Y_fsButton();

void SPI_Int_en();

void SPI_Int_dis();

void get_position(struct Coordinates *position);

#endif /* SRC_SPI_CONTROLLER_H_ */
