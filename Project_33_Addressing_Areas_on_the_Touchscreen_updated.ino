// Project 33 - Addressing Areas on the Touchscreen
int x,y = 0;
int led1= 0;
int led2= 0;
int led3= 0;
 int readX() // returns the value of the touchscreen's x-axis
{
  int xr=0;
  pinMode(A0, INPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, INPUT);
  pinMode(A3, OUTPUT);
  digitalWrite(A1, LOW);  // set A1 to GND
  digitalWrite(A3, HIGH); // set A3 as 5V
  delay(5);
  xr=analogRead(0);       // stores the value of the x-axis
  return xr;

}

 int readY() // returns the value of the touchscreen's y-axis
{
  int yr=0;
  pinMode(A0, OUTPUT);
  pinMode(A1, INPUT); 
  pinMode(A2, OUTPUT);
  pinMode(A3, INPUT); 
  digitalWrite(14, LOW);  // set A0 to GND
  digitalWrite(16, HIGH); // set A2 as 5V
  delay(5);
  yr=analogRead(1);       // stores the value of the y-axis
  return yr; 
}

void setup()
{
  Serial.begin(9600);

 pinMode(2, OUTPUT);
 pinMode(3, OUTPUT);
 pinMode(4, OUTPUT);
 pinMode(5, OUTPUT);
}

void loop()
{
  Serial.print(" x = ");
  x=readX();
  Serial.print(x);
  y=readY();
  Serial.print(" y = ");
  Serial.println(y);
  delay (200);


  if ((x < 511)&&(y < 511)){
    digitalWrite (2, HIGH);
  }
  else{
    digitalWrite (2, LOW);
  }

  if ((x > 511)&&(y < 511)){
    digitalWrite (3, HIGH);
  }
  else{
    digitalWrite (3, LOW);
  }

  if ((x < 511)&&(y > 511)){
    digitalWrite (4, HIGH);
  }
  else{
    digitalWrite (4, LOW);
  }

  if (((x > 511)&&(y > 511))&&((x < 1022)&&(y < 1022))){
    digitalWrite (5, HIGH);
    Serial.println("5");
  }
  else{
    digitalWrite (5, LOW);
  }
  
}



