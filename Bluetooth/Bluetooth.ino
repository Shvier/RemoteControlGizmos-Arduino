char currentOrder;
char lastOrder;
unsigned long lastTimestamp;
int currentTemperature;

int in1 = 5;
int in2 = 6;
int in3 = 9;
int in4 = 10;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  currentOrder = '\0';
  lastOrder = '\0';
  currentTemperature = 0;
  lastTimestamp = millis();

  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  checkTemperature();
  handleOrders();
}

void checkTemperature() {
  if (millis() - lastTimestamp > 5000) {
    currentTemperature = analogRead(A0);
    int val = analogRead(A0);
    int t = (125*val) / 256;
    Serial.println(t);
    lastTimestamp = millis();
  }  
}

void accelerate() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void slowDown() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void turnLeft() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void turnRight() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void dontMove() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void changeState() {
  if (currentOrder == 'l') {
    Serial.print("-------");
    Serial.println(currentOrder);  
    turnLeft();
  } else if (currentOrder == 'r') {
    Serial.print("-------");
    Serial.println(currentOrder);  
    turnRight();
  } else if (currentOrder == 'a') {
    Serial.print("-------");
    Serial.println(currentOrder);
    accelerate();
  } else if (currentOrder == 'b') {
    Serial.print("-------");
    Serial.println(currentOrder);
    slowDown();
  } else if (currentOrder == 's') {
    Serial.print("-------");
    Serial.println(currentOrder);
    dontMove();
  }
}

void handleOrders() {
  if (Serial.available()) {
    currentOrder = Serial.read();
    Serial.print("New Order - ");
    Serial.println(currentOrder);
    if (currentOrder != lastOrder) {
      Serial.println("Now Change");
      changeState();
      lastOrder = currentOrder;
    }
  }
}

