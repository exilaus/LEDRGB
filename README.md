LEDRGB
======

Raspberry pi deamon for manage 12v rgb led strip


Hw schema from :  mitchtech.net/raspberry-pi-pwm-rgb-led-strip/


after compile launch it in back ground

recall process with kill signal usr1 it read LEDRGB.INI And execute it.



LEDRGB.INI need build with simple 5 line example:

0

40

34

55

100

Where:
1th line are option 0=customize your color 1=demo1 2=demo2

2th line are delay for demo

3th line for RED (values from 0 to 100)

4th line for GREEN (values from 0 to 100)

5th line for BLUE (values from 0 to 100)


