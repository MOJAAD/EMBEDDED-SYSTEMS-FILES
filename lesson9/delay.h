#ifndef  __DELAY_H__
#define  __DELAY_H__

void delay(int iter);
void delay(int iter){
  int volatile counter;
  counter=0;
  while(counter<iter){ //delay loop
     ++counter;
  }
}

#endif // __DELAY_H__