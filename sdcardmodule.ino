#include <TMRpcm.h>
#include <SD.h>
#include <SPI.h>

TMRpcm audio;

const int chipSelect = 10;
const int speakerPin = 9;

const int nextButtonPin = 2;
const int prevButtonPin = 3;

int totalTracks = 4;        // Set this to number of tracks
int currentTrack = 1;

void setup() {
  Serial.begin(9600);

  pinMode(nextButtonPin, INPUT_PULLUP);
  pinMode(prevButtonPin, INPUT_PULLUP);

  if (!SD.begin(chipSelect)) {
    Serial.println("SD card failed");
    return;
  }

  audio.speakerPin = speakerPin;
  audio.setVolume(9);
  playCurrentTrack();
}

void loop() {
  static bool nextPressed = false;
  static bool prevPressed = false;

  // Next button
  if (digitalRead(nextButtonPin) == LOW) {
    if (!nextPressed) {
      currentTrack++;
      if (currentTrack > totalTracks) currentTrack = 1;
      playCurrentTrack();
      nextPressed = true;
    }
  } else {
    nextPressed = false;
  }

  // Previous button
  if (digitalRead(prevButtonPin) == LOW) {
    if (!prevPressed) {
      currentTrack--;
      if (currentTrack < 1) currentTrack = totalTracks;
      playCurrentTrack();
      prevPressed = true;
    }
  } else {
    prevPressed = false;
  }
}

void playCurrentTrack() {
  char filename[10];
  sprintf(filename, "%d.wav", currentTrack);
  Serial.print("Playing: ");
  Serial.println(filename);
  audio.stopPlayback();  // Stop previous audio
  audio.play(filename);
}