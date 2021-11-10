/**
 * @file Scheduler.hpp
 * @author Jules
 * @brief 
 * @version 0.1
 * @date 2021-10-07
 * 
 * @copyright Copyright (c) 2021
 * 
 */


#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <iostream>
#include <list>


#include "Sensor.hpp"
#include "Temperature.hpp"
#include "Pression.hpp"
#include "Light.hpp"
#include "Humidity.hpp"
#include "Data.hpp"
#include "Server.hpp"



class Scheduler
{
  public:
        //*********************************************************
        //
        //          COPLIEN
        //

        /**
         * @brief Construct a new Scheduler object with default attributes
         * 
         */
        Scheduler();

        /**
         * @brief Construct a new Scheduler object by copy
         * 
         * @param otherScheduler
         */
        Scheduler(const Scheduler& otherScheduler_p);
        
        /**
         * @brief Affect a scheduler into another one
         * 
         * @param otherScheduler : the other scheduler
         * @return Scheduler& : a reference on the object affected
         */
        Scheduler& operator=(const Scheduler& otherScheduler_p);

        /**
         * @brief Destroy the Scheduler object
         * 
         */
        ~Scheduler();

        //
        //          END COPLIEN
        //
        //*********************************************************


        //#########################################################
        //
        //          METHODS
        //

        /**
         * @brief Creates a sensor a adds it to the list of sensor in attributes
         * 
         * @param name : the name wanted for the sensor
         * @param sensorType : the type of the sensor wanted
         */
        template<typename T, typename S>
        void addSensor(std::string name_p, std::list<Sensor<S>*>& sensorList_p);

        /**
         * @brief
         *
         */
        void addTempSensor(std::string name_p);

        void addHumiSensor(std::string name_p);

        void addPressSensor(std::string name_p);

        void addLightSensor(std::string name_p);


        /**
         * @brief print the informations of all the sensor in the console
         * 
         */
        void printSensorInfoFromAllSensors();

        /**
         * @brief get data from all sensor and print them in the console
         * 
         */
        void printDataFromAllSensors();

        /**
         * @brief start capturing data
         *
         * @param logActivate
         */
        void startScheduling(bool logActivate_p, bool printActivate_p);


        //
        //          END METHODS
        //
        //#########################################################

        


  private:

          //$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
          //
          //          ATTRIBUTES
          //

          /**
           * @brief List of pointer on Sensor<float>, contains a pointer on each temperature sensor existing
           * 
           */
          std::list<Sensor<float>*> m_tempSensorList;

          /**
					 * @brief List of pointer on Sensor<float>, contains a pointer on each humidity sensor existing
					 *
					 */
          std::list<Sensor<float>*> m_humiSensorList;
          /**
					 * @brief List of pointer on Sensor<int>, contains a pointer on each pression sensor existing
					 *
					 */
          std::list<Sensor<int>*> m_pressionSensorList;
          /**
					 * @brief List of pointer on Sensor<bool>, contains a pointer on each light sensor existing
					 *
					 */
          std::list<Sensor<bool>*> m_lightSensorList;

          /**
           * @brief Instance of the class Server
           * 
           */
          Server m_server;

          /**
           * @brief equal to 0 if log option is not activate, else equal to 1
           *
           */
          bool m_logActivate;

          /**
					 * @brief equal to 0 if print option is not activate, else equal to 1
					 *
					 */
          bool m_printActivate;

          //
          //          END ATTRIBUTES
          //
          //$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

          //#########################################################
					//
					//          METHODS
					//

          
         /**
          * @brief Print all data from the sensor list in parameter
          *
          * @param sensorList : list of sensors
          */
					template <typename T>
					void printDataFromSensor(T& sensorList_p)
					{

					 for(auto sensor : sensorList_p)
					 {
						 if(this->m_printActivate)
						 {
							 this->m_server.consoleWrite(sensor->getData());
						 }

						 if(this->m_logActivate) //if option log activate
						 {
							 this->m_server.fileWrite(sensor->getData());
						 }
					 }
					}

          //
          //          END METHODS
          //
          //#########################################################

};


#endif //SCHEDULER_H
