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
                    if(myDir != UP && myDir != RIGHT)
                        myDir =LEFT;
                    break;

            case 'a':
                    if(myDir != UP && myDir != RIGHT)
                        myDir =LEFT;
                    break;

            case 's':
                    if(myDir != UP && myDir != RIGHT)
                        myDir =LEFT;
                    break;

            case 'd':
                    if(myDir != UP && myDir != RIGHT)
                        myDir =LEFT;
                    break;

                default:
                    break;


        }


}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic
}

// More methods to be added