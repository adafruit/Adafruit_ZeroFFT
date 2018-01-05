#include "Adafruit_ZeroFFT.h"
#include "signal.h"

#define DATA_SIZE 2048

// the setup routine runs once when you press reset:
void setup() {
  Serial.begin(115200);
  while(!Serial);

  ZeroFFT(signal, DATA_SIZE);

  for(int i=0; i<DATA_SIZE; i++){
    Serial.println(signal[i]);
  }
}

void loop() {
  //don't even do anything
}
