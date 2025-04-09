#include <Servo.h>
#include <LiquidCrystal_I2C.h>
#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9
String UID = "C3 DC 13 DA";
byte lock = 1; 
int failedAttempts = 0;
unsigned long lockoutTime = 0;
bool systemLocked = false;

Servo servo;
LiquidCrystal_I2C lcd(0x27, 16, 2);
MFRC522 rfid(SS_PIN, RST_PIN);

void setup() {
  Serial.begin(9600);
  servo.attach(3);
  servo.write(90);  
  lcd.init();
  lcd.backlight();
  SPI.begin();
  rfid.PCD_Init();
  
  showMessage("System Ready", "Door: OPEN", 2000);
}

void loop() {
  if (systemLocked) {
    handleLockout();
    return;  
  }

  showMessage("Welcome!", "Scan your card", 0);
  
  if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial()) {
    return;
  }

  processCard();
}

void handleLockout() {
  unsigned long remaining = 10 - (millis() - lockoutTime)/1000;
  
  lcd.setCursor(0, 0);
  lcd.print("SYSTEM LOCKED! ");
  lcd.setCursor(0, 1);
  lcd.print("Wait: ");
  lcd.print(remaining);
  lcd.print(" sec   ");
  
  if (millis() - lockoutTime >= 10000) {
    systemLocked = false;
    failedAttempts = 0;
    lcd.clear();
  }
}

void processCard() {
  showMessage("", "Scanning.....", 0);
  
  String ID = "";
  for (byte i = 0; i < rfid.uid.size; i++) {
    ID.concat(String(rfid.uid.uidByte[i] < 0x10 ? " 0" : " "));
    ID.concat(String(rfid.uid.uidByte[i], HEX));
    delay(100);
  }
  ID.toUpperCase();

  if (ID.substring(1) == UID) {
    if (lock == 1) {
      servo.write(0);  
      showMessage("Door is locked", "successfully", 3000);
      lock = 0;
    } else {
      servo.write(90); 
      showMessage("Door is opened", "successfully", 3000);
      lock = 1;
    }
    failedAttempts = 0;
  } else {
    handleInvalidAttempt();
  }
}

void handleInvalidAttempt() {
  failedAttempts++;
  showMessage("Invalid Card!", "Attempts: " + String(failedAttempts), 3000);

  if (failedAttempts >= 3) {
    systemLocked = true;
    lockoutTime = millis();
    showMessage("TOO MANY TRIES!", "Wait 10 seconds", 1000);
  }
}

void showMessage(String line1, String line2, int displayTime) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(line1);
  lcd.setCursor(0, 1);
  lcd.print(line2);
  if (displayTime > 0) {
    delay(displayTime);
    lcd.clear();
  }
}