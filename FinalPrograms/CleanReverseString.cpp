#include <iostream>
#include <math.h>
#include <string>
using namespace std;

void reverse(std::string& hold, int size)
{
  std::string temp;
  for(int i = size; i >= 0; i--)
  {

    temp += hold[i];

  }
  
  hold = temp;
}

int main() {
  
  std::string sentence;
  std::string holder;
  std::string backwards = " ";
  std::string space = " ";
  cout << "Enter Sentence: ";
  std::getline(std::cin, sentence);
  
  int length = sentence.length();
  
  
  for(int i = (length-1); i >= 0; i--)
  {
    holder += sentence[i];
    
    if(sentence[i] == space[0] or i == 0)
    {
      int size = holder.length();
      reverse(holder, size-1);
      backwards += holder;
      holder = " ";
    }
  }
  
  cout << backwards;
  
  return 0;

}