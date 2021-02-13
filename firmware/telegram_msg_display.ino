#include "CTBot.h"
CTBot myBot;

String ssid = "your_wifi_name_here";
String pass = "your_wifi_pwd_here";
String token = "1978155446:CCFb98rColFDcf92BKz9EeuVDRzzYcCxtGJ";

void setup()
{
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
}

void loop()
{
  TBMessage msg;

  // If there is an incoming message...
  if (myBot.getNewMessage(msg)) {
    if (msg.text == "/start") {
      Serial.print("Client ");
      Serial.print(msg.sender.id);
      Serial.write('\n');
      //myBot.sendMessage(msg.sender.id, "Welcome to Idris Bot.");
      digitalWrite(2,LOW);
    }
    else {
      Serial.print(msg.text);
      Serial.write('\n');
      //myBot.sendMessage(msg.sender.id, "Text received.");
      digitalWrite(2,HIGH);
      delay(1000);
    }
  }

  delay(500);
}
