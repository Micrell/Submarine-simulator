/**
 * @file Server.hpp
 * @author Jules
 * @brief 
 * @version 0.1
 * @date 2021-09-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */


#ifndef SERVER_H
#define SERVER_H

#include <string>
#include <iostream>
#include <ctime>
#include <fstream>

#include "Data.hpp"

class Server
{
  public:
        //*********************************************************
        //
        //          COPLIEN
        //

        /**
         * @brief Construct a new Server object with default attributes
         * 
         */
        Server();

        /**
         * @brief Construct a new Server object
         * 
         * @param otherServer
         */
        Server(const Server& otherServer_p);

        /**
         * @brief Affect a server object into another one
         * 
         * @param otherServer : another server object
         * @return Server& : a reference of the object affected
         */
        Server& operator=(const Server& otherServer_p);

        /**
         * @brief Destroy the Server object
         * 
         */
        ~Server(void);

        //
        //          END COPLIEN
        //
        //*********************************************************

        //#########################################################
        //
        //          METHODS
        //

        /**
         * @brief print in the console the informations of the data in parameter
         * 
         * @param data : a reference of a data object
         */
        template <typename T>
        void consoleWrite(Data<T> data_p) const
        {
        	std::string hour, min, sec;

        	std::time_t t = std::time(0);
        	std::tm* now = std::localtime(&t);

        	hour = std::to_string(now->tm_hour);
        	min = std::to_string(now->tm_min);
        	sec = std::to_string(now->tm_sec);

        	std::string time = "[" + hour + ":" + min + ":" + sec + "]";

          std::cout << time << data_p << std::endl;
        }

        /**
         * @brief print in a file .txt the informations of the data in parameter
         * 
         * @param data : a reference of data object
         */
        template <typename T>
        void fileWrite(Data<T> data_p) const
        {
        	std::string hour, min, sec, year, month, day, time, fileName, filePath, sensorTypeRep;

        	std::time_t t = std::time(0);
        	std::tm* now = std::localtime(&t);

        	year = std::to_string((now->tm_year)+1900);
        	month = std::to_string((now->tm_mon)+1);
        	day = std::to_string(now->tm_mday);
        	hour = std::to_string(now->tm_hour);
        	min = std::to_string(now->tm_min);
        	sec = std::to_string(now->tm_sec);

        	sensorTypeRep = data_p.getSensorType() + "/";

        	time = "[" + hour + ":" + min + ":" + sec + "]";
        	fileName = year+ "-" + month + "-" + day + "-" + hour + ".txt";
        	filePath = "Logs/"+ sensorTypeRep + fileName;

        	std::ofstream logFile (filePath, std::ios::app);


        	if (logFile.is_open())
        	{
        		logFile << time << data_p << std::endl;
        		logFile.close();
        	}
        	else
        	{
        		std::cout << "Unable to open file";
        	}

        }

        //
        //          END METHODS
        //
        //#########################################################
          
};


#endif //SERVER_H
