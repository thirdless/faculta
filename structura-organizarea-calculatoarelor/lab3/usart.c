#include "usart.h"
void USART_initialize(unsigned short int baud_rate)
{
  /* seteazã baud rate */
  UBRRH = (unsigned char)(baud_rate >> 8);
  UBRRL = (unsigned char)(baud_rate & 0xFF);
  UCSRB = (1 << RXEN) | (1 << TXEN); /* activeazã transmisia ?i
  recep?ia la ie?ire */
  /* seteazã pinul TXD: ie?ire */
  DDRD |= (1 << PD1);
  /* seteazã pinul RXD: intrare */
  DDRD &= ~(1 << PD0);
  /* activeazã întreruperea */
  //UCSRB |= (1 << RXCIE);
}
void USART_transmit(unsigned char data)
{
  /* a?teaptã pânã ce se terminã de transmis toate datele ?i dupã trece
  la urmãtoarele informa?ii */
  static int i = 0;
  while (!( UCSRA & (1 << UDRE)))
  {
    ;
  }
  UDR = data;
  data_send[i++] = data;
}
unsigned char USART_Receive( void )
{
  /* A?teaptã recep?ionarea datelor */
  while ( !(UCSRA & (1<<RXC)) )
  {
    ;
  }
  /* Preia ?i returneazã datele recep?ionate din buffer */
  return UDR;
}
