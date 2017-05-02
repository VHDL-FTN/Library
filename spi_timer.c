#include "spi_timer.h"

XScuGic INTCInst;

struct Coordinates position;
u32 counter = 0;

void FIT0_Intr_Handler(){
	xil_printf("FIT0 hendler!\n");
	if(spi_ready()){
		read_X_Y_fsButton(&position);
	}

}

void SPI_Intr_Handler(){
	xil_printf("SPI hender!\n");
	get_position(&position);
	print_position(position);
}

void FIT1_Intr_Handler(){
	//xil_printf("FIT1 hendler!\n");
	counter++;
}

int IntcInitFunction(u16 DeviceId,int *Fit0InstancePtr, int *SPIInstancePtr,int *Fit1InstancePtr)
{
	XScuGic_Config *IntcConfig;
	int status;

	// Interrupt controller initialization
	IntcConfig = XScuGic_LookupConfig(DeviceId);
	status = XScuGic_CfgInitialize(&INTCInst, IntcConfig, IntcConfig->CpuBaseAddress);
	if(status != XST_SUCCESS) return XST_FAILURE;

	// Call interrupt setup function
	status = InterruptSystemSetup(&INTCInst);
	if(status != XST_SUCCESS) return XST_FAILURE;

	// Register FIT0 interrupt handler
	status = XScuGic_Connect(&INTCInst,
					  	  	 INTC_FIT0_INTERRUPT_ID,
					  	  	 (Xil_ExceptionHandler)FIT0_Intr_Handler,
					  	  	 (void *)Fit0InstancePtr);
	if(status != XST_SUCCESS) return XST_FAILURE;

	// Register FIT1 interrupt handler
	status = XScuGic_Connect(&INTCInst,
							 INTC_FIT1_INTERRUPT_ID,
							 (Xil_ExceptionHandler)FIT1_Intr_Handler,
							 (void *)Fit1InstancePtr);
	if(status != XST_SUCCESS) return XST_FAILURE;

	// Register SPI interrupt handler
	status = XScuGic_Connect(&INTCInst,
							 INTC_SPI_INTERRUPT_ID,
							 (Xil_ExceptionHandler)SPI_Intr_Handler,
							 (void *)SPIInstancePtr);
	if(status != XST_SUCCESS) return XST_FAILURE;

	// Enable FIT0 interrupts in the controller
	XScuGic_Enable(&INTCInst, INTC_FIT0_INTERRUPT_ID);

	// Enable FIT1 interrupts in the controller
	XScuGic_Enable(&INTCInst, INTC_FIT1_INTERRUPT_ID);

	//Enable SPI interrupt in the controller
	XScuGic_Enable(&INTCInst, INTC_SPI_INTERRUPT_ID);



	return XST_SUCCESS;
}

int InterruptSystemSetup(XScuGic *XScuGicInstancePtr)
{
	// Register GIC interrupt handler

	Xil_ExceptionRegisterHandler(XIL_EXCEPTION_ID_INT,
			 	 	 	 	 	 (Xil_ExceptionHandler)XScuGic_InterruptHandler,
			 	 	 	 	 	 XScuGicInstancePtr);
	Xil_ExceptionEnable();


	return XST_SUCCESS;

}
u32 count()
{
	return counter;
}
void delay_ms(u32 num)
{
	u32 temp_counter = count();
	while(count() < (temp_counter+num));
}
