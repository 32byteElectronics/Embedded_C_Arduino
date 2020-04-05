const int led = PB5;//Built-in Led D13.

void setup() {
  
DDRB |=(1<<led); // configure PB5 as an output.
}

void loop() { 
  PORTB |=(1<<led);      //High
  _delay_ms(500);        // delay(500);
  PORTB &= ~(1<<led);    //Low
  delay(500);
}
