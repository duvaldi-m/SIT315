
//pin 2 for motion sensor
//pin 13 for LED
//as 8 bit ints
const uint8_t MTN_PIN = 2;
const uint8_t LED_PIN = 13;

//initial state of LED off
uint8_t motionState = LOW;
uint8_t ledState = LOW;

//Initail setup
void setup()
{
  //motion sensor as input
  pinMode(MTN_PIN, INPUT);
  //LED as output
  pinMode(LED_PIN, OUTPUT);
  //Start serial monitor
  Serial.begin(9600);
}

void loop()
{
  //take reading from motion sensor on pin 2
  uint8_t motionState = digitalRead(MTN_PIN);
  
  //print readings
  Serial.print(motionState);
  Serial.print(ledState);
  Serial.println("");
  
  
  //When motion is detected LED will go on and 
  //stay on until motion stops
  while(motionState == HIGH)
  {
    
    digitalWrite(LED_PIN, HIGH);
    Serial.print("motion sensor activated, LED on");
    Serial.print(motionState);
    Serial.println("");
    motionState = digitalRead(MTN_PIN);
  }
  
  digitalWrite(LED_PIN, LOW);
 
    

}