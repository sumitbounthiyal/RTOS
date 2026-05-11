#ifndef UART_DRV_H
#define UART_DRV_H

void uart_init(void);
void uart_send_byte(char data);
void uart_send_string(const char *str);

#endif
