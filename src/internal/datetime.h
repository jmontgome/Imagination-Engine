#ifndef DATETIME_H
#define DATETIME_H

#include "../sys/system.h"
#include "../internal/types.h"

#if WINDOWS
#include <time.h>
#endif
#if LINUX

#endif

#define TICKS_IN_A_MILLISECOND 10000
#define MILLISECONDS_IN_A_SECOND 1000
#define SECONDS_IN_A_MINUTE 60
#define MINUTES_IN_AN_HOUR 60
#define HOURS_IN_A_DAY 24
#define DAYS_IN_A_YEAR 365

typedef struct DateTime {
	u8 Year;
	u8 Month;
	u8 Day;
	u8 Hour;
	u8 Minute;
	u8 Second;
	u16 Millisecond;
	u64 Tick;
} DateTime;

DateTime DateTime_Create(u8 year, u8 month, u8 day, u8 hour, u8 minute, u8 second, u16 millisecond);

#if WINDOWS
char* DateTime_FromWinTimeString();
//DateTime DateTime_FromWinTime();
#endif
#if LINUX

#endif
#endif