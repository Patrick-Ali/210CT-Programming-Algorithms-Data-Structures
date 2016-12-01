#include <iostream>
#include <math.h>
using namespace std;
int main() {
  
  //int eggs[30]{3,3,3,3};
  
  int aliens[30]{1,1,1,1,1};
  
  //int ii = 4;
  
  //for(int i = 4; i < 30; i++)
  //{
    //eggs[i] = 3 * ii;
   // ii += 3;
  //}
  
  //for(auto const &element : eggs)
 // {
    //cout << element << " ";
  //}
  
  //cout << endl;
  
  for(int i = 5; i < 30; i++)
  {
    aliens[i] = aliens[i-1] + (aliens[i-5]*3);
  }
  
  for(auto const &element : aliens)
  {
    cout << element << " ";
  }
  
  //cout << 115-39 << endl;

}