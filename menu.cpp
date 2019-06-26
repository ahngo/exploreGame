/*********************************************************************
** Program name: menu.cpp
** Author: Andrew Ngo
** Date: 02/28/2018
** Description: Function implementation for a menu class that performs
* simple input validation.
*********************************************************************/

#include <iostream>
#include <string>
#include <cctype>

#include "menu.hpp"

/********************************************************************* 
** Description: checkValidChoice checks to see if the user's choice
* is in the range of valid menu options. Uses setValidChoice() to
* flag validChoice.
*********************************************************************/

bool Menu::checkValidChoice(int start, int end, int choice)
{
    if (choice >= start && choice <= end)
    {
        return true;
    }
    else return false;
}

/********************************************************************* 
** Description: setMenuChoice takes an int and sets the choice of the
* user. The choice is used to proceed within the program.
*********************************************************************/

void Menu::setMenuChoice(int choice)
{
    menuChoice = choice;
}

/********************************************************************* 
** Description: setValidChoice takes a bool and assigns it to 
* validChoice.
*********************************************************************/

void Menu::setValidChoice(bool validity)
{
    validChoice = validity;
}

/********************************************************************* 
** Description: setStart takes an int and sets it as the start of 
* valid inputs for the menu.
*********************************************************************/

void Menu::setStart(int s)
{
    start = s;
}

/********************************************************************* 
** Description: setStart takes an int and sets it as the end of 
* valid inputs for the menu.
*********************************************************************/

void Menu::setEnd(int e)
{
    end = e;
}

/********************************************************************* 
** Description: setStart takes an int and sets it as the end of 
* valid inputs for the menu.
*********************************************************************/

void Menu::setChoice(int c)
{
    choice = c;
}

/********************************************************************* 
** Description: menu() takes two ints and constructs a Menu class
* using the ints as the range of valid inputs for the menu.
*********************************************************************/
Menu::Menu(int s, int e)
{
    setStart(s);
    setEnd(e);
}

int Menu::getMenuChoice()
{
    return menuChoice;
}

int Menu::getStart()
{
    return start;
}

int Menu::getEnd()
{
    return end;
}

int Menu::getChoice()
{
    return choice;
}

bool Menu::getValidChoice()
{
    return validChoice;
}

/********************************************************************* 
** Description: displayMenu() greets the user and presents him or her
* with valid menu inputs. Validates the menu input and sets MenuChoice
* to pass it in main.
*********************************************************************/

void Menu::displayMenu()
{
    int entry = 0;
    std::string input = "";
    
    std::cout << "Labyrinth Pursuit" << std::endl;
    std::cout << "Please enter the number corresponding to your choice."
              << std::endl
              << "1. Play" << std::endl
              << "2. Quit" << std::endl;

    entry = requestIntInput("Your menu choice");
    
    setChoice(entry);
    
    checkValidChoice(getStart(), getEnd(), getChoice());
    
    while ((std::cin.fail()) || !(checkValidChoice(getStart(), getEnd(), getChoice())))
    {
        std::cout << "Please enter a valid menu option." << std::endl;
        
        std::cin.clear();
        entry = requestIntInput("Your menu choice");
        setChoice(entry);
        checkValidChoice(getStart(), getEnd(), getChoice());
    }
    
    setMenuChoice(entry);
}

/********************************************************************* 
** Description: validatePosInt() ensures that a passed integer is 
* positive. The function also accepts a string to give the user
* additional information if the function deems it necessary.
*********************************************************************/

int Menu::validatePosInt(int num, std::string request)
{
    if (!(std::cin.fail()) && num > 0)
    {
        return num;
    }
    
    int validatedRequest = 0;
    
    while (validatedRequest < 1 || std::cin.fail())
    {   
        
        std::cout << "Please enter a positive integer." << std::endl
                  << request << ": ";
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::cin >> validatedRequest;
    }
    return validatedRequest;
}

/********************************************************************* 
** Description: ensureLessThan() ensures that of two ints, one is
* smaller than the other. If not, uses two string variables to relay
* information to the user.
*********************************************************************/

int Menu::ensureLessThan(int var, int comparedTo, std::string var1, std::string var2)
{
    if (var < comparedTo)
    {
        return var;
    }

    while (var > comparedTo)
    {
        std::cout << "Error. " << var1 << " is too large compared to " << var2 
                  << "." << std::endl << "Please enter a new number for " << var1 
                  << ": ";
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::cin >> var;
        var = validatePosInt(var, var1);
    }
    return var;
}

/********************************************************************* 
** Description: ensureMoreThan() ensures that of two ints, one is
* larger than the other. If not, uses two string variables to relay
* information to the user.
*********************************************************************/

int Menu::ensureMoreThan(int var, int comparedTo, std::string var1, std::string var2)
{
    if (var > comparedTo)
    {
        return var;
    }
    
    while (var < comparedTo)
    {
        std::cout << "Error. " << var1 << " is too small compared to " << var2 
                  << "." << std::endl << "Please enter a new number for " << var1 
                  << ": ";
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::cin >> var;
        var = validatePosInt(var, var1);
    }
    return var;
}

/********************************************************************* 
** Description: validInt() uses getline to get a full input and checks
* all chars to ensure only ints were entered.
*********************************************************************/

bool Menu::validInt(std::string check)
{
    if (check.length() == 0)
    {
        return false;
    }
    
    for (unsigned int i = 0; i < check.length(); i++)
    {
        if (!(isdigit(check[i])))
        {
            return false;
        }
    }
    return true;
}

/********************************************************************* 
** Description: requestIntInput() takes a string to cout to the user
* as a request and validates the input.
*********************************************************************/

int Menu::requestIntInput(std::string request)
{
    std::string input = "";
    
    std::cout << request << ": ";
    
    getline(std::cin, input);
    
    while (!validInt(input) || std::cin.fail())
    {
        std::cout << "Please enter only integers." << std::endl;
        std::cin.clear();
        std::cout << request << ": ";
        getline(std::cin, input);
    }
    return stoi(input);
}

/********************************************************************* 
** Description: requestPosIntInput() takes a string to cout to the user
* as a request and validates the input, ensuring it is positive.
*********************************************************************/

int Menu::requestPosIntInput(std::string request)
{
    std::string input = "";
    
    std::cout << request << ": ";
    
    getline(std::cin, input);
    
    while (!validInt(input) || std::cin.fail() || (stoi(input) < 0))
    {
        std::cout << "Please enter only positive integers." << std::endl;
        std::cin.clear();
        std::cout << request << ": ";
        getline(std::cin, input);
    }
    return stoi(input);
}


/********************************************************************* 
** Description: requestPosIntInputBetween() takes a string to cout to the user
* as a request and validates the input, ensuring it is positive and within
* specified limits.
*********************************************************************/

int Menu::requestPosIntInputBetween(std::string request, int low, int high)
{
    std::string input = "";
    
    std::cout << request << ": ";
    
    getline(std::cin, input);
    
    while (!validInt(input) || std::cin.fail() || (stoi(input) < low) || (stoi(input) > high))
    {
        std::cout << "Please enter an integer within the specified limit." << std::endl;
        std::cin.clear();
        std::cout << request << ": ";
        getline(std::cin, input);
    }
    return stoi(input);
}

