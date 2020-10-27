// Jeremiah S Kleiber 9/20/20  4557414 Word Ladder problem
// Program takes a start word and ending word and finds a connection by only changing 1 letter at a time
#ifndef WORDLADDER_HPP
#define WORDLADDER_HPP
#include <iostream>
#include <fstream>
#include <cstring>
#include <queue>
#include <set>
#include <stack>

class wordLadder
{
    public:
        //constructor that sets up user with display
        wordLadder();
        //loads the dictionary file onto an array using the same size as the starting word input was
        void loadWord();
        //takes a word then checks to see if its in the array, returns a word
        std::string validateWords(std::string);
        //outputs the information about the array to the user
        void arrayData();
        //changes what position in the word the letter needs to be changed
        void changePosition(std::string,int);
        //changes the one letter in a string, uses recursion
        void changeLetter(std::string, char, int);
        //displays results form the word ladder
        void wordLadderDisplay(int);
        //starts finding the word ladder
        void wordLadderFinder();
        //deconstructor
        virtual ~wordLadder();

    private:
        int lengthOfArray;
        std::string dictionaryArray[20000], displayArray[40];//set up dictionary and display
        std::string startingWord, endingWord;
        std::set<std::string> testedWords; //holds all of the words tested
        std::stack<std::string> currentLadder; //holds a sequence of words
        std::queue<std::stack<std::string>> queueOfLadders; //This worked better than a linked list, and much easier to follow
};

#endif // WORDLADDER_HPP
