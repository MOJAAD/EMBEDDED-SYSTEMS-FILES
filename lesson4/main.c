int main()
{
  *((unsigned int *)0x400FE608u) = 0x20u;
  *((unsigned int *)0x40025400u) = 0x0Eu;
  *((unsigned int *)0x4002551Cu) = 0x0Eu;
  while(1){
    *((unsigned int *)0x400253FCu) = 0x02u;
    int counter=0;
    while(counter<1000000){
      ++counter;
    }
    *((unsigned int *)0x400253FCu) = 0x00u;
    counter=0;
    while(counter<1000000){
        ++counter;
    }
  }
  return 0;
}
