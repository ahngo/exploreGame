/*********************************************************************
** Program name: helpers.cpp
** Author: Andrew Ngo
** Date: 03/13/2018
** Description: Helper functions for main.
*********************************************************************/

#include "space.hpp"
#include "game.hpp"
#include "desert.hpp"
#include "snow.hpp"
#include "forest.hpp"
#include <cstdlib>

/********************************************************************* 
** Description: Generates a random derived class from Space.
*********************************************************************/

Space* randomTile()
{
    int random = (rand() % 3);
    
    switch (random)
    {
        case 0: 
        {
            return new Forest;
            break;
        }
        case 1:
        {
            return new Desert;
            break;
        }
        case 2:
        {
            return new Snow;
            break;
        }
        default:
        {
            return new Forest;
            break;
        }
    }
}

