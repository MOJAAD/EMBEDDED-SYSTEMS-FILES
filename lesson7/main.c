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
  SYSCTL_RCGCGPIO_R |= (1u << 5);
  SYSCTL_GPIOHBCTL_R |= (1u << 5); //enable AHB for GPIO FAST
  GPIO_PORTF_AHB_DIR_R |= (LED_RED | LED_BLUE | LED_GREEN);
  GPIO_PORTF_AHB_DEN_R |= (LED_RED | LED_BLUE | LED_GREEN);
  
  //GPIO_PORTF_DATA_R |= LED_BLUE;
  GPIO_PORTF_AHB_DATA_BITS_R[LED_BLUE] = LED_BLUE;
  while(1){
    //GPIO_PORTF_DATA_R |= LED_RED;      //blink on
    //*((unsigned long volatile *)(0x40025000 + (LED_RED << 2))) = LED_RED;
    //*(GPIO_PORTF_DATA_BITS_R + LED_RED) = LED_RED;
    GPIO_PORTF_AHB_DATA_BITS_R[LED_RED] = LED_RED;
    int volatile counter[2]={0,0};
    while(counter[0]<1000000){ //delay loop
      ++counter[0];
    }
    //GPIO_PORTF_DATA_R &= ~LED_RED;      //blink off
    GPIO_PORTF_AHB_DATA_BITS_R[LED_RED] = 0;
    //counter=0;
    while(*(counter+1)<1000000){ //delay loop
        ++counter[1];
    }
  }
  return 0;
}
