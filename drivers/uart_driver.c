#include<stdio.h>
#include"uart_driver.h"

void uart_driver_init(void)
{
	printf("UART DRIVER Initialized \n");
}

void uart_driver_send(const char *data)
{
	printf("UART TX: %s\n",data);
}



