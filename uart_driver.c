#include "uart_driver.h"
#include <stdio.h>

void UART_Init(void) {
    // Simulated UART Init
    printf("UART Initialized.\n");
}

void UART_SendString(const char* str) {
    printf("%s", str);
}

void UART_LogStatus(const char* status) {
    printf("Status: %s\n", status);
}
