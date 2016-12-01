#include <iostream>

using namespace std;

int size(int num)
{
    int count = 0;
    
    int *pnt = &count;
    
    while(num > 0)
    {
        num = num/10;
        //cout << num << endl;
        count += 1;
        //cout << *pnt << endl;
    }
    
    return count;
}

int factorial(int num)
{
    if(num < 0)
    {
        return -1;
    }
    else if(num == 0 or num == 1)
    {
        return 1;
    }
    else
    {
        return num*factorial(num-1);
    }
}

int main()
{
    int num = 12345;
    int count = 0;
    
    //cout << count << endl;
    
    int holdnum = num;
    
    while(holdnum > 0)
    {
        holdnum = holdnum/10;
        count += 1;
    }
    
    cout << count << endl;
    
    //for(int i = 0)
     //{
         cout << num << endl;
         
     //}
    
    return 0;
}