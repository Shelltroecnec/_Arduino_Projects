//*LCD INITIALIZATION*//
#include <LiquidCrystal.h>
const int rs=47,rw=46, en=45, d0=44, d1=43, d2=42, d3=41, d4 = 40, d5 = 39, d6 = 38, d7 = 37;
LiquidCrystal lcd(rs, rw,en,d0,d1,d2,d3, d4, d5, d6, d7);

int j=0;
int i=0;
int buzzer=31;
int LED1=22;
int LED2=23;
//*BLUETOOTH INITIALIZATION*//
char c[4];
int count1=0;
char a[4]={'0','7','0','1'};
//*RFID INITIALIZATION*//
char input[12]={'5','4','0','0','6','A','E','C','7','4','A','6'};
char b[12];
int count=0;

//*MOTOR INITIALIZATION*//
int Motor1=33;
int Motor2=34;

void setup() {
 lcd.begin(16,2); //SELECTING LCD COLUMNS & ROWS
 Serial.begin(9600); //INITALIZING SERIAL COMMUNICATION
 Serial2.begin(9600); //INITALIZING BLUETOOTH SERIAL COMMUNICATION
 Serial3.begin(9600); //INITALIZING RFID SERIAL COMMUNICATION
 pinMode(Motor1,OUTPUT); //DIFINING MOTOR1 AS OUTPUT DEVICE
 pinMode(Motor2,OUTPUT); //DIFINING MOTOR2 AS OUTPUT DEVICE
  pinMode(LED1,OUTPUT); //DIFINING LED1 AS OUTPUT DEVICE
  pinMode(LED2,OUTPUT); //DIFINING LED21 AS OUTPUT DEVICE
  pinMode(buzzer,OUTPUT); //DIFINING BUZZER AS OUTPUT DEVICE
  digitalWrite(LED1,HIGH); //INITIALIZING LED1 OFF
  digitalWrite(LED2,HIGH); //INITIALIZING LED2 OFF
  digitalWrite(Motor1,LOW); //INITIALIZING MOTOR1 OFF
  digitalWrite(Motor2,LOW); //INITIALIZING MOTOR2 OFF
  while(i!=3){              //MAKING MSG BLINK FOR 3 TIMES
  lcd.noDisplay(); 
delay(500);
lcd.display();
  lcd.print("! RFID BANK ! ");
  lcd.setCursor(0,1);
  lcd.print("SCAN YOUR CARD ");
  delay(500);
  i++;
}}

void loop() {
   if (Serial3.available()){  //IF RFID TAG IS AVAILABLE TO SCAN  
  b[count]=Serial3.read();    //SCAN THE TAG AND STORE THE VALUE IN ARRAY 'b'
  count++;
  }
  if(count==12)       //IF SCANNED ARRAY VALUE IS OF 12 DIGITS ENTER IN THE LOOP
  {
  if(strncmp(b,input,12)==0)  //COMPARING STRING BETWWEN STORED AND SCANNED VALUE 
  {
   lcd.clear();   //MAKING LCD CLEAR FOR PRINTING
  lcd.write("Access Granted"); //LCD OUTPUT
  delay(500);
  digitalWrite(LED1,LOW);   //LED1 ON
  digitalWrite(buzzer,HIGH);  //BUZZER ON
  delay(500);
  digitalWrite(LED1,HIGH);  //LED1 OFF
  digitalWrite(buzzer,LOW); //BUZZER OFF
  
  Serial2.println("PLEASE ENTER PASSCODE THROUGH MOBILE");  //PRINTING OUTPUT ON BLUETOOTH TERMINAL THROUGH BLUETOOTH 
  lcd.clear();
  lcd.write("ENTER PASSWORD");
  while(count1!=4){
  if (Serial2.available()){
  c[count1]=Serial2.read(); //READ THE VALUE THROUGH BLUETOOTH AND STORE IN STRING 'c'
  Serial.println(c[count1]);
  count1++;

  }}
  if(count1==4)
  { //IF THE EBTERD PASSWORD IS EQAUL TO 4, THEN ENTER
  if (strncmp(c,a,4)==0) //COMPARING STRING BETWWEN STORED AND SCANNED VALUE
  { lcd.clear();
    lcd.write("WELCOME SIR"); //LCD FINAL OUTPUT
    Serial2.println("WELCOME SIR"); //BLUETOOTH PRINT ON TERMINAL
    digitalWrite(Motor1,HIGH); //MOTOR1 ON
    delay(1000);
    digitalWrite(Motor1,LOW); //MOTOR1 ON
    digitalWrite(Motor2,HIGH); //MOTOR2 ON
    delay(1000);
    digitalWrite(Motor2,LOW); //MOTOR2 OFF
    digitalWrite(LED2,LOW); //LED2 ON
    delay(500);
    digitalWrite(LED2,HIGH);  //LED2 OFF
    count1=0; //RESETTING THE COUNT1=0 FOR PASSWORD ENTERING
  }
  else{lcd.clear();
  lcd.write("WRONG PASSWORD");  //IF ENTERED PASSWORD IN INCORRECT, PRINT ON LCD 
  Serial2.println("WRONG PASSWORD");  //IF ENTERED PASSWORD IN INCORRECT, PRINT ON BLUETOOTH TERMINAL
  count1=0;}
  }
  count=0;} //RESETTING THE COUNT=0 FOR THE NEXT SCAN & STORE
  else
  {lcd.clear();
  lcd.write("Access Denied"); //IF TAG READ VALUE IS MISMATCH, PRINT THIS ON LCD
count=0;}}}
    
