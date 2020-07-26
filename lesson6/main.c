#include "lm4f120h5qr.h"

//#define RCGCGPIO (*((unsigned int *)0x400FE608u))
//#define GPIO_BASE (*((unsigned int *)0x40025000u))
//#define GPIO_DIR (*((unsigned int *)(GPIO_BASE + 0x00000400u)))
//#define GPIO_DEN (*((unsigned int *)(GPIO_BASE + 0x0000051Cu)))
//#define GPIO_DATA (*((unsigned int *)(GPIO_BASE + 0x000003FCu)))

#define LED_RED   (1u << 1) 
#define LED_BLUE  (1u << 2)
#define LED_GREEN (1u << 3)
int main()
{
  SYSCTL_RCGCGPIO_R |= 0x20u;
  GPIO_PORTF_DIR_R |= (LED_RED | LED_BLUE | LED_GREEN);
  GPIO_PORTF_DEN_R |= (LED_RED | LED_BLUE | LED_GREEN);
  
  GPIO_PORTF_DATA_R |= LED_BLUE;
  while(1){
    GPIO_PORTF_DATA_R |= LED_RED;      //blink on
    int counter=0;
    while(counter<1000000){ //delay loop
      ++counter;
    }
    GPIO_PORTF_DATA_R &= ~LED_RED;      //blink off
    counter=0;
    while(counter<1000000){ //delay loop
        ++counter;
    }
  }
  return 0;
}
