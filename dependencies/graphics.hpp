#include <windows.h>
using namespace std;

void gotoxy(short int x, short int y)
{
    static HANDLE h = NULL;
    if (!h)
        h = GetStdHandle(STD_OUTPUT_HANDLE);
  
    COORD c = {x, y};
    SetConsoleCursorPosition(h, c);
}
