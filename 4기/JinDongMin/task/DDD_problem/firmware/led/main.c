#include <avr/io.h>
#include <util/delay.h>

#define F_CPU 16000000UL

#include "pin/pin.h"
#include "led/entity/led.h"
#include "common/peripheral_table.h"

pin pin_of_pb5;
led_object led1;

int main(void)
{
    init_pin(&pin_of_pb5, &PORTB, PORTB5);
    init_led(&led1, &pin_of_pb5);

    while(1)
    {
        pheripheral_call_table[LED_ON](&led1);
        _delay_ms(500);
        pheripheral_call_table[LED_OFF](&led1);
        _delay_ms(500);
    }

    return 0;
}
