/*********************************************************************
** Program name: snow.cpp
** Author: Andrew Ngo
** Date: 03/10/2018
** Description: Class and function implementation for a Snow class,
* derived from Space.
*********************************************************************/

#include "snow.hpp"
#include "space.hpp"
#include <iostream>
#include <cstdlib>
#include <string>

Snow::Snow()
{}

/********************************************************************* 
** Description: event(): Possible events for a Snow area.
*********************************************************************/

void Snow::event(Game* game)
{
    int random = (rand() % 10);
    
    switch (random)
    {
        case 0:
        {
            if (game->getWeapon() < 2)
            {
                std::cout << "You enter a cave for shelter from the cold. Inside, you find some usable armaments! (+30 Atk)";
                game->atkup(30);
                game->setWeapon(2);
                break;
            }
            else
            {
                std::cout << "You are attacked by a Frost Yeti! You prevail, but are injured. Your skill in combat grows. (-25 HP, +10 Atk).";
                game->atkup(10);
                game->hp(-25);
                break;
            }
        }
        
        case 1:
        {
            if (game->getArmor() < 2)
            {
                std::cout << "You find a cloak crafted from the hide of a Frost Yeti. You put it on, wanting any warmth and protection you can get. (+25 Def)";
                game->defup(25);
                game->setArmor(2);
                break;
            }
            else
            {
                std::cout << "You find a flask hanging on a frozen tree. You fill it with snow to let it melt into water.";
                game->addItem(2);
                break;
            }
        }
        
        case 2:
        {
            if (game->getHealth() > 50)
            {
                std::cout << "You are caught in a blizzard and frantically seek shelter. The elements take a toll on your health. (-15 HP)";
                game->hp(-15);
                break;
            }
            
            if (game->getHealth() < 50)
            {
                std::cout << "You find some flint and firewood stored in a cave. Able to start a fire, the warmth lifts your spirits and soothes your body (+10 HP, +5 Atk, +5 Def).";
                game->atkup(5);
                game->defup(5);
                game->hp(10);
                break;
            }
            break;
        }
        case 9:
        {        
            {
                std::cout << "The skies grow dark and the air somehow becomes even colder.. the Pursuer draws close. (-3 Time)";
                game->adjTimeLimit(3);
            }
        }
    }
    std::cout << std::endl;
}

void Snow::greet()
{
    int random = (rand() % 6);
    
    switch (random)
    {
        case 0:
        {
            std::cout << "Snowflakes drift slowly from the sky, blanketing the landscape in pure white..";
            break;
        }
        case 1:
        {
            std::cout << "The wind howls while frosty air saps your body heat.";
            break;
        }
        case 2:
        {
            std::cout << "You enter the zone, freshly fallen snow crunching beneath your feet.";
            break;
        }
        case 3:
        {
            std::cout << "The sounds of nature seem to be subdued by the layers of snow in the zone.";
            break;
        }
        case 4:
        {
            std::cout << "The temperature around you drops rapidly as you enter the zone.";
            break;
        }
        case 5:
        {
            std::cout << "Glancing at the zone, you squint as a ray of sunshine reflects off a hill of snow.";
            break;
        }
    }
    std::cout << std::endl;
}

/********************************************************************* 
** Description: getName(): possible names for Snow areas, including
* one that can be explored.
*********************************************************************/

std::string Snow::getName()
{
    setCanExplore(false);
    std::string name;
    int random = (rand() % 7);
    
    switch (random)
    {
        case 0:
        {
            name = "Snowy Trail";
            break;
        }
        case 1:
        {
            name = "Eternal Tundra";
            break;
        }
        case 2:
        {
            name = "Frozen Expanse";
            break;
        }
        case 3:
        {
            name = "Glacial Desert";
            break;
        }
        case 4:
        {
            name = "Pearl Flatlands";
            break;
        }
        case 5:
        {
            name = "Icicle Fields";
            break;
        }
        case 6:
        {
            name = "Temple of the Frost Spirits";
            setCanExplore(true);
            break;
        }
    }
    return name;
}

/********************************************************************* 
** Description: explore(): possible exploration events for Snow.
*********************************************************************/

void Snow::explore(Game* game)
{
    int random = (rand() % 3);
    {
        switch (random)
        {
            case 0:
            {
                std::cout << "The temple, although formed from ice, is rather comfortable inside. You take refuge and rest well (+20 HP)";
                game->hp(20);
                break;
            }
            case 1:
            {
                std::cout << "Despite being inside, there are several slight breezes in the air. There is something supernatural about the atmosphere. ";
                if (game->getSpecialAtk() == false)
                {
                    std::cout << "A frost spirit whispers to you, wanting to help you in your plight against the Pursuer. Your weapon glows an icy blue. (Atk greatly increased)";
                    game->atkup(100);
                    game->setSpecialAtk(true);
                    break;
                }
                else 
                {
                    std::cout << "The spirit in your weapon is excited to be back home, but you feel it urging you to complete your quest.";
                    break;
                }
            }
            case 2:
            {
                if (game->getInvSize() == 0)
                {
                    std::cout << "Exploring the temple, you find a plate of delicious looking fruit. Approaching it carefully, you take one for your pouch.";
                    game->addItem(1);
                    break;
                }
                else if (game->getInvSize() > 0)
                {
                    std::cout << "You sit and commune with the frost spirits for a while. They encourage you. (+5 HP, +5 Atk, +5 Def)";
                    game->hp(5);
                    game->atkup(5);
                    game->defup(5);
                    break;
                }
            }
        }
        setCanExplore(false);
        std::cout << std::endl;
    }
}