/*********************************************************************
** Program name: menu.hpp
** Author: Andrew Ngo
** Date: 03/09/2018
** Description: Header for a Menu class that can be reused for any
* type of text-based menu that accepts numerical input. Private data
* members are ints for the range of valid input, and additional 
* vars for user choice, used to verify if the input is valid and pass
* the valid user choice into a main program.
*********************************************************************/

#include <string>

#ifndef MENU_HPP
#define MENU_HPP

/********************************************************************* 
** Description: menuChoice is an enumerated variable used for quickly
* associating an action to an input variable.
*********************************************************************/

enum menuChoice {DEBUG, PLAY, QUIT};

class Menu
{
private: 
    int start = 0;
    int end = 0;
    int choice = 0;
    int menuChoice = 0;
    bool validChoice = false;
public:
    Menu(int start, int end);
    void displayMenu();
    
    // getters and setters
    void setStart(int);
    void setEnd(int);
    void setChoice(int);
    void setMenuChoice(int);
    void setValidChoice(bool);
    int getMenuChoice();
    int getStart();
    int getEnd();
    int getChoice();
    bool getValidChoice();
    
    // validation functions
    bool checkValidChoice(int start, int end, int choice);
    int validatePosInt(int num, std::string request);
    int ensureLessThan(int, int, std::string, std::string);
    int ensureMoreThan(int, int, std::string, std::string);
    bool validInt(std::string check);
    int requestIntInput(std::string request);
    int requestPosIntInput(std::string request);
    int requestPosIntInputBetween(std::string request, int low, int high);

};
#endif