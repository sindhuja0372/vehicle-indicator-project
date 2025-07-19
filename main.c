#include <windows.h>
#include <stdio.h>
#include <stdbool.h>
#include "uart_driver.h"

void blink_indicator(const char* side) {
    char log_msg[100];
    for (int i = 0; i < 5; i++) {
        sprintf(log_msg, "Toggling %s Indicator...\n", side);
        UART_SendString(log_msg);
        Sleep(300);
    }
}

void blink_hazard() {
    for (int i = 0; i < 5; i++) {
        UART_SendString("Toggling Hazard Light (Left + Right)...\n");
        Sleep(300);
    }
}

int main() {
    UART_Init();

    // Simulated button inputs (change values to test)
    bool left_button = true;
    bool right_button = true;

    if (left_button && right_button) {
        UART_LogStatus("Hazard Mode Activated");
        blink_hazard();
        UART_LogStatus("Hazard Mode Deactivated");
    } else if (left_button) {
        UART_LogStatus("Left indicator ON");
        UART_LogStatus("Right indicator OFF");
        blink_indicator("Left");
    } else if (right_button) {
        UART_LogStatus("Left indicator OFF");
        UART_LogStatus("Right indicator ON");
        blink_indicator("Right");
    } else {
        UART_LogStatus("No button pressed. All indicators OFF");
    }

    return 0;
}

