#include <SoftwareSerial.h>
#include <Adafruit_GPS.h>

SoftwareSerial sSerial(3,2); //sSerial object rx,tx
Adafruit_GPS GPS(&sSerial); //GPS object

String NMEA1;
String NMEA2;
char c; //per leggere i charatteri da GPS
 
void setup() {
  Serial.begin(115200);
  GPS.begin(9600);
 
  GPS.sendCommand(PMTK_SET_NMEA_OUTPUT_RMCGGA); //per leggere le $GPRMC and $GPGGA NMEA
  GPS.sendCommand(PMTK_SET_NMEA_UPDATE_1HZ);
  delay(1000);
}

void loop() {
  readGPS();
  delay(750);
}

void readGPS(){
  clearGPS();
  // prima NMEA
  while(!GPS.newNMEAreceived()){ //fare il loop fino a prendere buona NMEA
    c=GPS.read();
  }
  GPS.parse(GPS.lastNMEA());  //parse lultima buona NMEA
  NMEA1=GPS.lastNMEA();

 //seconda NMEA
 while(!GPS.newNMEAreceived()){ //fare il loop fino a prendere buona NMEA
    c=GPS.read();
  }
  GPS.parse(GPS.lastNMEA());  //parse lultima buona NMEA
  NMEA2=GPS.lastNMEA();
  
  Serial.println(NMEA1);
  Serial.println(NMEA2);
  Serial.println("");
}

void clearGPS() {  //Since between GPS reads, we still have data streaming in, we need to clear the old data by reading a few sentences, and discarding these
while(!GPS.newNMEAreceived()) {
  c=GPS.read();
  }
GPS.parse(GPS.lastNMEA());
while(!GPS.newNMEAreceived()) {
  c=GPS.read();
  }
GPS.parse(GPS.lastNMEA());
 
}
