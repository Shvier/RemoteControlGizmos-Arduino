char order;
unsigned long lastTimestamp;
int currentTemperature;

int in1 = 5;
int in2 = 6;
int in3 = 9;
int in4 = 10;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

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

void handleOrders() {
  if (Serial.available()) {
    order = Serial.read();
    if (strcmp(order, 'l')) {

    } else if (strcmp(order, 'r')) {
      
    } else if (strcmp(order, 'a')) {
      
    } else if (strcmp(order, 's')) {
      
    }
  }
}

