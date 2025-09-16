// C++ code
//


#include<Keypad.h>
const byte Rows=4;
const byte Cols=3;

char keys[Rows][Cols]={
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
byte rowPins[Rows]={9,8,7,6};
byte colPins[Cols]={5,4,3};

Keypad keypad=Keypad(makeKeymap(keys),rowPins,colPins,Rows,Cols);
    
void setup()
{
  Serial.begin(9600);
}

void loop()
{
 char key=keypad.getKey();
  if(key){
    Serial.println(key);
  }
 
}