/**
 * @file Pression.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2021-10-07
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "Sensor.hpp"
#include "Pression.hpp"
#include <iostream>
#include <string>

Pression::Pression() : Sensor("Pression", "Pression", "hPA")
{

}

Pression::Pression(std::string name_p) : Sensor(name_p, "Pression", "hPA")
{

}

Pression::Pression(const Pression& otherPression_p) : Sensor(otherPression_p)
{

}

Pression& Pression::operator=(const Pression& otherPression_p)
{
  this->m_name = otherPression_p.m_name;
  this->m_type = otherPression_p.m_type;
  this->m_unit = otherPression_p.m_unit;

  return *this;
}

Pression::~Pression()
{

}




Data<int> Pression::getData() const
{
  Data<int> data(this->m_type, this->m_name, aleaGenVal(), this->m_unit); //Create a data object

  return data;
}


int Pression::aleaGenVal() const
{
	int rand1_0 = rand() / (float)RAND_MAX;  //Random number between 0 and 1
	int rand1000_1013 = ((rand()%2)*3)+1000; //Random number between 1000 and 1013

	return rand1_0+rand1000_1013;
}


void Pression::printSensorInfo() const
{
  std::cout << "\nName : " << m_name;
  std::cout << "\nType : " << m_type;
  std::cout << "\nUnit : " << m_unit;
}


