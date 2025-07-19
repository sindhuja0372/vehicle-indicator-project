#ifndef UART_DRIVER_H
#define UART_DRIVER_H

void UART_Init(void);
void UART_SendString(const char* str);
void UART_LogStatus(const char* status);

#endif
