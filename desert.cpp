/*********************************************************************
** Program name: desert.cpp
** Author: Andrew Ngo
** Date: 03/10/2018
** Description: Class and function implementation for a Desert class,
* derived from Space.
*********************************************************************/

#include "desert.hpp"
#include "space.hpp"
#include <iostream>
#include <cstdlib>
#include <string>

Desert::Desert()
{}

/********************************************************************* 
** Description: event(): Possible events for a Desert area.
*********************************************************************/

void Desert::event(Game* game)
{
    int random = (rand() % 10);
    
    switch (random)
    {
        case 0:
        {
            if (game->getStats() < 170)
            {
                std::cout << "A malnourished desert coyote attacks you!" << std::endl;
                if (game->getStats() < 120)
                {
                    std::cout << "You managed to barely fend it off and took some damage. You become a bit better at combat. (-10 HP, +10 Atk)" << std::endl;
                    game->hp(-10);
                    game->atkup(15);
                    break;
                }
                if (game->getStats() >= 120)
                {
                    std::cout << "You fight it off without any problems. You become a bit better at fighting. (+10 Atk, +10 Def)";
                    game->atkup(10);
                    game->defup(10);
                    break;
                }
            }
            break;
        }
        
        case 1:
        {
            if (game->getWeapon() < 3)
            {
                std::cout << "You see a glinting piece of metal buried in the sand. You approach it and unearth a powerful sword! (+50 Atk)";
                game->atkup(50);
                game->setWeapon(3);
                break;
            }
            if (game->getHealth() < 100)
            {
                std::cout << "You come across a fresh water oasis and drink to quench your thirst. (HP restored)";
                if (game->getHealth() > 80)
                {
                    game->setHealth(100);
                    break;
                }
                else game->hp(20);
                break;
            }
            if (game->getStats() >= 150)
            {
                std::cout << "Traversing the desert makes you thirsty and tired, but tougher in mind and body. (-10 HP, +10 Atk, + 10 Def)";
                game->hp(-10);
                game->atkup(10);
                game->defup(10);
                break;
            }
            break;
        }
        case 2:
        {
            if (game->getStats() >= 150)
            {
                std::cout << "You stumble across two hungry wolves that lunge upon seeing you!" << std::endl;
                if (game->getStats() >= 200)
                {
                    std::cout << "They were no match for you. (+10 Atk, +10 Def)";
                    game->atkup(10);
                    game->defup(10);
                    break;
                }
                if (game->getStats() < 200)
                {
                    std::cout << "A two vs one fight is tough, but you prevail and your strength increases. (-15 HP, +15 Atk, +10 Def)";
                    game->hp(-15);
                    game->atkup(15);
                    game->defup(10);
                    break;
                }
            }
            if (game->getArmor() < 2)
            {
                std::cout << "You find a leather cloak, a bit sandy but still good for protection from the elements. (+20 Def)";
                game->defup(20);
                game->setArmor(2);
                break;
            }
            break;
        }
        case 3:
        {        
            if (game->getStats() > 160)
            {
                std::cout << "You're forced to traverse a long distance without water. (-15 HP)";
                game->hp(-15);
                break;
            }
            if (game->getStats() <= 160)
            {
                std::cout << "The raging desert winds assault your senses. (-5 HP)";
                game->hp(-5);
                break;
            }
            break;
        }
    }
    std::cout << std::endl;
}

/********************************************************************* 
** Description: greet(): messages that get printed to console in a desert area.
*********************************************************************/

void Desert::greet()
{
    int random = (rand() % 6);
    
    switch (random)
    {
        case 0:
        {
            std::cout << "The arid air parches your throat.";
            break;
        }
        case 1:
        {
            std::cout << "Swirling sand dances in the distance.";
            break;
        }
        case 2:
        {
            std::cout << "As you enter the zone, you feel the sand give way beneath your feet.";
            break;
        }
        case 3:
        {
            std::cout << "In the distance, you see mountains of golden sand.";
            break;
        }
        case 4:
        {
            std::cout << "As you cross into the zone, a barren landscape greets you.";
            break;
        }
        case 5:
        {
            std::cout << "You cough and shield your eyes as a sandstorm blows past you.";
            break;
        }
    }
    std::cout << std::endl;
}

/********************************************************************* 
** Description: getName(): possible names for Desert areas, including
* one that can be explored.
*********************************************************************/

std::string Desert::getName()
{
    setCanExplore(false);
    std::string name;
    int random = (rand() % 7);
    
    switch (random)
    {
        case 0:
        {
            name = "Wildspire Wastes";
            break;
        }
        case 1:
        {
            name = "Arid Barrens";
            break;
        }
        case 2:
        {
            name = "Dried Lake";
            break;
        }
        case 3:
        {
            name = "Parched Flats";
            break;
        }
        case 4:
        {
            name = "Scorched Sands";
            break;
        }
        case 5:
        {
            name = "Desolated Field";
            break;
        }
        case 6:
        {
            name = "Ancient Ruins";
            setCanExplore(true);
            break;
        }
    }
    return name;
}

/********************************************************************* 
** Description: explore(): possible exploration events for Desert.
*********************************************************************/

void Desert::explore(Game* game)
{
    int random = (rand() % 3);
    {
        switch (random)
        {
            case 0:
            {
                std::cout << "The ruins are filled with traps. You accidentally stumble across a dart trap. Fortunately, whatever poison on it has long since expired. (-15 HP)";
                game->hp(-15);
                break;
            }
            case 1:
            {
                std::cout << "These ruins are the tomb of an ancient king. ";
                if (game->getSpecialDef() == false)
                {
                    std::cout << "Several protective charms adorn the inner chambers. Sensing great power from them, you touch one. Your defensive power greatly increases!";
                    game->defup(100);
                    game->setSpecialDef(true);
                    break;
                }
                else 
                {
                    std::cout << "There doesn't seem to be anything else of value here.";
                    break;
                }
            }
            case 2:
            {
                if (game->getHealth() > 50)
                {
                    std::cout << "Exploring the ruins, the floor suddenly gives way beneath you. You are injured, but able to escape. Unfortunately, this gives the Pursuer some time to catch up. (-15 HP, -3 Time)";
                    game->hp(-15);
                    game->adjTimeLimit(3);
                    break;
                }
                else if (game->getHealth() < 50)
                {
                    std::cout << "Your breath runs ragged as fatigue sets in. You are forced to take a rest. (+10 HP, -2 Time)";
                    game->hp(10);
                    game->adjTimeLimit(2);
                    break;
                }
            }
        }
        setCanExplore(false);
        std::cout << std::endl;
    }
}