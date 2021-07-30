// C++ code
//

const byte LED_PIN = 13;
const byte METER_PIN = A4;
double timerFrequency;

void setup()
{
  pinMode(LED_PIN, OUTPUT);
  pinMode(METER_PIN, INPUT);
      
  Serial.begin(9600);
  //timerFrequency = 0.5;
  //attachInterrupt(METER_PIN, reading, CHANGE);
  //startTimer(timerFrequency);
}

void loop()
{ 
  timerFrequency = analogRead(METER_PIN);
  if (timerFrequency != analogRead(METER_PIN))
  {
    startTimer(timerFrequency);
  }
}



void startTimer(double timerFrequency){
  noInterrupts();
  //double timerFrequency
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1 = 0;
  
  //timerFrequency = analogRead(METER_PIN);
  Serial.println(timerFrequency);
  //0.5Hz = (16000000/(31250 * 1024)
  
  //timer compare
  int hertz = (160000000/timerFrequency)/1024;
  //int hertz = 31250;
  OCR1A = hertz;
    
  //prescaler 1024
  TCCR1B |= (1 << CS12) | (1 << CS10);
  
  //Output compare Match interupt enable
  TIMSK1 |= (1 << OCIE1A);
    
  //CTC
  TCCR1B |= (1 << WGM12);
  
  
  interrupts();
  
}

void reading(){
  timerFrequency = analogRead(METER_PIN);
  Serial.print("in reading");
  startTimer(timerFrequency);
}

ISR(TIMER1_COMPA_vect){
      digitalWrite(LED_PIN, digitalRead(LED_PIN) ^ 1);
}
