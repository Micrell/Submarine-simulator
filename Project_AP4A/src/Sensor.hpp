/**
 * @file Sensor.hpp
 * @author Jules
 * @brief 
 * @version 0.1
 * @date 2021-10-04
 * 
 * @copyright Copyright (c) 2021
 * 
 */


#ifndef SENSOR_H
#define SENSOR_H

#include <iostream>
#include <string>
#include "Data.hpp"

template <typename T>
class Sensor
{
  public:
        //*********************************************************
        //
        //          COPLIEN
        //

        /**
         * @brief Construct a new Sensor object with default attributes
         * 
         */
        Sensor() : m_name("Sensor"), m_type("none"), m_unit("none")
        {

        }

        /**
         * @brief Construct a new Sensor object with custom attributes
         * 
         * @param name : name of the sensor
         * @param type : type of the sensor
         * @param unit : unit of the sensor
         */
        Sensor(std::string name_p, std::string type_p, std::string unit_p) : m_name(name_p), m_type(type_p), m_unit(unit_p)
        {

        }

        /**
         * @brief Construct a new Sensor object by copy
         * 
         * @param otherSensor
         */
        Sensor(const Sensor<T>& otherSensor_p) : m_name(otherSensor_p.m_name), m_type(otherSensor_p.m_type), m_unit(otherSensor_p.m_unit)
        {

        }

        /**
         * @brief Affect a sensor object into another one
         * 
         * @param otherSensor : another sensor
         * @return Sensor& 
         */
        Sensor<T>& operator=(const Sensor<T>& otherSensor_p)
        {

        }

        /**
         * @brief Destroy the Sensor object
         * 
         */
        virtual ~Sensor(void)
        {

        }

        //
        //          END COPLIEN
        //
        //*********************************************************

        //#########################################################
        //
        //          METHODS
        //

        /**
         * @brief Get the Data object from the sensor
         * 
         * @return Data 
         */

        virtual Data<T> getData() const = 0;
        
        /**
         * @brief print the informations of the sensor in the console
         * 
         */
        virtual void printSensorInfo() const = 0;

        //
        //          END METHODS
        //
        //#########################################################


  protected:

        //#########################################################
        //
        //          METHODS
        //

        /**
         * @brief generate a random value
         * 
         * @return float 
         */
        virtual T aleaGenVal() const = 0;
        
        //
        //          END METHODS
        //
        //#########################################################

        //$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
        //
        //          ATTRIBUTES
        //

        /**
         * @brief name of the sensor
         * 
         */
        std::string m_name;

        /**
         * @brief type of the sensor
         * 
         */
        std::string m_type;

        /**
         * @brief unit of the value that the sensor generate
         * 
         */
        std::string m_unit;

        //
        //          END ATTRIBUTES
        //
        //$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
  
          
};


#endif //SENSOR_H
