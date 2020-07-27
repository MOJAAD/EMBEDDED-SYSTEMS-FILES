#include "lm4f120h5qr.h"
#include "delay.h"

//#define RCGCGPIO (*((unsigned int *)0x400FE608u))
//#define GPIO_BASE (*((unsigned int *)0x40025000u))
//#define GPIO_DIR (*((unsigned int *)(GPIO_BASE + 0x00000400u)))
//#define GPIO_DEN (*((unsigned int *)(GPIO_BASE + 0x0000051Cu)))
//#define GPIO_DATA (*((unsigned int *)(GPIO_BASE + 0x000003FCu)))

#define LED_RED   (1u << 1) 
#define LED_BLUE  (1u << 2)
#define LED_GREEN (1u << 3)

unsigned fact(unsigned n);

int main()
{
  unsigned volatile x;
  x=fact(0u);
  x=2u + 3u*fact(1u);
  (void)fact(5u);
  
  SYSCTL_RCGCGPIO_R |= (1u << 5);
  SYSCTL_GPIOHBCTL_R |= (1u << 5); //enable AHB for GPIO FAST
  GPIO_PORTF_AHB_DIR_R |= (LED_RED | LED_BLUE | LED_GREEN);
  GPIO_PORTF_AHB_DEN_R |= (LED_RED | LED_BLUE | LED_GREEN);
  
  GPIO_PORTF_AHB_DATA_BITS_R[LED_BLUE] = LED_BLUE;
  while(1){
    GPIO_PORTF_AHB_DATA_BITS_R[LED_RED] = LED_RED;
    delay(1000000);
    GPIO_PORTF_AHB_DATA_BITS_R[LED_RED] = 0;
    delay(500000);
    }
  return 0;
}


unsigned fact(unsigned n){
  //0!=1u
  //n!=n*(n-1)! for n>0
  if (n==0u){
    return 1u;
  }
  else{
    return n*fact(n-1u);
  }
  
}