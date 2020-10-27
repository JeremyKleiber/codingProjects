//Jeremy S Kleiber jsk84@zips.uakron.edu 9/8/20
//Creates an array or linked listed then allows cities to be created or removed.
//This is the linked list application
#ifndef LINKEDBASED_HPP
#define LINKEDBASED_HPP
#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <math.h>

struct node // node for the linked list
{
    std::string city;
    std::string latitude;
    std::string longitude;
    node *next;
};
class linkedBased
{
    private:
    node *head, *tail, *foundSpot;
    int sizeOfList;

    public:
        //constructor that sets up linked list head, tail and calls linked setup
        linkedBased();
        //sets up linked list by inputting the file onto it
        void listSetup();
        //takes city,x,y value and then inputs it onto the linked list
        void addNode(std::string,std::string,std::string);
        //displays linked list
        void displayList();
        //deletes node by searching by city
        void deleteNode(std::string);
        //searches for x,y coordinate in the linked list
        void searchByXY(std::string, std::string);
        //searches and deletes node by using x,y coordinates
        void deleteNodeByXY(std::string, std::string);
        //finds cities that are within the given distance, using a city and wanted range
        void distanceOfLocation(std::string, long double);
        //searches through linked list by city and outputs the findings
        void searchCity(std::string);
        //converts a decimal value of x,y to rad
        long double dec_to_rad (long double);
        //destructor
        virtual ~linkedBased();

};

#endif // LINKEDBASED_HPP
