#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include <stdio.h>
#include <string.h>

class SevenSegment {
private:
    uint dataPin;
    uint clockPin;
    uint latchPin;

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

    void shiftOut(uint8_t val);

public:
    SevenSegment(uint data, uint clock, uint latch);
    ~SevenSegment();
    void showNumber(int num);
    void countUp(int delayMs);
};

class LCD1602 {
private:
    uint sdaPin;
    uint sclPin;
    uint8_t addr;

    void sendCmd(uint8_t cmd);
    void sendData(uint8_t data);
    void sendByte(uint8_t val, uint8_t mode);
    void pulseEnable(uint8_t val);

public:
    LCD1602(uint sda, uint scl, uint8_t addr);
    ~LCD1602();
    void clear();
    void setCursor(int col, int row);
    void print(const char *text);
    void printNumber(int num);
};

SevenSegment :: SevenSegment(uint data, uint clock, uint latch) {
    this->dataPin  = data;
    this->clockPin = clock;
    this->latchPin = latch;

    gpio_init(dataPin);  gpio_set_dir(dataPin,  GPIO_OUT);
    gpio_init(clockPin); gpio_set_dir(clockPin, GPIO_OUT);
    gpio_init(latchPin); gpio_set_dir(latchPin, GPIO_OUT);
}

SevenSegment :: ~SevenSegment() {
    gpio_put(dataPin,  0);
    gpio_put(clockPin, 0);
    gpio_put(latchPin, 0);
}

void SevenSegment :: shiftOut(uint8_t val) {
    for (int i = 0; i < 8; i++) {
        gpio_put(dataPin, (val >> i) & 1);
        gpio_put(clockPin, 1);
        sleep_us(1);
        gpio_put(clockPin, 0);
        sleep_us(1);
    }
}

void SevenSegment :: showNumber(int num) {
    if(num < 0 || num > 9) return;
    gpio_put(latchPin, 0);
    shiftOut(DataArray[num]);
    gpio_put(latchPin, 1);
}

void SevenSegment :: countUp(int delayMs) {
    for(int i = 0; i < 10; i++) {
        showNumber(i);
        sleep_ms(delayMs);
    }
}

LCD1602 :: LCD1602(uint sda, uint scl, uint8_t addr) {
    this->sdaPin = sda;
    this->sclPin = scl;
    this->addr   = addr;

    i2c_init(i2c0, 100 * 1000);
    gpio_set_function(sdaPin, GPIO_FUNC_I2C);
    gpio_set_function(sclPin, GPIO_FUNC_I2C);
    gpio_pull_up(sdaPin);
    gpio_pull_up(sclPin);

    sleep_ms(50);

   
    sendCmd(0x33);
    sleep_ms(5);
    sendCmd(0x32);
    sleep_ms(1);
    sendCmd(0x28);
    sendCmd(0x0C);
    sendCmd(0x06);
    clear();
}

LCD1602 :: ~LCD1602() {
    clear();
}

void LCD1602 :: pulseEnable(uint8_t val) {
    uint8_t data;

    data = val | 0x04;
    i2c_write_blocking(i2c0, addr, &data, 1, false);
    sleep_us(1);

    data = val & ~0x04;
    i2c_write_blocking(i2c0, addr, &data, 1, false);
    sleep_us(50);
}

void LCD1602 :: sendByte(uint8_t val, uint8_t mode) {
    
    uint8_t high = (val & 0xF0) | mode | 0x08;
    uint8_t low  = ((val << 4) & 0xF0) | mode | 0x08;

    i2c_write_blocking(i2c0, addr, &high, 1, false);
    pulseEnable(high);

    i2c_write_blocking(i2c0, addr, &low, 1, false);
    pulseEnable(low);
}

void LCD1602 :: sendCmd(uint8_t cmd) {
    sendByte(cmd, 0x00);
}

void LCD1602 :: sendData(uint8_t data) {
    sendByte(data, 0x01);
}

void LCD1602 :: clear() {
    sendCmd(0x01);
    sleep_ms(2);
}

void LCD1602 :: setCursor(int col, int row) {
    int addr = (row == 0) ? 0x00 : 0x40;
    sendCmd(0x80 | (addr + col));
}

void LCD1602 :: print(const char *text) {
    while(*text) {
        sendData(*text++);
    }
}

void LCD1602 :: printNumber(int num) {
    char buf[16];
    sprintf(buf, "%d", num);
    print(buf);
}

int main() {
    stdio_init_all();
    sleep_ms(2000); 

    SevenSegment seg(19, 18, 17);
    LCD1602 lcd(4, 5, 0x27);

    int count = 0;

    while(true) {
        seg.showNumber(count % 10);

        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Count:");
        lcd.setCursor(0, 1);
        lcd.printNumber(count);

        count++;
        sleep_ms(1000);
    }
}