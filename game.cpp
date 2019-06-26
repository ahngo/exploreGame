/*********************************************************************
** Program name: game.hpp
** Author: Andrew Ngo
** Date: 03/10/2018
** Description: Class and function implementation for a Game class,
* which uses Space and its derived classes as a "map."
*********************************************************************/

#include "game.hpp"
#include "space.hpp"
#include "helpers.hpp"
#include <iostream>
#include <vector>

/********************************************************************* 
** Description: Constructor initializes several private members for
* gameplay.
*********************************************************************/

Game::Game()
{
    health = 100;
    timeLimit = 50;
    atk = 25;
    def = 10;
    weapon = 0;
    armor = 0;
    exploreFlag = false;
    specialDef = false;
    specialAtk = false;
}

/********************************************************************* 
** Description: Destructor deletes all Space tiles allocated by new
* in map(). map() populates a private member vector named tiles.
*********************************************************************/

Game::~Game()
{
    for (unsigned int i = 0; i < tiles.size(); i++)
    {
        delete tiles[i];
    }
    tiles.clear();
}

/********************************************************************* 
** Description: moveDIRECTION() functions are for moving the player
* on the map while checking for nullptrs.
*********************************************************************/

void Game::moveUp()
{
    if (position->getUp() != nullptr)
    {
        position = position->getUp();
    }
}

void Game::moveDown()
{
    if (position->getDown() != nullptr)
    {
        position = position->getDown();
    }
}

void Game::moveLeft()
{
    if (position->getLeft() != nullptr)
    {
        position = position->getLeft();
    }
}

void Game::moveRight()
{
    if (position->getRight() != nullptr)
    {
        position = position->getRight();
    }
}

/********************************************************************* 
** Description: getValidMoves() is a helper function that checks for
* valid moves (non-nullptr Spaces) and sets m_direction bools for
* printValidMoves(). Used to "update" available movement.
*********************************************************************/

void Game::getValidMoves()
{
    m_left = false;
    m_up = false;
    m_down = false;
    m_right = false;
    
    if (position->getLeft() != nullptr)
    {
        m_left = true;
    }
    if (position->getUp() != nullptr)
    {
        m_up = true;
    }
    if (position->getDown() != nullptr)
    {
        m_down = true;
    }
    if (position->getRight() != nullptr)
    {
        m_right = true;
    }
}

/********************************************************************* 
** Description: printValidMoves() uses information from getValidMoves()
* to tell the player which directions they can move. Additionally,
* uses exploreFlag to check for special exploration events and checks
* if items can be used. If so, also prompts the player with the 
* appropriate actions.
*********************************************************************/

void Game::printValidMoves()
{
    if (exploreFlag == true)
    {
        std::cout << "You sense something unique about this area.. [E]xplore?" << std::endl;
    }
    std::cout << "You can move: ";
    if (m_up != false)
    {
        std::cout << "[U]p ";
    }
    if (m_down != false)
    {
        std::cout << "[D]own ";
    }
    if (m_left != false)
    {
        std::cout << "[L]eft ";
    }
    if (m_right != false)
    {
        std::cout << "[R]ight ";
    }
    if (items.size() > 0)
    {
        std::cout << "or use an [I]tem.";
    }
    std::cout << std::endl;
}

/********************************************************************* 
** Description: move() drives the player movement function through input,
* making use of variables set by checkValidMoves() and explore flags.
* Special exploration options, item usage, or invalid movement options
* flag madeValidMove to false.
*********************************************************************/

void Game::move(char input)
{
    madeValidMove = true;
    exploring = false;
    
    if (input == 'U' || input == 'u')
    {
        if (m_up == false)
        {
            std::cout << "Invalid move." << std::endl;
            madeValidMove = false;
            return;
        }
        moveUp();
        return;
    }
    if (input == 'D' || input == 'd')
    {
        if (m_down == false)
        {
            std::cout << "Invalid move." << std::endl;
            madeValidMove = false;
            return;
        }
        moveDown();
        return;
    }
    if (input == 'L' || input == 'l')
    {
        if (m_left == false)
        {
            std::cout << "Invalid move." << std::endl;
            madeValidMove = false;
            return;
        }
        moveLeft();
        return;
    }
    if (input == 'R' || input == 'r')
    {
        if (m_right == false)
        {
            std::cout << "Invalid move." << std::endl;
            madeValidMove = false;
            return;
        }
        moveRight();
        return;
    }
    if ((input == 'I' || input == 'i') && items.size() > 0)
    {
        inventory();
        madeValidMove = false;
        return;
    }
    if ((input = 'E' || input == 'e') && exploreFlag == true)
    {
        exploring = true;
        madeValidMove = false;
        return;
    }
    else 
    {
        std::cout << "Invalid input." << std::endl;
        madeValidMove = false;
        return;
    }
}


/********************************************************************* 
** Description: printStatus() prints the player's stats and area to console.
*********************************************************************/

void Game::printStatus()
{
    std::cout << "HP: " << getHealth() << " Atk: " << getAtk() << " Def: " << 
    getDef() << " Time: " << getTimeLimit() << " Zone: " << position->getName() << std::endl;
}

/********************************************************************* 
** Description: hp(), atkup(), defup() are used for gameplay events
* and changing player stats. hp() sets health to 100 if it is above
* 100.
*********************************************************************/

void Game::hp(int change)
{
    health += change;
    if (getHealth() > 100)
    {
        health = 100;
    }
}

void Game::atkup(int change)
{
    atk += change;
}

void Game::defup(int change)
{
    def += change;
}

/********************************************************************* 
** Description: inventory() is called to view the player inventory.
* Checks the vector items, where each item is represented by an int.
* Also calls useInventory().
*********************************************************************/

void Game::inventory()
{
    if (items.size() == 0)
    {
        std::cout << "You have no items!" << std::endl;
    }
    else
    {
        std::cout << "You open your pouch.. you see: ";
        for (unsigned int i = 0; i < items.size(); i++)
        {
            if (items[i] == 1)
            {
                std::cout << "[F]orest Fruit ";
            }
            if (items[i] == 2)
            {
                std::cout << "[W]ater Flask ";
            }
        }
        std::cout << std::endl; 
        useInventory();
    }
}

/********************************************************************* 
** Description: useInventory() is used for when a player wants to use
* an item. Checks if they have that item, and "consumes" the item when used.
* Asks for input like a movement prompt.
*********************************************************************/

void Game::useInventory()
{
    bool fruit = false;
    bool water = false;
    int fruitpos = 0;
    int waterpos = 0;
    char use;
    
    for (unsigned int i = 0; i < items.size(); i++)
    {
        if (items[i] == 1)
        {
            fruit = true;
            fruitpos = i;
        }
        if (items[i] == 2)
        {
            water = true;
            waterpos = i;
        }
    }
    std::cout << "Enter the key of the item you want to use or any other keys to return: ";
    std::cin.get(use);
    std::cin.clear();
    std::cin.ignore(256, '\n');
    
    if ((use == 'F' || use == 'f') && fruit == true)
    {
        std::cout << "You ate the delicious fruit. It restores your health and makes you more vigorous. (+25 HP, +5 Atk, +10 Def)";
        hp(25);
        atkup(5);
        defup(10);
        items.erase(items.begin() + fruitpos);
        return;
    }
    if ((use == 'W' || use == 'w') && water == true)
    {
        std::cout << "The flasked water is very refreshing. It restores your health and fills you with energy. (+20 HP, +10 Atk)";
        hp(20);
        atkup(10);
        items.erase(items.begin() + waterpos);
        return;
    }
    else return;
}

/********************************************************************* 
** Description: getInvSize() returns the amount of items a player has.
* When non-zero, allows the player to access inventory in other functions.
* Otherwise, if 0, no inventory prompt is shown (cannot use items if you
* have none).
*********************************************************************/

int Game::getInvSize()
{
    return items.size();
}

/********************************************************************* 
** Description: addItem() pushes an int into the vector items, where
* each item is represented by an integer. Inventory space is capped
* at 5.
*********************************************************************/

void Game::addItem(int i)
{
    if (getInvSize() >= 5)
    {
        std::cout << " Unfortunately, you can't hold any more items." << std::endl;
        return;
    }
    else items.push_back(i);
}

/********************************************************************* 
** Description: generateMap() creates a randomized 4x4 map of Snow, Desert,
* or Forest tiles. Also randomizes the player's starting position,
* but is restricted to the center of the map. Links together each
* tile with Space's setPointers(). Adds each tile to a vector,
* for easy deletion.
*********************************************************************/

void Game::generateMap()
{
    Space* tile1 = randomTile();
    Space* tile2 = randomTile();
    Space* tile3 = randomTile();
    Space* tile4 = randomTile();
    Space* tile5 = randomTile();
    Space* tile6 = randomTile();
    Space* tile7 = randomTile();
    Space* tile8 = randomTile();
    Space* tile9 = randomTile();
    Space* tile10 = randomTile();
    Space* tile11 = randomTile();
    Space* tile12 = randomTile();
    Space* tile13 = randomTile();
    Space* tile14 = randomTile();
    Space* tile15 = randomTile();
    Space* tile16 = randomTile();
    
    tile1->setPointers(nullptr, tile4, nullptr, tile2);
    tile2->setPointers(nullptr, tile5, tile1, tile3);
    tile3->setPointers(nullptr, tile6, tile2, tile13);
    tile4->setPointers(tile1, tile7, nullptr, tile5);
    tile5->setPointers(tile2, tile8, tile4, tile6);
    tile6->setPointers(tile3, tile9, tile5, tile14);
    tile7->setPointers(tile4, tile10, nullptr, tile8);
    tile8->setPointers(tile5, tile11, tile7, tile9);
    tile9->setPointers(tile6, tile12, tile8, tile15);
    tile10->setPointers(tile7, nullptr, nullptr, tile11);
    tile11->setPointers(tile8, nullptr, tile10, tile12);
    tile12->setPointers(tile9, nullptr, tile11, tile16);
    tile13->setPointers(nullptr, tile14, tile3, nullptr);
    tile14->setPointers(tile13, tile15, tile6, nullptr);
    tile15->setPointers(tile14, tile16, tile9, nullptr);
    tile16->setPointers(tile15, nullptr, tile12, nullptr);
    
    tiles = {tile1, tile2, tile3, tile4, tile5, tile6, tile7, tile8, tile9, tile10, tile11, tile12, tile13, tile14, tile15, tile16};
    
    int startPos = (rand() % 4);
    
    switch (startPos)
    {
        case 0: 
        {
            setPosition(tile5);
            break;
        }
        case 1:
        {
            setPosition(tile6);
            break;
        }
        case 2:
        {
            setPosition(tile8);
            break;
        }
        case 3:
        {
            setPosition(tile9);
            break;
        }
    }
}

/********************************************************************* 
** Description: boss() starts a "boss fight." It consists of checking
* the stats for thresholds and returns a bool indicating if the player
* won or lost.
*********************************************************************/

bool Game::boss()
{
    bool won;
    std::cout << "You are out of time. You face the Pursuer." << std::endl;
    if (getHealth() < 33)
    {
        std::cout << "You don't have enough health to endure a prolonged battle. The Pursuer overwhelms you.";
        won = false;
    }
    else if (getStats() < 375)
    {
        std::cout << "The Pursuer overwhelms you with sheer power. Unfortunately, you were not strong enough.";
        won = false;
    }
    else if (getAtk() > 175)
    {
        std::cout << "Your mighty attacks overwhelm the Pursuer. Severely injured, the Pursuer cannot win against you!";
        won = true;
    }
    else if (getDef() > 175)
    {
        std::cout << "Your time in the Labyrinth has made you extraordinarily resilient. You shrug off the Pursuer's attacks and retaliate for the victory!";
        won = true;
    }
    else
    {
        std::cout << "Your experience in the Labyrinth has granted you the power to dispatch the Pursuer. You slay it.";
        won = true;
    }
    std::cout << std::endl;
    return won;
}

/********************************************************************* 
** Description: Getters and Setters for Game.
*********************************************************************/


bool Game::getMadeValidMove()
{
    return madeValidMove;
}

Space* Game::getPosition()
{
    return position;
}

int Game::getHealth()
{
    return health;
}

int Game::getDef()
{
    return def;
}

int Game::getStats()
{
    return (getHealth() + getAtk() + getDef());
}

void Game::setPosition(Space* s)
{
    position = s;
}

void Game::setHealth(int h)
{
    health = h;
}

void Game::setAtk(int a)
{
    atk = a;
}

void Game::setDef(int d)
{
    def = d;
}

void Game::setTimeLimit(int t)
{
    timeLimit = t;
}

int Game::getAtk()
{
    return atk;
}

int Game::getWeapon()
{
    return weapon;
}

int Game::getArmor()
{
    return armor;
}

void Game::setArmor(int a)
{
    armor = a;
}

void Game::setWeapon(int w)
{
    weapon = w;
}

void Game::adjTimeLimit(int i)
{
    timeLimit -= i;
}

int Game::getTimeLimit()
{
    return timeLimit;
}

void Game::setExploreFlag(bool b)
{
    exploreFlag = b;
}

bool Game::getSpecialDef()
{
    return specialDef;
}

bool Game::getSpecialAtk()
{
    return specialAtk;
}

void Game::setSpecialDef(bool b)
{
    specialDef = b;
}

void Game::setSpecialAtk(bool b)
{
    specialAtk = b;
}

void Game::setExploring(bool b)
{
    exploring = b;
}

bool Game::getExploring()
{
    return exploring;
}

bool Game::getJustExplored()
{
    return justExplored;
}

void Game::setJustExplored(bool b)
{
    justExplored = b;
}

