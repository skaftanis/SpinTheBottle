/*

### Boukala with arduino

by Dimitris Xarir, Spiros Kaftanis 
ShowMeYourCode.co.nf arduino project

Version 1.0
Release Date: 03/10/2015

### GPL License

  This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.    
    See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

### About ShowMeYourCode

ShowMeYourCode is a new website where you can post your open source application for free and get money from donations. We want to create a big open source community we much more tools in the future. We are just in the beginning, so if you have an open source application and you want to earn some money and reputation, join us. http://showmeyourcode.co.nf/﻿
You have already have some great applications for pc, android, linux, web and many insteresting programming tutorials. 

*/



int DS_pin = 8;
int STCP_pin = 9;
int SHCP_pin = 10;

const int buttonPin = 12;
int buttonState = 0;

int luck[] = {0, 1};

void setup()
{
  
pinMode(DS_pin,OUTPUT);
pinMode(STCP_pin,OUTPUT);
pinMode(SHCP_pin,OUTPUT);
pinMode(11, OUTPUT); //moter
pinMode(12, INPUT); //button
writereg();


}

boolean registers[16];

void writereg()
{
  digitalWrite(STCP_pin, LOW);
  for (int i = 15; i>=0; i--)
  {
    digitalWrite(SHCP_pin, LOW);
    digitalWrite(DS_pin, registers[i] );
    digitalWrite(SHCP_pin, HIGH);
  }
  digitalWrite(STCP_pin, HIGH);
}

void loop()
{
  
buttonState = digitalRead(buttonPin);
if (buttonState == HIGH) {
   
    //moter on-off
    digitalWrite(11, HIGH);
    delay(random(500,2500));
    digitalWrite(11, LOW);
    
   //seira----------
   for (int k=0; k<3; k++) {
        for(int i = 0; i<16; i++) { 
        registers[i] = HIGH;
        delay(50);
        writereg();
       if (i > 0)  {
         registers[i-1]=LOW;
          writereg();
       }
        }
    
      for(int i = 15; i>0; i--)
      {
        registers[i] = LOW;
        delay(50);
        writereg();
      }
   }
  //----------------
  
  //led choice
  registers[random(0,15)]=HIGH;
  writereg();
  
}

  
}

