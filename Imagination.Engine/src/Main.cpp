#include "Window.h"
#include "Logger.h"
#include "WindowsMessageMap.h"

#include <iostream>
#include <tchar.h>

int CALLBACK WinMain(
	HINSTANCE	hInstance,
	HINSTANCE	hPrevInstance,
	LPSTR		lpCmdLine,
	int			nCmdShow)

	/* Game Engine Notes:

		A game requires three things to function and live,
		these three things live within a loop that runs
		the entire duration of the program, once leaving
		this loop this whole process exits

		The Game Loop:
			Process Input (Input is taken and commands are prepared
				for the game to react to)
			Update Game (Where all logic and processes for the game
				takes place such as entities making moves or the
				simple daytime model advancing a step)
			Render (where frames are rendered for the user)

		A note on Windows Processes:

		All windows processes follow this flow:

		GetMssage()
			Message is sent to message queue where all messages
			are queued for reading.
			A note, this is how user inputs are received, they are
			a type of message.
		Filter Message Queue
		(A message is grabbed from the queue and the program begins to
		act on it).
		Modify Message
		TranslateMessage()
		DispatchMessage
			Dispatches the message to the window procedure for our
			app to react to this message.
	*/
{
	Logging::Log("Imagination Engine Starting...");

	Window window(500, 300, L"Imagination Engine");

	MSG message;
	BOOL messageResult;
	while ( (messageResult = GetMessage(&message, nullptr, 0, 0)) > 0)
	{
		TranslateMessage(&message);
		DispatchMessage(&message);
	}

	if (messageResult == -1)
	{
		return -1;
	}
	else
	{
		return (int)message.wParam;
	}
}