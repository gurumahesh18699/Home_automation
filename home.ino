#include <ArduinoJson.h>

int relay = 4;
int flame = 5;
int ir = 0;

#include<ESP8266WiFi.h>

const char* ssid = "Emarald";
const char* host = "miniproject191.000webhostapp.com";
int wifistatus;
String url;
void setup() {
  pinMode(ir, INPUT);
  pinMode(relay, OUTPUT);
  pinMode(flame, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(200);
  Serial.println("you are connecting to");
  Serial.println(ssid);
  WiFi.begin(ssid);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println(".");
  }

  wifistatus = WiFi.status();
  if (wifistatus == WL_CONNECTED) {

    Serial.println("");
    Serial.println("your Esp is connected");
    Serial.println("IP address");
    Serial.println(WiFi.localIP());
  }
  else {
    Serial.println("not connected");
  }
  delay(1000);
}

void loop() {

  WiFiClient client;
  const int httpport = 80;
  if (!client.connect(host, httpport)) {
    Serial.println("connection failed");
    return;
  }
  else {
    Serial.println("connected");
  }
  url = "/api/read.php?id=1";

  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" +
               "Connection: close\r\n\r\n");
  String section = "header";
  delay(1000);
  String line;
  while (client.available()) {
    line = client.readStringUntil('\r');


  }
  Serial.println(line);
  if (line.indexOf("on") > 0)
  {
    Serial.println("light on");
    digitalWrite(LED_BUILTIN, HIGH);
    digitalWrite(relay, HIGH);
  }
  else if (line.indexOf("off") > 0)
  {
    Serial.println("light off");
    digitalWrite(LED_BUILTIN, LOW);
    digitalWrite(relay, LOW);
  }
  else {
    Serial.println("not found");
  }

/*
This is  additional one you can use as a security system where you can attach a infrared sensor to it 
so if some one detected you can send a message it and attach a flame sensor so if flame detected you can 
switch off the electrical  appliances


  if (digitalRead(ir) == LOW)
  {
    Serial.println("detected");
    
  }
  else {
    Serial.println("not detected");
  }


 if (digitalRead(flame) == 1)
   {
    Serial.println("detected");
    digitalWrite(relay,LOW);
  }
  else {
    Serial.println(" not detected");
  }

       */

}
