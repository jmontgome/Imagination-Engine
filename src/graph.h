#ifndef GRAPH_H
#define GRAPH_H

#include <Windows.h>

void Graph_DrawWorld();
void Graph_DrawEntities();
void Graph_DrawPlayer();

void Graph_Init(HWND* hwnd);
void Graph_Main();

#endif