//*LCD INITIALIZATION*//
#include <LiquidCrystal.h>
const int rs=47,rw=46, en=45, d0=44, d1=43, d2=42, d3=41, d4 = 40, d5 = 39, d6 = 38, d7 = 37;
LiquidCrystal lcd(rs, rw,en,d0,d1,d2,d3, d4, d5, d6, d7);

int count;
int count1;
int count2;
int buzzer=31;
int LED1=22;
int LED2=23;
int LED3=24;

char c;

void setup(){
lcd.begin(16,2); //SELECTING LCD COLUMNS & ROWS
 Serial.begin(9600); //INITALIZING SERIAL COMMUNICATION
 Serial2.begin(9600); //INITALIZING BLUETOOTH SERIAL COMMUNICATION
  pinMode(LED1,OUTPUT); //DIFINING LED1 AS OUTPUT DEVICE
  pinMode(LED2,OUTPUT); //DIFINING LED21 AS OUTPUT DEVICE
  pinMode(LED3,OUTPUT); //DIFINING LED21 AS OUTPUT DEVICE
  pinMode(buzzer,OUTPUT); //DIFINING BUZZER AS OUTPUT DEVICE
  digitalWrite(LED1,HIGH); //INITIALIZING LED1 OFF
  digitalWrite(LED2,HIGH); //INITIALIZING LED2 OFF
  digitalWrite(LED3,HIGH); //INITIALIZING LED2 OFF
  lcd.write("PLZ SET TIMER");
  lcd.setCursor(0,1);
  lcd.write("USING BLUETOOTH");
  }
void loop(){
  lcd.noDisplay();
  delay(500);
  lcd.display();
here: lcd.clear(); 
lcd.write("! SET TIMER !");
  lcd.setCursor(0,1);
  lcd.write("USING BLUETOOTH");
  delay(500);
  if (Serial2.available()){  //IF BLUETOOTH IS CONNECTED  
  c=Serial2.read();    //SERIALLY READ FROM BLUETOOTH IS 'c'
  }
  if(c=='1')
  {
  for(count=10;count>=0;count--){
    digitalWrite(LED1,LOW);
    lcd.clear();
    lcd.print(count);
    lcd.setCursor(0,1);
    lcd.print("! START STRECH !");
    delay(1000);
    }
    digitalWrite(LED1,HIGH);
    lcd.clear();
    lcd.print("!! STOP !!");
    digitalWrite(buzzer,HIGH);
    delay(500);
    digitalWrite(buzzer,LOW);
    goto here; 
    }
    if(c=='2'){
    for(count1=20;count1>=0;count1--)
    {
      digitalWrite(LED2,LOW);
      lcd.clear();
      lcd.print(count1);
      lcd.setCursor(0,1);
      lcd.print("! JUMPING JACK !");
      delay(1000);
    }
    digitalWrite(LED2,HIGH);
    lcd.clear();
    lcd.print("!! STOP !!");
    digitalWrite(buzzer,HIGH);
    delay(500);
    digitalWrite(buzzer,LOW);
    goto here; 
    }
    if(c=='3'){
    for(count2=30;count2>=0;count2--)
    {
      digitalWrite(LED3,LOW);
      lcd.clear();
      lcd.print(count2);
      lcd.setCursor(0,1);
      lcd.print("! SQUATS !");
      delay(1000);
    }
    digitalWrite(LED3,HIGH);
    lcd.clear();
    lcd.print("!! STOP !!");
    digitalWrite(buzzer,HIGH);
    delay(500);
    digitalWrite(buzzer,LOW);
    goto here; 
    }}
/*else
  {
   lcd.clear();
   lcd.write("WRONG INPUT"); //LCD OUTPUT
   Serial2.println("WRONG INPUT,PLZ CHECK & REENTER");
  digitalWrite(LED1,HIGH); //LED1 OFF
  digitalWrite(LED2,HIGH);   //LED2 OFF
  digitalWrite(LED3,HIGH);  //LED3 OFF
  }}*/
