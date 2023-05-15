# Making my own Escape Room 🚪🗝️
### 📌 Summary:
Transformed my bedroom into an escape room! Combining electronics knowledge with programming, I designed and then put into action an experience 
made possible by the communication between the components and the Game Master's terminal dashboard

###🖥️ Requirements:
**Hardware**:
- Arduino UNO
- ESP32
- LEDs
- buzzer
- lcd 16x2 display
- Shift register
- 4 Digit 7 Segment LED Display
- 4x4 matrix keypad
- Rfid reader and card
- 9v Battery

**Software**:
- C++
- Node-Red
- Mosquitto
- PlatformIo

###🏆 Main challenges Overcomed
 - Setting up and syncing the inter-device data communications (Serial and MQTT).</li>
 - Setting the room's full status control and debug log for a Game Master</li>
 - Developing the respective board's codes in a fully modulized way, making code easy to reuse in the future.
 
## Fritzing diagrams:
<img src="https://github.com/kukelia/escape_room/blob/master/fritzing/escape_room_arduino.png" alt= “” width="850" height="550">
<img src="https://github.com/kukelia/escape_room/blob/master/fritzing/escape_room_esp32.png" alt= “” width="850" height="550">

## Node-red screenshot:
<img src="https://github.com/kukelia/escape_room/blob/master/img/node-red-example.png" alt= “” width="900" height="600">

## Gamemaster's Dashboard:
<img src="https://github.com/kukelia/escape_room/blob/master/img/dashboard.jpeg" alt= “” width="300" height="600">

## Escape Room Demonstration 🔎
https://user-images.githubusercontent.com/85851175/235522523-4b475099-6c93-435e-834e-76cc130d574e.mp4

The Room's first puzzle involves finding a code and inserting it in the 4x4 keypad.  
The second puzzle is solved placing an RFID card on a specific book (which has a hidden RFID reader).  
Afterwards, a Servo opens a box where the key to open the exit door is located.  
(Clues where hidden across my room, and are not shown for privacy reasons)

