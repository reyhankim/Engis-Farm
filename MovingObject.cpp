#include "MovingObject.hpp"
#include "LinkedList.hpp"
#include "Node.hpp"

MovingObject::MovingObject() {}

MovingObject::MovingObject(int x, int y) : Renderable(x, y) {}

MovingObject::~MovingObject() {}

int MovingObject::move(int direction, LinkedList<Cell*> field)
{
    bool canMove = true;
    int destX;
    int destY;

    switch (direction)
    {
        case 1:
            destX = this->x;
            destY = this->y-1;
            break;
        case 2:
            destX = this->x+1;
            destY = this->y;
            break;
        case 3:
            destX = this->x;
            destY = this->y+1;
            break;
        case 4:
            destX = this->x-1;
            destY = this->y;
            break;
        default:
            destX = this->x;
            destY = this->y;
            break;
    }

    Node<Cell *> * tempNode = field.head;
    
    while(tempNode != NULL)
    {
        int a = tempNode->info->getX();
        if (tempNode->info->getX() == destX && tempNode->info->getY() == destY)
        {
            if (!tempNode->info->isWalkable())
            {
                canMove = false;
            }
        }
    }

    if (canMove)
    {
        this->x = destX;
        this->y = destY;
    }

    return canMove ? 1 : -1;
}