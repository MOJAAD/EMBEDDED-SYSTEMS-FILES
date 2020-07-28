#ifndef  __DELAY_H__
#define  __DELAY_H__

void delay(int volatile iter);
void delay(int volatile iter){
  while(0<iter){ //delay loop
     --iter;
  }
}

#endif // __DELAY_H__