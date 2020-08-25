#include<LiquidCrystal.h>
int temp=0,i=0,x=0,k=0;
char str[100],msg[32];
LiquidCrystal lcd(2,3,4,5,6,7);
 
void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
Serial.begin(9600);
lcd.setCursor(0,0);
  lcd.print("Wireless Notice");
  lcd.setCursor(0,1);
  lcd.print("Board using Bluetooth ");
  delay(2000);
  lcd.scrollDisplayLeft();
Serial.print("Enter your message\n");
 
}

void loop()    
{
  for(unsigned int t=0;t<60000;t++)
  {
    serialEvent();
  if(temp==1)
  {
    x=0,k=0,temp=0;
    while(x<i)
    {
      while(str[x]=='#')
      {
        x++;
        while(str[x]!='*')
        {
          msg[k++]=str[x++];
        }
      }
      x++;
    }
    msg[k]='\0';
    lcd.clear();
    lcd.print(msg);
    delay(1000);
    temp=0;
    i=0;
    x=0;
    k=0;
  }
  }
  lcd.scrollDisplayLeft();
}
void serialEvent()
{
  while(Serial.available())
  {
    char ch=(char)Serial.read();
    str[i++]=ch;
    if(ch == '*')
    {
      temp=1;
      lcd.clear();
      lcd.print("Message Received");
      delay(1000);
    }
  }
}
