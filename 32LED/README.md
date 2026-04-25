# 32 LEDs Driving
System features a multi-channel LED driving architecture using constant-current LED driver ICs 
controlled by 18F6722. <br>
## System Overview
Microcontroller communicates with 4 cascaded driver ICs via a serial interface
with 4 signal wires: 
- SCK: synchronize clock, connect to **RD6/SCK2** pin
- SDI: serial data in, connect to **RD4/SDO2** pin
- LE0: enable data latch, connect to **RB3** pin
- OE: enable/disable module, connect to **RC5** pin

and then sending parallel data to buffer.
The driver IC sinks current from each LED channel to ground. When a channel is activated,
current flows from VCC - LED - driver - GND, turning the LED ON.

To control the system, we need a built-in CCS drivers: ``74595.c``

![Schematic](32LED/docs/schematic.png)

# Simulation
## led1.c
<p align="center">
  <img src="32LED/docs/led1.gif" width="600" />
</p>

## led2.c
<p align="center">
  <img src="32LED/docs/led2.gif" width="600" />
</p>

## led3.c
<p align="center">
  <img src="32LED/docs/led3.gif" width="600" />
</p>

## led4.c
<p align="center">
  <img src="32LED/docs/led4.gif" width="600" />
</p>

## led10.c
<p align="center">
  <img src="32LED/docs/led10.gif" width="600" />
</p>

## led11.c
<p align="center">
  <img src="32LED/docs/led11.gif" width="600" />
</p>

## led12.c
<p align="center">
  <img src="32LED/docs/led12.gif" width="600" />
</p>
