/*
 * spi_controller.c
 *
 *  Created on: Mar 5, 2017
 *      Author: damjan
 */

#include "spi_controller.h"

int *SPI_ptr  = (int *)XPAR_SPI_CONTROLLER_0_S00_AXI_BASEADDR;

void init_position(struct Coordinates *position){
	position->X = 0;
	position->Y = 0;
	position->fsButtons = 0;
}

void print_position(struct Coordinates position){
	xil_printf("X coordinate: %d, Y coordinate: %d, fsButtons: %d \n",position.X,position.Y,position.fsButtons);
}

void reset_SPI_and_set_delay(int delay){
	*(SPI_ptr + SPI_CNTRL_REG) = 0x00000001;//definisati, a ne hardkodovati
	while(!(*(SPI_ptr + SPI_INT_REG)&0x00000002)){}
	*(SPI_ptr + SPI_CNTRL_REG) = 0x00000000;//definisati, a ne hardkodovati
	*(SPI_ptr + SPI_DELAY_REG) = delay;
}

void turn_on_off_Green_LED (int on_off){
	while(!(*(SPI_ptr + SPI_INT_REG)&0x00000002)){}
	if (on_off){
		*(SPI_ptr + SPI_DATAI_0_REG) = 0x00000081;//definisati, a ne hardkodovati
	}else{
		*(SPI_ptr + SPI_DATAI_0_REG) = 0x00000080;//definisati, a ne hardkodovati
	}

	*(SPI_ptr + SPI_CNTRL_REG) = 0x00000052;//definisati, a ne hardkodovati
	*(SPI_ptr + SPI_CNTRL_REG) = 0x00000050;//definisati, a ne hardkodovati
	while(!(*(SPI_ptr + SPI_INT_REG)&0x00000002)){}
}

void set_Led_RGB (int duty_R, int duty_G, int duty_B){
	while(!(*(SPI_ptr + SPI_INT_REG)&0x00000002)){}
	*(SPI_ptr + SPI_DATAI_0_REG) = 0x0000084;//definisati, a ne hardkodovati
	*(SPI_ptr + SPI_DATAI_1_REG) = duty_R;//definisati, a ne hardkodovati
	*(SPI_ptr + SPI_DATAI_2_REG) = duty_G;//definisati, a ne hardkodovati
	*(SPI_ptr + SPI_DATAI_3_REG) = duty_B;//definisati, a ne hardkodovati
	*(SPI_ptr + SPI_CNTRL_REG) = 0x00000052;//definisati, a ne hardkodovati
	*(SPI_ptr + SPI_CNTRL_REG) = 0x00000050;//definisati, a ne hardkodovati
}

void read_X_Y_fsButton(){
	*(SPI_ptr + SPI_DATAI_0_REG) = 0x000000FF;//dummy
	*(SPI_ptr + SPI_CNTRL_REG) = 0x00000052;//definisati, a ne hardkodovati
	*(SPI_ptr + SPI_CNTRL_REG) = 0x00000050;//definisati, a ne hardkodovati
}

void get_position(struct Coordinates *position){
	char smpX_LB,smpX_HB,smpY_LB,smpY_HB = 0;
	smpX_LB = *(SPI_ptr + SPI_DATAO_0_REG);
	smpX_HB = *(SPI_ptr + SPI_DATAO_1_REG);
	smpY_LB = *(SPI_ptr + SPI_DATAO_2_REG);
	smpY_HB = *(SPI_ptr + SPI_DATAO_3_REG);
	position->fsButtons = *(SPI_ptr + SPI_DATAO_4_REG);
	position->X = (smpX_HB << 8) | smpX_LB;
	position->Y = (smpY_HB << 8) | smpY_LB;
}

int spi_ready(){
	return (*(SPI_ptr + SPI_INT_REG)&0x00000002);

}

void SPI_Int_en(){
	*(SPI_ptr + SPI_INTR_EN_REG) = 0x00000001;//definisati, a ne hardkodovati
}

void SPI_Int_dis(){
	*(SPI_ptr + SPI_INTR_EN_REG) = 0x00000000;//definisati, a ne hardkodovati
}

