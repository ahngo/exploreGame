/*********************************************************************
** Program name: snow.hpp
** Author: Andrew Ngo
** Date: 03/10/2018
** Description: Class and function declaration for a snow class,
* derived from Space.
*********************************************************************/

#ifndef SNOW_HPP
#define SNOW_HPP

#include "space.hpp"
#include "game.hpp"
#include <string>

class Snow : public Space
{

public:
    Snow();
    void greet();
    void event(Game*);
    friend class Game;
    std::string getName();
    void explore(Game*);
};
#endif
