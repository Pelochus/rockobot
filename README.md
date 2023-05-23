# Rockobot
Battlebot made for SMP subject in Computer Engineering, UGR. This subject focuses on learning microcontrollers and embedded systems, with Arduino especifically. In order to properly learn an actual use case for embedded systems, we have to build a battlebot and make it compete with our classmates' counterparts in a tournament. Personally, we wanted to take the chance to learn a bit more of what was taught in class, so we learned both Fusion 360 and KiCad in order to improve the performance and originality of our robot, adding custom 3D printed parts and a self-designed PCB. Here we have a photo of the final assembly:

TODO put the final assembly photo here

This repository contains information about the mechanics, electronics and programming of the robot along with parts lists, tools used, future ideas and a knowledge database. This README serves as an index for each subsection (Mechanics/Printables, Electronics and Programming) and for some generic stuff. For detailed information, see the READMEs for each subsection:

- [Mechanics/3D Printables](https://github.com/Pelochus/rockobot/tree/main/printables/)
- [Electronics](https://github.com/Pelochus/rockobot/tree/main/electronics/)
- [Arduino/Software](https://github.com/Pelochus/rockobot/tree/main/arduino/)

# Index
### Mechanics/3D Printables

1. [Components](https://github.com/Pelochus/rockobot/tree/main/printables#Components)
2. [Tools](https://github.com/Pelochus/rockobot/tree/main/printables#Tools)
3. [Requirements](https://github.com/Pelochus/rockobot/tree/main/printables#Requirements)
4. [3D designs](https://github.com/Pelochus/rockobot/tree/main/printables#3D-designs)
5. [Enhancing 3D prints strength](https://github.com/Pelochus/rockobot/tree/main/printables#Enhancing-3D-prints-strength)
6. [Mechanical designs](https://github.com/Pelochus/rockobot/tree/main/printables#Mechanical-designs)
7. [Ideas](https://github.com/Pelochus/rockobot/tree/main/printables#Ideas)
8. [Knowledge Base](https://github.com/Pelochus/rockobot/tree/main/printables#Knowledge-base)

### Electronics

1. [Components](https://github.com/Pelochus/rockobot/tree/main/electronics#Components)
2. [Tools](https://github.com/Pelochus/rockobot/tree/main/electronics#Tools)
3. [PCB](https://github.com/Pelochus/rockobot/tree/main/electronics#PCB)
4. [Circuits](https://github.com/Pelochus/rockobot/tree/main/electronics#Circuits)
5. [Ideas](https://github.com/Pelochus/rockobot/tree/main/electronics#Ideas)
6. [Knowledge Base](https://github.com/Pelochus/rockobot/tree/main/electronics#Knowledge-base)

### Arduino/Software

1. [Components](https://github.com/Pelochus/rockobot/tree/main/arduino#Components)
2. [Tools](https://github.com/Pelochus/rockobot/tree/main/arduino#Tools)
3. [Requirements](https://github.com/Pelochus/rockobot/tree/main/arduino#Requirements)
4. [Functions](https://github.com/Pelochus/rockobot/tree/main/arduino#Functions)
5. [Reducing the number of digital pins](https://github.com/Pelochus/rockobot/tree/main/arduino#Reducing-the-number-of-digital-pins)
6. [Ideas](https://github.com/Pelochus/rockobot/tree/main/arduino#Ideas)
7. [Knowledge Base](https://github.com/Pelochus/rockobot/tree/main/arduino#Knowledge-base)

## General Requirements
- Decent repairability (use screws, connectors instead of soldering)
- Make the robot as visually appealing as possible, this includes:
  - Cool shape
  - Some lighting
  - Reduce how many cables/screws are easy to see at a glance. This can be compensated by making them look cool/symmetrical
- Investigate reinforced parts with steel/aluminium. CNC machining?
- Take into account how enemy robots might attack and avoid it. For example:
  - Confuse sensors to change how the robot acts
  - Literally grab the robot and take it out the battle area
  - Damage the robot

## TODO
- Add the following subsections:
  - printables/gcodes
  - printables/stl
