#include "stdint.h"
#include "lm4f120h5qr.h"
#include "delay.h"

#define LED_RED   (1u << 1) 
#define LED_BLUE  (1u << 2)
#define LED_GREEN (1u << 3)

typedef struct {
uint8_t  y;
uint16_t x;
}point;
typedef struct {
  point top_left;
  point buttom_right;
}window;
typedef struct {
  point corners[3];
}tringle;
//struct point pa,pb;
//typedef struct point point;
point pa ,pb;
window w , w2 ;
tringle t;

int main()
{
  point *pp;
  window *wp;
  
  pa.x = sizeof(point);
  pa.y = 0xAAu;
  
  w.top_left.x = 1u;
  w.buttom_right.y = 2u;

  t.corners[0].x = 0u;
  t.corners[2].y = 2u;
  
  pb = pa;
  w2 = w;
  
  pp = &pa;
  wp = &w2;
  
  (*pp).x = 1u;
  (*wp).top_left = *pp;
  
  pp->x = 1u;
  wp->top_left = *pp;
  
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