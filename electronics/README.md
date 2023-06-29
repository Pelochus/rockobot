# Electronics 
This section will focus on the electronics side of Rockobot

## Components
| Component             | Units | Notes                         | Link                                      |
| --------------------- | ----- | ----------------------------- | ----------------------------------------- |
| Soldering Tin         | -     |                               | -                                         |
| Wires                 | -     | Dupont or common wires        | -                                         |
| 5K Ohms Resistors     | 4     | Used with infrarred sensors   | -                                         |
| 100 Ohms Resistors    | 4     | Used with infrarred sensors   | -                                         |
| Metallic Power Button | 1     | Red, with LEDs                | https://es.aliexpress.com/item/1005004917197015.html?spm=a2g0o.order_list.order_list_main.45.21ef194dUZIReA&gatewayAdapt=glo2esp |
| RCWL-1601 US Sensor   | 2     | Very similar to HC-SR04       | https://es.aliexpress.com/item/1005001622236950.html?spm=a2g0o.order_list.order_list_main.35.21ef194dUZIReA&gatewayAdapt=glo2esp |
| TCRT5000 Reflect IR   | 4     |                               | https://es.aliexpress.com/item/32841920225.html?spm=a2g0o.order_list.order_list_main.50.21ef194dUZIReA&gatewayAdapt=glo2esp |
| JGA25-370 DC Motor    | 2     | 100RPM@12V **Not used**       |                                           |
| L289N Motor Driver    | 1     |                               | https://es.aliexpress.com/item/33012645746.html?spm=a2g0o.order_list.order_list_main.55.21ef194dUZIReA&gatewayAdapt=glo2esp |
| StepDown Converter 5V | 2     | One at ~8V the other at ~5V   | https://es.aliexpress.com/item/1005003709975604.html?spm=a2g0o.order_list.order_list_main.40.21ef194dUZIReA&gatewayAdapt=glo2esp |
| 1550mAh 14.8V Battery | 1     | 4S LiPo, with XT60 connector  | https://www.amazon.es/Tattu-Batería-Multicopteros-Helicópteros-diversos/dp/B016Q3QT2W/ref=sr_1_6?__mk_es_ES=ÅMÅŽÕÑ&crid=17YJJHHE4X53W&keywords=bateria+4s+lipo&qid=1688040709&sprefix=bateria+4s+lipo+%2Caps%2C218&sr=8-6 |
| Battery Alarm         | 1     |                               | https://es.aliexpress.com/item/1005003884877902.html?spm=a2g0o.order_list.order_list_main.5.21ef194dAnVHwB&gatewayAdapt=glo2esp |
| XT-60 Female          | 1     | Used for battery connection   | https://es.aliexpress.com/item/32832063718.html?spm=a2g0o.productlist.main.5.4cce68d7uqyB0n&algo_pvid=f2a39a2c-4b0d-49bf-bfb3-23a6969efc6b&algo_exp_id=f2a39a2c-4b0d-49bf-bfb3-23a6969efc6b-2&pdp_npi=3%40dis%21EUR%212.9%212.46%21%21%21%21%21%40211bf3f716823401805221766d0748%2167141253823%21sea%21ES%212929719205&curPageLogUid=ANvkPRMcGOMp |
| JSTXH2.54 4P Wire     | 6     | For sensors/motors connection | https://es.aliexpress.com/item/32954418743.html?spm=a2g0o.productlist.main.3.6cdd6bbdnGxQ6M&algo_pvid=444edf7e-6ca2-40cf-865b-a8123773ac9f&algo_exp_id=444edf7e-6ca2-40cf-865b-a8123773ac9f-1&pdp_npi=3%40dis%21EUR%211.81%211.81%21%21%21%21%21%40211bf3f816823607632042705d0778%2166344746550%21sea%21ES%212929719205&curPageLogUid=5XfSF4QNlLvH |
| JSTXH2.54 4P Female   | 6     | For sensors/motors connection | Link above                                |
| Male 2.54 Pins        | ~20   | For some connections/upgrades | https://es.aliexpress.com/item/32864964634.html?spm=a2g0o.productlist.main.31.38874a4fYmaBDB&algo_pvid=4bd40f5d-cd70-4efb-9b0a-ecea0801835f&algo_exp_id=4bd40f5d-cd70-4efb-9b0a-ecea0801835f-15&pdp_npi=3%40dis%21EUR%212.85%212.85%21%21%21%21%21%40211be10916823601866484129d074a%2165396607366%21sea%21ES%212929719205&curPageLogUid=diwSjXOKLHrE |
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

Here is the totally finished design integrated in the robot (we used insulating tape to avoid unintended shortcircuits):

![PCB-Finished](https://github.com/Pelochus/rockobot/blob/main/electronics/images/pcb_final.jpg)

## Circuits
This is a photo of the schematic:

![KiCadSchematic](https://github.com/Pelochus/rockobot/blob/main/electronics/images/kicad_schematic.jpg)

Essentially, the circuit does this:

Connection to battery -> Power Button -> Divide current in 3, one directly to the L298N driver, the other 2 to the voltage regulators -> One regulator will power the Arduino through V<sub>in</sub>, the other will power the sensors -> Connect Arduino and sensors/driver through digital pins and analog pins

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
