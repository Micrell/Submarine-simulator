/**
 * @file Humidity.hpp
 * @author Jules
 * @brief
 * @version 0.1
 * @date 2021-10-07
 *
 * @copyright Copyright (c) 2021
 *
 */

#ifndef HUMIDITY_H
#define HUMIDITY_H

#include "Data.hpp"
#include "Sensor.hpp"
#include <iostream>
#include <string>



class Humidity : public Sensor<float>
{
  public:
        //#########################################################
        //
        //          COPLIEN
        //
        
        /**
         * @brief Construct a new Humidity object with default attributes
         * 
         */
        Humidity();

        /**
         * @brief Construct a new Humidity object with custom name
         * 
         * @param name : name of the sensor
         */
        Humidity(std::string name_p);

        /**
         * @brief Construct a new Humidity object by copy
         * 
         * @param otherHumi : other humidity sensor
         */
        Humidity(const Humidity& otherHumi_p);

        /**
         * @brief Affect a humidity sensor into another one
         * 
         * @param otherHumi : Another humidity sensor
         * @return Humidity& a reference on the object affected
         */
        Humidity& operator=(const Humidity& otherHumi_p);

        /**
         * @brief Destroy the Humidity object
         * 
         */
        ~Humidity();

        //
        //          END COPLIEN
        //
        //#########################################################

        //#########################################################
        //
        //          METHODS
        //

        /**
         * @brief Get a data from the sensor
         * 
         * @return Data 
         */
        Data<float> getData() const;

        /**
         * @brief print the informations about the sensor
         * 
         */
        void printSensorInfo() const;

        //
        //          END METHODS
        //
        //#########################################################

  private:
        //#########################################################
        //
        //          METHODS
        //

        /**
         * @brief Generate a random humidity value
         * 
         * @return float : the value generated
         */
        float aleaGenVal() const;

        //
        //          END METHODS
        //
        //#########################################################




};

#endif //HUMIDITY_H
