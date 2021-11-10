/**
 * @file Humidity.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2021-10-07
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "Sensor.hpp"
#include "Humidity.hpp"
#include <iostream>
#include <string>

Humidity::Humidity() : Sensor("Humidity", "Humidity", "%")
{

}

Humidity::Humidity(std::string name_p) : Sensor(name_p, "Humidity", "%")
{

}

Humidity::Humidity(const Humidity& otherHumi_p) : Sensor(otherHumi_p)
{

}

Humidity& Humidity::operator=(const Humidity& otherHumi_p)
{
  this->m_name = otherHumi_p.m_name;
  this->m_type = otherHumi_p.m_type;
  this->m_unit = otherHumi_p.m_unit;

  return *this;
}

Humidity::~Humidity()
{

}




Data<float> Humidity::getData() const
{
  Data<float> data(this->m_type, this->m_name, aleaGenVal(), this->m_unit); //Create an object Data

  return data;
}


float Humidity::aleaGenVal() const
{

  return (float) (rand()%5)+40; //Generate a random value between 40 and 45
}


void Humidity::printSensorInfo() const
{
  std::cout << "\nName : " << m_name;
  std::cout << "\nType : " << m_type;
  std::cout << "\nUnit : " << m_unit;
}


