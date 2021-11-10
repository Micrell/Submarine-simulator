/**
 * @file Temperature.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-10-07
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "Sensor.hpp"
#include "Temperature.hpp"
#include "Data.hpp"
#include <iostream>
#include <string>

Temperature::Temperature() : Sensor("Temperature", "Temperature", "celsius")
{

}

Temperature::Temperature(std::string name_p) : Sensor(name_p, "Temperature", "Celsius")
{

}

Temperature::Temperature(const Temperature& otherTemp_p) : Sensor(otherTemp_p)
{

}

Temperature& Temperature::operator=(const Temperature& otherTemp_p)
{
  this->m_name = otherTemp_p.m_name;
  this->m_type = otherTemp_p.m_type;
  this->m_unit = otherTemp_p.m_unit;

  return *this;
}

Temperature::~Temperature()
{

}

Data<float> Temperature::getData() const
{
  Data<float> data(this->m_type, this->m_name, aleaGenVal(), this->m_unit); //Create a data object

  return data;
}


float Temperature::aleaGenVal() const
{
  float rand1_0 = rand() / (float)RAND_MAX; //Generate a random float value between 19 et 20

  return rand1_0+19.0;
}


void Temperature::printSensorInfo() const
{
  std::cout << "\nName : " << m_name;
  std::cout << "\nType : " << m_type;
  std::cout << "\nUnit : " << m_unit;
}


