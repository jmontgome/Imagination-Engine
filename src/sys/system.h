#ifndef SYSTEM_H
#define SYSTEM_H

#if defined(_WIN32) || defined(_WIN64) && !defined(UNIX)
#define WINDOWS 1
#define LINUX 0
#elif defined(UNIX) && !defined(_WIN32) && !defined(_WIN64)
#define LINUX 1
#define WINDOWS 0
#endif

#endif