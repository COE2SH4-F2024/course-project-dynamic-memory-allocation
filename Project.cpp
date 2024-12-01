#include <iostream>
#include "MacUILib.h"
#include "objPos.h"

#include "Player.h"

using namespace std;

#define DELAY_CONST 100000

bool exitFlag;

Player *myPlayer;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);


    objPos lund1(2, 2, 'a');
    objPos lund2(4, 6, 'b');
    objPos lund3(6, 6, 'c');



int main(void)
{

    Initialize();

    while(exitFlag == false)  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();

    myPlayer = new Player(nullptr);

    exitFlag = false;
}

void GetInput(void)
{
   


}

void RunLogic(void)
{
    
}

void DrawScreen(void)
{

    MacUILib_clearScreen(); 

        //implement copy assignment operator here for this to work



        objPos playerPos = myPlayer->getPlayerPos();
        MacUILib_printf("Player[x,y] = [%d], [%d], %c\n", playerPos.pos->x, playerPos.pos->y, playerPos.symbol);

        int y,x;

    
    for(y=0; y<10; y++)
    {
        
        for(x=0; x<20; x++)
        {
            if ((y==0 || x==0)||(y==9 || x==19))
            {
                MacUILib_printf("#");
            }

            else if (x==(lund1.pos->x) && (y==lund1.pos->y))
            {
                MacUILib_printf("%c", lund1.symbol);
            }

            else if (x==(lund2.pos->x) && (y==lund2.pos->y))
            {
                MacUILib_printf("%c", lund2.symbol);
            }

            else if (x==(lund3.pos->x) && (y==lund3.pos->y))
            {
                MacUILib_printf("%c", lund3.symbol);
            }

            else{
                MacUILib_printf(" ");
            }
        }MacUILib_printf("\n");
    }


}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    

    delete myPlayer;

    MacUILib_uninit();
}
