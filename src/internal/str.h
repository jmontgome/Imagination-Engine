#ifndef STR_H
#define STR_H

#define MAX_STRING_LENGTH 1024

#include "types.h"

u64 strIndexOf(char* str, char ch);
u64 strLen(char* str);
u8 strIsNumber(char* str);
u8 strContains(char* str, char ch);

char* strConcat_M(char* strA, char* strB);

void freeStr(char* str);

#endif