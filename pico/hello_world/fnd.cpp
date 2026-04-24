#include "pico/stdlib.h"

const uint DataPin  = 19;  // GP19 → SER (14번)
const uint ClockPin = 18;  // GP18 → SRCLK (11번)
const uint LatchPin = 17;  // GP17 → RCLK (12번)

const uint8_t DataArray[10] = {
    0b11111100, // 0
    0b01100000, // 1
    0b11011010, // 2
    0b11110010, // 3
    0b01100110, // 4
    0b10110110, // 5
    0b10111110, // 6
    0b11100000, // 7
    0b11111110, // 8
    0b11110110  // 9
};

void shiftOut(uint dataPin, uint clockPin, uint8_t val) {
    for (int i = 0; i < 8; i++) {
        gpio_put(dataPin, (val >> i) & 1);   // LSB 먼저
        gpio_put(clockPin, 1);
        sleep_us(1);
        gpio_put(clockPin, 0);
        sleep_us(1);
    }
}

int main() {
    stdio_init_all();

    gpio_init(DataPin);  gpio_set_dir(DataPin,  GPIO_OUT);
    gpio_init(ClockPin); gpio_set_dir(ClockPin, GPIO_OUT);
    gpio_init(LatchPin); gpio_set_dir(LatchPin, GPIO_OUT);

    while (true) {
        for (int i = 0; i < 10; i++) {
            gpio_put(LatchPin, 0);
            shiftOut(DataPin, ClockPin, DataArray[i]);
            gpio_put(LatchPin, 1);
            sleep_ms(1000);
        }
    }
}