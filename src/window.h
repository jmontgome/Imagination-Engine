#ifndef WINDOW_H
#define WINDOW_H

#include <Windows.h>

#include "global.h"

HWND* Window_Init(HINSTANCE hInstance, int nCmdShow, LPCWSTR className);

#endif