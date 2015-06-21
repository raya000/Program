#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define Largura 80
#define Altura 40

void setCursor(int x, int y);

int DesenhaCampo();

int main()
{
    int i, j, tempo=0, Pontos=0,  posX=Largura/2, posY=Altura/2, dirX=1, dirY=1, posjog1X=70, Dirjog1X=1, posjog2X=40, Dirjog2X=1, *BolaX, *BolaY;


  system("mode 100,80");   //Set mode to ensure window does not exceed buffer size
  SMALL_RECT WinRect = {0, 0, Largura+20, Altura+20};   //New dimensions for window in 8x12 pixel chars
  SMALL_RECT* WinSize = &WinRect;
  SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), 1, WinSize);   //Set new size for window


    while(!GetAsyncKeyState(VK_ESCAPE)) // Enquanto a tecla ESC nao for pressionada VK_<Setas!>
    {
        system("COLOR 2F");
        //verifica colisoes bola
        if(posX+dirX == 0 || posX+dirX == Largura-1) dirX*=-1;
        if(posY+dirY == 0) Pontos++;//Ponto para jogador 1
        if(posY+dirY == Altura-1) Pontos++;//Ponto para o jogador 2
        if(posjog1X+Dirjog1X == 0 || posjog1X+Dirjog1X == Largura-1) Dirjog1X*=-1;



        //mov do jogador
        if (GetAsyncKeyState(VK_LEFT))
            posjog1X -= 1;
        if (GetAsyncKeyState(VK_RIGHT))
            posjog1X += 1;
        if (GetAsyncKeyState(65))
            posjog2X -= 1;
        if (GetAsyncKeyState(68))
            posjog2X += 1;

        //colisao do jogador
        if (posjog1X<=0) posjog1X = 1;
        if (posjog1X>=Largura-4) posjog1X = Largura-4;
        if (posjog2X<=0) posjog2X = 1;
        if (posjog2X>=Largura-4) posjog2X = Largura-4;

        setCursor(0, 0); //Altera a posicao do cursor para o inicio

        DesenhaCampo(posjog1X, posjog2X, posX, posY, Dirjog1X, Dirjog2X);




        setCursor(0, Altura+1);
        printf("Pontos: %d", Pontos);
        tempo += 1;
        printf("  Tempo: %d", tempo/5);
        Sleep(10); //30 frames por segundo

    }
    return 0;
}




int DesenhaCampo(int posjog1X, int posjog2X, int posX, int posY, int Dirjog1X, int Dirjog2X)
{
    int i, j, Pontos;
    int dirX=1, dirY=1;
    for(i=0; i<Altura; i++) //Varre a altura de 0 até o limite da altura
    {
        for(j=0; j<Largura; j++) // Varre a largura de 0 até o limite da largura
        {

            if (i==0) // Parte superior do campo
            {
                if (j==0) printf("%c", 201);//╔
                else if (j==Largura-1) printf("%c", 187);//╗
                else printf("%c", 205);//═
            }
            else if (i==1) // Primeira linha superior (para compensar tamanho da barra)
            {
                if (j==0 || j==Largura-3) printf("%c", 186);//║
                else if (posjog2X == j) printf("%c%c%c", 223, 223, 223); // ▀ - Barra jogador 2
                else printf(" ");
            }
            else if (i==Altura-1) //Parte inferior do campo
            {
                if (j==0) printf("%c", 200);//╚
                else if (j==Largura-1) printf("%c", 188);//╝
                else printf("%c", 205);//═
            }

            else if (i==Altura-2)//Ultima linha inferior (para compensar o tamanho da barra)
            {
                if (j==0 || j==Largura-3) printf("%c", 186);//║
                else if (posjog1X == j) printf("%c%c%c", 220, 220, 220); //▄ - Barra jogador 1
                else printf(" ");
            }
            else // Demais casos do campo
            {
                if (j==0 || j==Largura-1) printf("%c", 186);//║
                else printf(" ");
            }
            if (i==40 && j==20) printf ("X"); //Printa bola

        }
        printf("\n");
       /* //movimenta a bola
        posX += dirX;
        posY += dirY;

        if (posX == posjog1X && posY == Altura-2)
        {
            Pontos ++;
            posX = Altura/2;
            posY = Largura/2;
        }*/

    }

}


void setCursor(int x, int y)
{
    COORD coordinate;
    coordinate.X = x;
    coordinate.Y = y;
    HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(screen, coordinate);
}
