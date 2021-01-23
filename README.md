# Magic Box of Transmutation

Example build video:
https://www.youtube.com/watch?v=79AKvBjL8Qg

The STEP file is included in case you want to make your own remixes.


### Additional Parts

It requires the Arduino Starter Kit:
https://www.amazon.com/gp/product/B009UKZV0A/

And a small breadboard:
https://www.amazon.com/gp/product/B07KGQ7H8B/

Some jumper cables are helpful:
https://www.amazon.com/gp/product/B01EV70C78/


### Printing Guide

This has three parts to print: Top, Bottom, and Spinner.  The STL files to import into your slicer are provided.

![CAD Preview](cad_preview.jpg)

I'd recommend orienting the parts as shown below on the printer bed so that the quality of the connecting bottom of the spinner is as high as possible:

![Print Guide](print_guide.jpg)

I used 0.2 mm layer height on a Prusa i3 and had good results.


### Assembly Guide

Insert the servo motor into the housing, pulling the wires through the hole.  Use hot glue all around the housing to rigidly fix the motor in the housing.

Insert the Arduino into the bottom, and screw it in with M3 screws that are 4-6 mm long, or just let it sit on the bottom.

Insert the kit's phototransistor into the 5 mm circular hole in the top, and hot glue it into place from inside the case.

The Arduino kit recommends adding a 100 uF capacitor between power and ground due to the motor current draw.  It also needs a resistor between the photoresistor negative lead and ground.  This stuff is all covered in the Arduino kit book, so glossing over it here.

The code assumes that the photoresistor is connected to A0, and the motor PWM (white) pin is connected to D13.


### Programming Guide

The source code is under `magic_box.ino`.

Just drop it into the Arduino IDE and upload it.
