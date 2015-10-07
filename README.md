What we have here..??

The circuit contains an arduino pro mini, two 74hc595 8 bit shift register, a dc motor, a transistor, a diode, a swich and 16 led along with 16 resistors.

When we pres the swich the dc motor starts speening for an x amount of time, x is different every time. Then the leds light up one at a time with 50 ms its led, three time in a row an and after that one random led lights up. Its les correspondence to a diffrent task.

Let's explain the circuit. Pin 6 of the arduino witch is set as an input pin is connected via 20K resistor to groud so the pin 6 is low (0 volts).Often it is useful to steer an input pin to a known state if no input is present. This can be done by adding a pullup resistor (to +5V), or a pulldown resistor (resistor to ground) on the input.Arduino has 20K pullup resistors built into the Atmega chip that can be accessed from software. These built-in pullup resistors are accessed by setting the pinMode() as INPUT_PULLUP. This effectively inverts the behavior of the INPUT mode, where HIGH means the sensor is off, and LOW means the sensor is on. We used a pulldown resistor so when we pres the switch Vcc is coneced to pin 6 .Input pins make extremely small demands on the circuit that they are sampling, equivalent to a series resistor of 100 megohm in front of the pin. This means that it takes very little current to move the input pin from one state to another.


Pin 7 is set as an output.Pins configured as output with pinMode() are said to be in a low-impedance state. This means that they can provide a substantial amount of current to other circuits. Atmega pins can source (provide positive current) or sink (provide negative current) up to 40 mA (milliamps) of current to other devices/circuits. This is enough current to brightly light up an LED (don't forget the series resistor), or run many sensors, for example, but not enough current to run most relays, solenoids, or motors. Becauso 40 mA is not enough for the cd motor we used, we connected pin 7 via 1K resistor to the base of an NPN transistor that can handles a lot more current.What’s the diode used for?
Any time you are powering a device with a coil, such as a relay, solenoid, or motor, you need this guy, and don’t leave home without it. What happens is when you stop powering the coil, a reverse voltage, up to several hundred volts, spikes back. This only lasts a few microseconds, but it is enough to kill our transistor. So this diode (only allows current to pass one way) is normally facing the wrong direction and does nothing. But when that voltage spikes comes flowing the opposite direction, the diode allows it to flow back to the coil and not the transistor. We will need a diode fast enough to react to the kickback, and strong enough to take the load. A rectifier diode like the 1N4001 or SB560 should do the job. If you are looking for extra protection you could use an optoisolator between the Arduino and the transistor. An optoisolator optically isolates both sides (high and low power) of the circuit so the high-voltage can not possibly come back to the microcontroller.

Just make sure that protection diode is facing the correct way (stripe facing the V+ of device). If it is facing the wrong direction, the device you are trying to power will not work as the diode will just allow the current to bypass it.

The last part of the circuit it the shift registers. To cotrol x number of shift registers we need only 3 pins of our microcontroller. Let's see what its pin of the shift register do.

Q0 Q1 Q2 Q3 Q4 Q5 Q6 Q7 are the parallel data  output, 
Q7S serial data output, 
MR' master reset (active LOW), 
OE' output enable input (active LOW), 
SHCP shift register clock input, 
STCP  storage register clock input, 
DS serial data input, 
GND ground, 
Vcc supply voltage. 
MR' is conacted to Vcc (5 Volt) so it will de disabled  OE is conacted to ground to enable the output, Q7S from the top shifte register is connacted to the  DS of the down shift register, GND to ground Vcc to 5V DS of the top shift register is conacted the pin 8 on the arduino, STCP to pin 9 on the arduino and SHCP no the to pin 10. STCP SHCP MR' and OE' have the same input in both shift registers. Q0 Q1 Q2 Q3 Q4 Q5 Q6 Q7 are conacted to a 220 ohm resistor an then to the anode of the leds the led cathodes are conacted to ground.

