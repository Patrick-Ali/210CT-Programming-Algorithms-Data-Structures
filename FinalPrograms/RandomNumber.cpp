#include <iostream>
#include <cstdlib>
#include <ctime>

int getRandomNumber(int min, int max)
{
     srand(static_cast<int>(time(0)));
    
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0 );
    
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}


int main()
{
     using namespace std;
    
     cout<<getRandomNumber(1,10)<<endl;
    
     return 0;
 }