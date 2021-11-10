/**
 * @file main.cpp
 * @author Jules
 * @brief this file contains the main function and other function that operate the choices menus when the program start
 * @version 0.1
 * @date 2021-10-07
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "Scheduler.hpp"
#include <iostream>
#include <ctime>
#include <limits>


/**
 * @brief This function print the menu to choose to add a sensor or to start capturing data
 *
 * @return int : The choice of the user
 */
int choiceMenu();

/**
 * @brief This function print the menu to choose the log option or not
 *
 * @return bool : True if the user choose to activate the log, else false
 */
bool logChoiceMenu();


/**
 * @brief This function print the menu to choose the print in console option or not
 *
 * @return bool : True if the user choose to activate the log, else false
 */
bool printChoiceMenu();

/**
 * @brief This function print the menu to add a sensor by choosing his name
 *
 * @param choice : represent the type of sensor that we want to add to the list
 * @param scheduler : the scheduler
 */
void addSensorMenu(int choice, Scheduler& scheduler);


int main()
{

	Scheduler scheduler;
	int choice;
	bool logActivated, printActivated;

	do	//while the user doesn't choose an valid option
	{
		choice = choiceMenu(); //print the choice menu and capture the choice of the user

		if(choice > 0 && choice < 5)
		{
			addSensorMenu(choice, scheduler); //if the user choose to add a sensor
		}

	}while(choice != 5);

	logActivated = logChoiceMenu(); //pick the choice of the user to activate de log option or not
	printActivated = printChoiceMenu();

	scheduler.startScheduling(logActivated, printActivated); //start capturing data

  return 0;
}

bool printChoiceMenu()
{
	int choice;

	do
	{
		choice = 0;

		std::cout << "\nWould you activate the print in console option ?";
		std::cout << "\n1: yes";
		std::cout << "\n2: no\n";

		std::cin >> choice;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


	}while(choice < 1 || choice > 2);

	if(choice == 1)
	{
		return true;
	}else
	{
		return false;
	}

	return true;
}



bool logChoiceMenu()
{
	int choice;

	do
	{
		choice = 0;

		std::cout << "\nWould you activate the save in log file option ?";
		std::cout << "\n1: yes";
		std::cout << "\n2: no\n";

		std::cin >> choice;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


	}while(choice < 1 || choice > 2);

	if(choice == 1)
	{
		return true;
	}else
	{
		return false;
	}

	return true;
}



int choiceMenu()
{

	int choice;
	do
	{

		choice = 0;
		std::cout << "\nSUBMARINE SIMULATION\n";
		std::cout << "\n1: Add a temperature sensor";
		std::cout << "\n2: Add a humidity sensor";
		std::cout << "\n3: Add a light sensor";
		std::cout << "\n4: Add a pression sensor";
		std::cout << "\n5: Start data fishing\n";

		std::cin >> choice;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	}while(choice < 1 || choice > 5);

	return choice;
}

void addSensorMenu(int choice, Scheduler& scheduler)
{
	std::string sensorName;

	std::cout << "\nADD SENSOR\n";

	std::cout << "\nSensor name:";
	std::cin >> sensorName;


	switch(choice)
	{
		case 1:
		{
			scheduler.addTempSensor(sensorName);
		}
		break;

		case 2:
		{
			scheduler.addHumiSensor(sensorName);
		}
		break;

		case 3:
		{
			scheduler.addLightSensor(sensorName);
		}
		break;

		case 4:
		{
			scheduler.addPressSensor(sensorName);
		}
		break;

		default:
		{
			std::cout << "Error choice unknown";
		}
		break;
	}
}



