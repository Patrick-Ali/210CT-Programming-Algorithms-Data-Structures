#include <iostream>

int squareChecker(int paramater)
{
    if(paramater == 0 or paramater == 1)
    {
        return paramater;
    }
    
    for(int i = 0; i <= paramater; i++)
    {
        int square = i*i;
        
        if(square == paramater)
        {
            return i;
        }
        else if(square > paramater)
        {
            return i-1;
        }
    }
}

main()
{
    int paramater = -1;
    
    while(paramater < 0)
    {
        std::cout << "Please enter a number: ";
        std::cin >> paramater;
    
        if (paramater < 0)
        {
            std::cout << "This number is not acceptable" << std::endl;
        }
    }
    
    int hold = squareChecker(paramater);
    
    std::cout << hold << " is the square root of: " << hold*hold << " which is the highest perfect square of:  " << paramater << std::endl; 
    
 return 0;
}