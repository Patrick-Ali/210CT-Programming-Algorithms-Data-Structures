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

#include <limits>