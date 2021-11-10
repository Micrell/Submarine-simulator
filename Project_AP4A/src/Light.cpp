/**
 * @file Light.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2021-10-07
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "Sensor.hpp"
#include "Light.hpp"
#include <iostream>
#include <string>

Light::Light() : Sensor("Light", "Light", "")
{

}

Light::Light(std::string name_p) : Sensor(name_p, "Light", "")
{

}

Light::Light(const Light& otherLight_p) : Sensor(otherLight_p)
{

}

Light &Light::operator=(const Light& otherLight_p)
{
  this->m_name = otherLight_p.m_name;
  this->m_type = otherLight_p.m_type;
  this->m_unit = otherLight_p.m_unit;

  return *this;
}

Light::~Light()
{

}




Data<bool> Light::getData() const
{
  Data<bool> data(this->m_type, this->m_name, aleaGenVal(), this->m_unit); //Create an object data

  return data;
}


bool Light::aleaGenVal() const
{

	return true;
}


void Light::printSensorInfo() const
{
  std::cout << "\nName : " << m_name;
  std::cout << "\nType : " << m_type;
  std::cout << "\nUnit : " << m_unit;
}


