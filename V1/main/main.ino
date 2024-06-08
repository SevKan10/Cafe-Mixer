/*
TÀI KHOẢN BLYNK
Tài khoản Gmail Blynk: cafe123.apk@gmail.com
Mật khẩu Blynk: cafe12345678@

CẤU HÌNH WIFI
SSID: Cafe 2024
Pass: 12345678@
*/

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>

#define i2c_Address 0x3C
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
Adafruit_SH1106G display = Adafruit_SH1106G(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
/*=========OLED=========*/

#define BLYNK_FIRMWARE_VERSION "1.0.0"
#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPL6hiESVr6z"
#define BLYNK_TEMPLATE_NAME "Cafe"
#define BLYNK_AUTH_TOKEN "Z02-7fSBMf1msFz6MbGb-o7dwB_ixh7Z"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
/*=========BLYNK=========*/

#define buttonStart 21
#define buttonClear  18

#define volume1 32    
#define volume2 33    
#define volume3 25    
#define water 26     
#define buzzer 2      

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Cafe 2024";
char pass[] = "12345678@";

int timeV1 = 0;
int timeV2 = 0;
int timeV3 = 0;
int currentState = 0;
int flagBlynk = 0;

bool buttonStartBlynk = 0;
bool buttonClearBlynk = 0;
bool hasRun = 0;
bool lastCurrentButton = 1;
unsigned long timer1;
/*=========VAR=========*/

void ringBell(int delayTimes, int repeatTimes);
/*==========FUNCTION PROTOTYPES==========*/

void setup()
{ 
  Serial.begin(9600);
  Wire.begin(23, 22);
  WiFi.begin(ssid, pass);
  Blynk.begin(auth, ssid, pass);

  pinMode(volume1, OUTPUT);
  pinMode(volume2, OUTPUT);
  pinMode(volume3, OUTPUT);
  pinMode(water, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(buttonStart, INPUT_PULLUP);
  pinMode(buttonClear, INPUT_PULLUP);

  Serial.println("Device is booting...");
  display.begin(i2c_Address, OLED_RESET); 
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SH110X_WHITE);
  display.setCursor(23, 8);
  display.println("WELCOME");
  display.display();
  delay(2000);

  digitalWrite(volume1, 0);
  digitalWrite(volume2, 0);
  digitalWrite(volume3, 0);
  digitalWrite(water, 0);

  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("     CAFE MIXER");
  display.display();

  display.setTextSize(1);
  display.setCursor(0, 10);
  display.println("Decive Is Ready");
  display.display();

  Serial.println("Device is ready");

  delay(3000);
  ringBell(100,2);
}

void loop()
{
  Blynk.run();

  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("     CAFE MIXER");
  display.display();
  resetProcess();
  processMain();  
}

BLYNK_WRITE(V0) {timeV1 = param.asInt();Serial.println(timeV1);}
BLYNK_WRITE(V1) {timeV2 = param.asInt();Serial.println(timeV2);}
BLYNK_WRITE(V2) {timeV3 = param.asInt();Serial.println(timeV3);}
BLYNK_WRITE(V3) {buttonStartBlynk = param.asInt();}
BLYNK_WRITE(V4) {buttonClearBlynk = param.asInt();}







/*Code by SevKan*/