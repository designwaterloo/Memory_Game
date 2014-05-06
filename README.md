Memory Game
===========

Simple application for teaching basic circuit design and microcontroller capabilities. Includes setup mode operation, and a memory game with coloured LEDs and audio output. 

Gameplay
---------

* When the device is powered up (by connecting the battery), all four LEDs will blink in sequence and a two note melody will play.
* To enter gameplay mode, press the ‘S2’ switch on the microcontroller board.
* When the device enters gameplay mode, all four LEDs will blink in sequence and a six note melody will play.
* This will be immediately followed by a single blink of an LED, and a corresponding single note will be played.
* The object of the game is to copy the sequence using the corresponding buttons.
* If the sequence is copied correctly, the sequence will replay with the addition of a new LED flash and note.
* If you copy the sequence incorrectly, a low tone will play and the game will restart.
* You can replay your highscore at anytime by pressing the ‘S2’ switch while in gameplay mode.
* You can reset the entire device by pressing the ‘RESET’ switch or temporarily disconnecting the power source.

Folder Contents
---------------

**Memory_Game/Memory_Game** - Source code for this project.  Written for [Energia] (http://energia.nu/).

**Memory_Game/Fritzing** - Schemtic files creted using [Fritzing] (http://fritzing.org/).

**Memory_Game/Documentation** - Detailed assembly instructions, gameplay information, presentation material, and BOM.

**Presentation Material** - http://prezi.com/puz2dcljfam3/?utm_campaign=share&utm_medium=copy&rc=ex0share

Licenses
========

Documentation
-------------
This work is licensed under the Creative Commons Attribution 4.0 International License. To view a copy of this license, visit http://creativecommons.org/licenses/by/4.0/.

Software
--------

Software License Agreement (BSD License)
Copyright (c) 2014, Ryan Walker
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer. 
2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

The views and conclusions contained in the software and documentation are those
of the authors and should not be interpreted as representing official policies, 
either expressed or implied, of the FreeBSD Project.

