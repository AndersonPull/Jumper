#include <SoftwareSerial.h>

SoftwareSerial bluetooth(2, 3);

int In1 = 4;
int In2 = 5;
int In3 = 6;
int In4 = 7;
char command;

void setup() 
{
  Serial.begin(9600);
  bluetooth.begin(9600);
  pinMode(In1, OUTPUT);
  pinMode(In2, OUTPUT);
  pinMode(In3, OUTPUT);
  pinMode(In4, OUTPUT);
}

void loop()
{
  while(bluetooth.available())
  {
    command = bluetooth.read();

    Serial.println(command);
    if(command == 'A') { Front();}
    else if(command == 'L'){Left();}
    else if(command == 'R'){Right();}
    else if(command == 'B'){Back();}
    else if(command == 'S'){Stopped();}
  }
}

void Right()
{
  Serial.println("Indo para frente");
  digitalWrite(In1, HIGH);
  digitalWrite(In2, LOW);
  digitalWrite(In3, LOW);
  digitalWrite(In4, HIGH);
}

void Left()
{
  Serial.println("Indo para tras");
  digitalWrite(In1, LOW);
  digitalWrite(In2, HIGH);
  digitalWrite(In3, HIGH);
  digitalWrite(In4, LOW);

}

void Front()
{
  Serial.println("Indo para esquerda");
  digitalWrite(In1, LOW);
  digitalWrite(In2, HIGH);
  digitalWrite(In3, LOW);
  digitalWrite(In4, HIGH);

}

void Back()
{
  Serial.println("Indo para direita");
  digitalWrite(In1, HIGH);
  digitalWrite(In2, LOW);
  digitalWrite(In3, HIGH);
  digitalWrite(In4, LOW);
}

void Stopped()
{
  Serial.println("Parou");
  digitalWrite(In1, LOW);
  digitalWrite(In2, LOW);
  digitalWrite(In3, LOW);
  digitalWrite(In4, LOW);
}
