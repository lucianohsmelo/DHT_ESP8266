#include<dht.h>
dht DHT;

// Define NodeMCU D3 pin to as temperature data pin of  DHT11
#define DHT11_PIN D3

long lastMsg = 0;
char msg[50];

void setup() {
  Serial.begin(115200);
  int chk = DHT.read11(DHT11_PIN);
  Serial.print(" Starting Humidity: " );
  Serial.print(DHT.humidity, 1);
  Serial.println('%');
  Serial.print(" Starting Temparature ");
  Serial.print(DHT.temperature, 1);
  Serial.println('C');
  // put your setup code here, to run once:

}

void loop() {
  long now = millis();
  // read DHT11 sensor every 6 seconds
  if (now - lastMsg > 1000) {
     lastMsg = now;
     int chk = DHT.read11(DHT11_PIN);
     String msg="real time temperature: ";
     msg= msg+ DHT.temperature;
     msg = msg+" C ;real time Humidity: " ;
     msg=msg+DHT.humidity ;
     msg=msg+"%";
     char message[58];
     msg.toCharArray(message,58);
     Serial.println(message);
     //publish sensor data to MQTT broker
  }

}
