/*
 * Adafruit_ZeroFFT.h
 *
 *  Created on: Jan 5, 2018
 *      Author: deanm
 */

#ifndef ADAFRUIT_ZEROFFT_ADAFRUIT_ZEROFFT_H_
#define ADAFRUIT_ZEROFFT_ADAFRUIT_ZEROFFT_H_

#include <Arduino.h>

#define FFT_BIN(num, fs, size) (num*((float)fs/(float)size))
#define FFT_INDEX(freq, fs, size) ((int)((float)freq/((float)fs/(float)size)))

#ifndef ALIGN4
#define ALIGN4 __attribute__ ((aligned (4)))
#endif

#ifndef q15_t
#define q15_t int16_t
#endif

#ifndef q31_t
#define q31_t int32_t
#endif

#ifndef float32_t
#define float32_t float
#endif

#define ZERO_FFT_MAX 4096

#ifdef __cplusplus
extern "C"{
#endif // __cplusplus

extern int ZeroFFT(q15_t *source, uint16_t length);

extern const q15_t window_hanning_16[];
extern const q15_t window_hanning_32[];
extern const q15_t window_hanning_64[];
extern const q15_t window_hanning_128[];
extern const q15_t window_hanning_256[];
extern const q15_t window_hanning_512[];
extern const q15_t window_hanning_1024[];
extern const q15_t window_hanning_2048[];
extern const q15_t window_hanning_4096[];

#ifdef __cplusplus
};
#endif // __cplusplus
#include "arm_common_tables.h"

#endif /* ADAFRUIT_ZEROFFT_ADAFRUIT_ZEROFFT_H_ */
