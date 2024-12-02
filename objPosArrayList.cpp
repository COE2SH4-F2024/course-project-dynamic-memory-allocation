#include "objPosArrayList.h"

// Paste your Tested implementation here.
// Paste your Tested implementation here.
// Paste your Tested implementation here.

objPosArrayList::objPosArrayList() // default constructor
{
    listSize = 0;
    arrayCapacity = ARRAY_MAX_CAP;
    aList = new objPos[ARRAY_MAX_CAP];
}


objPosArrayList::objPosArrayList(int size) // parametrized contructor
{
    listSize = size;
    arrayCapacity = ARRAY_MAX_CAP;
    aList = new objPos[ARRAY_MAX_CAP];

}


objPosArrayList::~objPosArrayList() // destructor
{
    delete[] aList;
}

int objPosArrayList::getSize() const // return the size
{
    return listSize;
}

void objPosArrayList::insertHead(objPos thisPos) // add an obj at the front
{
    if (listSize == arrayCapacity){
        return;
    }
    for (int i = listSize; i > 0; i--){
        aList[i] = aList[i-1];
    }
    aList[0] =thisPos;
    listSize++;
}

void objPosArrayList::insertTail(objPos thisPos) // add an object at the end
{
    if (listSize == arrayCapacity){
        return;
    }
    aList[listSize] = thisPos;
    listSize++;
}

void objPosArrayList::removeHead() //remove first object
{
    if(listSize == 0){
        return;
    }
    for (int i = 0; i < listSize-1; i++){
        aList[i] = aList[i+1];
    }
    listSize--;
}

void objPosArrayList::removeTail() // remmove last object
{
    if(listSize == 0){
        return;
    }
    listSize--;
}

objPos objPosArrayList::getHeadElement() const // return first object
{
    return aList[0];
}

objPos objPosArrayList::getTailElement() const // return last object
{
    return aList[listSize-1];
}

objPos objPosArrayList::getElement(int index) const // return object at the certain index
{
    if(index < 0 || index >= listSize){

        return objPos();
    }
    
    return aList[index];
}