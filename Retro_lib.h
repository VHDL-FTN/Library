#ifndef SRC_RETRO_LIB_H_
#define SRC_RETRO_LIB_H_
#include <stdio.h>
#include "platform.h"
#include "xparameters.h"
#include "xil_printf.h"
#include "xil_io.h"

#include "object_define.h"
#include "game4_lib.h"

#define BASEADDR XPAR_GRAPH_IP_NEW_0_S00_AXI_BASEADDR
#define offset 4

void clear_slv_reg ();
unsigned int create_object (int, int, int, int, int);

#endif /* SRC_RETRO_LIB_H_ */
