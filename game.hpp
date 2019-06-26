/*********************************************************************
** Program name: game.hpp
** Author: Andrew Ngo
** Date: 03/10/2018
** Description: Class and function declaration for a Game class. Uses
* Space and its derived classes to drive an exploration game.
*********************************************************************/

#include <vector>

class Space;

#ifndef GAME_HPP
#define GAME_HPP

class Game
{
private:
    Space* position = nullptr;
    
    // movement flags
    bool m_up = 0;
    bool m_down = 0;
    bool m_left = 0;
    bool m_right = 0;
    bool madeValidMove = 0;
    
    // player stats
    int health;
    int timeLimit;
    int atk;
    int def;
    int weapon;
    int armor;
    bool specialDef = 0;
    bool specialAtk = 0;
    
    // map-related flags
    bool exploreFlag = 0;
    bool exploring = 0;
    bool justExplored = 0;
    
    // vectors to hold tiles (Spaces) and inventory items
    std::vector<Space*> tiles;
    std::vector<int> items;
public:
    Game();
    ~Game();
    void setPosition(Space*);
    void setHealth(int);
    void setAtk(int);
    void setDef(int);
    void setTimeLimit(int);
    void useItem(int);
    void addItem(int);
    int getAtk();
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    void getValidMoves();
    void printValidMoves();
    void move(char input);
    bool getMadeValidMove();
    Space* getPosition();
    void printStatus();
    int getHealth();
    int getDef();
    int getStats();
    void hp(int);
    void atkup(int);
    void defup(int);
    void inventory();
    void useInventory();
    int getInvSize();
    int getWeapon();
    int getArmor();
    void setWeapon(int);
    void setArmor(int);
    void adjTimeLimit(int);
    int getTimeLimit();
    void setExploreFlag(bool);
    bool getSpecialDef();
    void setSpecialDef(bool);
    void setSpecialAtk(bool);
    bool getSpecialAtk();
    bool getExploring();
    void setExploring(bool);
    bool getJustExplored();
    void setJustExplored(bool);
    void generateMap();
    bool boss();
};
#endif
