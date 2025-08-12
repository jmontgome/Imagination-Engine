#include "datetime.h"
#include "math.h"
#include "types.h"
#include "str.h"
#include "../sys/system.h"

#if WINDOWS
#include <time.h>
#endif
#if LINUX

#endif


DateTime DateTime_Create(u8 year, u8 month, u8 day, u8 hour, u8 minute, u8 second, u16 millisecond) {

}

#if WINDOWS
char* DateTime_FromWinTimeString() {
	time_t internalTime = time(NULL);
	char* time_str = asctime(localtime(&internalTime));
	return time_str;
}
DateTime DateTime_FromWinTime() {
	char* dateTimeString = DateTime_FromWinTimeString();
	char* weekDay, month, day, year, time;

	u8 dateTimeStrLen = (u8)strLen(dateTimeString);

}
#endif
#if LINUX

#endif