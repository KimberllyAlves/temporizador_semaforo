#include <stdio.h>
#include "pico/stdlib.h"   // Inclui a biblioteca padrão para funcionalidades básicas como GPIO, temporização e comunicação serial.
#include "hardware/timer.h" // Inclui a biblioteca para gerenciamento de temporizadores de hardware.

#define LED_PIN_Y 11
#define LED_PIN_G 12
#define LED_PIN_R 13


int led_on = 0; //Indica qual led está ligado

// Função de callback que será chamada repetidamente pelo temporizador

bool repeating_timer_callback(struct repeating_timer *t) {
    //Led vermelho ligado
    if (led_on == 0) { 
        gpio_put(LED_PIN_R, true);
        gpio_put(LED_PIN_Y, false);
        gpio_put(LED_PIN_G, false);
        led_on = 1;
    }
    //Led amarelo ligado
    else if (led_on == 1) {
        gpio_put(LED_PIN_Y, true);
        gpio_put(LED_PIN_G, false);
        gpio_put(LED_PIN_R, false);
        led_on = 2;
    }
    //Led verde ligado
    else  {
        gpio_put(LED_PIN_G, true);
        gpio_put(LED_PIN_R, false);
        gpio_put(LED_PIN_Y, false);
        led_on = 0;
    }
}

int main() {
    // Inicializa a comunicação serial, permitindo o uso de funções como printf.
    stdio_init_all();

    // Inicializar os pinos dos leds
    gpio_init(LED_PIN_R);
    gpio_set_dir(LED_PIN_R,true);
    gpio_init(LED_PIN_Y);
    gpio_set_dir(LED_PIN_Y,true);
    gpio_init(LED_PIN_G);
    gpio_set_dir(LED_PIN_G,true);

    // Declaração de uma estrutura de temporizador de repetição.
    // Esta estrutura armazenará informações sobre o temporizador configurado.
    struct repeating_timer timer;

    // Configura o temporizador para chamar a função de callback a cada 3 segundo.
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);

    // Loop infinito que mantém o programa em execução.
    while (true) {
        // Pausa de 1 segundos para reduzir o uso da CPU.
        sleep_ms(1000);
        printf("Dê prioridade aos pedestres\n");
    }
    return 0;
}
