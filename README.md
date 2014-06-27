AquariumLights
==============

Overkill aquarium light build
-----------------------------

This is a place to synchronise development of a massively over-engineered set of aquarium lights.

The general idea for the lights is for them to brighten up to daylight-like colours during the day, and dim to a low level blue at night.

To accomplish this we're building the system out of an Arduino clone, a string of RGB LED lights, some MOSFETs, a RTC and an Ethernet controller.

Why the Ethernet controller?  So the lights can be remotely controlled, of course!
