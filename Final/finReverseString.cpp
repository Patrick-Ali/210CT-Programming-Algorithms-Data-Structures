#include <iostream>
#include <string>


std::string reverse(std::string hold, std::string temp, int size)
{
  /*
    This takes in a reveresed word like 'dlrow' and turns it back around,
    It does this by taking each letter starting at the end and working recursivly 
    backwards until the variable size is less than zero, as this is the first 
    index.
  */
  if(size < 0)
  {
    return temp;
  }
  else
  {
    temp += hold[size];
    return reverse(hold, temp, (size-1));
  }
}

int main() {
  
  std::string temp;
  std::string sentence;
  std::string holder;
  std::string backwards = " ";
  std::string space = " ";//Used for determining a break in the sentence
  std::cout << "Enter Sentence: ";
  std::getline(std::cin, sentence);
  
  int length = sentence.length();
  
  
  for(int i = (length-1); i >= 0; i--)
  /*
    This takes in the sentence starting at the end of it and working towards the
    begining of the sentence. It calls the rverse function when it hits a space 
    so as to turn the word back around and places as the next word in the new
    sentence.
  */
  {
    holder += sentence[i];
    
    if(sentence[i] == space[0] or i == 0)
    {
      int size = holder.length();
      holder = reverse(holder, temp, size-1);
      backwards += space[0];
      backwards += holder;
      holder = " ";
    }
  }
  
  std::cout << backwards;
  
  return 0;

}