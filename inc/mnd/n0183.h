/*
 ============================================================================
 Name        : n0183.h
 Author      : Malcolm Herring
 Version     : 0.1
 Description : Marine Network Data Library
 Copyright   : © 2016 Malcolm Herring.
 This file is part of libmnd.
 ============================================================================
 */

#ifndef n0183_h
#define n0183_h

#include <stdbool.h>
#include <stdint.h>

// Function to convert NMEA.0183 sentences to text

extern char* translateN0183(char* ln, char* d0183);

// ln is sentence text string
// d0183 points to char array reserved for conversion string
// Return value: pointer to d0183 if conversion performed, NULL otherwise

// Function to convert Tracked Target encapsulated data to text

extern char* translateTTD(uint8_t* buf, int len, char* decttd);

// buf points to encapsulated data
// len is number of valid bytes in buf
// decttd points to char array reserved for conversion string
// Return value: pointer to decttd if conversion performed, NULL otherwise

#endif /* n0183_h */
