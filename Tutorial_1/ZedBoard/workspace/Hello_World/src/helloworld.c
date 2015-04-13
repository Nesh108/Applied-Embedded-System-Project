/*
* helloworld.c: simple test application
*
* This application configures UART 16550 to baud rate 9600.
* PS7 UART (Zynq) is not initialized by this application, since
* bootrom/bsp configures it to baud rate 115200
*
* ------------------------------------------------
* | UART TYPE BAUD RATE |
* ------------------------------------------------
* uartns550 9600
* uartlite Configurable only in HW design
* ps7_uart 115200 (configured by bootrom/bsp)
*/

#include <xparameters.h>
#include <xgpio.h>
#include "platform.h"

int main()
{
    init_platform();

    char switch_val = 0;	// var to store switch value
    XGpio dipsw, leds;		// GPIO Access variables, used by the driver
    						// dispw = switches access var
    						// leds = LEDs access var

    XGpio_Initialize(&dipsw, XPAR_SWS_8BITS_DEVICE_ID);	// Driver init for switches
    XGpio_Initialize(&leds, XPAR_LEDS_8BITS_DEVICE_ID);	// Driver init for LEDs
    XGpio_SetDataDirection(&leds, 1, 0);				// Set LEDs direction as output
    XGpio_SetDataDirection(&dipsw, 1, 0xFFFFFFFF);		// Set switches direction as input

    while(1)
    {
    	switch_val = XGpio_DiscreteRead(&dipsw, 1);		// Read the value of the switches
    	XGpio_DiscreteWrite(&leds, 1, switch_val);		// Write the switches value to the LEDs
    }

    return 0;
}
