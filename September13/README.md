## Documentation of motor homework
#### CODE
```
const int in1Pin = 7;
const int in2Pin = 6;
const int in3Pin = 5;
const int in4Pin = 4;

int x = 0;
void setup() {
  // put your setup code here, to run once:
pinMode(4, OUTPUT);
pinMode(5, OUTPUT);
pinMode(6, OUTPUT);
pinMode(7, OUTPUT);
pinMode(2,INPUT);
Serial.begin(9600);


}

void loop() {

 x = digitalRead(2);

if ( x == 1){  
digitalWrite(5, HIGH);
digitalWrite(4,LOW);

digitalWrite(6,LOW);
digitalWrite(7,HIGH);

}
if (x == 0){
  digitalWrite(5, LOW);
digitalWrite(4,LOW);

digitalWrite(6,LOW);
digitalWrite(7,LOW);

  
  }


}
```

[Video](https://drive.google.com/file/d/1rOAKjHJomB9qeYAhXOS_HO2dWveifDUg/view?usp=sharing)
