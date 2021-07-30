//pin 2 for motion sensor
//pin 13 for LED
//as 8 bit ints
const uint8_t MTN_PIN = 2;
const uint8_t LED_PIN = 13;



void setup()
{
  //motion sensor as input
  pinMode(MTN_PIN, INPUT);
  //LED as output
  pinMode(LED_PIN, OUTPUT);
  //Start serial monitor
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(MTN_PIN),my_isr,CHANGE);
}


void loop()
{
}


void my_isr()
{
  digitalWrite(LED_PIN, digitalRead(MTN_PIN));
  Serial.print("LED is ");
  Serial.println(digitalRead(MTN_PIN));
}

