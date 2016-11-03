## Design
This device is designed to hopefully eliminate startup crap spewed by low-cost FPV video transmitters while their PLL isn't locked yet, sweeping through the whole TX band and interfering anyone nearby. 
What this does is switching the VTX output to a load during VTX startup and then, after a configurable amount of time, switch the VTX output back to the antenna. 
The key aspects of the design are getting a high enough isolation when the antenna is disconnected, being capable of eating the VTX output while it's switched to the load and not generating extra harmonics or distortion that could potentially interfere regulated bands.

This design is based on a Peregrine Semiconductor PE42423 6GHz absorprive RF switch, capable of eating +26 dBm into its embedded terminators and letting about 2W through with very good linearity specs.
It was selected because of previous satisfactory experience with Peregrine Semiconductors and because of the inherent robustness of their UltraCMOS technology compared to GaAs devices. Also, it's cheap and promises an isolation of 40 dB at 6 GHz which should be enough.

The RF path consists of the switch itself, an AC coupling capacitor for the antenna input (the video TX shoudn't output DC but just in case...), a 50 ohm termination load for the unused switch branch
and a 1M resistor (should be around 100k to 1M) to give a path for the DC bias current of the switches. Peregrine says that you can go without AC coupling caps if all switch IO's are kept at 0V DC, and someone from Peregrine
support told me that it was a good practice to add these bias resistors and where to add them. Reality agrees.

There's a PIC microcontroller to time and control the switch. Basically, supervisors/POR generator IC's were just as expensive as the PIC and this way you can program your delay time.

A 24V input capable and reverse polarity protected voltage regulator provides the 3.3V required by the switch and the PIC. As both devices consume about 400uA there are 1K resistors in series to act as power filter combined with the decoupling capacitors. Voltage drop across them is negligible.
