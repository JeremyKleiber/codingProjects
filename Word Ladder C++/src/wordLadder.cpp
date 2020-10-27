// Jeremiah S Kleiber 9/20/20  4557414 Word Ladder problem
// Program takes a start word and ending word and finds a connection by only changing 1 letter at a time
#include "wordLadder.hpp"

//constructor that sets up user with display
wordLadder::wordLadder()
{
    lengthOfArray = 0; //needs default otherwise starts at random count

    std::cout << "Enter starting word" << std::endl;
    std::cin>> startingWord;

    loadWord(); //loads data from a text file, it uses the entered size of the first word to put in array

    startingWord = validateWords(startingWord);//validates and resets

    std::cout << "Enter ending word" << std::endl;
    std::cin>> endingWord;

    endingWord = validateWords(endingWord);//validates and resets

    std::stack<std::string> startingStack;// puts the starting word onto a stack to be stores in queue of stacks

    startingStack.push(startingWord);
    queueOfLadders.push(startingStack);
}
//loads the dictionary file onto an array using the same size as the starting word input was
void wordLadder::loadWord()
{
    std::string myText,word;
    int matchingLength = startingWord.length();//to load proper sizes onto the array
    std::ifstream myfile("Dictionary.txt"); //loads inputs from a file

    if (myfile.is_open())
    {
        while (! myfile.eof() )
        {
            getline (myfile,word);

            if(word.size() == matchingLength) // adds only words of the same size onto the dictionary array, helps speed things up a little
            {
                dictionaryArray[lengthOfArray] = word;
                lengthOfArray++;
            }
        }
        myfile.close();
    }
}
//takes a word then checks to see if its in the array, returns a word
std::string wordLadder::validateWords(std::string word)
{
    // using recursion to validate a word
    int matchingLength = word.length();//to load proper sizes onto the array
    bool realWord = false;

	for (int i = 0; i < lengthOfArray; i++)
    {
        if(word.compare(dictionaryArray[i]) == 0) //if they are the same, base case
        {
            realWord = true;
            return word;
        }
	}
	if(realWord == false) // uses a flag to check if the word was found or not
    {
        std::cout<<"Word not found in dictionary, please check spelling and enter again. The size of the word has to be " <<startingWord.length() << " characters "<<std::endl;
        std::cin >> word;
        std::cout<<std::endl;

        return validateWords(word); // calls the same function again
    }
}
//outputs the information about the array to the user
void wordLadder::arrayData()
{
	std::cout<<"Starting word is "<<startingWord<<" ending word is "<< endingWord<<std::endl;
	std::cout<<"Size of each word should be "<<startingWord.length()<<std::endl;
	std::cout<<"With the total number of "<<lengthOfArray<< " possible words that can be used in the ladder"<<std::endl;
}
//changes the position of what letter needs to be changed in the word
void wordLadder::changePosition(std::string word, int position)
{
    if(position < word.size())//recurson runs as long as the position is not bigger than the word itself
    {
        changeLetter(word,'a',position);
        changePosition(word,++position);// recursive call
    }
    else// base case
    {
        return;
    }
}
//changes a letter of the given word by using recursive calls
void wordLadder::changeLetter(std::string word, char letter, int position)
{

    bool flag = false;
    std::string test = word.substr(0, position);// creates test word from given letter
    test = test + letter;
    test = test + word.substr(position + 1);

    for(int i = 0; i < lengthOfArray; ++i)//checks to see if its a word in the array
    {
        if(test.compare(dictionaryArray[i]) == 0)
        {
            flag = true;
        }
    }
    if(flag == true)// if the test is a word
    {
        if (testedWords.count(test) == 0 )// if its a word that we used before in the set
        {
            std::stack<std::string> tempLadder = currentLadder;
            tempLadder.push(test);
            queueOfLadders.push(tempLadder); //adds a stack onto the queue of stacks, basically a potential ladder
        }
    }
    testedWords.insert(test);// inserts the test onto the set
	if( letter != 'z') // recursive call
    {
        changeLetter(test,++letter,position);
    }
    else //ending case
    {
        return;
    }
}
//displays results form the word ladder
void wordLadder::wordLadderDisplay(int temp)
{
    if(currentLadder.empty() == false)//adds the top value of the stack onto an array to be displayed
    {
        displayArray[temp] = currentLadder.top();
        currentLadder.pop();// take off top value
        temp++;
        wordLadderDisplay(temp); // recursive call
    }
    else //displays the array and base case
    {
        std::cout <<"The ladder is "<<std::endl;
        for (int i = 0; i < temp; i++)
        {
            std::cout<<displayArray[i]<<std::endl;
        }
        return;
    }
}
//starts finding the word ladder
void wordLadder::wordLadderFinder()
{
    if(queueOfLadders.empty() == false) // if there is something in the ladder
    {
        currentLadder = queueOfLadders.front();
        queueOfLadders.pop();
        std::string word = currentLadder.top();// to see if the last ladder worked

        if (word == endingWord) // base case
        {
            wordLadderDisplay(0); // calls the display because in a stack the ending word was found
            return;
        }
        else
        {
            changePosition(word,0);// starts to change the word
        }
        wordLadderFinder();// recursive call
    }
    else // if there is no longer anything in the queue because the starting value was popped off
    {
        std::cout<<"Word ladder not found, program exiting"<<std::endl; // meaning there is not a solution to the ladder
        return;
    }
}
//deconstructor
wordLadder::~wordLadder()
{
    //dtor
}
