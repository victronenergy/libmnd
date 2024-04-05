/*
 ============================================================================
 Name        : mnd.h
 Author      : Malcolm Herring
 Version     : 1.0
 Description : Marine Network Data Library
 Copyright   : © 2016,2024 Malcolm Herring.
 This file is part of libmnd.
 ============================================================================
 */

#ifndef mnd_h
#define mnd_h

typedef enum { MND_END, MND_EOM, MND_NUL, MND_I64, MND_F64, MND_ASC, MND_UNI, MND_BIN } MND_TYP;

typedef struct mnd_par MND_PAR;

struct mnd_par {
  MND_TYP typ;          // Parameter type
  union {
    int64_t i64;        // Integer
    double f64;         // Real
    uint8_t asc[8];     // Ascii
    uint16_t uni[4];    // Unicode
    uint8_t bin[8];     // Binary
  }dat;
};                      // Encode parameter

#include "n0183.h"
#include "m1371.h"
#include "n2000.h"

#endif /* mnd_h */
