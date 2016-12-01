#include <iostream>
#include <cstdlib>
#include <ctime>

int getRandomNumber(int min, int max)
{
     srand(static_cast<int>(time(0)));
    
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0 );
    
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

//void shuffel(int hand[])
//{
//  int shuffleTime = getRandomNumber(10,20);
 // std::cout << shuffleTime << std::endl;
  
//  for(int i = 1; i < shuffleTime; i++)
 // {
//      int num1 = getRandomNumber(0,9);
//     int num2 = getRandomNumber(0,9);
//     int hold = hand[num1];
//      hand[num1] = hand[num2];
//      hand[num2] = hand[num1];
//      
//  }
  

//}

int main()
{
  srand(static_cast<int>(time(0)));
  
  int hand[8] {5,3,8,6,1,9,2,7};
  int holdHand[8];
  
  int size = sizeof(hand)/sizeof(*hand); 
  
  int c = 0;  
  for(auto const &element : hand)
  {
    std::cout << element << " ";
    holdHand[c] = element;
    c++;
  }
  
  //shuffel(hand);0
  //std::cout << std::endl;
  
  for(int i = 1; i <= 100; i++)
  {
  
  int c = 0;  
  for(auto const &element : hand)
  {
    std::cout << element << " ";
    holdHand[c] = element;
    c++;
  }
  
  int shuffleTime = (rand()%10)+10;//getRandomNumber(10,20);
  //std::cout << shuffleTime << std::endl;
  
  for(int i = 1; i < shuffleTime; i++)
  {
      int num1 = (rand()%8);//getRandomNumber(0,8);
      while (num1 < 0)
      {
        num1 = (rand()%8);
      }
     //std::cout << num1 << std::endl;
      int num2 =  (rand()%8);//getRandomNumber(0,8);
     //std::cout << num2 << std::endl;
      while(num2==num1)
      {
         num2 = (rand()%8);//getRandomNumber(0,8);
         //std::cout << num2 << std::endl;
      }
      while (num2 < 0)
      {
        num2 = (rand()%8);
      }
      int hold = hand[num1];
      hand[num1] = hand[num2];
      hand[num2] = hold;
      
  }
  
  int count = 0;
  
  for(int i = 0; i < size; i++) 
  {
    if (hand[i] == holdHand[i])
    {
      count += 1;
    }
  }
  
  if(count == size)
  {
    std::cout << "True \n"; 
  }
  else
  {
    std::cout << "False \n";
  }
  
  }
  
  for(auto const &element : hand)
  {
    std::cout << element << " ";
  }
    
    return 0;
}