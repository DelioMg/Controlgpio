#include "pico/stdlib.h"
#include <stdio.h>
#include "hardware/pwm.h"
#include "hardware/uart.h"

#define LED_VERDE 11
#define LED_AZUL 12
#define LED_VERMELHO 13
#define BUZZER 21


uint slice_num;

void setup() {
    gpio_init(LED_VERDE);
    gpio_set_dir(LED_VERDE, GPIO_OUT);
    gpio_init(LED_AZUL);
    gpio_set_dir(LED_AZUL, GPIO_OUT);
    gpio_init(LED_VERMELHO);
    gpio_set_dir(LED_VERMELHO, GPIO_OUT);
    gpio_init(BUZZER);
    gpio_set_dir(BUZZER, GPIO_OUT);
    gpio_set_function(BUZZER, GPIO_FUNC_PWM);      
    slice_num = pwm_gpio_to_slice_num(BUZZER); 
    pwm_set_clkdiv(slice_num, 125.0);                  
    pwm_set_wrap(slice_num, 255); 

}

void desligar_todos_leds() {
    gpio_put(LED_VERDE, 0);
    gpio_put(LED_AZUL, 0);
    gpio_put(LED_VERMELHO, 0);
}

void tocar_buzzer(){
    pwm_set_gpio_level(BUZZER, 50);              
    pwm_set_enabled(slice_num, true);                  
    sleep_ms(2000);                                    
    pwm_set_enabled(slice_num, false);                 
}

int main() {
    stdio_init_all();
    setup();
    desligar_todos_leds();

    char comando[1024];

    while (!stdio_usb_connected()) {
        sleep_ms(100); 
    }
    printf("Conexão Serial realizada com sucesso!\n");
    printf("Digite G para ligar Led Verde, B para led Azul, R para Led Vermelho, W para liga os tres, BU para Buzzer e O para desligar todos Leds\n");
    printf("Digite o comando:\n");

    while (true) {

        scanf("%1023s", comando);

       if (strcmp(comando, "G") == 0) {
            desligar_todos_leds();
            gpio_put(LED_VERDE, 1);
            printf("Led Verde Acesso \n");
        } else if (strcmp(comando, "B" ) == 0) {
            desligar_todos_leds();
            gpio_put(LED_AZUL, 1);
            printf("Led Azul Acesso \n");
        } else if (strcmp(comando, "R" ) == 0) {
            desligar_todos_leds();
            gpio_put(LED_VERMELHO, 1);
            printf("Led Vermelho Acesso \n");
        } else if (strcmp(comando, "W" ) == 0) {
            gpio_put(LED_VERDE, 1);
            gpio_put(LED_AZUL, 1);
            gpio_put(LED_VERMELHO, 1);
            printf("Todos Leds Acesso \n");
        } else if (strcmp(comando, "O" ) == 0) {
            desligar_todos_leds();
            printf("Todos Leds Desligados \n");
        } else if (strcmp(comando, "BU" ) == 0) {
            tocar_buzzer();
            printf("Buzzer acionado \n");
        } else {
            printf("Comando inválido: %s\n", comando);
        }
   
   
        sleep_ms(500);
    }

    return 0;
}