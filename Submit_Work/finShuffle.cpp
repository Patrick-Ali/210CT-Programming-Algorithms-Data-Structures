#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

std::vector<int> shuffle(std::vector<int> hand)
{
  /*
    Takes in a vector, randomly shuffles it and outputs the shuffled vector.
  */
  
  int numberOfSwaps = (rand()%10)+11; /* This will determine the number of times we swap pairs, 
  in this case it has a mxaimum of 20 swaps, this being an arbitrary number */
  
  for(int i = 1; i <= numberOfSwaps; i++)//loops until we reach the number of swamps
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
  
  return hand;
}

int main()
{
  
  srand(static_cast<int>(time(0))); // generate random number seed
  
  std::vector<int> hand {5,3,8,6,1,9,2,7};

  hand = shuffle(hand);
    
  for(auto const &element : hand)//for every element in hand print it out
  {
    std::cout << element << " ";
  }
    
  return 0;
  
}