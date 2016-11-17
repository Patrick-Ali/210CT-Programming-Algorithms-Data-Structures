#include <iostream>
#include <limits>
#include <math.h>

int trailingZero(int num)
/* 
    Takes in a number and then works out the number of trailing zeros it has after
    factorising it.
*/
{
  int holdNum = num;
  int exponent = 1;
  int tz = 0;
  
  while((holdNum/pow(5,exponent)) >= 1 )
  /* 
    This is dividing the number by 5 raised to power i
    until the division is less than 1.
    This is to determine the number of times 5 or a power of it
    can go into the number thus generating the number of trailing zeros
    by adding these divisions togther.
  */
  {
    holdNum = holdNum/pow(5,exponent);
    tz += holdNum;
    exponent += 1;
    holdNum = num;
  }
  
  return tz;
}

int main() 
{

 int num;
 
 while(true)//validating user input
 {
    std::cout << "Please enter a number: ";
    std::cin >> num;
    
    if (num < 0)
    {
        std::cout << "This number is not acceptable" << std::endl;
        continue;
    }
        
    if(std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "That is not a valid input" << std::endl;
    }
    else
    {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        break;
    }
        
 }
 
 int tz = trailingZero(num);
 
 tz > 1 ? std::cout << num << "! has " << tz << " trailing zeros" :
 std::cout << num << "! has " << tz << " trailing zero";
 
 return 0;

}