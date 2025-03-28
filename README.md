# ChuniXR IO

Not enough is done for me to make an actual instruction booklet on how to use this.

## Specification on protocol

What was provided by S\*tools in it's LED protocol will be reused here because it generally works fine.<br>
Sync character is 0xE0. 0xD0 signifies an escape character and should be ignored, and the next character +1 should be applied instead.

### Types of commands

*From S\*tools*
- `0x00`: Left billboard (and accents)
- `0x01`: Right billboard  (and accents)
- `0x02`: Slider LEDs

*New*

- `0x03`: Slider input<br>
    First byte afterwards is the index (odd is bottom, even is top) and the second is it's value. (0 to 255)
- `0x04`: Air input<br>
    Similarly to slider input, first byte is the index, second is it's value (0 to 1)
- `0x05`: Non-specific input
    - `0x00`: Test
    - `0x01`: Service
    - `0x02`: Coin
- `0x06`: Card (future)<br>
    First byte will signify the card type (tbd),<br>
    The following will be lengthed based on the card type.