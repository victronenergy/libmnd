/*
 ============================================================================
 Name        : e2000.h
 Author      : Malcolm Herring
 Version     : 0.1
 Description : Marine Network Data Library
 Copyright   : © 2016 Malcolm Herring.
 This file is part of libmnd.
 ============================================================================
 */

#ifndef e2000_h
#define e2000_h

#include <stdbool.h>
#include <stdint.h>

#include "n2000.h"

// Function encode NMEA.2000 filed values into message binary

extern void encodeN2000(int nargs, T_2000 args[], E_2000* enc);

// nargs is number of fields to be encoded
// args is array of field values
// enc points to NMEA.2000 message structure

// Function to convert NMEA.2000 message data into SocketCAN frames

extern int enframeN2000(E_2000* enc, int seq, S_2000 frames[]);

// enc is NMEA.2000 data structure
// seq is sequence number to be used in fast packet frames
// frames points to array of frame structures reserved for conversion
// Return value: number of valid frames in frames array

#endif /* e2000_h */
