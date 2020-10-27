//Jeremy S Kleiber jsk84@zips.uakron.edu 9/8/20
//Creates an array or linked listed then allows cities to be created or removed.
//This is the array based application
#include "arrayBased.hpp"

//constructor and loads inputs from file onto array
arrayBased::arrayBased()
{
    std::string myText, infoLine, city , latitude, longitude;

    std::ifstream MyReadFile("Assignment_1_ Test Data.txt"); //loads inputs from a file

    getline(MyReadFile,infoLine);// gets the first line which is general information
    int temp = 0;

    while (getline (MyReadFile, myText))// loop that reads through all of the lines then inputs it onto an array
        {

            getline(MyReadFile, city, ':');
            cityInfo[temp] = city;
            temp++;

            getline(MyReadFile, latitude, ',');
            cityInfo[temp] = latitude;
            temp++;

            getline(MyReadFile, longitude);
            cityInfo[temp] = longitude;
            temp++;
        }

    sizeOfArray = 60; // default size of given text file, can use temp as a counter as well

    MyReadFile.close();

}
//outputs the list to the user
void arrayBased::listOfArray()
{
	for (int i = 0; i < sizeOfArray; i+=3)
    {
		std::cout<<cityInfo[i]<<", ("<<cityInfo[i+1]<<","<<cityInfo[i+2]<<")"<< std::endl;
	}
}
//takes 3 strings, city, x, and y then inserts it into the array
void arrayBased::insertRecord(std::string city, std::string latitude, std::string longitude)
{
    bool found = true, errorFlag = false;
    int tempValue = 0;

    while(found)//looks till the value is found
    {
        if(city.compare(cityInfo[tempValue]) == 0) // 0 means its equal
        {
            found = false;
            errorFlag = true;
            std::cout<<"No need to insert again, as this record exists in the existing data set."<<std::endl;

        }
        if(tempValue > sizeOfArray)// if value is never found
        {
            found = false;
        }
        tempValue++;
    }
    if(errorFlag == false)
    {
        cityInfo[sizeOfArray ] = city; // size of array is at the last value
        cityInfo[sizeOfArray + 1] = latitude;
        cityInfo[sizeOfArray + 2] = longitude;
        sizeOfArray +=3;
    }
}
//takes city name and then searches the array for it. It outputs the city name and coordinates
void arrayBased::searchByName(std::string city)
{
    bool found = true;
    int tempValue = 0;

    while(found)//looks till the value is found
    {
        if(city.compare(cityInfo[tempValue]) == 0) // 0 means its equal
        {
            found = false;
            std::cout<<city<<",("<<cityInfo[tempValue+1]<<","<<cityInfo[tempValue+2]<<")";

        }
        if(tempValue > sizeOfArray)// if value is never found
        {
            std::cout<<"No such record exists in the existing data set."<<std::endl;
            found = false;
        }
        tempValue++;
    }
}
//takes x,y value then looks through the array for those values and outputs them and city name
void arrayBased::searchByXY(std::string x, std::string y)
{
    bool found = true;
    int tempValue = 1;
    float xValue = std::stof(x), yValue = std::stof(y); // converts string to float, will throw argument if stof fails

    while(found)
    {
        if(xValue == std::stof(cityInfo[tempValue]))
        {
            if(yValue == std::stof(cityInfo[tempValue+1]))
            {
                found = false;
                std::cout <<"City is "<< cityInfo[tempValue - 1]<<" (" <<x<<","<<y<< ")";
            }
        }
        else
        {
           tempValue +=3;
        }
        if(tempValue > sizeOfArray)//not found case
        {
            std::cout<<"No such record exists in the existing data set.";
            found = false;
        }
    }
}
//takes city name and distance, then outputs all of the cities within that distance
void arrayBased::distanceOfLocation(std::string originCity, long double originDistance)
{
    //finds orginCity x,y values
    bool found = true;
    int tempCounter = 0;
    long double latitudeOrigin, longitudeOrigin;

    while(found)
    {
        if(originCity.compare(cityInfo[tempCounter]) == 0)
        {

            latitudeOrigin =  std::stold(cityInfo[tempCounter+1]);
            longitudeOrigin =  std::stold(cityInfo[tempCounter+2]);
            found = false;
        }
        tempCounter++;
    }
    // converts the dec version to radians
    latitudeOrigin = dec_to_rad(latitudeOrigin);
    longitudeOrigin = dec_to_rad(longitudeOrigin);

    long double latitude, longitude;//x and y values of all the other cities in the array
    long double distance , R = 3963.191;
    //starts search through array
    for (int tempValue = 0; tempValue < sizeOfArray+1; tempValue+= 3)
    {
        //converts all values
        latitude =  std::stold(cityInfo[tempValue+1]);
        longitude =  std::stold(cityInfo[tempValue+2]);
        latitude = dec_to_rad(latitude);
        longitude = dec_to_rad(longitude);

        long double dlong = longitude - longitudeOrigin;//used to simplify long equation

        distance = acos(sin(latitudeOrigin)*sin(latitude)+cos(latitudeOrigin)*cos(latitude)*cos(dlong))* R;// distance formula
        //checks each value to see if its within the distance and filters out the original city
        if(distance <= originDistance && originCity.compare(cityInfo[tempValue]) != 0)
        {
            std::cout<<cityInfo[tempValue]<<", ("<<cityInfo[tempValue+1]<<","<<cityInfo[tempValue+2]<<")"<< std::endl;

        }
	}
}
//converts a decimal value of x,y to rad
long double arrayBased::dec_to_rad(long double degree)
{
    long double M_PI = 3.1415926535;
    return (degree * (M_PI / 180.0));
}
//searches for city then deletes it
void arrayBased::deleteByCity(std::string city)
{
    bool found = true;
    int tempValue = 0;

    while(found)//searches for city then shifts the array to its spot
    {
        if(city.compare(cityInfo[tempValue]) == 0)
        {
            std::cout<<"Entry deleted"<<std::endl;
            found = false;
            for(tempValue; tempValue < sizeOfArray; tempValue +=3)
            {
                //replace city with next city
                cityInfo[tempValue] = cityInfo[tempValue + 3];
                //replace latitude with next latitude
                cityInfo[tempValue+1] = cityInfo[tempValue + 4];
                //replace longitude with next longitude
                cityInfo[tempValue+2] = cityInfo[tempValue + 5];
            }
        }
        if(tempValue > sizeOfArray+1)
        {
            std::cout<<"Error city not found"<<std::endl;
            found = false;
        }
    tempValue++;
    }
    sizeOfArray = sizeOfArray -3;
}
//searches for a coordinate then deletes it
void arrayBased::deleteByCord(std::string x,std::string y)
{
    bool found = true;
    int tempValue = 1;
    float xValue = std::stof(x), yValue = std::stof(y);//converts string to float,will throw argument if stof fails

    while(found)// searches for x and y values that match, then replaces them by shifting array
    {
        if(xValue == std::stof(cityInfo[tempValue]))
        {
            if(yValue == std::stof(cityInfo[tempValue+1]))
            {
                std::cout<<"Entry deleted"<<std::endl;
                found = false;
                for(tempValue; tempValue < sizeOfArray; tempValue +=3)
                {
                    //replace city with next city
                    cityInfo[tempValue-1] = cityInfo[tempValue + 2];
                    //replace latitude with next latitude
                    cityInfo[tempValue] = cityInfo[tempValue + 3];
                    //replace longitude with next longitude
                    cityInfo[tempValue+3] = cityInfo[tempValue + 4];
                }
            }
        }
        else
        {
           tempValue +=3;
        }
        if(tempValue > sizeOfArray+1)
        {
            std::cout<<" Error not found ";
            found = false;
        }
    }
    sizeOfArray = sizeOfArray-3;
}
//destructor
arrayBased::~arrayBased()
{
    //dtor
}
