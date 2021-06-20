#define alpha1 0.1
#define alpha2 0.3

#define base 150

#define R2 9
#define R1 6
#define L1 5
#define L2 3
#define BM 2 

float lr = 0.0, rr = 0.0,  lf01 = 0.0, lf02 = 0.0, rf01 = 0.0, rf02 = 0.0;
void setup()
{
  pinMode(A0, INPUT_PULLUP);
  
  pinMode(BM, OUTPUT);
  digitalWrite(BM, LOW);
  
  pinMode (R1, OUTPUT);
  pinMode (R2, OUTPUT);
  pinMode (L1, OUTPUT);
  pinMode (L2, OUTPUT);

  Serial.begin(38400);

  for(;;)
  {
    digitalWrite(BM, HIGH);
    
    if(analogRead(A0)<300)
    {
    back();
    delay(1000);

    right();
    delay(1000);
    }

    forward();
    
    //Serial.println(analogRead (A0));
  }
}

void loop()
{  
  lr = analogRead(A0);
  
  lf01 = (alpha1 * lr) + (1 - alpha1) * lf01;
  lf02 = (alpha2 * lf01) + (1 - alpha2) * lf02;
  rf01 = (alpha1 * rr) + (1 - alpha1) * rf01;
  rf02 = (alpha2 * rf01) + (1 - alpha2) * rf02;

  /*
   *Uncomment these to calibrate your robot according to the sensor readings and change the values below given for Alnitak according to your requirements 
  Serial.print(lr);
  Serial.print(" ");
  Serial.print(lf01);
  Serial.print(" ");
  Serial.print(lf02);
  Serial.print(" ");
  Serial.println(rf02);*/
  
  {
  if(lf02<250 && rf02>500)
  left();
  if(rf02<300 && lf02>600)
  right();
  if(lf02<=420 && rf02<=450)
  forward();
  }
  if(lf02>420 && rf02>450)
  stop();
}


void forward()
{analogWrite (L1, base);
digitalWrite (L2, LOW);
digitalWrite (R2, LOW);
analogWrite(R1, base);
  }

void back()
{analogWrite (L2, base);
digitalWrite (L1, LOW);
digitalWrite (R1, LOW);
analogWrite(R2, base);
  }

void right()
{analogWrite (L1, base);
digitalWrite (L2, LOW);
analogWrite (R2, base);
digitalWrite (R1, LOW);
  }

void left()
{
digitalWrite (L1, LOW);
analogWrite (L2, base);
digitalWrite (R2, LOW);
analogWrite (R1, base);
}

void stop()
{
  analogWrite (L1, 255);
  analogWrite (L2, 255);
  analogWrite (R2, 255);
  analogWrite (R1, 255);
}
