#include <iostream>
#include <limits>

int squareChecker(int num)
{
    /*
        Takes in a number and works out its closest perfect square.
        e.g. 80's perfect square would be 64 as it is 8*8 thus the closest
        perfect square number less than or equal to 80.
    */
    
    if(num == 0 or num == 1)
    {
        return num;
    }
    
    for(int i = 2; i <= num; i++)
    {
         /*
           Loops through every number less than the parameter, squaring the 
           iteration number until the square is either greater than or 
           equal to the parameter.
    
        */
        int square = i*i;
        
        if(square == num)
        {
            return i;
        }
        else if(square > num)
        {
            return i-1;
        }
    }
}

main()
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
    
    int hold = squareChecker(num);
    
    std::cout << hold << " is the square root of: " << hold*hold << ", which is the highest perfect square of:  " << num << std::endl; 
    
 return 0;
}