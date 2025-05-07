To watch the working project click here - https://drive.google.com/file/d/1vVxhNXgyrIeOLSsF5h9bcCeIgJpK-FUC/view?usp=sharing
# RFID-Based Smart Door Lock System🔒

This project is a **Smart Door Lock System** powered by **RFID technology**, built using Arduino. It enables secure access by scanning RFID cards and automatically controlling a servo motor to lock/unlock a door. The system uses an LCD to provide real-time feedback, and features a lockout mechanism after multiple failed access attempts.

## 📂 Files Included

- `Door_Lock_system_main.ino` – The main code that handles authentication, servo control, lockout logic, and LCD messages.
- `RFID_tag_scan_code.ino` – A utility script to scan and display RFID card UIDs for registration purposes.

---

## 🔧 Components Required

| Component                      | Quantity | Description                                           |
|-------------------------------|----------|-------------------------------------------------------|
| Arduino Uno                   | 1        | Microcontroller board to run the system              |
| Jumper Wires                  | As needed | For making all necessary connections                |
| Iron Stick                    | 1        | Acts as a physical locking mechanism with servo      |
| I2C Module for 16x2 LCD       | 1        | Enables easy communication with LCD via I2C protocol |
| 16x2 LCD Display              | 1        | Displays system status and feedback messages         |
| Servo Motor (e.g., SG90)      | 1        | Controls locking/unlocking by moving the iron stick  |
| RFID Module (MFRC522)         | 1        | Scans RFID cards and sends UID to Arduino            |
| RFID Tags/Cards               | 1+       | Used for access authentication                       |
| Door Lock                     | 1        | Mechanical lock that is moved by the servo and stick |

---

## 📚 Required Libraries

Make sure to install the following Arduino libraries before uploading the code:

1. **Servo**  
   Controls the servo motor.  
   📦 Install via Library Manager: `Servo by Arduino`

2. **LiquidCrystal_I2C**  
   Controls the I2C LCD display.  
   📦 Install via Library Manager or from GitHub:[LiquidCrystal_I2C by Frank de Brabander](https://github.com/fdebrabander/Arduino-LiquidCrystal-I2C-library)


3. **MFRC522**  
   For interacting with the RC522 RFID reader.  
  📦 Install via Library Manager or from GitHub:
[MFRC522 Library by Miguel Balboa](https://github.com/miguelbalboa/rfid)

5. **SPI**  
Required for communication with the RFID module.

---
### Pin Diagram: 

![Screenshot 2025-04-09 162657](https://github.com/user-attachments/assets/fe2f6b23-52f8-487e-89c7-72002d31466d)

---

## ⚙️ How It Works

### 1. **Setup Phase**
- The system initializes the servo motor to the "open" position.
- LCD shows a welcome message prompting the user to scan a card.

### 2. **Authentication**
- When an RFID card is scanned:
- Its UID is read and compared with the authorized UID stored in the code.
- If it matches:
 - If the door is open, it locks (servo moves to 0°).
 - If the door is locked, it opens (servo moves to 90°).
 - LCD shows a success message.
- If it doesn’t match:
 - Increments a failed attempts counter.
 - Displays an "Invalid Card" warning on the LCD.

### 3. **Security Lockout**
- After **3 invalid attempts**, the system enters a **10-second lockout**.
- During lockout:
- No cards are processed.
- LCD shows countdown.
- Once timeout ends, normal operation resumes.

---

## 🛠 How to Use

1. Upload `RFID_tag_scan_code.ino` to your Arduino.
2. Open the **Serial Monitor** (9600 baud) and scan your RFID card.
3. Note the UID printed — copy and update this UID inside `Door_Lock_system_main.ino` under the `String UID` variable.
4. Upload `Door_Lock_system_main.ino` to your Arduino.
5. Power the system, scan your card, and watch it work!

---

## 🧠 Features

- ✅ RFID-based secure door access
- 🔒 Lockout after repeated failed attempts
- 📟 LCD feedback for real-time status
- 🔁 Toggle open/close on successful scan
- 🧩 Modular design: easy to expand

---

## 📸 Components and Project Setup Images - 

### 🔧 Components Used

| Component                      | Image |
|-------------------------------|-------|
| **1. Arduino Uno**            | ![Screenshot 2025-04-09 151515](https://github.com/user-attachments/assets/ed36e84e-2342-42b5-8e9b-46bfc534c940) |
| **2. Jumper Wires**           |  ![Screenshot 2025-04-09 151556](https://github.com/user-attachments/assets/48c5f204-10be-46aa-ae52-1fd4f85b96fe) |
| **3. Door Lock Mechanism**    |![Screenshot 2025-04-09 152832](https://github.com/user-attachments/assets/0a904f98-d09f-47ad-894b-b62246c4e08f) |
| **4. I2C Module for 16x2 LCD**|  ![Screenshot 2025-04-09 151532](https://github.com/user-attachments/assets/b624384b-54a9-4329-b117-df8b063d1cfd) |
| **5. 16x2 LCD Display**       | ![Screenshot 2025-04-09 151848](https://github.com/user-attachments/assets/ecae17a5-b4aa-4a36-a579-ab5ee2937fae) |
| **6. Servo Motor**            |  ![Screenshot 2025-04-09 151543](https://github.com/user-attachments/assets/1e72ea2a-faa4-4cc2-8b18-4c292caf0b04) |
| **7. RFID Module (RC522)**    | ![Screenshot 2025-04-09 152031](https://github.com/user-attachments/assets/3a9aec96-828b-4a1d-ae96-26e2ffa79bac) |

---

### Below are real-time images of the setup and how it works:  

![WhatsApp Image 2025-04-09 at 3 51 10 PM](https://github.com/user-attachments/assets/2dd759fe-6c7a-4390-aeb5-8649db3a9f08)

![WhatsApp Image 2025-04-09 at 3 52 04 PM](https://github.com/user-attachments/assets/b147a25e-12d1-4c88-a207-2d928d31d9d2)

![WhatsApp Image 2025-04-09 at 3 52 04 PM (1)](https://github.com/user-attachments/assets/db960d37-8699-4bef-9549-531c1eda5302)

![WhatsApp Image 2025-04-09 at 3 52 05 PM (1)](https://github.com/user-attachments/assets/ac08061c-0666-49fe-a466-39f9dd58d26c) 

![WhatsApp Image 2025-04-09 at 3 58 18 PM](https://github.com/user-attachments/assets/279d8f31-5c64-42c8-8656-6823f7ce35d6)

![WhatsApp Image 2025-04-09 at 3 52 05 PM](https://github.com/user-attachments/assets/8d0cee39-36db-4b50-8f5a-98ba71216e69)

![WhatsApp Image 2025-04-09 at 3 51 10 PM](https://github.com/user-attachments/assets/62c80c3c-8d89-41e4-b620-4228696752f8)

![WhatsApp Image 2025-04-09 at 3 52 04 PM (2)](https://github.com/user-attachments/assets/fc4ad886-5aec-4158-b799-3923fac4e043)

![WhatsApp Image 2025-04-09 at 3 52 07 PM (1)](https://github.com/user-attachments/assets/b1f34c96-ec0f-41a4-bcce-b5ad3d33f554)

![WhatsApp Image 2025-04-09 at 3 52 06 PM (2)](https://github.com/user-attachments/assets/748a1f14-620f-4a07-aa74-3f65635c481c)

![WhatsApp Image 2025-04-09 at 3 52 49 PM](https://github.com/user-attachments/assets/33d61a4c-2ec0-4ffc-8ac4-0ef655bf06c7)

![WhatsApp Image 2025-04-09 at 3 52 06 PM](https://github.com/user-attachments/assets/04940656-2cee-453a-b1a1-4a9f4d7b9e5e)

![WhatsApp Image 2025-04-09 at 3 52 06 PM (1)](https://github.com/user-attachments/assets/35577b2c-8560-4172-b7c9-92d74f19f299)

![WhatsApp Image 2025-04-09 at 3 52 07 PM](https://github.com/user-attachments/assets/200f645d-bf1e-435b-baa1-57e0038735b6)


---

## 📜 License

This project is open-source and available under the [MIT License](LICENSE).

---

## 🙌 Acknowledgements

- [MFRC522 Library by Miguel Balboa](https://github.com/miguelbalboa/rfid)
- [LiquidCrystal_I2C by Frank de Brabander](https://github.com/fdebrabander/Arduino-LiquidCrystal-I2C-library)




---
