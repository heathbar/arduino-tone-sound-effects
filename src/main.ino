// some effects sourced from https://bikeshedeffect.weebly.com/arduino-piezo-sounds.html

#include <Arduino.h>
#include "pitches.h"

const uint8_t SPEAKER_PIN = 11;

void setup()
{
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  digitalWrite(12, LOW);
  randomSeed(analogRead(A0));
}

void tone_blocking(long frequency, long length)
{
  tone(SPEAKER_PIN, frequency, length);
  delay(length);
}

void coin()
{
  tone_blocking(NOTE_B5, 100);
  tone_blocking(NOTE_E6, 750);
  noTone(SPEAKER_PIN);
}

void oneUp()
{
  tone_blocking(NOTE_E6, 125);
  tone_blocking(NOTE_G6, 125);
  tone_blocking(NOTE_E7, 125);
  tone_blocking(NOTE_C7, 125);
  tone_blocking(NOTE_D7, 125);
  tone_blocking(NOTE_G7, 125);

  noTone(SPEAKER_PIN);
}

void fireBall()
{
  tone_blocking(NOTE_G4, 35);
  tone_blocking(NOTE_G5, 35);
  tone_blocking(NOTE_G6, 35);
  noTone(SPEAKER_PIN);
}

void levelClear()
{
  tone_blocking(NOTE_G3, 111);
  tone_blocking(NOTE_C4, 111);
  tone_blocking(NOTE_E4, 111);
  tone_blocking(NOTE_G4, 111);
  tone_blocking(NOTE_C5, 111);
  tone_blocking(NOTE_E5, 111);
  tone_blocking(NOTE_G5, 333);
  tone_blocking(NOTE_E5, 333);
  tone_blocking(NOTE_E3, 111);
  tone_blocking(NOTE_C4, 111);
  tone_blocking(NOTE_DS4, 111);
  tone_blocking(NOTE_GS4, 111);
  tone_blocking(NOTE_C5, 111);
  tone_blocking(NOTE_DS5, 111);
  tone_blocking(NOTE_GS5, 333);
  tone_blocking(NOTE_DS5, 333);
  tone_blocking(NOTE_AS3, 111);
  tone_blocking(NOTE_D4, 111);
  tone_blocking(NOTE_F4, 111);
  tone_blocking(NOTE_AS4, 111);
  tone_blocking(NOTE_D5, 111);
  tone_blocking(NOTE_F5, 111);
  tone_blocking(NOTE_AS5, 333);
  delay(33);
  tone_blocking(NOTE_AS5, 111);
  delay(33);
  tone_blocking(NOTE_AS5, 111);
  delay(33);
  tone_blocking(NOTE_AS5, 111);
  tone_blocking(NOTE_C6, 1333);
}

void eightBitTick()
{
  tone_blocking(250, 2);
  tone_blocking(250, 2);
  tone_blocking(250, 2);
  tone_blocking(250, 2);
  tone_blocking(250, 2);
}
void eightBitTock()
{
  tone_blocking(100, 5);
  tone_blocking(100, 5);
  tone_blocking(100, 5);
}

void sharpClockTick()
{
  tone(11, 100, 3);
  delay(2);
  tone(11, 250, 3);
  delay(2);
  tone(11, 600, 3);
  delay(2);
  tone(11, 500, 3);
  delay(2);
  tone(11, 250, 3);
  delay(2);
  tone(11, 100, 3);
  delay(2);
  tone(11, 50, 3);
  delay(2);
}

void sharpClockTick2()
{
  tone(11, 100, 3);
  delay(5);
  tone(11, 250, 3);
  delay(5);
  tone(11, 600, 3);
  delay(5);
  tone(11, 500, 3);
  delay(5);
  tone(11, 250, 3);
  delay(5);
  tone(11, 100, 3);
  delay(5);
  tone(11, 50, 3);
  delay(5);
}

void anotherClockTick()
{
  tone_blocking(100, 5);
  tone_blocking(250, 5);
  tone_blocking(2000, 1);
  tone_blocking(4000, 1);
  tone_blocking(2000, 1);
  tone_blocking(4000, 1);
}

void blaster()
{
  for (int i = 1200; i > 800; i-= 16)
  {
    tone_blocking(i, 8);
  }
}

void blaster2()
{
  for (int i = 1000; i > 600; i -= 4)
  {
    tone_blocking(i, 3);
  }
}

void blaster3()
{
  for (int i = 2000; i > 600; i -= 64)
  {
    tone_blocking(i, 10);
  }
}

void whiteNoise(int duration)
{
  for (int i = 0; i < duration; i++)
  {
    int freq = random(400, 600);
    tone_blocking(freq, i % 3);
    noTone(SPEAKER_PIN);
  }
}


void loop()
{
  blaster();
  delay(10);
  blaster();
  delay(10);
  blaster();
  delay(10);

  delay(2000);

  blaster2();
  delay(25);
  blaster2();
  delay(25);
  blaster2();
  delay(25);

  delay(2000);
  
  blaster3();
  delay(10);
  blaster3();
  delay(10);
  blaster3();
  delay(10);

  delay(2000);

  eightBitTick();
  delay(1000);
  eightBitTock();
  delay(1000);
  eightBitTick();
  delay(1000);
  eightBitTock();
  delay(1000);

  delay(2000);

  sharpClockTick();
  delay(1000);
  sharpClockTick();
  delay(1000);
  sharpClockTick();
  delay(1000);
  sharpClockTick();
  delay(1000);
  
  delay(2000);

  sharpClockTick2();
  delay(1000);
  sharpClockTick2();
  delay(1000);
  sharpClockTick2();
  delay(1000);
  sharpClockTick2();
  delay(1000);
  
  delay(2000);

  anotherClockTick();
  delay(1000);
  anotherClockTick();
  delay(1000);
  anotherClockTick();
  delay(1000);
  anotherClockTick();
  delay(1000);

  delay(2000);

  coin();
  delay(2000);

  oneUp();
  delay(2000);

  fireBall();
  delay(2000);

  levelClear();
  
  delay(2000);

  whiteNoise(2000);
  delay(2000);

  while(1);
}