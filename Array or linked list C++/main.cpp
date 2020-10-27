//Jeremy S Kleiber jsk84@zips.uakron.edu 9/8/20
//Creates an array or linked listed then allows cities to be created or removed
#include <iostream>
#include <fstream>
#include <cstring>
#include "arrayBased.hpp"
#include "linkedBased.hpp"

//Takes a Char and int and then decides if its linked list or array
void implementationOptions(char,int);
// selects what option form the menu the user wants to run, this one is array based
void menuSelection(int, arrayBased &);
// selects what option form the menu the user wants to run, this one is linked based
void menuSelection(int, linkedBased &);
// Text for the menu options 1 - 8
void menuOptions();

int main()
{
    //Takes users input
    std::cout<<"*************************************"<<std::endl;
    std::cout<< "Implementation Options:"<<std::endl;
    std::cout<< "A. Use an array-based list implementation"<<std::endl;
    std::cout<< "B. Use a linked-list implementation"<<std::endl;
    std::cout<<std::endl;
    //calling wall of text
    menuOptions();

    //taking implementation options and then storing it
    //validation is built into implementation options function
    std::cout<<"Enter your implementation option: ";
    char linkedOrArray;
    std::cin>>linkedOrArray;
    std::cout<<std::endl;

    //Takes what menu selection the user inputs and then
    //validates it right away
    std::cout<< "Enter your operation option: ";
    int menuOptions;
    std::cin>>menuOptions;
    std::cout<<std::endl;

    while(true)
    {
        if(std::cin.fail() || menuOptions > 8 || menuOptions < 1)
        {
            std::cin.clear();// get rid of bad inputs
            std::cin.ignore();
            std::cout<<"Please enter 1-8"<<std::endl;
            std::cin>>menuOptions;
        }
        if(!std::cin.fail() && menuOptions <= 8 && menuOptions >= 1)
            break;// exits while loop
    }
    //calls function to decide if its linked list or array option
    implementationOptions(linkedOrArray,menuOptions);

    return 0;
}
void menuSelection(int selection , arrayBased &obj)
{
    //each case represents a option from the menuOption function
    switch(selection)
    {

    case 1: //insert a record option
        {
            std::string city, x, y;
            std::cout<<"Enter the name of the city :";
            std::cin >> city ;
            std::cout<<std::endl;
            std::cout<<"Enter x coordinate of the city:";
            std::cin >> x ;
            std::cout<<std::endl;
            std::cout<<"Enter y coordinate of the city:";
            std::cin >> y ;
            std::cout<<std::endl;
            obj.insertRecord(city, x, y); //runs function from arrayBased class

            menuOptions();
            std::cout<<"Enter new option :";
            std::cin>> selection;
            menuSelection(selection , obj); // recursive call

            break;
        }

    case 2:// search for city in array
        {
            std::string city;
            std::cout<<"Enter name of city to be searched: ";
            std::cin>> city;
            obj.searchByName(city);// calls function inside of array based class

            menuOptions();
            std::cout<<"Enter new option :";
            std::cin>> selection;
            menuSelection(selection , obj);

            break;
        }
    case 3:// searches x , y coordinates in array
        {
            std::string x , y;
            std::cout<<"Please enter a latitude :";
            std::cin>> x;
            std::cout<<std::endl;
            std::cout<<"Please enter a longitude :";
            std::cin >>y;
            obj.searchByXY(x,y);//calls function inside of array based to search for long and lat

            menuOptions();
            std::cout<<"Enter new option :";
            std::cin>> selection;
            menuSelection(selection , obj);

            break;
        }

    case 4:// deletes city by name
        {
            std::string city;
            std::cout<<"Enter city name to be deleted :";
            std::cin>> city;
            std::cout<<std::endl;
            obj.deleteByCity(city);// calls function from array based to delete a city form array

            menuOptions();
            std::cout<<"Enter new option :";
            std::cin>> selection;
            menuSelection(selection , obj);

            break;
        }

    case 5: // deletes city by x , y coordinate
        {
            std::string latitude , longitude;
            std::cout<<"Enter latitude to be deleted : ";
            std::cin >>latitude;
            std::cout<<std::endl;
            std::cout<<"Enter longitude to be deleted : ";
            std::cin >>longitude;
            std::cout<<std::endl;
            obj.deleteByCord(latitude,longitude);// calls from array based to delete by x,y coord

            menuOptions();
            std::cout<<"Enter new option :";
            std::cin>> selection;
            menuSelection(selection , obj);

            break;
        }
    case 6:// searches nearby cities by distance
        {
            std::string city;
            long double distance;
            std::cout<<"Enter name of specified location :";
            std::cin >> city;
            std::cout<<std::endl;
            std::cout<<"Enter distance: ";
            std::cin >> distance;
            std::cout<<std::endl;
            obj.distanceOfLocation(city,distance);//calls from array based to find cites by distance

            menuOptions();
            std::cout<<"Enter new option :";
            std::cin>> selection;
            menuSelection(selection , obj);

            break;
        }
    case 7:// list of array
        {
            obj.listOfArray();//calls array class to list array

            menuOptions();
            std::cout<<"Enter new option :";
            std::cin>> selection;
            menuSelection(selection , obj);

            break;
        }
    case 8:// exits recursive loop
        {
            std::cout<<"Program exiting"<<std::endl;

            break;
        }
    }

}
void menuSelection(int selection , linkedBased &obj)
{
//each case represents a option from the menuOption function
    switch(selection)
    {
    case 1://insert a record option
        {
            std::string city, x, y;
            std::cout<<"Enter the name of the city :";
            std::cin >> city ;
            std::cout<<std::endl;

            std::cout<<"Enter x coordinate of the city:";
            std::cin >> x ;
            std::cout<<std::endl;

            std::cout<<"Enter y coordinate of the city:";
            std::cin >> y ;
            std::cout<<std::endl;

            obj.addNode(city, x, y);//runs function from linked class to add a city

            menuOptions();
            std::cout<<"Enter new option :";
            std::cin>> selection;
            menuSelection(selection , obj); // recursive call

            break;
        }

    case 2: // searches for city
        {
            std::string city;
            std::cout<<"Enter name of city to be searched: ";
            std::cin>> city;

            obj.searchCity(city);// call to linked class to search for city
            menuOptions();
            std::cout<<"Enter new option :";
            std::cin>> selection;
            menuSelection(selection , obj);
            break;
        }
    case 3: //searches by latitude and longitude
        {
            std::string x , y;
            std::cout<<"Please enter a latitude :";
            std::cin>> x;
            std::cout<<std::endl;
            std::cout<<"Please enter a longitude :";
            std::cin >>y;

            obj.searchByXY(x,y); // call linked class to be searched

            menuOptions();
            std::cout<<"Enter new option :";
            std::cin>> selection;
            menuSelection(selection , obj);// recursive call

        break;
        }

    case 4:// delete entry by city name
        {
            std::string city;
            std::cout<<"Enter city name to be deleted :";
            std::cin>> city;
            std::cout<<std::endl;
            obj.deleteNode(city);// calls linked list to delete a entry by city

            menuOptions();
            std::cout<<"Enter new option :";
            std::cin>> selection;
            menuSelection(selection , obj);

            break;
        }

    case 5:// delete by latitude and longitude
        {
            std::string latitude , longitude;
            std::cout<<"Enter latitude to be deleted : ";
            std::cin >>latitude;
            std::cout<<std::endl;
            std::cout<<"Enter longitude to be deleted : ";
            std::cin >>longitude;
            std::cout<<std::endl;
            obj.deleteNodeByXY(latitude,longitude);// calls linked list to delete by x , y

            menuOptions();
            std::cout<<"Enter new option :";
            std::cin>> selection;
            menuSelection(selection , obj);

            break;
        }
    case 6:// searches nearby cities by using a distance (miles)
        {
            std::string city;
            long double distance;
            std::cout<<"Enter name of specified location :";
            std::cin >> city;
            std::cout<<std::endl;
            std::cout<<"Enter distance: ";
            std::cin >> distance;
            std::cout<<std::endl;
            obj.distanceOfLocation(city,distance);// calls linked list function to find distance

            menuOptions();
            std::cout<<"Enter new option :";
            std::cin>> selection;
            menuSelection(selection , obj);

            break;
        }
    case 7:// displays linked list
        {
            obj.displayList();// calls linked list display

            menuOptions();
            std::cout<<"Enter new option :";
            std::cin>> selection;
            menuSelection(selection , obj);

            break;
        }
    case 8:// end to recursive loop
        {
            std::cout<<"Program exiting"<<std::endl;
            break;
        }

    }



}
void implementationOptions(char option, int selection)
{
    switch(option)
    {
        case 'A':// array based and creates a array based object
            {
                arrayBased obj;
                menuSelection(selection, obj);

                break;
            }

        case 'B': // linked list based and creates an object
            {
                linkedBased obj;
                menuSelection(selection, obj);

                break;
            }
        default:// a validation for the string
            {
                std::cout<<"Invalid Input, please enter A or B (capital letter only):";
                char newSelection;
                std::cin>> newSelection;
                implementationOptions(newSelection,selection);
            }
    }
}

void menuOptions()
{
    //text that listed out all of the options for inputs
    std::cout<<std::endl;
    std::cout<< "Operation Options:"<<std::endl;
    std::cout<< "1. Insert a record"<<std::endl;
    std::cout<< "2. Search for a record by name"<<std::endl;
    std::cout<< "3. Search for a record by coordinate"<<std::endl;
    std::cout<< "4. Delete a record by name"<<std::endl;
    std::cout<< "5. Delete a record by coordinate" <<std::endl;
    std::cout<< "6. Print records within a given distance of a specified location" <<std::endl;
    std::cout<< "7. Print all records" <<std::endl;
    std::cout<< "8. Exit"<<std::endl;
    std::cout<<std::endl;
}
