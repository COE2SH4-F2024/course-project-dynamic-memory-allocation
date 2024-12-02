#include "Player.h"
#include "objPos.h"
#include "iostream"

Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;


    // more actions to be included
    
    //dynamically allocaate memory for the playerPositions List
    playerPosList = new objPosArrayList(0);

    //initialize starting position variables
    int xpos = mainGameMechsRef->getBoardSizeX()/2;
    int ypos = mainGameMechsRef->getBoardSizeY()/2;

    objPos headPos(xpos,ypos,'*');

    playerPosList->insertHead(headPos);

}



Player::~Player()

{   
    delete playerPosList;
    
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
  
        // as long as the player has not lost the game, collect input to control the snake, else only take escape key input. 
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
    // if the head collides with the food, we add another element to the head, increment the score, and regenerate the food 
    if (head.pos->x == mainGameMechsRef->getFoodPos().pos->x && head.pos->y == mainGameMechsRef->getFoodPos().pos->y){
        objPos tHead = objPos(mainGameMechsRef->getFoodPos().pos->x, mainGameMechsRef->getFoodPos().pos->y, '*');
        playerPosList->insertHead(tHead);
        mainGameMechsRef->generateFood(playerPosList);
        mainGameMechsRef->incrementScore();

    }// add the head and remove the tail
    else{
        playerPosList->insertHead(head);
        playerPosList->removeTail();
    }


}


// More methods to be added

bool Player::checkSelfCollision(){ // if the head is on the coordinates of any of the body, return that it crashed
    for (int i = 1; i < playerPosList->getSize(); i++){
        if (playerPosList->getHeadElement().pos->x == playerPosList->getElement(i).pos->x && playerPosList->getHeadElement().pos->y == playerPosList->getElement(i).pos->y){
            return true;
        }
    }
    return false;
}