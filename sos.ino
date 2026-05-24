#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <TinyGPS++.h>
#include <HardwareSerial.h>

LiquidCrystal_I2C lcd(0x27,16,2);

TinyGPSPlus gps;

HardwareSerial gpsSerial(2); // RX2=16 TX2=17
HardwareSerial sim800(1);    // RX=27 TX=26

#define BTN1 32
#define BTN2 33

String lat="";
String lon="";

void setup()
{
  Serial.begin(115200);

  pinMode(BTN1, INPUT_PULLUP);
  pinMode(BTN2, INPUT_PULLUP);

  lcd.init();
  lcd.backlight();

  gpsSerial.begin(9600, SERIAL_8N1, 16, 17);
  sim800.begin(9600, SERIAL_8N1, 27, 26);

  Serial.println("SOS SYSTEM STARTING...");
  
  lcd.setCursor(0,0);
  lcd.print("SOS SYSTEM");
  lcd.clear();
  delay(2000);
}

void loop()
{
  lcd.setCursor(0,0);
  lcd.print("SOS SYSTEM");
  
  while(gpsSerial.available())
  {
    char c = gpsSerial.read();
    gps.encode(c);
  }

  if(gps.location.isValid())
  {
    lat = String(gps.location.lat(),6);
    lon = String(gps.location.lng(),6);

    Serial.print("Latitude: ");
    Serial.println(lat);

    Serial.print("Longitude: ");
    Serial.println(lon);
  }
  else
  {
    Serial.println("Waiting for GPS signal...");
    
    lat = "11.323078";
    lon = "77.674987";

    Serial.println("Using Default Location:");
    Serial.print("Latitude: ");
    Serial.println(lat);

    Serial.print("Longitude: ");
    Serial.println(lon);
  }

  if(digitalRead(BTN1)==LOW)
  {
    Serial.println("Button 1 Pressed");
    
    lcd.clear();
    lcd.print("BTN1 Pressed");
    delay(500);
    lcd.clear();
    lcd.print("Send to police");
    lcd.setCursor(0, 1);
    lcd.print("FR, HP, AMB");

    sendGroup1();

    delay(5000);
  }

  if(digitalRead(BTN2)==LOW)
  {
    Serial.println("Button 2 Pressed");
    
    lcd.clear();
    lcd.print("BTN2 Pressed");
    delay(500);
    lcd.clear();
    lcd.print("Send to police");
    lcd.setCursor(0, 1);
    lcd.print("HP, AMB");

    sendGroup2();

    delay(5000);
  }
}

void sendSMS(String number, String message)
{
  Serial.print("Sending SMS to: ");
  Serial.println(number);

  sim800.println("AT+CMGF=1");
  delay(1000);

  sim800.print("AT+CMGS=\"");
  sim800.print(number);
  sim800.println("\"");

  delay(1000);

  sim800.print(message);

  delay(500);

  sim800.write(26);

  Serial.println("SMS Sent");
  Serial.println(message);

  delay(5000);
}
String createMessage1()
{ 
  String msg="EMERGENCY ALERT!\n";
  msg+="Animal Coming\n";
  msg+="Need immediate help.\n";
  msg+="Location:\n";

  msg+="Lat:";
  msg+=lat;

  msg+=" Lon:";
  msg+=lon;

  msg+="\n";
  msg+="https://maps.google.com/?q=";
  msg+=lat;
  msg+=",";
  msg+=lon;

  Serial.println("Generated Message:");
  Serial.println(msg);

  return msg;
}

String createMessage2()
{ 
  String msg="EMERGENCY ALERT!\n";
  msg+="Medical Emergency\n";
  msg+="Need immediate help.\n";
  msg+="Location:\n";

  msg+="Lat:";
  msg+=lat;

  msg+=" Lon:";
  msg+=lon;

  msg+="\n";
  msg+="https://maps.google.com/?q=";
  msg+=lat;
  msg+=",";
  msg+=lon;

  Serial.println("Generated Message:");
  Serial.println(msg);

  return msg;
}

void sendGroup1()
{
  Serial.println("Sending Group 1 Alerts");

  String message=createMessage1();

  sendSMS("+916379193192", message); // Police
  lcd.clear();
  lcd.print("Send to police");

  sendSMS("+919994933370", message); // Forest
  lcd.clear();
  lcd.print("Send to Forest");
  lcd.setCursor(0,1);
  lcd.print("Ranger");

  sendSMS("+917603834343", message); // Hospital
  lcd.clear();
  lcd.print("Send to Hospital");

  sendSMS("+919789613292", message); // Ambulance
  //lcd.clear();
  //lcd.setCursor(0,0);
 // lcd.print("Send to ");
  lcd.setCursor(0,1);
  lcd.print("Ambulance");

  lcd.clear();
  lcd.print("Group1 Sent");
  lcd.clear();

  Serial.println("Group 1 SMS Completed");
}

void sendGroup2()
{
  Serial.println("Sending Group 2 Alerts");

  String message=createMessage2();

  sendSMS("+916379193192", message); // police
  lcd.clear();
  lcd.print("Send to police");

  sendSMS("+917603834343", message); // Hospital
  lcd.clear();
  lcd.print("Send to Hospital");

  sendSMS("+919789613292", message); // Ambulance
 // lcd.clear();
 // lcd.setCursor(0,0);
  //lcd.print("Send to ");
  lcd.setCursor(0,1);
  lcd.print("Ambulance");

  lcd.clear();
  lcd.print("Group2 Sent");
  lcd.clear();
  Serial.println("Group 2 SMS Completed");
  
}