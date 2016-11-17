#include <iostream>
#include <limits>

bool isPrime(int num1, int num2)
/*
    Takes in two numbers, the first beng the number we are testing
    the second is an ever decreasing number until it hits 1.
    It checks if num1 can be wholly devided by num2 as if it can 
    the numbver is not prime.
*/
{
  
    if (num1 <= 1)
    {
       return false;
    }
    else if (num1 == 2)
    {
        return true;
    }
    else if (num2 <= 1)
    {
        return true;
    }
    else if (num1%num2 == 0)//can num1 be wholly devided by num2 
    {
        return false;
    }
    else
    {
        return isPrime(num1, (num2-1));
    }
}    

int main()
{
  
    int num1;
    
    while(true)//validating user input
    {
        std::cout << "Please enter a number: ";
        std::cin >> num1;
        
        if (num1 < 0)
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
    
    bool prime = isPrime(num1, (num1-1));
    
    prime == true ?  std::cout << "This is a Prime Number" << std::endl :
        std::cout << "This is not a Prime Number" << std::endl;

    return 0;
}