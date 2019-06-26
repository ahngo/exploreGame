/*********************************************************************
** Program name: main.cpp
** Author: Andrew Ngo
** Date: 03/10/2018
** Description: main.cpp combined with Space and its derived classes
* Desert, Snow, Forest, as well as a Game class creates an exploration
* game.
*********************************************************************/

#include "space.hpp"
#include "game.hpp"
#include "desert.hpp"
#include "snow.hpp"
#include "forest.hpp"
#include "menu.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "helpers.hpp"

int main()
{
    srand(time(NULL)); // seed for random rolls
    Menu menu(1, 2);
    bool open = true;
    while (open)
    {
        menu.displayMenu();
        if (menu.getMenuChoice() == QUIT)
        {
            std::cout << "Quitting program." << std::endl;
            return 0;
        }
        if (menu.getMenuChoice() == PLAY)
        {   
            std::cout << "You are an adventurer trapped in the Labyrinth of the Pursuer." << std::endl;
            std::cout << "You have limited time to scavenge what items and power you can in the mysterious, everchanging Labyrinth." << std::endl;
            std::cout << "You perish if your health hits zero. When time hits zero, the Pursuer will attack you. Each movement takes 1 Time. Each exploration takes 2 Time." << std::endl;
            std::cout << "Navigate the map, events and your inventory (when possible) by entering keys when prompted (not case sensitive)." << std::endl;
            std::cout << "Good luck and may the mysteries of the Labyrinth reveal themselves to you." << std::endl;
            std::cout << "Starting the game.." << std::endl;
    
            // create game and the random map
            Game* game = new Game();
            game->generateMap();
            game->printStatus();
            char input;
            bool running = true;
            while (running)
            {
                // health check
                if (game->getHealth() <= 0)
                {
                    std::cout << "Your vision goes dark as your body collapses from fatigue." << std::endl;
                    running = false;
                    break;
                }
                // explore event check
                if ((game->getPosition()->getCanExplore() == true) && (game->getJustExplored() == false))
                {
                    game->setExploreFlag(true);
                }
                // update/print valid moves, get user input for move
                game->getValidMoves();
                game->printValidMoves();
                std::cout << "Your choice: ";
                std::cin.get(input);
                std::cin.clear();
                std::cin.ignore(256, '\n');
                game->move(input);
                std::cout << std::endl;
                // after a valid move 
                if (game->getMadeValidMove() == true)
                {
                    game->getPosition()->greet();
                    game->getPosition()->event(game);
                    game->adjTimeLimit(1);
                    game->setJustExplored(false);
                    game->printStatus();
                }
                // for explore events
                if (game->getExploring() == true)
                {
                    game->getPosition()->explore(game);
                    game->adjTimeLimit(2);
                    game->setJustExplored(true);
                    game->setExploreFlag(false);
                    game->printStatus();
                }
                // boss fight/end
                if (game->getTimeLimit() <= 0)
                {
                    running = false;
                    bool boss = game->boss();
                    if (boss == true)
                    {
                        std::cout << "Congratulations and thank you for playing!";
                    }
                    else 
                    {
                        std::cout << "You were defeated, but thank you for playing!";
                    }
                    std::cout << std::endl;
                }
            }
            delete game;
        }
    }
}