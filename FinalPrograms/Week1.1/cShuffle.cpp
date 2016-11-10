#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
  srand(static_cast<int>(time(0)));
  
  int hand[8] {5,3,8,6,1,9,2,7};
  
  int shuffleTime = (rand()%10)+11; // This will determine the number of times we swap pairs, in this case it has a mxaimum of 20 swaps, this being an arbitrary number
  
  for(int i = 1; i < shuffleTime; i++)
  {
      int num1 = (rand()%8);
      
      int num2 =  (rand()%8);
      
      while(num2 == num1) // making sure not to swap the same item
      {
         num2 = (rand()%8);
         
      }
      
      int hold = hand[num1];
      hand[num1] = hand[num2];
      hand[num2] = hold;
      
  }
  
  for(auto const &element : hand)
  {
    std::cout << element << " ";
  }
    
    return 0;
}