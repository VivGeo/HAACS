#include <CayenneMQTTESP8266.h>
#define CAYENNE_DEBUG
#define CAYENNE_PRINT Serial


char ssid[] = "MHacks";
char password[] = "MHacksMilestone";

char username[] = "a5155990-a0a4-11e7-8c02-137ff2c4ffef";
char mqtt_password[] = "3244a2b27d0e86e95f801f9b90dd6168026f08f0";
char client_id[] = "d9317850-a0a7-11e7-b0e9-e9adcff3788e";

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




