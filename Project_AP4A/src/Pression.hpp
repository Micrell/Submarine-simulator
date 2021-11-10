/**
 * @file Pression.hpp
 * @author Jules
 * @brief
 * @version 0.1
 * @date 2021-10-07
 *
 * @copyright Copyright (c) 2021
 *
 */

#ifndef PRESSION_H
#define PRESSION_H

#include "Data.hpp"
#include "Sensor.hpp"
#include <iostream>
#include <string>



class Pression : public Sensor<int>
{
  public:
        //#########################################################
        //
        //          COPLIEN
        //

        /**
         * @brief Construct a new Pression object with default attributes
         * 
         */
        Pression();

        /**
         * @brief Construct a new Pression object with a custom name
         * 
         * @param name
         */
        Pression(std::string name);

        /**
         * @brief Construct a new Pression object by copy
         * 
         * @param otherPression
         */
        Pression(const Pression& otherPression);

        /**
         * @brief Affect a pression object into another one
         * 
         * @param otherPression
         * @return Pression& 
         */
        Pression &operator=(const Pression& otherPression);

        /**
         * @brief Destroy the Pression object
         * 
         */
        ~Pression();

        //
        //          END COPLIEN
        //
        //#########################################################

        //#########################################################
        //
        //          METHODS
        //

        /**
         * @brief Get the Data from the sensor
         * 
         * @return Data 
         */
        Data<int> getData() const;

        /**
         * @brief Print the informations of the sensor
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
         * @brief Generate a random pression value 
         * 
         * @return float : the value generated
         */
        int aleaGenVal() const;

        //
        //          END METHODS
        //
        //#########################################################


};

#endif //PRESSION_H
