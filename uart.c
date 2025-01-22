#include <stdio.h>
#include "pico/stdlib.h"

int main() {
    stdio_init_all();

    char comando[1024];

    while (!stdio_usb_connected()) {
        sleep_ms(100); 
    }
    printf("Conexão Serial realizada com sucesso!\n");
    printf("Digite o comando:\n");
    
    while (true) {
   
        if (scanf("%1023s", comando) == 1) {
            printf("Recebido: %s\n", comando);
        }

   
        sleep_ms(500);
    }

    return 0;
}