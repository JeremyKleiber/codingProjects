//Jeremy S Kleiber jsk84@zips.uakron.edu 9/8/20
//Creates an array or linked listed then allows cities to be created or removed.
//This is the array based application
#ifndef ARRAYBASED_HPP
#define ARRAYBASED_HPP
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <math.h>

class arrayBased
{
    public:
        //constructor and loads inputs from file onto array
        arrayBased();
        //outputs the list to the user
        void listOfArray();
        // takes 3 strings, city, x, and y then inserts it into the array
        void insertRecord(std::string,std::string,std::string);
        //takes city name and then searches the array for it. It outputs the city name and coordinates
        void searchByName(std::string);
        //takes x,y value then looks through the array for those values and outputs them and city name
        void searchByXY(std::string, std::string);
        //takes city name and distance, then outputs all of the cities within that distance
        void distanceOfLocation(std::string, long double);
        //converts a decimal value of x,y to rad
        long double dec_to_rad (long double);
        //searches for city then deletes it
        void deleteByCity(std::string);
        //searches for a coordinate then deletes it
        void deleteByCord(std::string, std::string);
        //destructor
        virtual ~arrayBased();

    protected:
        std::string cityInfo[9999];
        int sizeOfArray;
};

#endif // ARRAYBASED_HPP
