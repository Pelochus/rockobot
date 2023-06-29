# Printables and Mechanics
This section will focus on the printables and mechanics sides of Rockobot<br>
If you want the STLs files or CAD files click this [link for STLs](https://github.com/Pelochus/rockobot/tree/main/printables/stl) or this [one for Fusion 360 files](https://github.com/Pelochus/rockobot/tree/main/printables/fusion360)

## Components

| Component             | Units | Notes                                         |
| --------------------- | ----- | --------------------------------------------- |
| Motor                 | 2     | Extracted from old VHS                        |
| PLA/PLA+              | 850 g | Weight is estimated                           |
| TPU 95A               | 250 g | Weight is estimated                           |
| M3x8 Screws           | 32    |                                               |
| M3x20 Screws          | 20    |                                               |
| M4x60 Screws          | 70    | Used in tracks and some cogs                  |
| M4 Stop Nuts          | 64    | Used along the M4 screws                      |
| M3 Threaded Insert    | 50    | Ruthex Brand                                  |
| M3x80 Rod             | 4     | If threaded, use x8 M3 stop nuts              |
| M3 Nuts               | ~15   | Used with threaded rods                       |
| M4 Nuts               | ~8    | Used with some OutConn screws                 |
| Optional components   | -     | Vaseline (lubricant), washers, silicone...    |

## Tools
- Screwdrivers
- Soldering Iron (inserting threaded inserts in prints)
- 3D printers (we used these):
    - Ender 3 V2
    - Elegoo Neptune 2

## Requirements
- Get as close as possible to the 4 kg limit
- Make it near as big as the limit (350x350 mm)
- Low center of gravity, high stability
- Good traction, no slippery wheels
- High Torque, speed is not important
- High resistance parts, intelligently print parts as durable as possible (high temps, low speeds, better materials, intelligent designs)
- Intelligently design parts for durability

## 3D designs
### Rockobot Core
Here is a photo of the full design in Fusion 360. This only includes what was designed with Fusion, not any other mechanical component. There may be some minor differences, since the mounted has some manual adaptations that were later introduced properly to the design.

**You can easily inspect the full design [here](https://a360.co/3mfHlEx)**

![Full-Design](https://github.com/Pelochus/rockobot/blob/main/printables/images/rockobot-core.png)

#### Fillable Base
This was not used in final design, but its purpose was being filled with something dense and liquid/fluid so that the robot weigh could be changed easily.
Our idea was to use sand, but it isn't a great idea mixing 3D prints (which are not totally sealed, due to the concept of layers) with something like sand. Also added complications with the infrarred sensors, so it was abandoned as an idea, but still present in the design.

![Fillable-Base](https://github.com/Pelochus/rockobot/blob/main/printables/images/fillable-base.png)

#### Motors Floor
Biggest, most important 3D printed part of the whole design. Will need at least 280 g of plastic. The purpose of this floor is to connect the motor to the tracks, act as the bottom floor, includes the infrarred sensors and the slot for the battery. With everything set, it weighs not too far from a kilogram. There is a second slot for another battery, or for adding something heavy to add extra weight.

![Motors-Floor](https://github.com/Pelochus/rockobot/blob/main/printables/images/motors-floor.png)

#### Electronics Floor
Second most important part, where almost all the electronics are located. This includes the PCB and the L298N motor driver, there are 2 slots, one for each. There are also some extra slots, intended for passing the wires through them. These are big because we wanted to save some material, reduce complexity in thinking how to properly distribute wires and easeness of installation.

![Electronics-Floor](https://github.com/Pelochus/rockobot/blob/main/printables/images/electronics-floor.png)

#### Top Layer
This layer serves only 3 purposes: decorative, sloting the power button and as a base for Rockins (explained below). The majority of shapes here are decorative and for saving some material.

![Top-Layer](https://github.com/Pelochus/rockobot/blob/main/printables/images/top-layer.png)

#### Rockins
The purpose of Rockins is to add a bit of modularity to Rockobot. In our case, we only added The Rock (Dwayne Johnson) head, who is the inspiration for the name of the robot. Rockins are made for adding some decorative pieces to the robot and changing them whenever you want, however, they can also be designed with some functionality, that's why we kept a big hole below in the Top Layer, to pass some wires through it, so we could also make a version with red LEDs in The Rock eyes.

![Rockin-Rock](https://github.com/Pelochus/rockobot/blob/main/printables/images/the-rock-rockin.png)

![Rockin-SWAD](https://github.com/Pelochus/rockobot/blob/main/printables/images/swad-rockin.png)

### Rockobot Gearbox
Designed as a separate part, included to the Core design. Due to having 2 versions, (one independent to the core, the other is the integration) the Fusion 360 design is slightly messy. We recommend looking at the Adapted-To-Core version, which is more updated. There are various gears, a cylinder which represents the motor and the actual gearbox.

![GearBox-NoGears](https://github.com/Pelochus/rockobot/blob/main/printables/images/gearbox-nogears.png)

### Rockobot Shield
Can be 3D printed, but it is designed to be done with a metal sheet and a laser cutter. The design includes some holes for screwing the US sensor, but we did not use them in the final design because it fitted exactly in the holes for the sensor. In Fusion we use 2 mm thickness, but we built it with 1 mm (we started getting to close to the 4 kg limit...) and also increased the curved ramp length a bit (about 20 mm). **Inox Steel 403** is the material used. Thanks to Pelochus' dad for actually doing this piece (we obviously did not have access to a laser cutter...). 

![Rockobot-Shield](https://github.com/Pelochus/rockobot/blob/main/printables/images/shields.png)

### Outer Connector and Tracks
Extracted from a FPV Rover Tank from Thingiverse ([thanks to the guy who designed and published it](https://www.thingiverse.com/thing:1240754)). Both the track, outer connector and cogs where oversized by about 130% from the original design. There are also heavy modifications to the outer connector to adapt it to our design. The design is basically a simplified version of a real tank, in which the cogs apply the forces to the tracks and the outer connector serves as a structure to keep it all connected.

![OuterConnector-Tracks](https://github.com/Pelochus/rockobot/blob/main/printables/images/tracks.png)

## Enhancing 3D prints strength
To enhance 3D prints strength, there are various techniques and slicer settings to adjust. These settings assume a **0.4 mm nozzle**, but it can be done with similarly sized nozzles. **Unless otherwise specified these are the common settings**:
- 215/250ºC Hotend and 60/75ºC Bed temperatures for PLA+/PETG respectively
- 50 mm/s speed, 60 mm/s for bigger parts, 40 mm/s for smaller, stronger parts.
- 4 walls, 0.4 mm thickness per wall
- Cubic/Cubic Subdivision/Grid Infill Type. We recommend (and used) cubic subdivision for strength in all axes and also to lower the amount of plastic used
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
| Cogs / Gears      | PETG       | 25%  | 100%   | No      | No      |              |


There were some TPU prints (tracks). The settings where these:
- 225ºC Hotend / 55ºC Bed
- 30 mm/s speed
- 3 walls, 0.4 mm thickness per wall
- Grid Infill Type / 10% infill. Infill can be changed if extra flexibility is desired.
- 80% Fan
- 0.16 mm layer height

It's worth mentioning that threaded inserts where used throughout the whole design. Using bare holes in 3D printing for screws is generally not a good idea,
that's why we decided to use threaded inserts, allowing better repairability and strength. They also require to have 1.6 mm walls, that is why that setting is 4 walls instead of the common 3 walls. Below there is a link in which CNC Kitchen explains how to design holes for 3D printable parts and threaded inserts.

## Mechanical designs
### Motor reduction through gears
Since we used two motors from an old VHS player, we had to reduce the speed of these. We incorporated a gearbox to the Motors Floor with various gears in it, achieving a **reduction of 85,75:1** (3.5<sup>3</sup> x 2). This way, we reduce our robot to a reasonable, controllable speed and we get **lots of extra torque**, which is critical for pushing (which is this robot's main purpose). The gearbox is adapted to both the Motors Floor, and to the Outer Connector and related pieces (the Main Cog that goes as the last gear was also from the guy who inspired our tracks).

![GearBox implemented into the design](https://github.com/Pelochus/rockobot/blob/main/printables/images/integrated-gearbox.png)

## Ideas
Some ideas for future revisions:
- Think about an easy way of adding weigh to the robot. This is in order to get as close as possible to the 4kg limit, without surpassing it before final design
- Reduce the number of screws and reduce the variety between them, for example, change the frontal MC to M3, to be the same as the back ones (or viceversa)
- Use more PETG and/or ABS/ASA. PETG is better for parts that require some give, flexibility and reduced friction (floors, guides). ABS/ASA is recommended for parts that need to be impact and heat resistant (gears, outer connectors). PETG has better layer adhesion.
- Redesign from zero if want lots of changes, because some sketches and other Fusion features are a bit messy
- Use more parametric dimensions
- Improve structure and think how to reduce filamente use along the way
- Think about a simpler version with wheels and 4 motors (as an alternative, speedier version, more than an upgrade) 

## Knowledge Base
- [Tank where the tracks design was extracted](https://www.thingiverse.com/thing:1240754)
- [3D printing Tricks](https://youtu.be/krrqydtneO0)
- [Designing for Threaded Inserts](https://www.cnckitchen.com/blog/tipps-amp-tricks-fr-gewindeeinstze-im-3d-druck-3awey)
- [Strengthening through texturing by CNC Kitchen](https://youtu.be/3-ygdNQThAs)
- [Transparent and strong PETG settings by CNC Kitchen](https://www.youtube.com/watch?v=9qb25Gi4Jv0)
