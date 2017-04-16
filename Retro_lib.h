#ifndef SRC_RETRO_LIB_H_
#define SRC_RETRO_LIB_H_
#include "xparameters.h"
#include "xil_io.h"
#define offset 4
// Base add -> XPAR_GRAPH_IP_0_S00_AXI_BASEADDR

void clear_slv_reg ()
{
	int i;
	for (i=0;i<50;i++)
	{
		Xil_Out32 (XPAR_GRAPH_IP_0_S00_AXI_BASEADDR+offset*i,0x00000000);
	}
}

#endif /* SRC_RETRO_LIB_H_ */
