/*
             _          __                                           
  /\/\   ___| |_ __ _  / _\ ___  __ _ _   _  ___ _ __   ___ ___ _ __ 
 /    \ / _ \ __/ _` | \ \ / _ \/ _` | | | |/ _ \ '_ \ / __/ _ \ '__|
/ /\/\ \  __/ || (_| | _\ \  __/ (_| | |_| |  __/ | | | (_|  __/ |   
\/    \/\___|\__\__,_| \__/\___|\__, |\__,_|\___|_| |_|\___\___|_|   
                                   |_|                               
                                                         // by microbe modular
// =============================================================================
       
Copyright 2014 Bret Truchan / John Staskevich

  The Meta Sequencer source code is free software: you can redistribute it 
  and/or modify it under the terms of the GNU General Public License as 
  published by the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

Credits:
  Circuit/PCB design, parts selection, and manufacturing oversight by John Staskevich
  Front panel design by Hannes Pasqualini

Parts:
  DAC: MCP4725 - http://www.adafruit.com/datasheets/mcp4725.pdf
  LED Driver: AS1115 - http://www.ams.com/eng/content/download/18430/343782
  EEPROM: 24LC256 - http://ww1.microchip.com/downloads/en/DeviceDoc/21203M.pdf

TODO:  
  - get rid of sequencer object?
  - test manual stepping
  - test manual reset
  - line by line code review
  - update factory reset

Bugs
  - 

Waiting for John
  - When ram is replaced, see if I can remove the delay after writes

Ram links
  - http://www.fujitsu.com/downloads/MICRO/fme/fram/datasheet-fram-mb85rc64.pdf
  - library for fram: https://github.com/sosandroid/FRAM_MB85RC_I2C

Notes on memory

* the fram I sent John is 8,192 words, where a word is 8 bytes.  So, that's 
  4096 16-bit values.  A pattern is 64 16-bit values.  4096 / 64 = 64.  So,
  technically, I should have plenty of memory.

  
// =========================== - 80 column - ===================================
12345678901234567890123456789012345678901234567890123456789012345678901234567890

*/

#include <Wire.h>
#include <avr/pgmspace.h>
#include "GlobalScales.h"
#include "Engine.h"

Engine *engine = new Engine();

void setup() 
{
  // set unused pins as outputs to prevent floating
  pinMode(4,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  
  engine->init();
}

void loop() 
{
  engine->loop();
}