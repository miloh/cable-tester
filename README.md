Generic cable tester shield for arduino megas
=============================================
Good for reprap users and hobbyists to test standard cables with 0.100"(2.54mm) wire to board connections,  and possibly 0.050"(1.25mm) and 0.100" ribbon headers via a connected prototyping area

INTRODUCTION:
-------------
this simple ribbon cable testrig tests continuity for Series One 2014 ribbon cables and pcbs

test rig plugs into a arduino mega body and uses the accompanying arduino
sketch to signal each pin sequentially, allowing the user to check for shorts or opens.

OPERATION:
----------
Signal path continuity is tested sequentially by making pin(N) high which
lights up a specific LED for the connection.  If there is an open circuit from a bad solder joint or crimp
in the cable, the led won't light up.  If there is a short between the pins then multiple leds will light up from a single input. 

The next revision will be pcb based and allow for specific line testing. See
the TO DO at the end of this document.

TEST COMPONENTS
---------------
6 way  24AWG power cables connected with molex 1x6 microfit connection to pcb
20 way 30AWG 0.025" ribbon connected with 20-way EHF samtec connection to pcb
26 way 30AWG 0.025" ribbon connected with 26-way EHF samtec connection to pcb

just need a set of dongles for testing the connection back:

VDC (1x2 micro fit 3.0mm)
HEATS (1x4 micro fit 3.0mm)

Dongle set for endstops (2x12 0.100" header) 
E0 Motor dongle (1x4 c-grid to 1x4 c-grid)
E1 Motor (1x4 c-grid to 1x4 c-grid)
X Motor (1x4 c-grid to 1x4 c-grid)
Thermistor block (1x4 c-grid to 1x4 c-grid)
Fan0 and Fan1 ( (1x4 c-grid to 1x4 c-grid)
Aux   (1x4 c-grid to 1x4 c-grid)

dongle set for Y motor chassis connect
dongle set for Z motor chassis connect

molex c-grid also is compatible  with molex sl

backplane breakout (bpbo) pcb can be connected with KG 6-way and 26 way cable and ramps/rumba dongles
gantry (gbo) pcb should be connected with KG 6-way and 26 way cable, dongle and 20-way cable
carriage (cbo) pcb should be connected with KG 6-way and 20way cable, and motor/heat/fan/extruder dongles as required

TO DO
-----

In the following versions shorting can be determined by making pin(53-N) low.

for example, at pin(1) becomes high and pin(52) becomes low.  if there is a
connetion to test between them (a ribbon cable connecting out from pin 1and pcb-dongle assembly
connecting back to 52), then the GREEN LED will light up and the test
will proceed.  

Otherwise a warning Red led will flash. 

At pin 26,  pin(26) and pin (27)  are tested. The inversion scheme is just to
simplify the pcb layout. 

There are jumper spots and pushbuttons on the board to sanity test the test
device itself.

This current method tests well for shorts and open circuits, but we need a way
to test intermittant open circuits and high frequency connections between
circuits. what is this behavior?  we can send a simple known signal with the send pin and if the
receive pin doesn't get it, then we can start to characterize open or distorted
intermittant connections. This would require a slightly more complex circuit
that has individual multi color outputs for each channel. 
