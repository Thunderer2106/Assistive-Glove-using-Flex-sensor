#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"
#include<LiquidCrystal.h>



LiquidCrystal lcd(12,11,5,8,4,7);

// Use pins 2 and 3 to communicate with DFPlayer Mini
static const uint8_t PIN_MP3_TX = 2; // Connects to module's RX 
static const uint8_t PIN_MP3_RX = 3; // Connects to module's TX 

SoftwareSerial softwareSerial(PIN_MP3_RX, PIN_MP3_TX);
 int flexVal,prev=-1,chk,val;

// Create the Player object
DFRobotDFPlayerMini Player;

void setup() {

  // Init USB serial port for debugging
  Serial.begin(9600);
  // Init serial port for DFPlayer Mini
  softwareSerial.begin(9600);
  Player.begin(softwareSerial);



  analogWrite(6,20);
  lcd.begin(16,2);
  
  
}
int vol=30;
void loop() {
 
  flexVal=analogRead(A0);
  if(flexVal==0){
    val=0;
  }

  if(flexVal<150){
    val=1;
  }

  else{
    val=2;
  }
  Serial.println("reading");
  Serial.print(flexVal);
  if(prev==-1){
    prev=val;
    chk=1;
  }
  else if(prev!=val){
    chk=1;
  }

  else{
    chk=1;
  }
  if(chk){
  if(flexVal==0){
    Player.volume(vol);
     Player.play(1);
     Serial.println("0 value");
     lcd.setCursor(0,0);
     lcd.print("need water");
     delay(5000);
    
  }
  

  else if (flexVal<150) {
     Serial.println("below 150 and above 0");
     Player.volume(vol);
     Player.play(2);
     lcd.setCursor(0,0);
     lcd.print("time");
     delay(5000);
     
  }
  else{
    Serial.println("third case");
     Player.volume(vol);
     Player.play(3);
     lcd.setCursor(0,0);
     lcd.print("help");
     delay(5000);
  }
  }
  
  

}
//
//#include<LiquidCrystal.h>
//
//LiquidCrystal lcd(12,11,5,8,4,7); //4 3 2 
//
//void setup(){
//  analogWrite(6,20);
//  lcd.begin(16,2);
//}
//
//void loop(){
//  lcd.setCursor(0,0);
//  lcd.print("1234");
//  delay(5000);
//}
