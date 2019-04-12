#include "MovingObject.hpp"
#include "LinkedList.hpp"
#include "Node.hpp"
#include <iostream>

MovingObject::MovingObject() {}

MovingObject::MovingObject(int x, int y) : Renderable(x, y) {}

MovingObject::~MovingObject() {}

int MovingObject::move(int direction, LinkedList<Cell*>& field, int fieldXBoundary, int fieldYBoundary)
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

    if (destX < 0 || destY < 0 || destX >= fieldXBoundary || destY >= fieldYBoundary)
    {
        canMove = false;
    }
    else
    {
        Node<Cell *> tempNode;

        for (int i = 0; i<field.count; i++)
        {
            tempNode = field.get(i);
            if (tempNode.info->getX() == destX && tempNode.info->getY() == destY)
            {
                if (!tempNode.info->isWalkable())
                {
                    canMove = false;
                }
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