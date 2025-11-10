// C++ code
//
#include <stdlib.h>

#define BTN 12
#define LEDR 9
#define LEDG 5

int RandNum = 0;
int Increase = 0;

int val = 0;

int stop = 0;

int btn_pressed = 0; 

void setup()
{
  Serial.begin(9600);
  
  pinMode(BTN, INPUT);
  pinMode(LEDR, OUTPUT);
  pinMode(LEDG, OUTPUT);
}

void blinkLEDs()
{
  for(int i = 0; i < 2; i++)
  {
    digitalWrite(LEDG, HIGH);
    digitalWrite(LEDR, HIGH);
    delay(100);
    digitalWrite(LEDG, LOW);
    digitalWrite(LEDR, LOW);
    delay(100);
  }
}

void loop()
{
  if(stop == 0)
  {
    RandNum = rand() % 10;
    if(val >= 0 && val <= 5)
    {
      Serial.println(RandNum);

      if(RandNum > 6)
      {
        digitalWrite(LEDR, HIGH);
        digitalWrite(LEDG, LOW);

        Increase = 0;
      }
      else if(RandNum <= 6)
      {
        digitalWrite(LEDG, HIGH);
       // delay(100);
        digitalWrite(LEDR, LOW);

        Increase = 1;
      }
      
      if(digitalRead(BTN) == 1 && btn_pressed == 0)
      {
        btn_pressed = 1;
      }
      else if(digitalRead(BTN) == 0 && btn_pressed == 1)
      {
        btn_pressed = 0;
      }

      delay(10);

      if(btn_pressed == 1)
        {
          if(Increase == 1)
          {
            val++;
          }
          else 
          {
            val--;
          }
          delay(200);
        }

      Serial.print("Pontuacao: ");
      Serial.print(val);
      Serial.print("\n");
    }
    else if(val > 5)
    {
      Serial.println("Ganhou");
      blinkLEDs();
      stop = 1;
    }
    else if(val < 0)
    {
      Serial.println("Perdeu");
      blinkLEDs();
      
      stop = 1;
    }
    delay(1000);
  }
  if(stop == 1 && digitalRead(BTN) == 1)
  {
    stop = 0;
    val = 0;
    blinkLEDs();
  }
  
}