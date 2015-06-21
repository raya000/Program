#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

#define WIDTH 80
#define HEIGHT 40


void setCursor(int x, int y)
{
    COORD coordinate;
    coordinate.X = x;
    coordinate.Y = y;
    HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(screen, coordinate);
}


void print (){






}

void main(){
int a=1, i=0, j=0, posX, posY, posjogX, posjogY;

do{
system("COLOR 2F");
system("cls");
printf(".---.                    .---.        .-.  .-.\n: .; :                   : .; :       : :  : :\n:  _.'.--. ,-.,-. .--.   :   .' .--.  : :  : :\n: :  ' .; :: ,. :' .; :  : .; :' .; ; : :_ : :_\n:_;  `.__.':_;:_;`._. ;  :___.'`.__,_;`.__;`.__;\n                  .-. :\n                  `._.'                         ");
Sleep(2000); //30 frames por segundo
system("COLOR 4B");
system("cls");
printf("'||''|.                              '||''|.           '||  '||\n ||   ||   ...   .. ...     ... .     ||   ||   ....    ||   ||\n ||...|' .|  '|.  ||  ||   || ||      ||'''|.  '' .||   ||   ||\n ||      ||   ||  ||  ||    |''       ||    || .|' ||   ||   ||\n.||.      '|..|' .||. ||.  '||||.    .||...|'  '|..'|' .||. .||.\n                          .|....'                               \n");
Sleep(2000); //30 frames por segundo


}while (a!=0);


}


