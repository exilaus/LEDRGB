LEDRGB
======

Raspberry Pi deamon for manage 12v rgb led strip


Derived hw schema from :  mitchtech.net/raspberry-pi-pwm-rgb-led-strip/
Default in this project pin are 22 - 24 - 26 of Raspberry Pi.
```
22- Red
24- Green
26- Blue
```

After compile launch it in back ground and recall it with kill signal usr1 it read/execute LEDRGB.INI information.

LEDRGB.INI is composed from 5 text line, example:

```
0
40
34
55
100
```

Where:
```
1th line are option 0=customize your color 1=demo1 2=demo2
2th line are delay for demo
3th line for RED (values from 0 to 100)
4th line for GREEN (values from 0 to 100)
5th line for BLUE (values from 0 to 100)
```
In this example led set color at R=34 G=55 B=100
