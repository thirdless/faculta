#include <inavr.h>
#include <iom16.h> 
int main(void)
{
 DDRD = (1<<PD1);
 while(1)
 {
 PORTD=2;
 __delay_cycles(2000000);
 PORTD=0;
 __delay_cycles(2000000);
 }
}