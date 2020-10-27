//Jeremy S Kleiber jsk84@zips.uakron.edu 9/8/20
//Creates an array or linked listed then allows cities to be created or removed.
//This is the linked list application
#include "linkedBased.hpp"
//constructor that sets up linked list head, tail and calls linked setup
linkedBased::linkedBased()
{
    head = NULL;
    tail = NULL;
    listSetup();
}
//sets up linked list by inputting the file onto it
void linkedBased::listSetup()
{
    std::string myText, infoLine, city , latitude, longitude;
    std::ifstream MyReadFile("Assignment_1_ Test Data.txt");

    getline(MyReadFile,infoLine);//gets ride of the input file
    int tempCounter =0;

    while (getline (MyReadFile, myText))//reads from file
        {
            tempCounter++;
            getline(MyReadFile, city, ':');
            getline(MyReadFile, latitude, ',');
            getline(MyReadFile, longitude);

            if(tempCounter < 20)//uses add node to input the information from the file, the if is used as a check, can be removed
                addNode(city,latitude,longitude);
        }
    MyReadFile.close();
}
//takes city,x,y value and then inputs it onto the linked list
void linkedBased::addNode(std::string city, std::string latitude, std::string longitude)
{
    //sets up the add by making a new node and loading info onto it
    node *temp = new node;
    temp->city = city;
    temp->latitude = latitude;
    temp->longitude = longitude;
    temp->next = NULL;

    //if the head is the first value
    if(head == NULL)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        //adds node to the bottom of the list
        tail->next = temp;
        tail = tail->next;
    }
}
//displays linked list
void linkedBased::displayList()
{
    // creates a new node that starts at the beginning of the list
    node* temp = head;
    while (temp != NULL)
    {
        std::cout<< temp->city <<", ("<< temp->latitude<<","<<temp->longitude <<")"<< std::endl;
        temp = temp->next;
    }
}
//deletes node by searching by city
void linkedBased::deleteNode(std::string city)
{
    bool loopFlag = true, errorFlag = false;
    int counter = 0;
    node* temp = head;
    node* prevLink;

    while(loopFlag)//searches for the city inside the array
    {
        if(counter >=sizeOfList )//if the city is not found
        {
            std::cout<<"City not found, make sure to use capital letters ";
            errorFlag = true;

            break;
        }
        if(temp->city.compare(city) == 0)
        {
            loopFlag = false;
        }
        else
        {
            prevLink = temp;
            temp = temp->next;

        }
        counter++;
    }
    if(errorFlag == false)//checks to see if there was an error
    {
        //deletes the node
        node* temp2;
        temp2 = prevLink->next;
        prevLink->next = temp2->next;
        delete temp2;
        std::cout<<"Entry deleted"<<std::endl;
        sizeOfList = sizeOfList -1;// adjusts the new size
    }
}
//searches for x,y coordinate in the linked list
void linkedBased::searchByXY(std::string x,std::string y)
{
    float xValue = std::stof(x), yValue = std::stof(y);
    int counter = 0;
    bool loopFlag = true;
    node* temp = head;
    while(loopFlag)
    {
        if(counter >=sizeOfList )//if the city is not found,will throw argument if stof fails
        {
            std::cout<<"No such record exists in the existing data set.";

            break;
        }
        if(xValue == std::stof(temp->latitude))//checking each value
        {
            if(yValue == std::stof(temp->longitude))
            {
                std::cout<<temp->city<<",("<< temp->latitude<<","<< temp->longitude<< ")"<<std::endl;
                loopFlag = false;
            }
        }
        else
        {
            temp = temp->next;

        }
        counter++;
    }
}
//searches and deletes node by using x,y coordinates
void linkedBased::deleteNodeByXY(std::string x, std::string y)
{
    float xValue = std::stof(x), yValue = std::stof(y);
    bool loopFlag = true,errorFlag = false;
    int counter = 0;
    node* temp = head;
    node* prevLink;

    while(loopFlag)// searches for matching x,y
    {
        if(counter >=sizeOfList )//if the city is not found,will throw argument if stof fails
        {
            std::cout<<"Coordinates not found ";
            errorFlag = true;

            break;
        }
        if(xValue == std::stof(temp->latitude))
        {
            if(yValue == std::stof(temp->longitude))
            {
                loopFlag = false;
            }
        }
        else
        {
            prevLink = temp;
            temp = temp->next;

        }
        counter++;
    }
    if(errorFlag == false)//checks to see if there was an error
    {
        //deletes the node
        node* temp2;
        temp2 = prevLink->next;
        prevLink->next = temp2->next;
        delete temp2;
        std::cout<<"Entry deleted"<<std::endl;
        sizeOfList = sizeOfList -1;// adjusts the new size
    }

}
//finds cities that are within the given distance, using a city and wanted range
void linkedBased::distanceOfLocation(std::string orginCity, long double orginDistance)
{
    bool loopFlag = true, errorFlag = false;
    int counter =0;
    node* temp = head;
    long double latitudeOrgin, longitudeOrgin;

    while(temp != NULL)
    {
        if(counter >=sizeOfList )//if the city is not found
        {
            std::cout<<"Cordinates not found";
            errorFlag = true;
            break;
        }
        if (temp->city.compare(orginCity) == 0)
        {
            latitudeOrgin =  std::stold(temp->latitude);
            longitudeOrgin =  std::stold(temp->longitude);
        }
        temp = temp->next;
        counter++;
    }
    // not here
    if(errorFlag == false)//code is skipped if city inputed is not found
    {
        node* temp2 = head;

        //searching other cities
        latitudeOrgin = dec_to_rad(latitudeOrgin);
        longitudeOrgin = dec_to_rad(longitudeOrgin);

        long double latitude, longitude;
        long double distance , R = 3963.191;

        while(temp2 != NULL)//checks linked list for cities
        {
            latitude =  std::stold(temp2->latitude);
            longitude =  std::stold(temp2->longitude);
            latitude = dec_to_rad(latitude);
            longitude = dec_to_rad(longitude);
            long double dlong = longitude - longitudeOrgin;

            distance = acos(sin(latitudeOrgin)*sin(latitude)+cos(latitudeOrgin)*cos(latitude)*cos(dlong))* R;

            if(distance <= orginDistance && orginCity.compare(temp2->city) != 0) // checks distance and makes sure doesn't output given city
            {
                std::cout<<temp2->city<<", ("<<temp2->latitude<<","<<temp2->longitude<<")"<< std::endl;
            }
            temp2 = temp2->next;
        }
    }
}
//searches through linked list by city and outputs the findings
void linkedBased::searchCity(std::string city)
{
    bool loopFlag = true;
    int counter = 0;
    node* temp = head;
    long double latitudeOrgin, longitudeOrgin;

    while(loopFlag) //searches through the linked list for cities
    {
        if(counter >=sizeOfList )//if the city is not found
        {
            std::cout<<"No such record exists in the existing data set.";

            break;
        }
        if (temp->city.compare(city) == 0)//if the city was found
        {
            std::cout<<temp->city<<",("<< temp->latitude<<","<< temp->longitude<< ")"<<std::endl;
            loopFlag = false;
        }
        else
        {
            temp = temp->next;
        }
        counter++;
    }
}
//converts a decimal value of x,y to rad
long double linkedBased::dec_to_rad(long double degree)
{
    long double M_PI = 3.1415926535;
    return (degree * (M_PI / 180.0));
}
//desctuctor
linkedBased::~linkedBased()
{
    //dtor
}
