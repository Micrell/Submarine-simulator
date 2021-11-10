/**
 * @file Scheduler.cpp
 * @author Jules
 * @brief 
 * @version 0.1
 * @date 2021-10-07
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream>
#include <string>
#include <list>

#include "Scheduler.hpp"
#include "Temperature.hpp"




Scheduler::Scheduler() : m_server()
{
  addTempSensor("temp_1");
  addHumiSensor("humi_1");
  addPressSensor("press_1");
  addLightSensor("light_1");
}

Scheduler& Scheduler::operator=(const Scheduler& otherScheduler_p)
{
  this->m_tempSensorList = otherScheduler_p.m_tempSensorList;

  return *this;
}


Scheduler::~Scheduler()
{
  while(!this->m_tempSensorList.empty())
  {
  	delete this->m_tempSensorList.back();
  	this->m_tempSensorList.pop_back();
  }
}

void Scheduler::addTempSensor(std::string name_p)
{
	addSensor<Temperature, float>(name_p, this->m_tempSensorList);
}

void Scheduler::addHumiSensor(std::string name_p)
{
	addSensor<Humidity, float>(name_p, this->m_humiSensorList);
}

void Scheduler::addPressSensor(std::string name_p)
{
	addSensor<Pression, int>(name_p, this->m_pressionSensorList);
}

void Scheduler::addLightSensor(std::string name_p)
{
	addSensor<Light, bool>(name_p, this->m_lightSensorList);
}



template<typename T, typename S>
void Scheduler::addSensor(std::string name_p, std::list<Sensor<S>*>& sensorList_p)
{
	Sensor<S>* newSensor;

	newSensor = new T(name_p);

	sensorList_p.push_back(newSensor);
}


void Scheduler::printDataFromAllSensors()
{
	for(auto sensor : this->m_tempSensorList)
	{
		this->m_server.consoleWrite(sensor->getData());

		if(this->m_logActivate == true) //if option log activate
		{
			this->m_server.fileWrite(sensor->getData());
		}
	}
}

void Scheduler::printSensorInfoFromAllSensors()
{
  for(auto sensor : this->m_tempSensorList)
  {
		sensor->printSensorInfo();
  }
}

void Scheduler::startScheduling(bool logActivate_p, bool printActivate_p)
{

  this->m_logActivate = logActivate_p;
  this->m_printActivate = printActivate_p;

  std::clock_t iteratorTemp, iteratorHumi, iteratorPress, iteratorLight, now;

  iteratorTemp = std::clock();
  iteratorHumi = std::clock();
  iteratorPress = std::clock();
  iteratorLight = std::clock();

	while(true)
	{
		now = std::clock();

		if(now - iteratorTemp >= 20*CLOCKS_PER_SEC) //capture the data from all temperature sensors each 20 seconds
		{
			printDataFromSensor(this->m_tempSensorList);
			iteratorTemp = std::clock();
		}

		if(now - iteratorHumi >= 30*CLOCKS_PER_SEC) //capture the data from all humidity sensors each 30 seconds
		{
			printDataFromSensor(this->m_humiSensorList);
			iteratorHumi = std::clock();
		}

		if(now - iteratorPress >= 2*CLOCKS_PER_SEC) //capture the data from all pression sensors each 2 seconds
		{
			printDataFromSensor(this->m_pressionSensorList);
			iteratorPress = std::clock();
		}

		if(now - iteratorLight >= 60*CLOCKS_PER_SEC) //capture the datas from all light sensors each 60 seconds
		{
			printDataFromSensor(this->m_lightSensorList);
			iteratorLight = std::clock();
		}
	}
}

