#pragma once
#include<iostream>
#include<Windows.h>
using namespace std;

HANDLE hStdin;
DWORD fdwSaveOldMode;

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x; coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    return;
}

VOID ErrorExit(const char*) //LPSTR lpszMessage
{
    fprintf(stderr, "%s\n", "BLACKPINK"); //lpszMessage

    // Restore input mode on exit.

    SetConsoleMode(hStdin, fdwSaveOldMode);

    ExitProcess(0);
}

int main()
{
    HANDLE hin = GetStdHandle(STD_INPUT_HANDLE);
    INPUT_RECORD InputRecord;
    DWORD Events, fdwMode;

    /*
   Step-1:
   Disable 'Quick Edit Mode' option
*/
    fdwMode = ENABLE_EXTENDED_FLAGS;
    if (!SetConsoleMode(hin, fdwMode))
        ErrorExit("SetConsoleMode");
    /*
       Step-2:
       Enable the window and mouse input events,
       after you have already applied that 'ENABLE_EXTENDED_FLAGS'
       to disable 'Quick Edit Mode'
    */
    fdwMode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
    if (!SetConsoleMode(hin, fdwMode))
        ErrorExit("SetConsoleMode");

    while (true)
    {
        ReadConsoleInput(hin, &InputRecord, 1, &Events);

        switch (InputRecord.EventType) {
        case MOUSE_EVENT: // mouse input 

            if (InputRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
            {
                gotoxy(InputRecord.Event.MouseEvent.dwMousePosition.X, InputRecord.Event.MouseEvent.dwMousePosition.Y);

                cout << "Hello world at " << InputRecord.Event.MouseEvent.dwMousePosition.X << " x " << InputRecord.Event.MouseEvent.dwMousePosition.Y << " ";
            }
            break;
            FlushConsoleInputBuffer(hin);
        }
    }
    SetConsoleMode(hin, fdwMode);
    return 0;
}
