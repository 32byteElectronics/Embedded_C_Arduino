#define BAUD_RATE_9600_BPS  103 // 9600kps
int i = 0;
unsigned int ubrr = BAUD_RATE_9600_BPS;
unsigned char data[] = "Hello Byte Electronics  ";

void setup() {
    UBRR0H = (ubrr>>8);
    UBRR0L = (ubrr);
 
    UCSR0C = 0x06;       /* Set frame format: 8data, 1stop bit  */
    UCSR0B = (1<<TXEN0); /* Enable  transmitter                 */
 

}

void loop() {
  i = 0;
        while(data[i] != 0) /* print the String  "Hello Byte Electronics  " */
        {
          while (!( UCSR0A & (1<<UDRE0))); /* Wait for empty transmit buffer*/
          UDR0 = data[i];            /* Put data into buffer, sends the data */
          i++;                             /* increment counter           */
        }

        /* Sending '\n'  '\r' Character pair helps to format the output properly on console putty Screen */
    /*************************************************************************************************/
    /* Send "\n" Character */
     while (!( UCSR0A & (1<<UDRE0)));   /* Wait for empty transmit buffer       */
     UDR0 = '\n';             /* Put data into buffer, sends the data */
    
    /* Send "\r" Character */
    // while (!( UCSR0A & (1<<UDRE0)));   /* Wait for empty transmit buffer       */
    // UDR0 = '\r';             /* Put data into buffer, sends the data */
    /*------------------------------------------------------------------------------------------------*/
    
    _delay_ms(100);
}
