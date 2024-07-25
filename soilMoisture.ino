int sensor;
const int delaytime= 1000;//delay
const int redled=7; //pin_number of redLight
const int greenled=3;//pin_number of greenlight
const int thresh=850; //850 is arbitrary, this value must be calibrated for different soils
void setup(){ //this block of code is run once at the start of execution
  Serial.begin(9600);
  pinMode(redled,OUTPUT);
  pinMode(greenled,OUTPUT);
}
void loop(){//gives supply to sensor
  delay(10);//time delay to make the sensor on
  sensor=analogRead(A0);//signal sensed//made led off
  Serial.println(sensor);//gives output after knowing the moisture level
  if(sensor<thresh){
    //soil moist
    digitalWrite(redled,LOW);
    digitalWrite(greenled,HIGH);
  }
  else {//soil dry
  digitalWrite(greenled,LOW);
  digitalWrite(redled,HIGH);
  }
  delay(delaytime);
}
