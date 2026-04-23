#include <stdio.h>
#include "pico/stdlib.h"

//GPIO class////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class MY_GPIO
{
private:
    const bool HIGH = 1;
    const bool LOW = 0;
    uint pin_num;
    bool dir;

public:
    int setHigh();
    int setLow();
    int setToggle();
    bool getRead();
    


    MY_GPIO(int pin_num);
    MY_GPIO(int pin_num, bool dir);
    ~MY_GPIO();
};


int MY_GPIO::setHigh(){
   if(this->dir == GPIO_OUT){
    gpio_put(this->pin_num, this->HIGH);
   return 0;
}

   
return -1;
}

int MY_GPIO::setLow(){
    if(this->dir == GPIO_OUT){
    gpio_put(this->pin_num, this->LOW); return 0;
}
    
    return -1;
}

int MY_GPIO::setToggle(){
    if (gpio_get(this->pin_num) == this->HIGH) {
        this->setLow();
    } else {
        this->setHigh();
    }
    return 0;
}

bool MY_GPIO::getRead(){
   
    return gpio_get(this->pin_num);
}

MY_GPIO::MY_GPIO(int pin_num) : MY_GPIO(pin_num, GPIO_OUT){}


MY_GPIO::MY_GPIO(int pin_num, bool dir)
{
    this->pin_num = pin_num;
    this->dir = dir;
    gpio_init(this->pin_num);
    gpio_set_dir(this->pin_num, this->dir);
}

MY_GPIO::~MY_GPIO()
{
}
/// LED class ///////////////////////////////////////////////////////////////////////////////////////////////////////////////

class MY_LED : public MY_GPIO
{
private:
    /* data */
public:
    
    MY_LED(int pin_num, bool dir=GPIO_OUT): MY_GPIO(pin_num, dir) {}
    ~MY_LED ();
};


MY_LED ::~MY_LED()
{
}

int main()
{
     stdio_init_all();
       printf("프로그램 시작\n");

    MY_LED led1(21, GPIO_OUT);
    MY_LED led2(22, GPIO_OUT);

    MY_LED sw1(20, GPIO_IN);

     gpio_pull_up(20);

    int state_led1 = 0;
    bool cur_sw1= 0;
    bool pre_sw1 = 0;
while (true)
{
    cur_sw1 = sw1.getRead();

    if (pre_sw1 == 0 && cur_sw1 == 1) {
        if (state_led1 == 0) {
            led1.setHigh();
            state_led1 = 1;
        } else {
            led1.setLow();
            state_led1 = 0;
        }
        sleep_ms(20);
    }

    pre_sw1 = cur_sw1;
    
}

}
