#include "Player.h"
#include "objPos.h"
#include "iostream"

Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;


    // more actions to be included
 
    playerPosList = new objPosArrayList(0);

    int xpos = mainGameMechsRef->getBoardSizeX()/2;
    int ypos = mainGameMechsRef->getBoardSizeY()/2;

    objPos headPos(xpos,ypos,'*');

    playerPosList->insertHead(headPos);

}



Player::~Player()

{
    delete[] playerPosList;
    // delete any heap members here
}

objPosArrayList* Player::getPlayerPos() const
{
    return playerPosList;
    // return the reference to the playerPos arrray list
}

void Player::updatePlayerDir()
{
        char input = mainGameMechsRef->getInput();
        bool loseFlag = mainGameMechsRef->getLoseFlagStatus();
        // PPA3 input processing logic
  
        if (loseFlag == false){

            switch (input)
            {

                case 'w':
                        if(myDir != UP && myDir != DOWN)
                            myDir =UP;
                        break;

                case 'a':
                        if(myDir != LEFT && myDir != RIGHT)
                            myDir =LEFT;
                        break;

                case 's':
                        if(myDir != UP && myDir != DOWN)
                            myDir =DOWN;
                        break;

                case 'd':
                        if(myDir != LEFT && myDir != RIGHT)
                            myDir =RIGHT;
                        break;

                    default:
                        break;


            }
        }
        else{
            myDir = STOP;
        }

}
void Player::movePlayer()
{
    // PPA3 Finite State Machine logic
    objPos head = playerPosList->getHeadElement();

    switch(myDir)
    {
        case UP:
        head.pos->y--;
        if(head.pos->y <= 0)
            head.pos->y = mainGameMechsRef->getBoardSizeY()-2;

        break;

        case DOWN:
        head.pos->y++;
        if(head.pos->y >= mainGameMechsRef->getBoardSizeY() -1)
            head.pos->y = 1;

        break;

        case LEFT:
        head.pos->x--;
        if(head.pos->x <= 0)
            head.pos->x = mainGameMechsRef->getBoardSizeX()-2;

        break;

        case RIGHT:
        head.pos->x++;
        if(head.pos->x >= mainGameMechsRef->getBoardSizeX()-1)
            head.pos->x = 1;

        break;

        case STOP:
        default:
        break;
        

    };

    if (head.pos->x == mainGameMechsRef->getFoodPos().pos->x && head.pos->y == mainGameMechsRef->getFoodPos().pos->y){
        objPos tHead = objPos(mainGameMechsRef->getFoodPos().pos->x, mainGameMechsRef->getFoodPos().pos->y, '*');
        playerPosList->insertHead(tHead);
        mainGameMechsRef->generateFood(playerPosList);
        mainGameMechsRef->incrementScore();

    }
    else{
        playerPosList->insertHead(head);
        playerPosList->removeTail();
    }


}


// More methods to be added

bool Player::checkSelfCollision(){
    for (int i = 1; i < playerPosList->getSize(); i++){
        if (playerPosList->getHeadElement().pos->x == playerPosList->getElement(i).pos->x && playerPosList->getHeadElement().pos->y == playerPosList->getElement(i).pos->y){
            return true;
        }
    }
    return false;
}