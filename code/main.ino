#define LDR A0
#define IR 4
#define LED 5

int ldrValue;
int irValue;

void setup()
{
  pinMode(IR, INPUT);
  pinMode(LED, OUTPUT);

  Serial.begin(9600);
}

void loop()
{
  ldrValue = analogRead(LDR);   // Read light intensity
  irValue = digitalRead(IR);    // Read IR sensor

  Serial.print("LDR Value: ");
  Serial.println(ldrValue);

  if(irValue == LOW)   // Object detected (most IR sensors give LOW)
  {
      if(ldrValue < 500)   // Dark condition
      {
          analogWrite(LED,255); // LED Bright
      }
      else
      {
          analogWrite(LED,80);  // LED Dim
      }
  }
  else
  {
      analogWrite(LED,0); // LED OFF
  }

  delay(200);
}
