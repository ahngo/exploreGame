/*********************************************************************
** Program name: space.hpp
** Author: Andrew Ngo
** Date: 03/10/2018
** Description: Class and function declaration for a Space class, which
* will be an abstract base class. All derived classes from Space
* will be declared as a friend class to Game in order to access and change
* variables within Game.
*********************************************************************/

#ifndef SPACE_HPP
#define SPACE_HPP

#include <string>
#include "game.hpp"

class Space
{
private:
    // direction pointers
    Space* up;
    Space* down;
    Space* left;
    Space* right;
    // area name
    std::string name;
    // special exploration area
    bool canExplore = false;
public:
    // constructors/destructors
    Space();
    ~Space();
    
    // setters/getters
    void setUp(Space*);
    void setDown(Space*);
    void setLeft(Space*);
    void setRight(Space*);
    void setPointers(Space*, Space*, Space*, Space*);
    Space* getUp();
    Space* getDown();
    Space* getLeft();
    Space* getRight();
    void setName(std::string);
    void setCanExplore(bool b);
    bool getCanExplore();
    
    // polymorphic functions/variables
    // exploration events (can only happen on certain sub-Spaces)
    virtual void explore(Game*) = 0;
    // messages that get printed to console when entering a new Space
    virtual void greet() = 0;
    // random events that have a chance to happen in each Space
    virtual void event(Game*) = 0;
    // each area will have a randomized name
    virtual std::string getName();
};
#endif