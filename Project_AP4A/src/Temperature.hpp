/**
 * @file Temperature.hpp
 * @author Jules
 * @brief 
 * @version 0.1
 * @date 2021-10-07
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include "Data.hpp"
#include "Sensor.hpp"
#include <iostream>
#include <string>



class Temperature : public Sensor<float>
{
  public:
        //#########################################################
        //
        //          COPLIEN
        //
        
        /**
         * @brief Construct a new Temperature object with default attributes
         * 
         */
        Temperature();

        /**
         * @brief Construct a new Temperature object with a custom name
         * 
         * @param name : name of the sensor
         */
        Temperature(std::string name_p);

        /**
         * @brief Construct a new Temperature object by copy
         * 
         * @param otherTemp : another temperature sensor
         */
        Temperature(const Temperature& otherTemp_p);

        /**
         * @brief Affect a temperature object into another one
         * 
         * @param otherTemp : another temperature object
         * @return Temperature& : a reference on the object affected
         */
        Temperature& operator=(const Temperature& otherTemp_p);

        /**
         * @brief Destroy the Temperature object
         * 
         */
        ~Temperature();

        //
        //          END COPLIEN
        //
        //#########################################################

        //#########################################################
        //
        //          METHODS
        //

        /**
         * @brief Get the Data object from the sensor
         * 
         * @return Data 
         */
        Data<float> getData() const;

        /**
         * @brief print the informations of the sensor in the console
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
         * @brief Generate a random temperature value
         * 
         * @return float 
         */
        float aleaGenVal() const;

        //
        //          END METHODS
        //
        //#########################################################

};

#endif //TEMPERATURE_H
