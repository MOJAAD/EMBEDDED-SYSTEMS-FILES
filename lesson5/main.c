//include "lm4f120h5qr.h"     (i don't have board!)

#define RCGCGPIO (*((unsigned int *)0x400FE608u))
#define GPIO_BASE (*((unsigned int *)0x40025000u))
#define GPIO_DIR (*((unsigned int *)(GPIO_BASE + 0x00000400u)))
#define GPIO_DEN (*((unsigned int *)(GPIO_BASE + 0x0000051Cu)))
#define GPIO_DATA (*((unsigned int *)(GPIO_BASE + 0x000003FCu)))


int main()
{
  RCGCGPIO = 0x20u;
  GPIO_DIR = 0x0Eu;
  GPIO_DEN = 0x0Eu;
  while(1){
    GPIO_DATA = 0x02u;      //blink on
    int counter=0;
    while(counter<1000000){ //delay loop
      ++counter;
    }
    GPIO_DATA = 0x00u;      //blink off
    counter=0;
    while(counter<1000000){ //delay loop
        ++counter;
    }
  }
  return 0;
}
