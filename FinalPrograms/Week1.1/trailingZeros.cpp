#include <iostream>
#include <math.h>
using namespace std;

int trailingZero(int num)
/* 
    Takes in a number and then works out the number of trailing zeros it has after
    factorising it.
*/
{
  int holdNum = num;
  int i = 1;
  int tz = 0;
  
  while((holdNum/pow(5,i)) >= 1 )
  /* 
    This is dividing the number by 5 raised to power i
    until the division is less than 1.
    This is to determine the number of times 5 or a power of it
    can go into the number thus generating the number of trailing zeros
    by adding these divisions togther.
  */
  {
    holdNum = holdNum/pow(5,i);
    tz += holdNum;
    i += 1;
    holdNum = num;
  }
  
  return tz;
}

int main() {

 cout << "Please enter a number: ";
 int num;
 cin >> num;
 
 int tz = trailingZero(num);
 
 cout << num << "! has " << tz << " trailing zero(s)";

}