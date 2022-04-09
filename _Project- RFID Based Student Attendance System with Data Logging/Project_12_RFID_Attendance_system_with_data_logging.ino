
//*LCD INITIALIZATION*//
#include <LiquidCrystal.h>
const int rs=47,rw=46, en=45, d0=44, d1=43, d2=42, d3=41, d4 = 40, d5 = 39, d6 = 38, d7 = 37;
LiquidCrystal lcd(rs, rw,en,d0,d1,d2,d3, d4, d5, d6, d7);

int j=0;
int i=0;
int buzzer=31;
int LED1=22;

//*RFID INITIALIZATION*//
char b[12];
char Rahul[12]={'0','8','0','0','F','0','5','4','B','2','1','E'};
char Reshma[12]={'0','8','0','0','C','7','9','8','0','4','5','3'};
int count=0;

//*MOTOR INITIALIZATION*//
int Motor1=33;
int Motor2=34;

void setup() {
 lcd.begin(16,2); //SELECTING LCD COLUMNS & ROWS
 Serial.begin(9600);//INITALIZING SERIAL COMMUNICATION
 Serial2.begin(9600);//INITALIZING BLUETOOTH SERIAL COMMUNICATION
 Serial3.begin(9600); //INITALIZING RFID SERIAL COMMUNICATION
 pinMode(Motor1,OUTPUT); //DIFINING MOTOR1 AS OUTPUT DEVICE
 pinMode(Motor2,OUTPUT); //DIFINING MOTOR2 AS OUTPUT DEVICE
 pinMode(LED1,OUTPUT); //DIFINING LED1 AS OUTPUT DEVICE
 pinMode(buzzer,OUTPUT); //DIFINING BUZZER AS OUTPUT DEVICE
 digitalWrite(LED1,HIGH); //INITIALIZING LED1 OFF
 digitalWrite(Motor1,LOW); //INITIALIZING MOTOR1 OFF
 digitalWrite(Motor2,LOW); //INITIALIZING MOTOR2 OFF
 Serial.println("CLEARDATA");
 Serial.println("LABEL,Time,Date,Student Name,");
 Serial.println("RESTTIMER");
 while(j!=5){
 lcd.noDisplay(); 
 delay(500);
 lcd.display();
 delay(500);
 lcd.print("!! ATTENDANCE !!");
 lcd.setCursor(0,1);
 lcd.print("! SCAN YOUR CARD !");
 j++;
 }}
  
void loop() {
   
   if (Serial3.available()){  //IF RFID TAG IS AVAILABLE TO SCAN  
  b[count]=Serial3.read();    //SCAN THE TAG AND STORE THE VALUE IN ARRAY 'b'
  count++;
  }
  if(count==12)       //IF SCANNED ARRAY VALUE IS OF 12 DIGITS ENTER IN THE LOOP
  {
  if(strncmp(b,Rahul,12) ==0)  //COMPARING STRING BETWWEN STORED AND SCANNED VALUE 
  {
  lcd.clear();   //MAKING LCD CLEAR FOR PRINTING
  lcd.write("Access Granted"); //LCD OUTPUT
  delay(500);
  digitalWrite(LED1,LOW);   //LED1 ON
  digitalWrite(buzzer,HIGH);  //BUZZER ON
  delay(500);
  digitalWrite(LED1,HIGH);  //LED1 OFF
  digitalWrite(buzzer,LOW); //BUZZER OFF
  Serial.println("DATA,TIME,DATE,Rahul,");
  Serial.println(b[count]);
  delay(1000);
  Serial2.println("RAHUL PRESENT");  //PRINTING OUTPUT ON BLUETOOTH TERMINAL THROUGH BLUETOOTH 
  lcd.clear();
  lcd.write("WELCOME RAHUL");
  delay(500);
  digitalWrite(Motor1,HIGH); //MOTOR1 ON
  delay(1000);
  digitalWrite(Motor1,LOW); //MOTOR1 OFF
  count=0;}
  
  else if (strncmp(b,Reshma,12)==0) //COMPARING STRING BETWWEN STORED AND SCANNED VALUE
  { 
    lcd.clear();   //MAKING LCD CLEAR FOR PRINTING
  lcd.write("Access Granted"); //LCD OUTPUT
  delay(500);
  digitalWrite(LED1,LOW);   //LED1 ON
  digitalWrite(buzzer,HIGH);  //BUZZER ON
  delay(500);
  digitalWrite(LED1,HIGH);  //LED1 OFF
  digitalWrite(buzzer,LOW); //BUZZER OFF
  Serial.println("DATA,TIME,DATE,Reshma,");
  delay(1000);
  Serial2.println("RESHMA PRESENT");  //PRINTING OUTPUT ON BLUETOOTH TERMINAL THROUGH BLUETOOTH 
  lcd.clear();
  lcd.write("WELCOME RESHMA");
  digitalWrite(Motor1,HIGH); //MOTOR1 ON
  delay(1000);
  digitalWrite(Motor1,LOW); //MOTOR1 OFF
  count=0;
  }else
  {lcd.clear();
  lcd.write("Access Denied"); //IF TAG READ VALUE IS MISMATCH, PRINT THIS ON LCD
count=0;}
  count=0;}} //RESETTING THE COUNT=0 FOR THE NEXT SCAN & STORE
