#include "spi_timer.h"
#include <stdio.h>
#include "platform.h"
#include "xil_printf.h"
#include "xparameters.h"
#include "xil_exception.h"
#include "xscugic.h"
#include "spi_controller.h"
#include "Retro_lib.h"

int main()
{
    int status;
    turn_on_off_Green_LED(1);

    init_position(&position);
    print_position(position);
    reset_SPI_and_set_delay(0x000F0A19);

    status = IntcInitFunction(INTC_DEVICE_ID, NULL,NULL,NULL); //NE DIRAJ NI U LUDILU!
    if(status != XST_SUCCESS) return XST_FAILURE;  //NE DIRAJ NI U LUDILU!

    SPI_Int_en(); //NE DIRAJ NI U LUDILU!

    /* ----------------GAME LOGIC ------------------- */
    game4_start();

    while(1){
    	turn_on_off_Green_LED(1);
    	delay_ms(1000);
    	turn_on_off_Green_LED(0);
    	delay_ms(1000);
    }

    print("program end\n");
    cleanup_platform(); //NE DIRAJ NI U LUDILU!
    return 0;
}
