#include "GameMechs.h"
#include "MacUILib.h"

GameMechs::GameMechs()
{
    input = 0;
    exitFlag = false;
    loseFlag = false;
    score = 0;
    boardSizeX = 30;
    boardSizeY = 15;
    food.setObjPos(-10, -10, 'o');
    xLt = 30;
    yLt = 15;
}

GameMechs::GameMechs(int boardX, int boardY)
{
    input = 0;
    exitFlag = false;
    loseFlag = false;
    score = 0;
    boardSizeX = boardX;
    boardSizeY = boardY;
    food.setObjPos(-10, -10, 'o');
    xLt = boardX;
    yLt = boardY;
}

// do you need a destructor?
GameMechs::~GameMechs()
{
    
}

bool GameMechs::getExitFlagStatus() const
{
    return exitFlag;
}

bool GameMechs::getLoseFlagStatus() const
{
    return loseFlag;
}
    

char GameMechs::getInput()
{
    if(MacUILib_hasChar()){
        input = MacUILib_getChar();
    }
    
    return input;
}

int GameMechs::getScore() const
{
    return score;
}

void GameMechs::incrementScore()
{
    score++;
}

void GameMechs::incrementScoreCase1()
{
    score = score + 10;
}

void GameMechs::incrementScoreCase2()
{
    score = score + 50;
}

int GameMechs::getBoardSizeX() const
{
    return boardSizeX;
}

int GameMechs::getBoardSizeY() const
{
    return boardSizeY;
}


void GameMechs::setExitTrue()
{
    exitFlag = true;
}

void GameMechs::setLoseFlag()
{
    loseFlag = true;
}

void GameMechs::setInput(char this_input)
{
    input = this_input;
}

void GameMechs::clearInput()
{
    input = 0;
}


void GameMechs::generateFood(objPosArrayList* playerPosList){
    int rx, ry;
    bool wrongGen;
    do{
        srand(time(0));
        rx = (rand() % (xLt-2)) + 1;
        ry = (rand() % (yLt-2)) + 1;
        wrongGen = false;
        for (int i = 0; i < playerPosList->getSize(); i++){
            if (rx == playerPosList->getElement(i).pos->x && ry == playerPosList->getElement(i).pos->y){
                wrongGen = true;
                break;
            }
        }
    }
    while(wrongGen);
    food = objPos(rx, ry, '+');
}


objPos GameMechs::getFoodPos() const{
    return food;
}

// More methods should be added here

