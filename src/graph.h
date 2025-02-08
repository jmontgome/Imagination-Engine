#ifndef GRAPH_H
#define GRAPH_H

#include <Windows.h>

typedef struct Point {
	u16 X;
	u16 Y;
} Point;

typedef struct Triangle {
	Point Vertices[3];
} Triangle;

u16 GetScreenWidth();
u16 GetScreenHeight();

void Graph_Init(HWND* hwnd);
void Graph_Main();

#endif