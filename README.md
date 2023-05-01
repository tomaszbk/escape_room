# Making my own Escape Room
### Summary:
Transformed my bedroom into an escape room! Combining electronics knowledge with programming, I designed and then put into action an experience 
made possible by the communication between the components and the Game Master's terminal dashboard

### Requirements:
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

  ### Main challenges Overcomed
 - Setting up and syncing the inter-device data communications (Serial and MQTT).</li>
 - Setting the room's full status control and debug log for a Game Master</li>
 - Developing the respective board's codes in a fully modulized way, making code easy to reuse in the future.
 
Fritzing diagrams:
![alt text](https://github.com/kukelia/escape_room/blob/master/fritzing/escape_room_arduino.png)
![alt text](https://github.com/kukelia/escape_room/blob/master/fritzing/escape_room_esp32.png "hola")

Node-red screenshot:
![alt text](https://github.com/kukelia/escape_room/blob/master/img/node-red-example.png)

Gamemaster's Dashboard:
![alt text](https://github.com/kukelia/escape_room/blob/master/img/dashboard.jpeg)

Escape Room Demonstration
![alt text](https://github.com/kukelia/escape_room/blob/master/img/demonstration.mp4)
