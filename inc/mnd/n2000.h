/*
 ============================================================================
 Name        : n2000.h
 Author      : Malcolm Herring
 Version     : 0.1
 Description : Marine Network Data Library
 Copyright   : © 2016 Malcolm Herring.
 This file is part of libmnd.
 ============================================================================
 */

#ifndef n2000_h
#define n2000_h

#include <stdbool.h>
#include <stdint.h>

typedef struct p_2000 P_2000;

typedef struct {
  int pgn;          // PGN
  int pri;          // Priority
  int dst;          // Destination address
  int src;          // Source address
  bool fpp;         // Fast packet flag
  int len;          // Number of bytes in message
  uint8_t msg[250]; // Message bytes
} E_2000;           // Message contents

typedef enum { M2K_ASC, M2K_UNI, M2K_I64, M2K_F64 } M2K_TYP;

typedef struct {
  M2K_TYP typ;          // Parameter type
  union {
    uint8_t asc[8];     // Ascii
    uint16_t uni[4];    // Unicode
    int64_t i64;        // Integer
    double f64;         // Real
  }dat;
} T_2000;               // Encode parameter

typedef struct {
  int pgn;        // PGN
  char* cap;      // Text name
  bool fpp;       // Fast packet flag
  int pri;        // Default priority
  P_2000* fmt;    // Format table
} M_2000;         // Message parameters

typedef struct {
  uint32_t hdr;         // Frame header
  uint8_t len;          // Number of bytes
  uint8_t pad1;
  uint8_t pad2;
  uint8_t pad3;
  uint8_t dat[8];       // Frame bytes
} S_2000;               // SocketCAN frame

// Function to concatenate data bytes in SocketCAN frames

extern int deframeN2000(S_2000* frame, E_2000* enc);

// frame is input SocketCAN frame
// enc points to buffer reserved for concatenated data
// Return value: -1 if lost frames detected
//                0 if waiting for more frames
//                1 if complete pgn received & data in enc is valid

// Function to extract NMEA.2000 PGN message fields

extern int decodeN2000(E_2000* enc, T_2000 args[]);

// enc is NMEA.2000 message data
// args points to array of field structures reserved for decoded data
// Return value: number of valid items in args

// Function to convert NMEA.2000 PGN messages into text

extern char* translateN2000(E_2000* enc, char* d2000);

// enc is NMEA.2000 message data
// d2000 points to char array reserved for decoded data
// Return value: points to d2000 if conversion complete, NULL otherwise

#endif /* n2000_h */
