/*********************************************************************
** Program name: forest.hpp
** Author: Andrew Ngo
** Date: 03/10/2018
** Description: Class and function declaration for a Forest class,
* derived from Space.
*********************************************************************/

#include "forest.hpp"
#include "space.hpp"
#include "game.hpp"
#include <iostream>
#include <cstdlib>
#include <string>

Forest::Forest()
{}

/********************************************************************* 
** Description: event(): Possible events for a Forest area.
*********************************************************************/

void Forest::event(Game* game)
{
    int random = (rand() % 10);
    
    switch (random)
    {
        case 0:
        {
            if (game->getWeapon() < 1)
            {
                std::cout << "You find an unattended axe sticking out of a tree stump. Approaching it cautiously, you remove it and arm yourself (+15 Atk)";
                game->atkup(15);
                game->setWeapon(1);
                break;
            }
            if (game->getArmor() < 1)
            {
                std::cout << "Stumbling across the remains of a campfire, you find a worn-out, but sturdy pair of boots. They fit you! (+10 Def)";
                game->defup(10);
                game->setArmor(1);
                break;
            }
        }
        
        case 1:
        {
            if (game->getStats() < 180)
            {
                std::cout << "You are assailed by a forest goblin! It tackles you, but you manage to defeat it! (-5 HP, +5 Atk)";
                game->hp(-5);
                game->atkup(5);
                break;
            }
            if (game->getStats() >= 180)
            {
                std::cout << "You come across an unguarded goblin encampment and snatch a Forest Fruit from their stores.";
                game->addItem(1);
                break;
            }
        }
        
        case 2:
        {
            if (game->getHealth() < 90)
            {
                std::cout << "A bit weary from all the travel, you sit and rest next to a stream (HP slightly restored)";
                game->hp(10);
                break;
            }
            
            if (game->getHealth() > 90)
            {
                std::cout << "Coming across a training dummy used by a long-gone adventurer, you practice fighting and using your weapon. (+10 Atk)";
                game->atkup(10);
                break;
            }
            break;
        }
        case 9:
        {        
            if (game->getWeapon() <= 1)
            {
                std::cout << "The remains of an adventurer sit against a tree, a sword sitting next to him or her. It will find better use in your hands. (+30 Atk)";
                game->atkup(30);
                game->setWeapon(2);
                break;
            }
            else
            {
                std::cout << "You sense the presence of the Pursuer. An ominous feeling shrouds your mind, but you manage to hide from it for now. (-3 Time)";
                game->adjTimeLimit(3);
                break;
            }
            
        }
    }
    std::cout << std::endl;
}

/********************************************************************* 
** Description: greet(): possible messages for Forest areas.
*********************************************************************/

void Forest::greet()
{
    int random = (rand() % 6);
    
    switch (random)
    {
        case 0:
        {
            std::cout << "A verdant forest greets your eyes as you enter the zone.";
            break;
        }
        case 1:
        {
            std::cout << "The scent of vegetation tickles your nose.";
            break;
        }
        case 2:
        {
            std::cout << "You hear the sound of a stream trickling and birds chirping.";
            break;
        }
        case 3:
        {
            std::cout << "The sounds of nature surround the zone.";
            break;
        }
        case 4:
        {
            std::cout << "As you enter the zone, twigs crunch beneath your shoes.";
            break;
        }
        case 5:
        {
            std::cout << "You wander across oak-brown trees with clumps of moss.";
            break;
        }
    }
    std::cout << std::endl;
}

/********************************************************************* 
** Description: getName(): possible names for Forest areas, including
* two that can be explored.
*********************************************************************/

std::string Forest::getName()
{
    setCanExplore(false);
    std::string name;
    int random = (rand() % 7);
    
    switch (random)
    {
        case 0:
        {
            name = "Serene Grove";
            setCanExplore(true);
            break;
        }
        case 1:
        {
            name = "Ancient Forest";
            break;
        }
        case 2:
        {
            name = "Waterfall Woods";
            break;
        }
        case 3:
        {
            name = "Whispering Forest";
            break;
        }
        case 4:
        {
            name = "Vibrant Thicket";
            break;
        }
        case 5:
        {
            name = "Verdant Woodland";
            break;
        }
        case 6:
        {
            name = "Verdant Sanctuary";
            setCanExplore(true);
            break;
        }
    }
    return name;
}

/********************************************************************* 
** Description: explore(): possible exploration events for Forest.
*********************************************************************/

void Forest::explore(Game* game)
{
    int random = (rand() % 3);
    {
        switch (random)
        {
            case 0:
            {
                std::cout << "Unfortunately, you didn't find anything of value..";
                break;
            }
            case 1:
            {
                std::cout << "You come across an ancient hero's hideout. You sense the presence of protective wards and rest well. (HP Restored, +5 Def)";
                game->hp(100);
                game->defup(5);
                break;
            }
            case 2:
            {
                if (game->getInvSize() < 5)
                {
                    std::cout << "You found an adventurer's abandoned flask of water and put it in your pouch.";
                    game->addItem(2);
                    break;
                }
                else if (game->getInvSize() >= 5)
                {
                    std::cout << "You found some items, but your pouch is full!";
                    break;
                }
            }
        }
        setCanExplore(false);
        std::cout << std::endl;
    }
}