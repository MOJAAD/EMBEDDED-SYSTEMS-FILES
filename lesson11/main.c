#include "stdint.h"
#include "lm4f120h5qr.h"
#include "delay.h"

#define LED_RED   (1u << 1) 
#define LED_BLUE  (1u << 2)
#define LED_GREEN (1u << 3)

uint8_t  u8a , u8b;
uint16_t u16c,u16d;
uint32_t u32e,u32f;

int8_t  s8;
int16_t s16;
int32_t s32;


int main()
{
  u8a  = sizeof(u8a);
  u16c = sizeof(uint16_t);
  u32e = sizeof(uint32_t);
  
  u8a  = 0xa1u;
  u16c = 0xc1c2u;
  u32e = 0xe1e2e3e4u; 
  
  u8b  = u8a;
  u16d = u16c;
  u32f = u32e;
  
  u16c = 40000u;
  u16d = 30000u;
  u32e = (uint32_t)u16c + u16d;
  
  u16c = 100u;
  s32  = 10 - (int16_t)u16c;
  
  if ((int32_t)u32e > -1){
    u8a = 1u;
  }
  else{
    u8a = 0u;
  }
  
  u8a = 0xffu;
  if (~u8a ==0x00u){
    u8b = 1u;
  }
  
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