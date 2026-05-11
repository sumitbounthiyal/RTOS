#include "uart_driver.h"



void uart_init(void)
{
    // Configure baud rate divider 
    // ESP32 frequency 80Mhz and baudrate = freq/div_int
    UART0.clk_div.div_int = 694;

    // 8 data bits Esp Encoding 
    // 0 -> 5bits
    // 1 -> 6bits
    // 2 -> 7bits
    // 3 -> 8bits
    UART0.conf0.bit_num = 3;

    // 1 stop bit
    UART0.conf0.stop_bit_num = 1;

    // No parity, 0 -> Disable : 1 -> Enable
    UART0.conf0.parity_en = 0;
}

void uart_send_byte(char data)
{
	//Wait while FIFO is full
	while(UART0.status.txfifo_cnt >= 128)
	{

	}
	// UART TX logic 
	UART0.fifo.rw_byte = data;
}
