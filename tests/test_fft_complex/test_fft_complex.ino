#include "Adafruit_ZeroFFT.h"

static const int16_t DELTA_AMPLITUDE = (1 << 15) - 1;
static const int16_t N_MAX = 2048;

static int16_t x[N_MAX]{};
static int16_t y[2 * N_MAX]{};

void setup() {
  Serial.begin(115200);
  while(!Serial); //wait for serial port to be ready

  // create a delta function of maximum amplitude for a signed, 16-bit int.
  // all values except the first are set to zero.
  x[0] = DELTA_AMPLITUDE;

  // compute the error in the magnitude of the output over a range of sizes
  for (int N = 16; N <= N_MAX; N *= 2) {

    uint32_t start = micros();
    ZeroFFTRealToComplex(x, y, N, false);     // false == do not use window function
    int32_t dt = micros() - start;

    // the output is expected to be the amplitude of the delta function
    // divided evenly into all of the frequency bins (i.e. by the FFT length).
    // note that if you do this in matlab or python, the FFT output is
    // scaled by a factor of N (so divide by N to remove it before comparing).
    float sum_of_sq = 0;
    for (int i = 0; i < N; ++i) {
      int16_t a = y[i*2+0];  // real
      int16_t b = y[i*2+1];  // imag
      int16_t mag = (int32_t)(sqrt(a * a + b * b));
      sum_of_sq += sq(mag - (float)DELTA_AMPLITUDE / N);
    }

    float rms_err = sqrt(sum_of_sq / N);
    Serial.print(" N = ");
    Serial.print(N);
    Serial.print(" \ttime (us) = ");
    Serial.print(dt);
    Serial.print("  \trms err = ");
    Serial.print(rms_err);
    Serial.println(rms_err < 1.2 ? " PASSED" : " FAILED");
  }
}

void loop() {
}
