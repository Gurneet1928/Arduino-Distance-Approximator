
// -------------------------Distance Approximater using Arudino Ultrasonic Sensor and LEDs----------------
// By : Gurneet Singh
// Materials Used:
// 1. 10 LEDS
// 2. Ultrsonic Sensor
// 3. Resistors
// 4. Jumper Wires and Breadboards

#define echoPin 2 // D2 to Echo
#define trigPin 3 //D3 to trig
int led_pins[] = {13,12,11,10,9,8,7,6,5,4}; // Array of 10Pins as output to LED
int high_pins = 0; // Count of High/On Pins
int low_pins = 10; // Count of Low/Off Pins
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  for(int i=0;i<9;i++){
    pinMode(led_pins[i],OUTPUT);  // Sets all the LED pins as OUTPUT
  }
  Serial.begin(9600); 
  Serial.println("Ultrasonic Sensor HC-SR04 and LED Distance Apporximater");
}
void loop() {
  digitalWrite(trigPin, LOW);
  digitalWrite(trigPin, HIGH);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;  // Distance formula 
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm"); 

  // Below are a lot of IF-ELSE which decide on the basis of the distance, how much LEDs need to glow
  if(distance > 0 && distance <= 5){
    high_pins = 10;
    }
  else if(distance <= 9){
    high_pins = 9;
    }   
  else if(distance <= 14){
    high_pins = 8;
    }   
  else if(distance<=18){
    high_pins = 7;
    }
    else if(distance<=22){
    high_pins = 6;
    }
    else if(distance<=26){
    high_pins = 5;
    }
    else if(distance<=30){
    high_pins = 4;
    }
    else if(distance<=34){
    high_pins =3;
    }
    else if(distance <=38){
      high_pins = 2;}
     else if(distance <=43){
     high_pins = 1;
     }
     else {
      high_pins = 0;
      }
    for(int i=0;i<=high_pins;i++){
      digitalWrite(led_pins[i],HIGH);   // Loop to set the led pins to HIGH
      }
     for(int j=high_pins;j<11;j++){
      digitalWrite(led_pins[j],LOW);   // Loop to set the led pins to LOW
      }
}
