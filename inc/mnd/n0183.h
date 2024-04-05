/*
 ============================================================================
 Name        : n0183.h
 Author      : Malcolm Herring
 Version     : 1.0
 Description : Marine Network Data Library
 Copyright   : © 2016,2024 Malcolm Herring.
 This file is part of libmnd.
 ============================================================================
 */

#ifndef n0183_h
#define n0183_h

#include <stdbool.h>
#include <stdint.h>

extern char* translateN0183(char* ln, char* d0183);
extern char* translateTTD(uint8_t* buf, int len, char* trttd);
extern void decodeN0183(char* ln, MND_PAR args[]);
extern MND_PAR* encodeN0183(MND_PAR args[], char* ln);

#endif /* n0183_h */
