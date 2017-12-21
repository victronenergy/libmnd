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

extern char* translateN0183(char* ln, char* d0183);
extern char* translateTTD(uint8_t* buf, int len, char* trttd);

#endif /* n0183_h */
