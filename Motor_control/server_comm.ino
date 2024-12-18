#include "server_comm.h"

/*
  Simple WebSocket client for ArduinoHttpClient library
  Connects to the WebSocket server, and sends a hello
  message every 5 seconds
  created 28 Jun 2016
  by Sandeep Mistry
  modified 22 Jan 2019
  by Tom Igoe
  Modified by Gabriel Sessions
  for EE 31
  this example is in the public domain
*/
#include <ArduinoHttpClient.h>
#include <WiFi.h>

///////please enter your sensitive data in the Secret tab/arduino_secrets.h
/////// WiFi Settings ///////
char ssid[] = "tufts_eecs";
char pass[] = "foundedin1883";

char serverAddress[] = "34.28.153.91";  // server address
int port = 80;

WiFiClient wifi;
WebSocketClient client = WebSocketClient(wifi, serverAddress, port);
String clientID = "89C87865077A"; //Insert your Server ID Here!;
int status = WL_IDLE_STATUS;
int count = 0;

void setup_server() {
  Serial.begin(9600);
  while (status != WL_CONNECTED) {
    // Connect to WPA/WPA2 network:
    status = WiFi.begin(ssid, pass);
  }

  // print the SSID of the network you're attached to:
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print your WiFi shield's IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  client.begin();
  client.beginMessage(TYPE_TEXT);
  client.print(clientID);
  client.endMessage();

}

// Send message to server, used to send message to partner team
// Input: Message to send 
void send_message(String message) 
{
  if(!client.connected()) setup_server();
  client.begin();
  client.beginMessage(TYPE_TEXT);
  client.print(message);
  client.endMessage();
}

// Gets message from server
// Return: message that client sent 
String get_message() 
{
    if(!client.connected()) setup_server();
    
    int messageSize = client.parseMessage();
    if (messageSize > 0) {
      delay(10);
      return client.readString();
    }

    return "";
 }



 