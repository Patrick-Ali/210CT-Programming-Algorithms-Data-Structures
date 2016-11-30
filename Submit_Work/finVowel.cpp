#include <iostream>
#include <string>

bool vowelCheck(char letter, std::string vowel, int count, int size)
{
    /*
        Takes in a letter which it checks against a list of vowels
        if the letter is in the list it returns true otherwise it
        returns false indicating it is not a vowel. This check is done
        recursively. 
    */
    if(count >= size)
    {
        return false;
    }
    if(letter == vowel[count])
    {
        return true;
    }
    else 
    {
        return vowelCheck(letter, vowel, count+1, size);
    }
}

int main()
{
    std::string word;
    std::cout << "Please enter a word: ";
    std::getline(std::cin, word);
    std::string newWord = " ";
    int count = 0;
    std::string vowels = "aAeEiIoOuU";
    int size = vowels.length();
    
    for(int i = 0; i < word.length(); i++)
    {
        /*
            Goes through the word letter by letter adding non-vowels to the new word
            and skipping the vowels.
        */
        count = 0;
        bool isVowel = vowelCheck(word[i], vowels, count, size);
        if(isVowel != true)
        {
            newWord += word[i];
        }
    }
    
    std::cout << "The word without vowels is: " << newWord << std::endl;
    
    return 0;
}