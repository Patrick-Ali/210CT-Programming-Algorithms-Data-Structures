#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
  srand(static_cast<int>(time(0)));
  
  int hand[8] {5,3,8,6,1,9,2,7};
  
  int shuffleTime = (rand()%10)+10;
  
  for(int i = 1; i < shuffleTime; i++)
  {
      int num1 = (rand()%8);
      while (num1 < 0)
      {
        num1 = (rand()%8);
      }
      
      int num2 =  (rand()%8);
      
      while(num2 == num1)
      {
         num2 = (rand()%8);
         
      }
      while (num2 < 0)
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