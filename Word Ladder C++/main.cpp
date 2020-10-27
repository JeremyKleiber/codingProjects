// Jeremiah S Kleiber 9/20/20  4557414 Word Ladder problem
// Program takes a start word and ending word and finds a connection by only changing 1 letter at a time
#include <iostream>
#include <fstream>
#include <cstring>
#include "wordLadder.hpp"

int main()
{
    wordLadder obj; //creates object to call different functions inside of the class
    obj.arrayData();
    obj.wordLadderFinder();
    return 0;
}

