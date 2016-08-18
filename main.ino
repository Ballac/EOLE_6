/*
 * Copyright (c) 2014, Majenko Technologies
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 * 
 * * Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 * 
 * * Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 * 
 * * Neither the name of Majenko Technologies nor the names of its
 *   contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */


#include <Widgets.h>
#include <DSPI.h>
#include <TFT.h>
#include <BMPFile.h>
#include <SD.h>

const int buttonPin = 2;     // the number of the pushbutton pin
const int Btn_config = 7;   // Bouton de configuration
const int Pompe = 8;        // sortie commande pompe
const int EV_off = 9;         // sortie EV off
const int EV_on = 10;       // sortie EV on
const int ledPin =  13;      // the number of the LED pin


// Configure the display
PICadillo35t tft;
AnalogTouch ts(LCD_XL, LCD_XR, LCD_YU, LCD_YD, 320, 480);

void setup() {
	analogWrite(PIN_BACKLIGHT, 255);
	tft.initializeDevice();
	ts.initializeDevice();
  ts.scaleX(4.3);
  ts.scaleY(3.3);
  ts.offsetY(5);
	tft.setRotation(1);
	tft.fillScreen(Color::Black);
	tft.setFont(Fonts::Topaz);
	tft.setTextColor(Color::White, Color::Black);	
  if (!SD.begin(PIN_SD_SS)) {
    tft.print("Carte SD absebte");
    while(1);
  }
  pinMode(Btn_config, INPUT);     
}

void Config(){
    
}

void loop() {
	    File f = SD.open("/images/logo.bmp");
      BMPFile bmp(f);
      delay(5000);
      tft.fillScreen(Color::White);
      if (digitalRead(Btn_config)== HIGH)
              Config();     
}
