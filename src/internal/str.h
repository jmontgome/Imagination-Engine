#ifndef STR_H
#define STR_H

#define MAX_STRING_LENGTH 1024

#include "types.h"

u16 strLen(char* str);
u8 strIsNumber(char* str);

char* strConcat(char* strA, char* strB);

#endif