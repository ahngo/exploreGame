/*********************************************************************
** Program name: space.hpp
** Author: Andrew Ngo
** Date: 03/10/2018
** Description: Class and function implementation for a Space class, which
* will be an abstract base class.
*********************************************************************/

#include "space.hpp"

/********************************************************************* 
** Description: Empty constructors and destructors.
*********************************************************************/

Space::Space()
{}

Space::~Space()
{}

/********************************************************************* 
** Description: Setters and getters for private members of Space.
*********************************************************************/

void Space::setUp(Space* u)
{
    up = u;
}

void Space::setDown(Space* d)
{
    down = d;
}

void Space::setLeft(Space* l)
{
    left = l;
}

void Space::setRight(Space* r)
{
    right = r;
}

void Space::setPointers(Space* u = nullptr, Space* d = nullptr, Space* l = nullptr, Space* r = nullptr)
{
    up = u;
    down = d;
    left = l;
    right = r;
}

Space* Space::getUp()
{
    return up;
}

Space* Space::getDown()
{
    return down;
}

Space* Space::getLeft()
{
    return left;
}

Space* Space::getRight()
{
    return right;
}

void Space::setName(std::string n)
{
    name = n;
}

std::string Space::getName()
{
    return name;
}

bool Space::getCanExplore()
{
    return canExplore;
}

void Space::setCanExplore(bool b)
{
    canExplore = b;
}