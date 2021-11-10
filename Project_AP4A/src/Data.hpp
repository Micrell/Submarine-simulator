/**
 * @file Data.hpp
 * @author Jules
 * @brief Object created by a sensor and send to the server to be saved in a log file or print in the console. It contains few informations about the sensor which created the data.
 * @version 0.1
 * @date 2021-10-07
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef DATA_H
#define DATA_H


#include <iostream>
#include <string>
#include <iomanip>

template <typename T>
class Data
{

public:
        //*********************************************************
        //
        //          COPLIEN
        //

        /**
         * @brief Construct a new Data object with default param
         * 
         */
        Data(): m_data(), m_sensorType("none"), m_dataUnit("none"), m_sensorName("none")
        {

        }

        /**
         * @brief Construct a new Data object
         * 
         * @param sensorType : type of the sensor (temperature, humidity, light or pression) which create the data
         * @param sensorName : name of the sensor which create the data
         * @param data : value of the data 
         * @param dataType : unit of the value
         */
        Data(std::string sensorType_p, std::string sensorName_p, T data_p, std::string dataType_p) : m_data(data_p), m_sensorType(sensorType_p), m_dataUnit(dataType_p), m_sensorName(sensorName_p)
        {

        }

        /**
         * @brief Construct a new Data object by copy
         * 
         * @param otherData : reference of another data object that will be copied
         */
        Data(const Data<T>& otherData_p): m_data(otherData_p.m_data), m_sensorType(otherData_p.m_sensorType),  m_dataUnit(otherData_p.m_dataUnit), m_sensorName(otherData_p.m_sensorName)
        {

        }

        /**
         * @brief Affect a Data object to another
         * 
         * @param otherData : A reference of another object Data
         * @return A reference of the object Data affected; 
         */
        Data<T>& operator=(const Data<T>& otherData_p)
        {
          this->m_sensorType = otherData_p.m_sensorType;
          this->m_sensorName = otherData_p.m_sensorName;
          this->m_dataUnit = otherData_p.m_dataUnit;
          this->m_data = otherData_p.m_data;

          return *this;
        }
        /**
         * @brief Destroy the Data object
         * 
         */
        ~Data()
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
         * @brief Get the Sensor Type of the sensor which created the data
         * 
         * @return std::string 
         */
        std::string getSensorType()
        {
          return this->m_sensorType;
        }

        /**
         * @brief Get the Data Type of the sensor which created the data
         * 
         * @return std::string 
         */
        std::string getDataUnit()
        {
          return this->m_dataUnit;
        }

        /**
         * @brief Get the Sensor Name of the sensor which created the data
         * 
         * @return std::string 
         */
        std::string getSensorName()
        {
          return this->m_sensorName;
        }
        
        /**
         * @brief Get the value of the Data that the sensor created 
         * 
         * @return float 
         */
        T getData()
        {
          return this->m_data;
        }

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
         * @brief value of the data
         * 
         */
        T m_data;

        /**
         * @brief Type of the sensor which emitted the data
         * 
         */
        std::string m_sensorType;

        /**
         * @brief Unit of the data
         * 
         */
        std::string m_dataUnit;

        /**
         * @brief Name of the sensor which emitted the data
         * 
         */
        std::string m_sensorName;




        //
        //          END ATTRIBUTES
        //
        //$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

};


/**
 * @brief Overload of the << operator for the class Data
 * 
 * @param os 
 * @param data 
 * @return std::ostream& 
 */

template <typename T>
std::ostream& operator<<(std::ostream& os_p, Data<T>& data_p)
{
	os_p << std::fixed;
  os_p << "(" << data_p.getSensorType() << ") " << data_p.getSensorName() << " : " << data_p.getData() << " " << data_p.getDataUnit();

  return os_p;
}

#endif //DATA_H
