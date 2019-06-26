/*********************************************************************
** Program name: desert.hpp
** Author: Andrew Ngo
** Date: 03/10/2018
** Description: Class and function declaration for a Desert class,
* derived from Space.
*********************************************************************/

#ifndef DESERT_HPP
#define DESERT_HPP

#include "space.hpp"
#include "game.hpp"
#include <string>

class Desert : public Space
{
public:
    Desert();
    void greet();
    std::string getName();
    void event(Game*);
    friend class Game;
    void explore(Game*);
};
#endif