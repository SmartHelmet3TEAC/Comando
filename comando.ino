
#include <WiFi.h>
#include <WebServer.h>

 // Variaveis input

int input1 = 5;
int input2 = 18;
int input3 = 19;
int input4 = 21;
int input5 = 26;
int input6 = 25;
int ledcheck = 2;

bool var1=0;
bool var2=0;
bool var3=0;
bool var4=0;
bool var5=0;
bool var6=0;

const char* ssid = "Carlos Osorio ";  
const char* password = "CmG79DvSmH";  

WebServer server(80); 

void setup() {
  pinMode(2,OUTPUT);
  pinMode(5,INPUT_PULLUP);
  pinMode(18,INPUT_PULLUP);
  pinMode(19,INPUT_PULLUP);
  pinMode(21,INPUT_PULLUP);
  pinMode(26,INPUT_PULLUP);
  pinMode(25,INPUT_PULLUP);
  
  Serial.begin(115200);
  Serial.println("Try Connecting to ");
  Serial.println(ssid);

  // Connect to your wi-fi modem
  WiFi.begin(ssid, password);

  // Check wi-fi is connected to wi-fi network
  while (WiFi.status() != WL_CONNECTED) {
  delay(1000);
  Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected successfully");
  digitalWrite(ledcheck, HIGH);
  Serial.print("Got IP: ");
  Serial.println(WiFi.localIP());  //Show ESP32 IP on serial

  server.on("/", handle_root);

  server.begin();
  Serial.println("HTTP server started");
  delay(100); 
}

void loop() {
 var1=digitalRead(input1);
 var2=digitalRead(input2);
 var3=digitalRead(input3);
 var4=digitalRead(input4);
 var5=digitalRead(input5);
 var6=digitalRead(input6);
  delay(150);
  Serial.print(var1); 
  Serial.print(var2); 
  Serial.print(var3);
  Serial.print(var4); 
  Serial.print(var5); 
  Serial.print(var6); 
  Serial.println(); 
    
  server.handleClient();
  
}

// HTML & CSS contents which display on web server
String HTML = "<!DOCTYPE html>\
<html>\
<body>\
<h1>My First Web Server with ESP32 - Station Mode &#128522;</h1>\
</body>\
</html>";

// Handle root url (/)
void handle_root() {
  server.send(200, "text/html", HTML);
}
