#include "math.h"

ModuloResultSet64 ModuloS64(s64 dividend, s64 divider) {
	s64 remainder = dividend % divider;
	s64 result = dividend / divider;
	ModuloResultSet64 resultSet = {
		.remainder = remainder,
		.result = result
	};

	return resultSet;
}