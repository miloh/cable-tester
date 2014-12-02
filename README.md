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
* 26 way 30AWG 0.025" ribbon connected with 26-way EHF samtec connection to pcb

(unimplemented)
<block>6 way  24AWG power cables connected with molex 1x6 microfit connection to pcb
just need a set of dongles for testing the connection back:
* 20 way 30AWG 0.025" ribbon connected with 20-way EHF samtec connection to pcb

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
</block>
molex c-grid also is compatible  with molex sl

the current config is still useful:
backplane breakout (bpbo) pcb can be connected with 2 26 way cable, and gantry(gbo) or carriage(cbo) pcbs to test devices

a few words about toolpath gen with pcb's gcode export
------------------------------------------------------
pcb has a gcode export that formats files with a #NUMBER meant to be
replaced with a specific value

use the following stanza in bash to see the commands: 
egrep "#10.=" cable-tester-top.gcode

use the following sed command to get rid of them
sed -i s/Z\#100/Z'${VAR}'/g

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



From an email Using the hardware (sort this out)
------------------------------------------------
pdf downloads of the schematic are available in the bitbucket downloads: 
https://bitbucket.org/miloh/series1-ribboncable-pcb-testrig/downloads

bitbucket issue tracker:
https://bitbucket.org/miloh/series1-ribboncable-pcb-testrig/issues?status=new&status=open

You can use the initial form of the ribbon cable tester for the 26 and 20 pin high density cable runs. It will also test the pcb traces that connect those runs using the same config.

This project still requires known good ('KG') hardware in order to reliably determine faults in the device under test.  So, you hook up *two* KG 26
ribbon 'Gantry' cables to the board, and between them you can hook up an assortment of gantry pcb, x ribbon cable, backplane board, etc. in order to test the signal path in a single component.

Assemble spare parts (make sure they are KG!) to build the most valuable test configuration to start (I imagine this is the 20 pin cable in the X ribbon cable.) I didn't include the 6 pin cable because it didnt' fit the number of pins I had free for my testing scheme, *and* because it is super easy to test with a DMM.  The 20/26 pin cables are however far
harder to test with a DMM.

So what does it need still?  It needs users to help develop it by filing issues (use bitbucket above, or the github repo which is a clone of the same).  And it needs someone to combine 3 arduino sketches together in a sensible, simple fashion and submit a pull request to the repos linked above.

The three arduino sketches to combine are: 'timed blink', 'toneMelody' and Adafruit's OLED libraries (which are actually two libraries). I started a sketch folder with a .ino file in the repo as a guide.   


Summary of sketches to combine:
Timed Blink and the schematic from the downloads can be used to quickly create a sketch that blink the 26 indicator lights on a standard schedule (see the attached schematic to figure out which pins
control which output).

'toneMelody' can be used to create audio output accompanying every blink or maybe a fault or a test success or test failure, whatever you think is best.  

And finally, adafruit's SPI OLED library and GFX libary need to be incorporated.  That's low priority really, but if you want to give it a try you can get started by there are two libaries Adafruit
developed:  one driver library for oleds (spi or i2c) and one graphic effects of 'GFX' library, for the wigets/animates.


issues to improve it can be filed on my bitbucket or github repos:
https://github.com/miloh/cable-tester/issues


