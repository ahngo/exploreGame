/*********************************************************************
** Program name: forest.hpp
** Author: Andrew Ngo
** Date: 03/10/2018
** Description: Class and function declaration for a Forest class,
* derived from Space.
*********************************************************************/

#ifndef FOREST_HPP
#define FOREST_HPP

#include "space.hpp"
#include "game.hpp"
#include <string>

class Forest : public Space
{

public:
    Forest();
    void greet();
    std::string getName();
    void event(Game*);
    void explore(Game*);
    friend class Game;
};
#endif