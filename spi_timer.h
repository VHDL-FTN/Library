#include "xscugic.h"
#include "spi_controller.h"
//interrupt
extern struct Coordinates position;
#define INTC_DEVICE_ID 		XPAR_PS7_SCUGIC_0_DEVICE_ID
#define FIT0_DEVICE_ID		0
#define SPI_DEVICE_ID		0
#define FIT1_DEVICE_ID 		0
#define INTC_FIT1_INTERRUPT_ID XPAR_FABRIC_FIT_TIMER_1_INTERRUPT_INTR
#define INTC_FIT0_INTERRUPT_ID XPAR_FABRIC_FIT_TIMER_0_INTERRUPT_INTR
#define INTC_SPI_INTERRUPT_ID  XPAR_FABRIC_SPI_CONTROLLER_INTERRUPT_INTR

void FIT_Intr_Handler();
void SPI_Intr_Handler();
int IntcInitFunction(u16 DeviceId,int *Fit0InstancePtr, int *SPIInstancePtr,int *Fit1InstancePtr);
int InterruptSystemSetup(XScuGic *XScuGicInstancePtr);
u32 count();
void delay_ms(u32 num);
