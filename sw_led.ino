const int led = PB5; //D13 Arduino Pin
const int sw = PD2; //D2 Arduino Pin
int sw_val;

void setup() {  
DDRB |=(1<<led);// DDRB = DDRB | (1<<led); configure PB5 as output
DDRD &= ~(1<<sw); // DDRD = DDRD & (~(1<<2)); configure PD2 as nput
PORTD |=(1<<sw); // enable the pullup resitor

}

void loop() {
 sw_val = PIND & (1<<2);
  if(sw_val==0){
  
  PORTB |=(1<<led);
}
else{
  PORTB &=~(1<<led);
}
}
