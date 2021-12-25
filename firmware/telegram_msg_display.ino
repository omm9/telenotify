#include "CTBot.h"

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
// Declaration for SSD1306 - SPI
#define OLED_MOSI 23
#define OLED_CLK 18
#define OLED_DC 19
#define OLED_CS 12
#define OLED_RESET 13
CTBot myBot;

String ssid = "your_wifi_name_here";
String pass = "your_wifi_pwd_here";
String token = "1978155446:CCFb98rColFDcf92BKz9EeuVDRzzYcCxtGJ";

OledDisplay oledDisplay(int screen_width, int screen_height, int oled_mosi,int oled_clk,int oled_dc, int oled_reset, int oled_cs );
void setup() {
  Serial.begin(9600);

  myBot.wifiConnect(ssid, pass);
  myBot.setTelegramToken(token);

  delay(5000);
  pinMode(2, OUTPUT);
  // Check if all things are ok
  if (myBot.testConnection()) {
    Serial.print("Telegram Bot Ready\n");
  }
  else {
    Serial.print("Connection problem\n");
  }
  // put your setup code here, to run once:
oledDisplay.init();
oledDisplay.displayTextonOLED("Connecting to WIFI");

}

void loop()
{
  TBMessage msg;

  // If there is an incoming message...
  if (myBot.getNewMessage(msg)) {
      digitalWrite(2,HIGH);
      delay(1000);
    if (msg.text == "/off") {
      if(msg.sender.id == 540135993){
        Serial.print("Om   : ");
      }else if(msg.sender.id == 1524460302){
        Serial.print("Pedda: ");
      }else if(msg.sender.id == 745440618){
        Serial.print("Uday : ");
      }else{
        Serial.print("Client ");
        Serial.print(msg.sender.id);
        Serial.print(": ");
      }

      digitalWrite(2,LOW);
      Serial.print("LED OFF ");
      Serial.write('\n');
      display.DisplayTextOnOled("LED OFF ")
    }
    else{
         
            if(msg.sender.id == 540135993){
              Serial.print("Om   : ");
            }else if(msg.sender.id == 1524460302){
              Serial.print("Pedda: ");
              }else if(msg.sender.id == 745440618){
              Serial.print("Uday : ");
              }else{
              Serial.print("Client ");
              Serial.print(msg.sender.id);
              Serial.print(": ");
              }
      Serial.print(msg.text); 
      Serial.write('\n');
      display.DisplayTextOnOled(msg.text)
      //myBot.sendMessage(msg.sender.id, "Text received.");
      //digitalWrite(2,HIGH);
      //delay(1000);
      }
  }
  

  delay(500);
}
