#include <CayenneMQTTESP8266.h>
#include "keys.h"
#define CAYENNE_DEBUG
#define CAYENNE_PRINT Serial


char ssid[] = key_ssid;
char password[] = key_password;

char username[] = key_username;
char mqtt_password[] = key_mqtt_password;
char client_id[] = key_client_id;

int reading = 0;

void setup() {
  Serial.begin(115200);
  // put your setup code here, to run once:
  Cayenne.begin(username, mqtt_password, client_id, ssid, password);
  pinMode(2, OUTPUT);
  pinMode(13, OUTPUT);
  digitalWrite(2,HIGH);
  digitalWrite(13,HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
Cayenne.loop();

Cayenne.virtualWrite(0, analogRead(A0));
Cayenne.virtualWrite(2, analogRead(A0));
delay (500);

}

CAYENNE_IN(0)
{
  digitalWrite(2, !getValue.asInt());
}

CAYENNE_IN(1)
{
  digitalWrite(13, getValue.asInt());
}

CAYENNE_LOG("CAYENNE_IN_DEFAULT(u%) - %s, %s", request.channel, getValue.getId(), getValue.asString());

//int i = getValue.asInt();
//digitalWrite(4, i)




