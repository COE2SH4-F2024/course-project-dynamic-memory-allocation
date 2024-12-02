#include <iostream>
#include "MacUILib.h"
#include "objPos.h"

#include "Player.h"

using namespace std;

#define DELAY_CONST 100000.

Player *myPlayer;
GameMechs *GMC;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);


    objPos lund1(2, 2, 'a');


int main(void)
{

    Initialize();

    while(GMC->getExitFlagStatus() == false)  
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

    GMC = new GameMechs();
    myPlayer = new Player(GMC);
     objPosArrayList* playerPos = myPlayer->getPlayerPos();
    GMC->generateFood(playerPos);

}

void GetInput(void)
{

GMC->getInput();


}

void RunLogic(void)
{
    if (GMC->getInput()== 27){
        GMC->setExitTrue();
    }
    myPlayer->movePlayer();
    myPlayer->updatePlayerDir();
    
}

void DrawScreen(void)
{

    MacUILib_clearScreen(); 

        //implement copy assignment operator here for this to work



        objPosArrayList* playerPos = myPlayer->getPlayerPos();
        objPos head = playerPos->getHeadElement();
        objPos foodPos = GMC->getFoodPos();
        int bx = GMC->getBoardSizeX();
        int by = GMC->getBoardSizeY();
        MacUILib_printf("Player[x,y] = [%d], [%d], %c\n",head.pos->x, head.pos->y, head.symbol);


        int y,x;

    
    for(y=0; y<by; y++)
    {
        
        for(x=0; x<bx; x++)
        {


            if ((y==0 || x==0)||(y==by-1 || x==bx-1))
            {
                MacUILib_printf("#");
            }


            else if (x==(foodPos.pos->x) && (y == foodPos.pos->y))
            {
                MacUILib_printf("%c", foodPos.symbol);
            }

            else
            {
                bool snakebody = false;
                for (int s = 0; s < playerPos->getSize(); s++)
                {
                    if(x == playerPos->getElement(s).pos->x && y == playerPos->getElement(s).pos->y)
                    {
                        MacUILib_printf("%c", playerPos->getHeadElement().getSymbol());
                        snakebody = true;
                        break;
                    }
                }
                if (snakebody == false)
                {
                    MacUILib_printf(" ");
                }
            }

        }
            
        
         MacUILib_printf("\n");


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
    delete GMC;

    MacUILib_uninit();
}