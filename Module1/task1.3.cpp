//pin 2 for motion sensor
//pin 13 for LED
//as 8 bit ints
const uint8_t MTN_PIN = 2;
const uint8_t LED_PIN = 13;
const uint8_t RED_LED_PIN = 10;
const uint8_t USD_PIN = 3;
volatile byte r,b = 0;

void setup()
{
  //motion sensor as input
  pinMode(MTN_PIN, INPUT);
  //blue LED as output
  pinMode(LED_PIN, OUTPUT);
  //USD sensor as input
  pinMode(USD_PIN, INPUT);
  //red LED as output
  pinMode(RED_LED_PIN, OUTPUT);
  //Start serial monitor
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(MTN_PIN),my_isr,CHANGE);
  attachInterrupt(digitalPinToInterrupt(USD_PIN),my_isr,CHANGE);
}


void loop()
{
  digitalWrite(LED_PIN,b);
  digitalWrite(RED_LED_PIN,r);
}


void my_isr()
{
  b = digitalRead(MTN_PIN);
  r = digitalRead(USD_PIN);
  Serial.print("blue LED is :");
  Serial.println(b);
  Serial.print("red LED is :");
  Serial.println(r);
}


