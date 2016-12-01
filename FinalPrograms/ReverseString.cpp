#include <iostream>
#include <math.h>
#include <string>
using namespace std;

void reverse(std::string& hold, int size)
{
  std::string temp;
  std::string space = " ";
  for(int i = size; i >= 0; i--)
  {
    cout << hold[size] << endl;
    int count = size-i;
    cout << "Round: "<< count << endl;

   // if(count == 0)
    //{

      //temp[count] = hold[i];
      //cout << temp << endl;
    //}
    //else
    //{
      temp += hold[i];
      cout << temp << endl;
    //}
  }
  
  cout << "Temp is: " << temp << endl;
  hold = temp;
}

int main() {
  
  char word1;
  char word2;
  std::string sentence;
  std::string holder;
  std::string backwards = " ";
  std::string space = " ";
  //cout << "Enter Word: ";
  //std::getline(std::cin, sentence);
  
  sentence = "Hello World!";
  
  int length = sentence.length();
  
  //cout << sentence << endl;
  
  //cout << sentence[length-1] << endl;
  
  int teller = 0;
  
  for(int i = (length-1); i >= 0; i--)
  {
    //cout << sentence[i];
    if(i == (length-1))
    {
      cout << "hello 1 " << sentence[i] << endl;
      holder = sentence[i];
      teller = 1;
    }
    else
    {
      holder += sentence[i];
    }
    
    if(sentence[i] == space[0] or i == 0)
    {
      cout << holder << endl;
      teller = 0;
      int size = holder.length();
      reverse(holder, size-1);
      cout << endl;
      //if(backwards[0] == space[0])
      //{
        //backwards = holder;
     // }
     // else
     // {
        backwards += space[0];
        backwards += holder;
      //}
      holder = " ";
      
    }
  }
  
  cout << endl;
  cout << backwards;
  
  return 0;

}