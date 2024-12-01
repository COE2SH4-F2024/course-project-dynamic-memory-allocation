#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;


    // more actions to be included
    playerPos.pos->x = mainGameMechsRef->getBoardSizeX()/2;
    playerPos.pos->y = mainGameMechsRef->getBoardSizeY()/2; 
    playerPos.symbol = '@';

}


Player::~Player()

{
    // no heap member yet however might need this later. 
    // delete any heap members here
}

objPos Player::getPlayerPos() const
{
    return playerPos;
    // return the reference to the playerPos arrray list
}

void Player::updatePlayerDir()
{
        char input = mainGameMechsRef->getInput();
        // PPA3 input processing logic
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

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic
    switch(myDir)
    {
        case UP:
        playerPos.pos->y--;
        if(playerPos.pos->y <= 0)
            playerPos.pos->y = mainGameMechsRef->getBoardSizeY()-2;

        break;

        case DOWN:
        playerPos.pos->y++;
        if(playerPos.pos->y >= mainGameMechsRef->getBoardSizeY())
            playerPos.pos->y = 1;

        break;

        case LEFT:
        playerPos.pos->x--;
        if(playerPos.pos->x <= 0)
            playerPos.pos->x = mainGameMechsRef->getBoardSizeX()-2;

        break;

        case RIGHT:
        playerPos.pos->x++;
        if(playerPos.pos->x >= mainGameMechsRef->getBoardSizeX())
            playerPos.pos->x = 1;

        break;

        case STOP:
        default:
        break;
        

    };
    


}

// More methods to be added