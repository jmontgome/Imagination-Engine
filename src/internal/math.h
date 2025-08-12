#ifndef MATH_H
#define MATH_H

#include "types.h"

typedef struct ModuloResultSet64 {
	s64 remainder;
	s64 result;
} ModuloResultSet64;
typedef struct ModuloResultSetFloat {
	float remainder;
	float result;
} ModuloResultSetFloat;
typedef struct ModuloResultSetDouble {
	double remainder;
	double result;
} ModuloResultSetDouble;

ModuloResultSet64 ModuloS64(s64 dividend, s64 divider);

#endif