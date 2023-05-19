# Printables and Mechanics
This section will focus on the printables and mechanics side of Rockobot

## Components

| Component             | Units | Notes                         |
| --------------------- | ----- | ----------------------------- |
| Motor                 | 2     | Extracted from old VHS        |
| PLA/PLA+              | 800 g | Weight is estimated           |
| TPU 95A               | 200 g | Weight is estimated           |
| M3x8 Screws           | 32    |                               |
| M3x20 Screws          | 20    |                               |
| M4x60 Screws          | 70    | Used in tracks and some cogs  |
| M4 Stop Nuts          | 64    | Used along the M4 screws      |
| M3 Threaded Insert    | 50    | Ruthex Brand                  |
| M3x80 Threaded Rod    | 4     |                               |
| M3 Nuts               | 8     | Used with threaded rods       |

## Tools
- Screwdrivers
- Soldering Iron (inserting threaded inserts in prints)
- 3D printers:
    - Ender 3 V2
    - Elegoo Neptune 2

## Requirements
- Get as close as possible to the 4 kg limit
- Make it near as big as the limit (350x350 mm)
- Low center of gravity, high stability
- Good traction, no slippery wheels
- High Torque, speed is not that important
- High resistance parts, intelligently print parts as durable as possible (high temps, low speeds, better materials, intelligent designs)
- Intelligently design parts for durability

## 3D designs
### Rockobot Core
Explain each floor and the added modules (gearbox, shield...)

#### Fillable Base
This was not used in final design, but its purpose was being filled with something dense and liquid/fluid so that the robot weigh could be changed easily.
Our idea was to use sand, but it isn't a great idea mixing 3D prints (which are not totally sealed) with something like sand. Also added complications with the infrarred sensors

#### Motors Floor
Biggest, most important 3D printed part of the whole design. Will need at least 280 g of plastic. The purpose of this floor is to connect the motor to the tracks, act as the bottom floor, includes the infrarred sensors and the slot for the battery. With everything set it weighs not too far from a kilogram. There is a second slot for another battery, or for adding something heavy to add extra weight.

#### Electronics Floor
Second most important part, where almost all the electronics are located. This includes the PCB and the L298N motor driver, there are 2 slots, one for each. There are also some extra slots, intended for passing the wires through them. These are big because we wanted to save some material, reduce complexity in thinking how to properly distribute wires and easeness of installation.

#### Top Layer
This layer serves only 3 purposes: decorative, sloting the power button and as a base for Rockins (explained below). The majority of shapes here are decorative and for saving some material.   

#### Rockins
The purpose of Rockins is to add a bit of modularity to Rockobot. In our case, we only added The Rock (Dwayne Johnson) head, who is the inspiration for the name of the robot. Rockins are made for adding some decorative pieces to the robot and changing them whenever you want, however, they can also be designed with some functionality, that's why we kept a big hole below in the Top Layer, to pass some wires through it, so we could also make a version with red LEDs in The Rock eyes.

### Rockobot Gearbox
Designed as a separate part, included to the Core design. Due to having 2 versions, (one independent to the core, the other is the integration) the Fusion 360 design is slightly messy. We recommend looking at the Adapted-To-Core version, which is more updated. There are various gears, a cylinder which represents the motor and the actual gearbox. 

### Rockobot Shield
Can be 3D printed, but it is designed to be done with a metal sheet and a laser cutter. The design includes some holes for screwing the US sensor, but we did not use them in the final design because it fitted exactly in the holes for the sensor. In Fusion we use 2 mm thickness, but we built it with 1 mm (we started getting to close to the 4 kg limit...) and also increased the curved ramp length a bit (about 20 mm). **Inox Steel 403** is the material used. Thanks to Pelochus' dad for actually doing this piece (we obviously did not have access to a laser cutter...). 

## Enhancing 3D prints strength
To enhance 3D prints strength, there are various techniques and slicer settings to adjust. There is a [gcode](https://github.com/Pelochus/rockobot/tree/main/printables/gcodes) section where the gcodes of each part with the following settings are stored. **Unless otherwise specified these are the common settings**:
- 215/250ºC Hotend and 65/75ºC Bed temperatures for PLA+/PETG respectively
- 50 mm/s speed, 60 mm/s for bigger parts
- 4 walls, 0.4 mm thickness per wall
- Cubic/Cubic Subdivision/Grid Infill Type. We recommend (and used) cubic subdivision for strength in all axes and also to lower plastic used 
- Avoid supports (it is possible, some parts may require higher fan speeds)
- Prints must be intelligently aligned with the axes so that the forces that will be applied are not ripping layers apart

| Part              | Material   | Fan  | Infill | Support | Ironing | Extras       |
| ----------------- | ---------- | ---- | ------ | ------- | ------- | ------------ |
| Fillable Base     | PLA+       | 25%  | 25%    | No      | No      |              |
| Motors Floor      | PLA+       | 50%  | 15%    | No      | No      |              |
| Electronics Floor | PLA+       | 25%  | 10%    | No      | No      |              |
| Top Layer         | PLA+       | 25%  | 10%    | No      | No      |              |
| The Rock Rockin   | PLA+       | 100% | 5%     | Yes     | Yes     |              |
| Outer Connector   | PLA+       | 25%  | 15%    | No      | No      |              |
| Cogs / Gears      | PLA+       | 25%  | 100%   | No      | No      |              |


There were some TPU prints (tracks). The settings where these:
- 225ºC Hotend / 55ºC Bed
- 30 mm/s speed
- 3 walls, 0.4 mm thickness per wall
- Grid Infill Type / 10% infill
- 80% Fan
- 0.16 mm layer height

It's worth mentioning that threaded inserts where used throughout the whole design. Using bare holes in 3D printing for screws is generally not a good idea,
that's why we decided to use threaded inserts, allowing better repairability and strength. They also require to have 1.6 mm walls, that is why that setting is 4 walls instead of the common 3. 
Below there is a link in which CNC Kitchen explains how to design holes for 3D printable parts 

## Mechanical designs
### Motor reduction through gears
Explain the motor reduction and the design of the gears. Talk about connection to tracks and main cog...

## Ideas
- Think about an easy way of adding weigh to the robot. This is in order to get as close as possible to the 4kg limit, without surpassing it before final design.

## Knowledge Base
- [Tank where the tracks design was extracted](https://www.thingiverse.com/thing:1240754)
- [3D printing Tricks](https://youtu.be/krrqydtneO0)
- [Designing for Threaded Inserts](https://www.cnckitchen.com/blog/tipps-amp-tricks-fr-gewindeeinstze-im-3d-druck-3awey)
- [Strengthening through texturing by CNC Kitchen](https://youtu.be/3-ygdNQThAs)
- [Transparent and strong PETG settings by CNC Kitchen](https://www.youtube.com/watch?v=9qb25Gi4Jv0)
