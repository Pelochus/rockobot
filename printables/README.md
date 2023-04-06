# Printables and Mechanics
This section will focus on the printables and mechanics side of Rockobot

## Components

| Component             | Units | Notes                         |
| --------------------- | ----- | ----------------------------- |
| Motor                 | 4     | Extracted from old toy car    |
| PLA+                  | 200 g | Weight is estimated           |
| Transpartent PETG     | 100 g | Weight is estimated           |
| TPU 95A               | 200 g | Weight is estimated           |
| M4 Screws             | 20    |                               |
| M4 Threaded Insert    | 20    | Inox Steel                    |

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
Info about designs, pictures, why it was designed that way

## Enhancing 3D prints strength
To enhance 3D prints strength, there are various techniques and slicer settings to adjust. There is a [gcode](https://github.com/Pelochus/rockobot/tree/main/printables/gcodes) section where the gcodes of each part with the following settings are stored. **Unless otherwise specified these are the common settings**:
- 220/250ºC Hotend and 65/70ºC Bed temperatures for PLA+/PETG respectively
- 40 mm/s speed
- 5 walls, 0.4 mm thickness per wall
- Cubic Infill Type
- Avoid supports if possible
- Prints must be intelligently aligned with the axes so that the forces that will be applied are not ripping layers apart

| Part              | Material   | Fan  | Infill | Support | Ironing | Extras       |
| ----------------- | ---------- | ---- | ------ | ------- | ------- | ------------ |
| Fillable Base     | PLA+       | 25%  | 30%    | No      | Yes     |              |
| Motors Base       | PLA+       | 25%  | 40%    | Yes     | No      |              |
| Electronics Base  | PLA+       | 25%  | 40%    | Yes     | No      |              |

There were some TPU prints (tracks). The settings where these:
- 225ºC Hotend / 55ºC Bed
- 30 mm/s speed
- 3 walls, 0.4 mm thickness per wall
- Grid Infill Type / 10% infill
- 80% Fan
- 0.16 mm layer height

## Mechanical designs
Info about how motors where connected to the battlebot, how torque was improved...

## Ideas
- 3D print the wok
- Think about an easy way of adding weigh to the robot. This is in order to get as close as possible to the 4kg limit, without surpassing it before final design.

## Knowledge Base
- [Tank where the tracks design was extracted](https://www.thingiverse.com/thing:1240754)
- [3D printing Tricks](https://youtu.be/krrqydtneO0)
- [Strengthening through texturing by CNC Kitchen](https://youtu.be/3-ygdNQThAs)
- [Maker's Muse Mini BattleBot as inspiration](https://www.youtube.com/watch?v=BvNRtRuOALw)
- [Improved version of previous Mini BattleBot](https://www.youtube.com/watch?v=YWOqAwXmvJU)
- [Transparent and strong PETG settings by CNC Kitchen](https://www.youtube.com/watch?v=9qb25Gi4Jv0)
