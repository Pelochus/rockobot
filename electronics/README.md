# Electronics 
This section will focus on the electronics side of Rockobot

## Components
| Component             | Units | Notes                         | Link                                      |
| --------------------- | ----- | ----------------------------- | ----------------------------------------- |
| Soldering Tin         | -     |                               |                                           |
| Wires                 | -     | Dupont or common wires        |                                           |
| 5K Ohms Resistors     | 4     | Used with infrarred sensors   |                                           |
| 100 Ohms Resistors    | 4     | Used with infrarred sensors   |                                           |
| Metallic Power Button | 1     | Red, with LEDs                |                                           |
| RCWL-1601 US Sensor   | 2     | Very similar to HC-SR04       |                                           |
| TCRT5000 Reflect IR   | 4     |                               |                                           |
| JGA25-370 DC Motor    | 2     | 100RPM@12V **Not used**       |                                           |
| L289N Motor Driver    | 1     |                               |                                           |
| StepDown Converter 5V | 2     | One at 8V the other at 5V     |                                           |
| 1550mAh 14.8V Battery | 1     | 4S LiPo, with XT60 connector  |                                           |
| Battery Alarm         | 1     |                               |                                           |
| XT-60 Female          | 1     | Used for battery connection   |                                           |
| JSTXH2.54 4P Wire     | 6     | For sensors/motors connection |                                           |
| JSTXH2.54 4P Female   | 6     | For sensors/motors connection |                                           |
| Male 2.54 Pins        | ~20   | For some connections/upgrades |                                           |
| Rockobot v1.0 PCB     | 1     |                               |                                           |
| Optional Components   | -     | Some other useful components: | Heat Shrink tubing, insulating tape...    |

## Tools
- Soldering Iron
- Balance Charger

## PCB
Here we have a photo of the PCB in KiCad:

![KiCadPCB](https://github.com/Pelochus/rockobot/blob/main/electronics/images/kicad_pcb.jpg)

We can see these components:
- Various connectors, including male 2.54 pins, JSTXH 2.54 for the sensors and XT60 male for the battery
- Resistors for the IR sensors
- 2 voltage regulators, one will be exclusively for the Arduino (needs more than 7V, max 12V, the Vin pin will do the rest) and the other for the sensors (both infrarred and US) at 5 volts
- Arduino NANO itself

The final result should look like this (except for all the male pins which are connected to the JST, which are **backup connectors**):

![KiCadPCB3D](https://github.com/Pelochus/rockobot/blob/main/electronics/images/kicad_pcb_3D.jpg)

However we made little changes to adapt it to our final design. The only two important changes are **the female pins for the Arduino** (so we can remove it or insert it whenever we want) and the **position of the XT60 connector**, which is facing downwards because our battery didn't have a long enough wire. We also did not include those extra male pins, which were inserted just in case we had problems with the JST connectors.

![PCB-Almost-Finished](https://github.com/Pelochus/rockobot/blob/main/electronics/images/pcb.jpg)

Here is the totally finished design integrated in the robot:

TODO put a photo here of the final PCB integrated in the robot

## Circuits
This is a photo of the schematic:

![KiCadSchematic](https://github.com/Pelochus/rockobot/blob/main/electronics/images/kicad_schematic.jpg)

The electronic design is relatively simple, basically we can divide it in two parts:
- Battery Input, voltage regulators and power switch
- Arduino and its connections to the sensors

## Ideas
Here are some ideas for future revisions:
- Change from Arduino NANO to, for example, ESP32
- Add a section to the PCB with male pins connected to the digital pins, to add some modularity. Also add two more male pins, one connected to Arduino 5V and the other to GND
- Change some pins (like the 6 motor driver pins) to other JST XH2.54 or other connectors. For the previous example, from common male pins to JST XH2.54 6P
- Rethink some components like the regulators. For example:
  - Reduce to just one regulator, by using the Arduino for powering sensors (depending on how many sensors are used, in this design it is possible but near the Arduino limit)
  - Change to a fixed SMD regulator, to avoid changing the potentiometer unintentionally to an unsafe voltage. Also to better fit in the PCB (current implementation is rather messy)
- Resize PCB accordingly to what new changes were introduced

## Knowledge Base
- [KiCad 7 Tutorial, from schematics to final PCB](https://www.youtube.com/watch?v=3FGNw28xBr0)
