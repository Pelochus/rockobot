# Printables and Mechanics
This section will focus on the printables and mechanics side of Rockobot

## Components

| Component             | Units | Notes                         |
| --------------------- | ----- | ----------------------------- |
| Motor                 | 2     | Extracted from old VHS        |
| PLA/PLA+              | 500 g | Weight is estimated           |
| TPU 95A               | 200 g | Weight is estimated           |
| M3x8 Screws           | 20    |                               |
| M3x20 Screws          | 20    |                               |
| M4x60 Screws          | 64    | Used in tracks                |
| M4 Stop Nuts          | 64    | Used along the M4 screws      |
| M3 Threaded Insert    | 30    | Ruthex Brand                  |
| M3x80 Threaded Rod    | 4     |                               |

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

#### Electronics Floor

#### Top Layer

#### Rockins

### Rockobot Gearbox

### Rockobot Shield

## Enhancing 3D prints strength
To enhance 3D prints strength, there are various techniques and slicer settings to adjust. There is a [gcode](https://github.com/Pelochus/rockobot/tree/main/printables/gcodes) section where the gcodes of each part with the following settings are stored. **Unless otherwise specified these are the common settings**:
- 220/250ºC Hotend and 65/70ºC Bed temperatures for PLA+/PETG respectively
- 50 mm/s speed
- 4 walls, 0.4 mm thickness per wall
- Cubic/Cubic Subdivision/Grid Infill Type
- Avoid supports if possible
- Prints must be intelligently aligned with the axes so that the forces that will be applied are not ripping layers apart

| Part              | Material   | Fan  | Infill | Support | Ironing | Extras       |
| ----------------- | ---------- | ---- | ------ | ------- | ------- | ------------ |
| Fillable Base     | PLA+       | 25%  | 25%    | No      | No      |              |
| Motors Floor      | PLA+       | 50%  | 15%    | No      | No      |              |
| Electronics Floor | PLA+       | 25%  | 10%    | No      | No      |              |
| Top Layer         | PLA+       | 25%  | 10%    | No      | No      |              |
| The Rock Rockin   | PLA+       | 25%  | 5%     | Yes     | Yes     |              |
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
that's why we decided to use threaded inserts, allowing better repairability and strength. Below there is a link in which CNC Kitchen explains how to design holes for 3D printable parts 

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
