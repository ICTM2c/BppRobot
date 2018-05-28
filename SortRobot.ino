// COM7

const int PIN_ENGINE_1_SPEED = 6;
const int PIN_ENGINE_1_DIRECTION = 7;
const int PIN_ENGINE_2_SPEED = 5;
const int PIN_ENGINE_2_DIRECTION = 4;

void setup() {
  pinMode(PIN_ENGINE_1_SPEED, OUTPUT);
  pinMode(PIN_ENGINE_1_DIRECTION, OUTPUT);
  pinMode(PIN_ENGINE_2_SPEED, OUTPUT);
  pinMode(PIN_ENGINE_2_DIRECTION, OUTPUT);
  
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  char direction = Serial.read();

  
  if (direction == 'l') {
    Serial.println("LEFT");
    digitalWrite(PIN_ENGINE_2_DIRECTION, HIGH);
    digitalWrite(PIN_ENGINE_1_DIRECTION, LOW);
  }
  else if (direction == 'r') {
    Serial.println("RIGHT");
    digitalWrite(PIN_ENGINE_2_DIRECTION, LOW);
    digitalWrite(PIN_ENGINE_1_DIRECTION, HIGH);
  }
  else {
    return;
  }
  Serial.println((String)direction);

  analogWrite(PIN_ENGINE_1_SPEED, 255);
  analogWrite(PIN_ENGINE_2_SPEED, 255);
  delay(2000);
  analogWrite(PIN_ENGINE_1_SPEED, 0);
  analogWrite(PIN_ENGINE_2_SPEED, 0);
  Serial.print("done");
}